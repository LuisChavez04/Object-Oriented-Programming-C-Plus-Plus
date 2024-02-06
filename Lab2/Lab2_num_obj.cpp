//Lab1_num_obj.cpp
/***
 * {This lab will display different examples of number objects.
 * For example: integers, floats, doubles, characters, and booleans
 * These will be displayed with an example of what each is.}
***/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    //numerical
    int int_example = 1;
    float float_example = 2.0;
    double double_example = 2.0;

    //non-numerical
    char char_example = 'a';
    bool bool_example = true;

    //sizeof returns the number of bytes (8 bits is equivalent to 1 byte))
    cout << "int_example: " << sizeof(int_example) << endl;
    cout << "float_example: " << sizeof(float_example) << endl;
    cout << "double_example: " << sizeof(double_example) << endl;

    cout << "char_example: " << sizeof(char_example) << endl;
    cout << "bool_example: " << sizeof(bool_example) << endl;
}