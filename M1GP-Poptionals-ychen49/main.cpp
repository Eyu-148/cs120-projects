#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <experimental/optional>

using namespace std;
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;

/*
 *  This project will use ASCII art:
 *                                                                  _
 *  A box represents reserved memory (to hold a variable's value): | |
 *                                                                 |_|
 *                                                                              ?_
 *  A box with a question mark in the upper left corner represents an optional: | |
 *                                                                              |_|
 *                                                      _ _ _ _ _ _
 *  A series of consecutive boxes represents a vector: | | | | | | |
 *                                                     |_|_|_|_|_|_|
 *
 *  An arrow represents a pointer: ---->
 *
 *  An arrow with a bar represents a nullptr: -->|
 */

// Function declarations
void funcNine(shared_ptr<string> myptr);
optional<int> funcTen(shared_ptr<vector<optional<int>>> myptrr, unsigned int i);


int main() {
    /* 1. Create the following optional integers:
     *      ?__
     *      |  |
     *      |__|
     *      ?__
     *      |42|
     *      |__|
     *      ?__?__?__?__?__?__?__?__
     *      |  |90|44|  |79|  |-5|17|
     *      |__|__|__|__|__|__|__|__|
     */
    optional<int> optEmpty1 = nullopt;
    optional<int> opt1_0 = make_optional<int>(42);
    // Now make a vector of optionals
    vector<optional<int>> optVec1 = { nullopt, make_optional<int>(90), make_optional<int>(44),
                                      nullopt, make_optional<int>(79), nullopt, make_optional<int>(-5),
                                      make_optional<int>(17) };
    // Check the elements
    /** for (optional<int> item:optVec1) {
        if (item) {
            cout << *item << endl;
        } else {
            cout << "Null Optional" << endl;
        }
    }**/




    /* 2. Create the following smart pointers,
     *    where each one points to a different data type:
     *      Stack           Heap
     *       __              __
     *      |  | ---------> |11|
     *      |__|            |__|
     *       __              ___
     *      |  | ---------> |0.3|
     *      |__|            |___|
     *       __              __
     *      |  | ---------> |d |
     *      |__|            |__|
     *       __              __
     *      |  | ---------> |yo|
     *      |__|            |__|
     *       __              ____
     *      |  | ---------> |true|
     *      |__|            |____|
     *       __              _________
     *      |  | ---------> |123456789|
     *      |__|            |_________|
     */
    unique_ptr<int> ptr2_1 = make_unique<int>(11);
    unique_ptr<float> ptr2_2 = make_unique<float>(0.3);
    unique_ptr<char> ptr2_3 = make_unique<char>('d');
    unique_ptr<bool> ptr2_4 = make_unique<bool>(true);
    unique_ptr<long> ptr2_5 = make_unique<long>(123456789);


    /* 3. Create the following smart pointers:
     * (Note that the orientation is horizontal instead of vertical for Stack and Heap memory on this one.)
     *            __ __ __ __ __ __ __ __ __
     *  Stack    |  |  |  |  |  |  |  |  |  |
     *           |__|__|__|__|__|__|__|__|__|
     *            |  |  |  |  |  |  |  |  |
     *            |  |  v  |  |  v  |  v  |
     *            v  v  -  v  v  -  v  -  v
     *           __  __   __  __   __    __
     *  Heap    |w ||- | |* ||? | |L |  |; |
     *          |__||__| |__||__| |__|  |__|
     */
    vector<shared_ptr<char>> ptrVec1 = {make_shared<char>('w'), make_shared<char>('-'), nullptr,
                                        make_shared<char>('*'), make_shared<char>('?'), nullptr,
                                        make_shared<char>('L'), nullptr, make_shared<char>(';')};
    /*for (int i=0; i<ptrVec1.size(); ++i) {
        if (ptrVec1[i]) {
            cout << *ptrVec1[i] << endl;
        }
    }*/



    /* 4. Create the following smart pointer:
     *      Stack           Heap
     *       __              __ __ __ __ __ __ __ __
     *      |  | ---------> |11|22|33|44|55|66|77|88|
     *      |__|            |__|__|__|__|__|__|__|__|
     */
    vector<int> ptrVec2 = { 11, 22, 33, 44, 55, 66, 77, 88 };
    unique_ptr<vector<int>> ptr4 = make_unique<vector<int>>(ptrVec2);
    //check
    /**for (int item:*ptr4) {
        cout << item << endl;
    }**/



    /* 5. Create the following smart pointers to your choice of data type:
     *      Stack      Heap
     *       __         __
     *      |  | ----> |  |
     *      |__|       |__|
     *                  |
     *                  v
     *                  __
     *                 |  |
     *                 |__|
     */
    unique_ptr<unique_ptr<int>> ptr5 = make_unique<unique_ptr<int>>(make_unique<int>( ));
    //cout << &ptr5 << " points to a pointer storing " << **ptr5;

    /* 6. Create the following smart pointers to your choice of data type:
     *      Stack      Heap
     *       __         __
     *      |  | ----> |  |
     *      |__|    >  |__|
     *             /
     *       __   /
     *      |  | /
     *      |__|
     */
    shared_ptr<int> ptr6 = make_shared<int>(2022);
    shared_ptr<int> ptr6AnotherOne = ptr6;
    //cout << &ptr6 << " and " << &ptr6AnotherOne << " are shared pointers. " << endl;



    /* 7. Create the following optional smart pointers:
     *      Stack      Heap
     *      ?__         __
     *      |  | ----> |98|
     *      |__|       |__|
     *
     *      ?__
     *      |  |
     *      |__|
     *
     *      ?__
     *      |  | --->|
     *      |__|
     */
    optional<unique_ptr<int>> opt7_1 = make_unique<int>(98);
    //cout << &opt7_1 << " points to " << **opt7_1 << endl;
    optional<unique_ptr<int>> opt7_2 = nullopt;
    optional<unique_ptr<int>> opt7_3 = nullptr;



    /* 8. Create the following smart pointers to optionals:
     *      Stack      Heap
     *       __        ?__
     *      |  | ----> |hi|
     *      |__|       |__|
     *
     *       __        ?__
     *      |  | ----> |  |
     *      |__|       |__|
     *
     *       __
     *      |  | --->|
     *      |__|
     */
    unique_ptr<optional<string>> ptr8_1 = make_unique<optional<string>>("hi");
    unique_ptr<optional<string>> ptr8_2 = make_unique<optional<string>>(nullopt);
    unique_ptr<optional<string>> ptr8_3 = nullptr;
    /*cout << **ptr8_1 << endl;
    if (*ptr8_2) {
        cout << **ptr8_2 << endl;
    } else {
        cout << "Null " << endl;
    }*/



    /* 9. Write a nontrivial function that takes at least one
     *    smart pointer parameter. Its effects and return value
     *    are up to you. Declare the function above main and
     *    define it below main. Call it here.
     */
    char ans = 'y';
    while (ans == 'y') {
        string inputStr;
        cout << "Give a string: " << endl;
        cin >> inputStr;
        shared_ptr<string> ptr9 = make_shared<string>(inputStr);
        funcNine(ptr9);
        ptr9 = nullptr;
        cout << "Continue? (y/n) " << endl;
        cin >> ans;
    }
    cout << "Completed. " << endl;



    /* 10. Write a function that takes a pointer to a vector of
     *     optionals and an unsigned integer index. Return the
     *     value at that index in the vector. If the index is
     *     out of range, return nullopt. Declare the function
     *     above main and define it below main. Call it here.
     */
    vector<optional<int>> optVec2 = {nullopt, make_optional<int>(90), make_optional<int>(44),
                                      nullopt, make_optional<int>(79), nullopt, make_optional<int>(-5),
                                      make_optional<int>(17), make_optional<int>(2398), nullopt};
    shared_ptr<vector<optional<int>>> ptr10 = make_shared<vector<optional<int>>>(optVec2);
    while (1) {
        unsigned int indexInput;
        cout << "Enter the index -- the vector size is 10: " << endl;
        cin >> indexInput;
        optional<int> opt10 = funcTen(ptr10, indexInput);
        if (opt10) {
            cout << "The value at " << indexInput << " is " << *opt10 << endl;
        } else {
            cout << "Null value or the input is out of range. " << endl;
        }
    }


    return 0;
}

// The global function should receive a pointer as parameter
// and return a message based on situations
// This function should return the length(maybe)
void funcNine(shared_ptr<string> myptr) {
    string mystr = *myptr;
    if (mystr.length() <= 0) {
        cout << "Please write something. " << endl;
    }
    if (mystr.length() > 0 && mystr.length() < 7) {
        while (mystr.length() < 7) {
            mystr.append("g");
        }
        cout << mystr.length() << endl;
    }
    if (mystr.length() == 7) {
        cout << "You got it! " << endl;
    } else {
        mystr.erase(7, mystr.length());
        cout << mystr.length() << endl;
    }
}

//function that takes a pointer to a vector of
//optionals and an unsigned integer index. Return the
//value at that index in the vector. If the index is
//out of range, return nullopt
optional<int> funcTen(shared_ptr<vector<optional<int>>> myptrr, unsigned int i) {
    try {
        return (*myptrr)[i];
    } catch (const out_of_range& oor) {
        return nullopt;
    }

}