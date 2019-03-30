#include <iomanip>
#include <iostream>
using namespace std;


// takes input celsius, converts to fahrenheit
void celsiusToFahrenheit(int celsius){
    
    float fahrenheit; // fahrenheit can be a decimal number
   
    fahrenheit = celsius * 9.00 / 5.00 + 32; //use formula to calculate fahrenheit
   
    cout << "The temperature of " << celsius << " in fahrenheit is "; //output celsius
    cout << fixed << setprecision (2) << fahrenheit << endl; //output fahrenheit to 2 decimal places

}


// takes input seconds, converts into hours, minutes, and seconds
void convertSeconds(int thetime){

    int hours;
    int minutes;
    int seconds;
    
    hours = thetime / 3600;
    minutes = (thetime % 3600) / 60;
    seconds = (thetime % 3600) % 60;
    
    cout << thetime << " seconds equals ";
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s) " << endl; //print out answers
    
    return;
}

// given a current population, finds the population after a certain
// number of years, given the birth rate, death rate, and immigration rate
int population(int currentPopulation){
    
    int population; //population is an integer
    population = currentPopulation + 365*24*60*60/8 + 365*24*60*60/27 - 365*24*60*60/12; 365; //calculate population after including birth, death, immigration rates
    
    return population; //return the population
}


int main() {

    celsiusToFahrenheit(100);

    convertSeconds(100);
    
    population(100);
    
    return 0;

}
