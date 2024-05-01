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
template<typename T>
int iterativeSearch(vector<T>v, T elem){
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
template<typename T>
int binarySearch(vector<T> & v, int start, int end, T elem){
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
template<typename T>
void vecGen(string filename, vector<T> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

/**
 * @brief writes to file the time it took to search with respect to the
 *  size of the vector, n
 *  Number of Elements (n)      Time (sec)
 *  XXXX                        X.XXXXX
 *  XXXX                        X.XXXXX
 * 
 * @param filename (string) : filename (e.g. output_10000_numbers.csv)
 * @param times (vector<double>) : average times
 * @param n (vector<int>) : sizes of vectors
 */
void writeTimes(string filename, const vector<chrono::microseconds> times, const vector<int> n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for(int i = 0; i < times.size(); i++){

        myFile << n[i] << "\t" << std::chrono::duration<double>(times[i]).count() << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

/**
 * @brief computes the average of the elements in vector, a
 * 
 * @param a vector of double
 * @return double 
 */
std::chrono::microseconds average(const vector<chrono::microseconds> a){
    std::chrono::microseconds sum;
    sum = std::chrono::microseconds::zero();
    for(int i = 0; i < a.size(); i++){
        sum = sum + a[i];
    }
    return sum / a.size();
}

int main(){
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++) {
        // gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        clock_t start = clock(); // start time
        // call binarySearch with appropraite parameters
        int index_if_found = binarySearch(v, 0, v.size(), elem);
        clock_t end = clock(); // end time

        // calculates the total time it took in seconds
        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

        // prints the index and how long it took to find it
        cout << index_if_found << ": " << elapsed_time_in_sec << endl;
    }
    vector<double> d;
    vecGen("1000_double.csv", d);
    vector<double> double_to_find;
    vecGen("double_to_find.csv", double_to_find);

    // repeat the for loop above for binarySearch to search
    // through a vector of doubles

    //for(int i = 0; i < elem_to_find.size(); i++) {
            // gets the elem to search for
        //int elem = elem_to_find[i];

            // stopwatches the time
        //auto start = std::chrono::high_resolution_clock::now(); // start time
            // call binarySearch with appropraite parameters
        //int index_if_found = binarySearch(v, 0, v.size(), elem);
        //auto end = std::chrono::high_resolution_clock::now(); // end time

            // calculates the total time it took in seconds
        //auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            // prints the index and how long it took to find it
        //cout << index_if_found << ": " << duration.count() << endl;
    //}
    //d;
    //vecGen("1000_double.csv", d);
    //double_to_find;
    //vecGen("double_to_find.csv", double_to_find);
    
}