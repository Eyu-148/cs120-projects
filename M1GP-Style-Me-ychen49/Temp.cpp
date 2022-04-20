//
// Created by 15255 on 1/30/2022.
//
#include "Temp.h"

Temp::Temp() : fahrenheitDegree(32) {}

double Temp::getF() const {
    return fahrenheitDegree;
}

double Temp::getC() const {
    return (fahrenheitDegree - 32) * (5/9);
}

void Temp::setF(double fahNew) {
    fahrenheitDegree = fahNew;
}

void Temp::setC(int celNew) {
    // change the celsius degree into fahrenheit
    fahrenheitDegree = celNew * (9/5) + 32;
}
