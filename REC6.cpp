#include <iostream>
using namespace std;

// given an input string, a deliminaor, and an array: stores the items in the
// input string (that are separated by the deliminator) into the array
int split(string input, char delim, string array[]){
    
    int numItems = 0;
    int idxArr = 0;
    
    // if input string is empty, return 0
    if(input == ""){
        return 0;
    }
    
    // read the string
    for(int idxStr = 0; input[idxStr] != '\0'; idxStr++){
        
        // while deliminator is not reached, add string char to array
        if(input[idxStr] != delim){
            array[idxArr] += input[idxStr];
        }
        // if deliminator is reached, move on to next idxArr
        if(input[idxStr] == delim){
            numItems++;
            idxArr++;
        }
    }
    
    // num counts deliminators, so numItems is one more than num deliminators
    numItems++;
    
    // return number of items in array at the end
    return numItems;
}


int main(){
    
    string array[4];
    split("You're a wizard Harry", ' ' , array);
    
    for(int idxArr = 0; idxArr < 4; idxArr++){
        cout << array[idxArr] << "\n";
    }
    return 0;
}
