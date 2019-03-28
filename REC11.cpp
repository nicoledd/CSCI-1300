#include <iostream>
using namespace std;

// this function converts decimal to binary
// using a while loop
// returns a string
string decimalToBinaryIterative( int num ){
    string str;
    if( num == 0 )
        return "0";
    while( num != 0 ){
        str = ( num % 2 == 0 ? "0" : "1" ) + str;
        num /= 2;
    }
    return str;
}

// this function converts decimal to binary
// using recursion
// returns a string
string decimalToBinaryRecursive( int num ){
    if ( num == 0 )
        return "0";
    num = num % 2 + 10 * ( stoi( decimalToBinaryRecursive( num/2 ) ) );
    return to_string( num );
}


int main(){
    cout << decimalToBinaryIterative(7) << "\n";
    cout << decimalToBinaryRecursive(7);
    return 0;
}
