#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;


/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterativeSearch starts at the first index and iterates sequentially to the next until it either
 * finds the element or until it reaches the end (i.e. element does not exist)
 * 
 * @param v : vector of elements
 * @param elem : integer to look for
 * @return int
 */
int iterativeSearch(vector<int>v, int elem){
    // use a for loop where the index, i goes from 0 to the size of v
    for(int i = 0; i < v.size(); i++){
    
    // inside the for loop, use an if statement to check whether the element at i (e.g. v[i]) equals elem
    // inside the if statement return i

        if(v[i] == elem){
            return i;
        }
    }
    // outside of the for loop return -1
    return -1;
}

/**
 * @brief returns the index of elem, if it exists in v. Otherwise it returns -1.
 * binarySearch is recursive (i.e. function calls itself).
 * It utilizes the fact that v is increasing order (e.g. values go up and
 * duplicates are not allowed).
 * 
 * It calculates the mid from the start and end index. It compares v[mid] (i.e. values
 * at mid) with elem and decides whether to search the left half (lower values)
 * or right half (upper values).
 * 
 * 
 * @param v : vecotr of elements
 * @param start : leftmost index (starting value is 0)
 * @param end : rightmost index (starting value is v.size())
 * @param elem : integer to look for
 * @return int 
 */
int binarySearch(vector<int> & v, int start, int end, int elem){
    //write an if statement that checks the terminating case
    if(start > end){
    //inside the if statement return -1
        return -1;
    }

    // instantiate the midpoint
    int mid = (start + end) / 2;

    // Use if/else statements to do the following:
    // 1) update end (search left half)
    // 2) update start (search right half)
    // 3) return mid (found the elem)
    if(v[mid] == elem){
        return mid;
    } else if(v[mid] < elem){
        return binarySearch(v, mid + 1, end, elem);
    } else{
        return binarySearch(v, start, mid -1, elem);
    }
    // return a recursive call to binarySearch(...)

}

void vecGen(string filename, vector<int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

int main(){
    // populate v with 10000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);


    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++){
        // gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        auto start = std::chrono::high_resolution_clock::now();                        // start time
        int index_if_found = iterativeSearch(v, elem);  // call search
        auto end = std::chrono::high_resolution_clock::now();                          // end itme

        // calculates the total time it took in seconds
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        //prints the index and how long it took to find it
        cout << index_if_found << ": " << duration.count() << endl;
    }
    
        // repeat the for loop above so that it records the time
        // it takes for binarySearch to do the same operation
    for(int i = 0; i < elem_to_find.size(); i++){
        // gets the elem to search for
        int elem = elem_to_find[i];

        auto start = std::chrono::high_resolution_clock::now();                        // start time
        int index_if_found = binarySearch(v, 0, v.size(), elem);            // call search
        auto end = std::chrono::high_resolution_clock::now();                          // end itme

        // calculates the total time it took in seconds
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        //prints the index and how long it took to find it
        cout << index_if_found << ": " << duration.count() << endl;
    }
}