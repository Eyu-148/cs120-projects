#include "Button.h"
#include "graphics.h"
using namespace std;

Button::Button(color fill, point center, unsigned int width, unsigned int height, std::string label) : Quad(fill, center, width, height) {
    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {fill.red - 0.5, fill.green - 0.5, fill.blue - 0.5};
}

void Button::draw() const {
    // draw the button
    Quad::draw();
    // draw the text
    glColor3f(0, 0, 0);
    glRasterPos2i(center.x - (4 * label.length()), center.y + 7);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}

/* Returns true if the coordinate is inside the box */
bool Button::isOverlapping(int x, int y) const {
    // TODO: Implement
    if ((x <= center.x + width / 2 && x >= center.x - width / 2) && (y <= center.y + height / 2 && y >= center.y - height / 2)) {
        return true;
    }
    return false; // Placeholder for compilation
}

/* Change color of the box when the user is hovering over it */
void Button::hover() {
    setColor(hoverFill);
}

/* Change color of the box when the user is clicking on it */
void Button::pressDown() {
    setColor(pressFill);
}

/* Change the color back when the user is not clicking/hovering */
void Button::release() {
    setColor(originalFill);
}