#include "ClassTriangle.h"

void Triangle::calculateAngels(){
    firstAngel = acos((secondSide * secondSide + thirdSide * thirdSide - firstSide * firstSide) 
     / (2 * secondSide * thirdSide)) * 180 / M_PI;
    
    secondAngel = acos((firstSide * firstSide + thirdSide * thirdSide - secondSide * secondSide)
     / (2 * firstSide * thirdSide)) * 180 / M_PI;

    thirdAngel = acos((firstSide * firstSide + secondSide * secondSide - thirdSide * thirdSide)
     / (2 * firstSide * secondSide)) * 180 / M_PI;
}

bool Triangle::isTriangle(double a, double b, double c){
    return (a + b > c) && 
    (a + c > b) &&
    (b + c > a) &&
    (a > 0) && (b > 0) && (c > 0);
}

Triangle::Triangle(){
    firstSide = 6;
    secondSide = 6;
    thirdSide = 6;
    calculateAngels();
}

Triangle::Triangle(double a, double b, double c){
    if (isTriangle(a, b, c)){
        firstSide = a;
        secondSide = b;
        thirdSide = c;
        calculateAngels();
    }
    else{
        Triangle();
    }
}

string Triangle::toString(){
    return "Sides of triangle: " + to_string(firstSide) + " " + to_string(secondSide) + " " + to_string(thirdSide) +
            ". Angels of triangle: " + to_string(firstAngel) + " " + to_string(secondAngel) + " "
             + to_string(thirdAngel) + ".";
}

double Triangle::getSide(int numOfSide){
    switch(numOfSide){
        case 1:
            return firstSide;
        case 2:
            return secondSide;
        case 3:
            return thirdSide;
        default:
            return -1;
    }
}

double Triangle::getAngle(int numOfAngel){
    switch(numOfAngel){
        case 1:
            return firstAngel;
        case 2:
            return secondAngel;
        case 3:
            return thirdAngel;
        default:
            return -1;
    }
}

void Triangle::setSide(int numOfSide, double a){
    switch(numOfSide){
        case 1:
            if (isTriangle(a, secondSide, thirdSide)){
                firstSide = a;
                calculateAngels();
            }
            break;
        case 2:
            if (isTriangle(firstSide, a, thirdSide)){
                secondSide = a;
                calculateAngels();
            }
            break;
        case 3:
            if (isTriangle(firstSide, secondSide, a)){
                thirdSide = a;
                calculateAngels();
            }
            break;
    }
}

double Triangle::calculateHeight(){
    return secondSide * sin(thirdAngel);
}

double Triangle::calculatePerimeter(){
    return firstSide + secondSide + thirdSide;
}


double Triangle::calculateSquare(){
    return 0.5 * firstSide * calculateHeight();
}

string Triangle::triangleType(){
    if (abs(firstSide - secondSide) < EPS && abs(secondSide - thirdSide) < EPS)
        return "equilateral";
    else if (abs(firstSide - secondSide) < EPS || abs(firstSide - thirdSide) < EPS || abs(secondSide - thirdSide) < EPS)
        return "isosceles";
    else if (abs(firstAngel - 90) < EPS || abs(secondAngel - 90) < EPS || abs(thirdAngel - 90) < EPS)
        return "rectangular";
    else if (abs(firstAngel - 90) > EPS || abs(secondAngel - 90) > EPS || abs(thirdAngel - 90) > EPS)
        return "obtuse";
    return "acute-angled";
}
