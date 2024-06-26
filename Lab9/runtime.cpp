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
    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);
    // size (n) of all tests
    vector<int> file_size;
    vecGen("sizes.csv", file_size);

    //n list of numbers
    vector<int>v;

    //results of times
    vector<std::chrono::microseconds> times;

    //results of average times
    vector<std::chrono::microseconds> avg;

    // create a for loop to iterate through the file sizes
        for(int i = 0; i < file_size.size(); i++) {
        // get the name/size of the file and assign it to string called filename
            string filename = to_string(file_size[i]) + "_numbers.csv";
        //call vecGen on filename and v
            vecGen(filename, v);

        //print filename (this will be good for debugging)
            cout << filename << endl;

        //call times.clear() // this ensures that we reset times everytime we read a new file
            times.clear();

        //create another for loop to iterate through all the elements from elem_to_find.
        // the code here should be nearly identical to the code from the previous lab
        for(int i = 0; i < elem_to_find.size(); i++) {
            int elem = elem_to_find[i];

            auto start = std::chrono::high_resolution_clock::now();
            int index_if_found = iterativeSearch(v, elem);
            auto end = std::chrono::high_resolution_clock::now(); 
        
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            cout << index_if_found << ": " << duration.count() << endl;
            
            // append the elapsed_time_in_sec to the vector, times (hint: push_back())
            // This code should be within the for loop that iterates
            // through all the elements from elem_to_find
            times.push_back(duration);
        }
            std::chrono::microseconds avg_time = average(times);
            avg.push_back(avg_time);


        // append the double to avg. (hint: push_back())
            //avg.push_back(avg_time);
        // This code should be outside the for loop that iterates throught
        // all the elements from elem_to_find
        // but within the for loop that iterates through the file sizes    

    }
    writeTimes("iterativeSearch_times.csv", avg, v);

    //This next part is purely for binarySearch
    for(int i = 0; i < file_size.size(); i++) {
            string filename = to_string(file_size[i]) + "_numbers.csv";

            vecGen(filename, v);

            cout << filename << endl;

            times.clear();

        for(int i = 0; i < elem_to_find.size(); i++){
            int elem = elem_to_find[i];

            auto start = std::chrono::high_resolution_clock::now();
            int index_if_found = binarySearch(v, 0, v.size(), elem);
            auto end = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            cout << index_if_found << ": " << duration.count() << endl;

            times.push_back(duration);
        }
            std::chrono::microseconds avg_time = average(times);
            avg.push_back(avg_time);
    }
    //Outside both for loops call writeTimes with the appropriate parameters
    // the first parameter should be "binarySearch_times.csv"
    // read the function brief to complete the rest of the parameters
    writeTimes("binarySearch_times.csv", avg, v);
}