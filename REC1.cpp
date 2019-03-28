#include <iostream>
using namespace std;

int main(){
    string removeCapitals ( string );
    string str = "#Aello";
    cout << removeCapitals ( str );
    return 0;
}



string removeCapitals ( string str ) {
    int num = 0;
    for ( int i = 0; i < str.length(); i++ ) {
        if ( str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'M' &&
            str[i] != 'B' && str[i] != 'F' && str[i] != 'J' && str[i] != 'N' &&
            str[i] != 'C' && str[i] != 'G' && str[i] != 'K' && str[i] != 'O' &&
            str[i] != 'D' && str[i] != 'H' && str[i] != 'L' && str[i] != 'P' &&
            str[i] != 'Q' && str[i] != 'T' && str[i] != 'W' && str[i] != 'Y' &&
            str[i] != 'R' && str[i] != 'U' && str[i] != 'X' && str[i] != 'Z' &&
            str[i] != 'S' && str[i] != 'V' ) {
            num++;
        }
    }
    char arr[num];
    for ( int j = 0; j < num; j ++ ) {
        for ( int i = 0; i < str.length(); i++ ) {
            if ( str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'M' &&
            str[i] != 'B' && str[i] != 'F' && str[i] != 'J' && str[i] != 'N' &&
            str[i] != 'C' && str[i] != 'G' && str[i] != 'K' && str[i] != 'O' &&
            str[i] != 'D' && str[i] != 'H' && str[i] != 'L' && str[i] != 'P' &&
            str[i] != 'Q' && str[i] != 'T' && str[i] != 'W' && str[i] != 'Y' &&
            str[i] != 'R' && str[i] != 'U' && str[i] != 'X' && str[i] != 'Z' &&
            str[i] != 'S' && str[i] != 'V' ) { 
                arr[j] = str[i];
                j++;
            }
        }
    }
    
    string results = "";
    for ( int k = 0; k < num; k++ ) {
        results += arr[k];
    }
    return results;

}
