#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the array and their memory locations
 * 
 * @param arr - array of integers
 * @param size - the number of elements in the array
 */
void printMemArr(const int * arr, int size) { // void printMemArr(int arr[], int size)
    printf("Array - Each int is worth %lu bytes\n", sizeof(arr[0]));
    for(int i = 0; i < size; i++) {
        printf("Value :%i at Memory Location: %p\n", arr[i], arr + i);
    }
}

/**
 * @brief increments all the elements in arr by 10
 * 
 * @param arr - array of integers
 * @param size - the number of elements in the array
 */
void incArrBy10(int * arr, int size) { // void incArrBy10(int arr[], int size)
    for(int i = 0; i < size; i++) {
        arr[i] += 10;
    }
}