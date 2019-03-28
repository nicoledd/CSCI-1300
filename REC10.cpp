// write a function that takes in an int
// vector as a parameter. Prompt the user
// to oenter int values and fill the vector
// with those values at the rear of the vector.
// continue to prompt the user until the user
// enters a value less than or equal to 0.

#include <iostream>
#include <vector>
using namespace std;

void modifyVector( vector <int> & v ) {
    
    int user_input_number = 10;

    while ( user_input_number > 0 ) {
        
        // prompt the user to enter an integer value
        cout << "Please enter an integer value: \n";
        cin >> user_input_number;
        
        // if user_input_number isn't 0 or negative
        
        // if vector size is zero, add the input to the vector
        if ( v.size() == 0 && user_input_number > 0 ) {
            v.insert( v.begin() + 0, user_input_number );
        }
        
        // else if input is divisible by 5, delete first vector element
        else if ( user_input_number > 0 && user_input_number % 5 == 0 ) {
            v.erase( v.begin() + 0 );
        }
        
        // else if input is divisible by 3, delete last vector element
        else if ( user_input_number > 0 && user_input_number % 3 == 0 ) {
            v.pop_back();
        }
        
        // else insert the input at the end of the vector
        else if ( user_input_number > 0 ) {
            v.insert( v.begin() + v.size(), user_input_number );
        }
    }
} 

   
int main() { 
    
    // initialize vector
    vector <int> v; 
    
    // call modifyVector function
    modifyVector(v);
    
    cout << "size: " << v.size() << "\n";
    cout << "value at position 0 in the vector: " << v.at(0) << "\n";
    cout << "value at position 1 in the vector: " << v.at(1) << "\n";
    
    return 0; 
}
