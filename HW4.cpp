/* Steps to solve this problem
    1. Introduction narration
    2. asks question to user, if they want to go or not
    3. if yes, the human will roll dice, and add points to turn total as needed
    4. if no, the computer will roll dice, and add points to turn total as needed
        the computer will continue rolling until t is 10 or more
        in which case the computer's turn ends
    5. when 100 points or more is reached by one of the players, the game ends
    6. the rules for adding to the turn total are:
        roll a 1 or 6, turn ends, t = 0
        roll a 3, turn ends, t = 15
        roll a 2, 4, 5, value on rolldice adds to t
        at the end of turn, t is added to playerTotal
*/


#include <iostream>
using namespace std;

// generates random number between 1 and 6
int rollDice(){
    int dice = random() % 6 + 1;
    return dice;
}


// human's turn
int human(){
    
    int t = 0;
    char a;
    
    // asks user if they want to use their turn
    cout << "Do you want to roll a dice (Y/N)?: \n";;
    
    while(1){
        cin >> a;
        
        // if user says yes, roll dice
        if(a == 'y'){
            
            int dice = rollDice();
            cout << "You rolled a " << dice << "\n";
            
            // game rules
            if(dice == 1 || dice == 6){
                t = 0;
            }
            else if(dice == 3){
                t = 15;
            }
            else{
                t += dice;
            }
            cout << "Your turn total is " << t << "\n";
            if ( dice == 1 || dice == 6 || dice == 3 ){
                return t;
            }
        }
        
        // if user says no, return
        else if(a == 'n') {
            return t;
        }
        cout << "Do you want to roll a dice (Y/N)?: \n";;
    }
}




// computer's turn
int computer(){
    
    // num of turns computer has rolled
    int t = 0;
    
    while(1){
        
        // roll dice
        int dice = rollDice();
        cout << "Computer rolled a " << dice << "\n";
        
        // game rules
        if(dice == 1 || dice == 6){
            t = 0;
        }
        else if(dice == 3){
            t = 15;
        }
        else{
            t += dice;
        }
        cout << "Computer turn total is " << t << "\n";
        
        // if num of turns exceeds max, return
        if(t >= 10 && (dice != 1 || dice != 6 || dice != 3)){
            return t;
        }
        else if(dice == 1 || dice == 6 || dice == 3){
            return t;
        }
    }
}


// function to start the game
// is called in the main function
// this calls the human() and computer() functions
void game(){
    
    int humScore = 0;
    int compScore = 0;
    
    cout << "Welcome to Jeopardy Dice!\n\n";
    cout << "It is now human's turn\n\n";
    
    while(1){
    
        // human's turn
        humScore += human();
        cout << "computer: " << compScore << "\n";
        cout << "human: " << humScore << "\n";
    
        // if human wins, end game and return
        if (humScore >= 100){
            cout << "Congratulations! human won this round of jeopardy dice!\n";
            return;
        }
        
        // if computer wins, end game and return
        if (compScore >= 100){
            cout << "Congratulations! computer won this round of jeopardy dice!\n";
            return;
        }
        
        // computer's turn
        cout << "\nIt is now computer's turn\n\n";
        compScore += computer();
        cout << "computer: " << compScore << "\n";
        cout << "human: " << humScore << "\n";
        
        // if human wins, end game and return
        if (humScore >= 100){
            cout << "Congratulations! human won this round of jeopardy dice!\n";
            return;
        }
        
        // if computer wins, end game and return
        if (compScore >= 100){
            cout << "Congratulations! computer won this round of jeopardy dice!\n";
            return;
        }
        
        // human's turn
        cout << "\nIt is now human's turn\n\n";
    }
    
}


int main(){
    game();
    return 0;
}
