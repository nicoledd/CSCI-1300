#include <iostream>
using namespace std;

// given an input number, prints whether number is pos, neg, or zero
void numberSign(int number){
    
    if(number < 0){
        cout << "negative\n"; 
    }
    
    else if(number > 0){
        cout << "positive\n";
    }
    
    else{
        cout << "zero\n";
    }
}

// given an input year, returns 1 if year is leap year, else returns 0
int checkLeapYear(int year){
    
    if( (year % 4 == 0 && year <= 1582)
        ||(year % 4 == 0 && year > 1582 && year % 100 != 0)
        ||(year % 4 == 0 && year > 1582 && year % 100 == 0 && year % 400 == 0) ){
        
        cout << "leap year\n";
        return 1;
    }
    
    else{
        cout << "not leap year\n";
        return 0;
    }
}

int main(){
    numberSign(10);
    checkLeapYear(10);
    return 0;
}
