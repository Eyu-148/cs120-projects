#include "graphics.h"
#include "Button.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;
enum displayWin {wdStart, wdConfettify, wdEnding};
Button spawn({1, 0, 0}, {100, 100}, 100, 50, "Spawn");
vector<Quad> confetti;
displayWin screen;

void spawnConfetti() {
    confetti.push_back(Quad({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0}, {rand() % (int)width, rand() % (int)height}, 10, 10));
}

void init() {
    width = 500;
    height = 500;
    srand(time(0));
    screen = wdStart;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/*
 * method to output text message */
void output(int x, int y, float red, float green, float blue, void* font, string meg) {
    glColor3f(red, green, blue);
    glRasterPos2f(x, y);
    int len, i;
    for (const char& c : meg) {
        glutBitmapCharacter(font, c);
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    /*
     * Draw here
     */
    if (screen == wdStart) {
        output(100, 100, 1.0, 1.0, 1.0, GLUT_BITMAP_HELVETICA_18, "Enter s to start!");
    }
    else if (screen == wdConfettify && confetti.size() <= 100) {
        // TODO: call the Button's draw method.
        spawn.draw();

        for (const Quad &piece: confetti) {
            piece.draw();
        }
    }
    else if (screen == wdConfettify && confetti.size() > 100){
        screen = wdEnding;
    }
    if (screen == wdEnding) {
        output(100, 100, 1.0, 1.0, 1.0, GLUT_BITMAP_HELVETICA_18, "See U next time!");
    }
    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // press s key
    if (key == 115 && screen == wdStart) {
        screen = wdConfettify;
    }

    if (key == 27 && screen == wdEnding) {
        glutDestroyWindow(screen);
        exit(0);
    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        // note that move in y-axis is opposite --> + is down, - is up
        case GLUT_KEY_DOWN:
            spawn.move(0, y);
            break;
        case GLUT_KEY_LEFT:
            spawn.move(-x, 0);
            break;
        case GLUT_KEY_RIGHT:
            spawn.move(x, 0);
            break;
        case GLUT_KEY_UP:
            spawn.move(0, -y);
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    // TODO: If the Button is overlapping with the (x, y) coordinate passed in, call the hover method. Otherwise, call the release method.
    if (spawn.isOverlapping(x, y)) {
        spawn.hover();
    } else {
        spawn.release();
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    // TODO: If the left button is down and the cursor is overlapping with the Button, call the pressDown method. Otherwise, call the release method.
    // TODO: If the left button is up and the cursor is overlapping with the Button, call spawnConfetti.
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN && spawn.isOverlapping(x, y)) {
            spawn.pressDown();
        }
        if (state == GLUT_DOWN && !spawn.isOverlapping(x, y)){
            spawn.release();
        }
        if (state == GLUT_UP && spawn.isOverlapping(x, y)) {
            spawnConfetti();
        }
    }
    
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Confettify!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
