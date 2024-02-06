//Lab2_calc.cpp
/***
 * {This lab will calculate and display answers for one integer divided by another integer.
 * It will also display the answer for one integer divided by a double. The numerical values chosen are unable to change}
***/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    //numerical
    int int_x = 1;
    int int_y = 2;
    double double_z = 2.0;

    cout << "int divided by int: " << int_x / int_y << endl;
    cout << "int divided by double: " << int_x / double_z << endl;
}