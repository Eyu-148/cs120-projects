/*
 * Declaration of Temp class
 * getters to return values of Fahrenheit/Celsuis
 * setters requires the input and assign it to the varibles
 * setters will calculate if the unit is not the same */

#ifndef STYLE_ME_TEMP_H
#define STYLE_ME_TEMP_H

class Temp {
public:
    // Default Constructor
    Temp();

    // getters
    double getF() const;
    double getC() const;

    // setters
    void setF(double fahNew);
    void setC(int celNew);

private:
    // fields
    double fahrenheitDegree;
};

#endif //STYLE_ME_TEMP_H
