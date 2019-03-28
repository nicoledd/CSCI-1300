#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// class dice //////////////////////////////////////////////////////////////////
class Dice{

private:
      // face value on dice
      int faceValue;

public:
      // default constructor
      Dice();
      // roll dice
      void roll();
      // get value rolled
      int getFaceValue();
};

// Dice default constructor
Dice::Dice() {
      // iniitalize dice value to 0
      this->faceValue = 0;
}

// roll dice
void Dice::roll() {
      // generate random number, 1-6, for dice
      this->faceValue = rand() % 6 + 1;
}

// return dice facevalue
int Dice::getFaceValue() {
      return this->faceValue;
}

// class player ////////////////////////////////////////////////////////////////
class Player{

private:
      // array of Dice
      Dice myDice[5];
      // num of dice each player has
      int numDice;

public:
      // default constructor
      Player(int);
      // roll all the dice the player has
      void playerRoll();
      // set num dice
      void setNumDice(int);
      // get value of dice at input index of myDice[] array
      int getDiceValueAtIndex(int);

};

// creates many instants of Dice for player
Player::Player(int numDice){
      // this for-loop instantiates Dice and places them into myDice[] array
      for(int i = 0; i < numDice; i++){
            Dice dice;
            this->myDice[i] = dice;
      }
}

// initializes number of dice player has
void Player::setNumDice(int numDice){
      this->numDice = numDice;
}

// player rolls all the dice they own in their myDice array
void Player::playerRoll(){
      for(int i = 0; i < numDice; i++){
            myDice[i].roll();
      }
}

// get dice value at input index
int Player::getDiceValueAtIndex(int idx){
      return myDice[idx].getFaceValue();
}

// creates instance of a player who proceeds to roll all of his dice
int main(){

      // creating Player with 5 dices
      Player player(5);
      
      // player rolls his dice
      player.playerRoll();
      
      for (int i = 0; i < 5; i++){
            // print out values of dice that he got
            cout << player.getDiceValueAtIndex(i) << " ";
      }
      cout << "\n";

      return 0;
}
