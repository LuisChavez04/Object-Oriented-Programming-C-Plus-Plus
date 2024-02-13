#include <iostream>
#include <cmath>

using namespace std;
// This lab will run a Control FLow program that we reference
// from a diagram. The program utilizes a while loop
// and if/else statements

int main()
{
    int x = 0;
    int y = 5;

    while (x < y) {
        printf("%i\n", x);
        x = x + 3;
    }
    if (x % 2 == 0) {
        printf("x is even\n");
    } else {
        printf("x is odd\n");
    }      
}