#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double EPS = 1e-9;

class Triangle{
    double firstAngel, secondAngel, thirdAngel;
    double firstSide, secondSide, thirdSide;

    public:
    bool isTriangle(double a, double b, double c);
    Triangle();
    Triangle(double a, double b, double c);
    void calculateAngels();

    string toString();
    double getSide(int numOfSide);
    double getAngle(int numOfAngel);

    void setSide(int numOfSide, double a);

    double calculateHeight();
    double calculatePerimeter();
    double calculateSquare();

    string triangleType();
};
