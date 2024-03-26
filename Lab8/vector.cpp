#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
 */
void printMemVec(...){}

/**
 * @brief increments all the elements in v by 10
 * 
 * @param v - address to a vector of integers
 */
void incVecBy10(...){}


int main() {
    // create a constant integer called SIZE that is of value 5

    // create a vector of integers called vec that can hold up to 5 elements

    // use a for loop to populate vec with the values 100 to 104

    printf("Before Increment-----------\n");
    //call printMemVec(...) on vec

    //call incBy10(...) on vec

    printf("After Increment-----------\n");
    //call printMemVec(...) on vec again to view the changes

    //remove last element of vec
    // (refer to docs)

    printf("After Pop-----------\n");
    //call printMemVec(...) on vec again to view the changes

    //append 101 and 102 at the end of vec
    // (refer to docs)

    printf("After Push-----------\n");
    //call printMemVec(...) on vec again to view the changes

    return 0;
}