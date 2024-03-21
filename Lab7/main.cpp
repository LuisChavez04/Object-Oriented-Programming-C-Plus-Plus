#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief writes sample_size number of integers
 * Example output: if n = 3 and arr = [1, 2, 3]
 * 1
 * 2
 * 3
 *
 * 
 * 
 * @param filename 
 * @param arr 
 * @param sample_size
 * 
 * array_int : 1 2 3 4 5 6 7 8 9 10
 * index (i) : 0 1 2 3 4 5 6 7 8 9
 * index addressable:
 * cout << array_int[0]; // 1
 * cout << array_int[9]; // 10 
 */
void writeToFile(string filename, int * arr, int sample_size){
    ofstream file(filename);
    int val;

    for(int i = 0; i < sample_size; i++){ //loop 1 - 9
        file << arr[i];
        file << "\n";
        // i        : 2
        // arr[i]   : 2
        /*
        file contents:
            1\n
            2\n
            3\n
        */
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

//---------------------------------------------------------------
/**
 * @brief writes sample_size number of strings
 * Example output: if n = 2 and arr = ["cat", "dog"]
 * cat
 * dog
 * @param filename 
 * @param arr 
 * @param sample_size 
 */
void writeToFile(string filename, string * arr, int sample_size){
    ofstream file(filename);
    int val;

    for(int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("wrote to %s\n", filename.c_str());
}

//-------------------------------------------------------------
/**
 * @brief writes sample_size number of char
 * Example outpute: if n = 2 and arr = ["c", "d"]
 * c
 * d
 * 
 * @param filename 
 * @param arr 
 * @param sample_size 
 */
void writeToFile(string filename, char * arr, int sample_size){
    ofstream file(filename);
    int val;

    for(int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

//---------------------------------------------------------------
/**
 * @brief reads the content of any file
 * 
 * @param filename 
 */
void readFile(string filename){
    ifstream file(filename);
    if(file.fail()){
        cout << "Couldn't open file " << filename << endl;
    
        file.close();
        return;
    }
}



int main(){
    const int SAMPLE_SIZE = 10;
    int array_int[SAMPLE_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string array_str[SAMPLE_SIZE] = {"This", "is", "a", "sentence.",
                                    "This", "is", "another", "sentence.",
                                    "The", "end."};

    char array_char[SAMPLE_SIZE] = {'a', 'b', 'c', 'd', 'e', '0', '1', '2', '3', '4'};

    string int_file = "array_int.csv";
    writeToFile(int_file, array_int, SAMPLE_SIZE); // arr is already a pointer

    //Do the same for the other arrays

    //Create a string variable as the file name and assign
    //it the value "array_str.csv"
    //CALL writeToFile using the string variable above, array_str, and SAMPLESIZE as
    //parameters

    string str_file = "array_str.csv";
    writeToFile(str_file, array_str, SAMPLE_SIZE);

    string char_file = "array_char.csv";
    writeToFile(char_file, array_char, SAMPLE_SIZE);




    //CALL readFile() on all three generated files
    string filename = "display_functions";
    readFile(filename);


    return 0;
}