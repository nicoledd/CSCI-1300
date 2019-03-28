#include <iostream>
using namespace std;

// function that removes capital letters from input string
string removeCapitals(string str){
    
    string strNoCapitals;
    
    // this for-loop all non-capital-letters to strNoCapitals string
    for(int i = 0; i < str.length(); i++){

        if(str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'M' &&
            str[i] != 'B' && str[i] != 'F' && str[i] != 'J' && str[i] != 'N' &&
            str[i] != 'C' && str[i] != 'G' && str[i] != 'K' && str[i] != 'O' &&
            str[i] != 'D' && str[i] != 'H' && str[i] != 'L' && str[i] != 'P' &&
            str[i] != 'Q' && str[i] != 'T' && str[i] != 'W' && str[i] != 'Y' &&
            str[i] != 'R' && str[i] != 'U' && str[i] != 'X' && str[i] != 'Z' &&
            str[i] != 'S' && str[i] != 'V'){

            strNoCapitals += str[i];
        }
    }

    // return the final strNoCapitals string
    return strNoCapitals;
}

int main(){
    string str = "#Aello";
    cout << removeCapitals(str) << endl;
    return 0;
}

