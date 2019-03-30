#include <iostream>
using namespace std;

// given input integer, returns number next in the Collatz sequence
int collatzStep(int n){
    

    if ( (n % 2 == 0) && (n >= 0) ){
        return n / 2; //if the number is both even and positive, output n/2
    }

    else if ( (n % 2 != 0) && (n >=0) ){
        return 3 * n + 1; //if the number is both odd and positive, output 3n+1
    }
    
    else{
        return 0; //if the number doesn't fit the previous parameters, as in it is either zero or negative, output zero
    }

}


// counts num digits in input integer
int countDigits(int n){

    int m;
    
    if (n < 0){
        m = n * -1; //if the integer is negative, turn it positive
    }
    
    else{
        m = n; //otherwise, take in the integer as it is
    }
    
    if (m == 1000){
        return 4; //if the integer is 1000, it has 4 digits
    }
    
    //if the integer is between 100 and 999, it has 3 digits
    if ((m >= 100) && (m <= 999)){
        return 3;
    }
    
    if ((m <= 99) && (m >= 10)){
        return 2; //if the integer is between 99 and 10, it has 2 digits
    }
    
     //if the integer is between 0 and 9, it has 1 digit
    if ((m <= 9) && (m >= 0)){
        return 1;
    }

}



// returns num days in input month
void daysOfMonth(int n){
    
    switch (n){
        case 1: n = 1; cout << "Month 1 has 31 days"; break; //Janurary has 31 days
        case 2: n = 2; cout << "Month 2 has 28 or 29 days"; break; //February has 28 days
        case 3: n = 3; cout << "Month 3 has 31 days"; break; //March has 31 days
        case 4: n = 4; cout << "Month 4 has 30 days"; break; //April has 30 days
        case 5: n = 5; cout << "Month 5 has 31 days"; break; //May has 31 days
        case 6: n = 6; cout << "Month 6 has 30 days"; break; //June has 30 days
        case 7: n = 7; cout << "Month 7 has 31 days"; break; //July has 31 days
        case 8: n = 8; cout << "Month 8 has 31 days"; break; //August has 31 days
        case 9: n = 9; cout << "Month 9 has 30 days"; break; //September has 30 days
        case 10: n = 10; cout << "Month 10 has 31 days"; break; //October has 31 days
        case 11: n = 11; cout << "Month 11 has 30 days"; break; //November has 30 days
        case 12: n = 12; cout << "Month 12 has 31 days"; break; //December has 31 days
        default: cout << "Invalid month number"; break; //This month doesn't exist
    } 
}



int main() {
    collatzStep(5);
    countDigits(100);
    daysOfMonth(4);
    return 0;
}
