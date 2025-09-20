#include "ClassTriangle.h"

int main(){

    Triangle lol(5, 4, 3);
    cout << lol.toString() << endl;
    cout << lol.triangleType() << endl;
    cout << lol.getAngle(1) << endl;
    cout << lol.getSide(2) << endl;
    cout << lol.getSide(5) << endl;
    cout << lol.getAngle(8) << endl;

    lol.setSide(2, 80);
    lol.setSide(1, 6);

    cout << lol.toString() << endl;
    cout << lol.calculatePerimeter() << endl;
    cout << lol.calculateSquare() << endl;
    cout << lol.calculateHeight() << endl;
    return 0;
}