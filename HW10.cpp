// all riddles are from Brilliant.org

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <chrono>
using namespace std;


// probability
int generateRandNum(int minValue, int maxValue){
    srand ( (unsigned) time (0) );
    int randNum = rand() % ( maxValue - minValue + 1 ) + minValue;
    return randNum;
}

// class store
class Store{
private:
    int foodPrice;
    int foodAmount;
    int healthPrice;
    int healthAmount;
    int moneyAmount;
    int daysWorking;
public:
    Store(){
        foodPrice=10;
        foodAmount=50;
        healthPrice=10;
        healthAmount=50;
        moneyAmount=100;
        daysWorking=5;
    }
    void setFoodPrice( int foodPrice ){
        this-> foodPrice = foodPrice;
    }
    int getFoodPrice(){
        return foodPrice;
    }
    void setHealthPrice( int healthPrice ){
        this-> healthPrice;
    }
    int getHealthPrice(){
        return healthPrice;
    }
    void setFoodAmount( int foodAmount ){
        this-> foodAmount;
    }
    int getFoodAmount(){
        return foodAmount;
    }
    void setHealthAmount( int healthAmount ){
        this-> healthAmount;
    }
    int getHealthAmount(){
        return healthAmount;
    }
    void setMoneyAmount( int moneyAmount ){
        this-> moneyAmount;
    }
    int getMoneyAmount(){
        return moneyAmount;
    }
    void setDaysWorking( int daysWorking ){
        this-> daysWorking;
    }
    int getDaysWorking(){
        return daysWorking;
    }
};


// class riddle
class Riddle{
private:
    int minDist;
    int maxDist;
    int minProb;
    int maxProb;
    int answer;
    int passed;
    string riddleText;
    bool riddleAppears;
public:
    Riddle(){
        minDist=0;
        maxDist=0;
        minProb=0;
        maxProb=0;
        answer=0;
        passed=false;
        riddleText="";
        riddleAppears=false;
    }
    void setMinDist(int minDist){
        this->minDist=minDist;
    }
    int getMinDist(){
        return minDist;
    }
    void setMaxDist(int maxDist){
        this->maxDist=maxDist;
    }
    int getMaxDist(){
        return maxDist;
    }
    void setMinProb(int minProb){
        this->minProb=minProb;
    }
    int getMinProb(){
        return minProb;
    }
    void setMaxProb(int maxProb){
        this->maxProb=maxProb;
    }
    int getMaxProb(){
        return maxProb;
    }
    void setAnswer(int answer){
        this->answer=answer;
    }
    int getAnswer(){
        return answer;
    }
    void setRiddlePassed(bool passed){
        this->passed=passed;
    }
    bool riddlePassed(){
        return passed;
    }
    void setRiddleText(string riddleText){
        this->riddleText=riddleText;
    }
    string displayRiddleText(){
        return riddleText;
    }
    void setRiddleAppears(int minProb, int maxProb){
        int chance = generateRandNum(1,100);
        if(1<=minProb && chance<=maxProb)
            riddleAppears=true;
        else{
            riddleAppears=false;
        }
    }
    bool getRiddleAppears(){
        return riddleAppears;
    }
};

// class journey
class Journey{
private:
    int distTravelled;
    int moneyLeft;
    int foodLeft;
    int daysTravelled;
    int distLeft;
    Riddle riddles[8];
    string riddleOneText;
    string riddleTwoText;
    string riddleThreeText;
    string riddleFourText;
    string riddleFiveText;
    string riddleSixText;
    string riddleSevenText;
    string riddleEightText;
    string godHumanDemon;
public:
    Journey(){
        moneyLeft=2000;
        foodLeft=1000;
        daysTravelled=0;
        distTravelled=0;
        distLeft=2000;
        godHumanDemon="1. A God\n2. A human\n3. A demon\n";
        riddleOneText="You meet three villagers who say:\nMei:\"Yu is a human\"\nYu:\"Lan is a human\"\nLan:\"Mei is a human\"\nExactly one of them is a demon.\nHow many are Gods?\n";
        riddleTwoText="You meet a villager who says:\n\"I am a demon\"\nWhat is the villager?\n"+godHumanDemon;
        riddleThreeText="You find three treasure chests.\nThey are all incorrectly labelled.\nEach label describes the contents of\na different chest. You pick a single\ncoin to determine which chest has\nthe 100 gold coins. Which do you pick?\n-------   -------    -------\n|  1  |   |  2  |    |  3  |\n-------   -------    -------\n100-gold  50-silver  100 silver\n          50-gold              \n";
        riddleFourText="You meet a villager. You ask:\n\"If I asked if you were a God,\nwhat would you say?\"\nThe villager replies: \"No.\"\nWhat is the villager?\n"+godHumanDemon;
        riddleFiveText="You meet two villagers, Yan and Su.\nYou ask Yan:\"Is Su a demon?\"\nYan whispers his answer to Su.\nYou ask Su: \"Did Yan whisper 'yes'?\"\nSu says: \"No.\"\nWhat is Yan?\n"+godHumanDemon;
        riddleSixText="You find three stone tablets.\nA phrase is carved on each tablet.\n  _______    _______    _______ \n/|  one  | /|  two  | /| three |\n|| tablet| ||tablets| ||tablets|\n||   is  | ||  are  | ||  are  |\n|| false | || false | || false |\n||_______| ||_______| ||_______|\n|/_______/ |/_______/ |/_______/ \n                                \nHow many tablets are false?\n";
        riddleSevenText="You meet two villagers, Lian and Fa\nLian:\"We are both humans.\"\nFa:\"I am a demon.\"\nWhat is Fa?\n"+godHumanDemon;
        riddleEightText="You meet a villager. You ask:\n\"If I asked if you were a human,\nwhat would you say?\"\nThe villager replies: \"Yes.\"\nWhat is the villager?\n"+godHumanDemon;
    }
    void setDistTravelled( int distTravelled ){
        this-> distTravelled = distTravelled;
    }
    int getDistTravelled(){
        return distTravelled;
    }
    void setMoneyLeft( int moneyLeft ){
        this-> moneyLeft = moneyLeft;
    }
    int getMoneyLeft(){
        return moneyLeft;
    }
    void setFoodLeft( int foodLeft ){
        this-> foodLeft = foodLeft;
    }
    int getFoodLeft(){
        return foodLeft;
    }
    void setDaysTravelled( int daysTravelled ){
        this-> daysTravelled = daysTravelled;
    }
    int getDaysTravelled(){
        return daysTravelled;
    }
    void setDistLeft( int distLeft ){
        this-> distLeft = distLeft;
    }
    int getDistLeft(){
        return distLeft;
    }
    void initRiddleMinDist(){
        int i=0;
        while(i<8){
            riddles[i].setMinDist(i*200);
            i++;
        }
    }
    void initRiddleMaxDist(){
        int i=0;
        while(i<8){
            riddles[i].setMaxDist( (i+1) *200 );
            i++;
        }
    }
    void initRiddleProb(){
        for(int i=0; i<8; i++){
            riddles[i].setMinProb(1);
        }
        for(int i=0; i<8; i++){
            riddles[i].setMaxProb( 100 - (i*5) );
        }
        for(int i=0; i<8; i++){
            riddles[i].setRiddleAppears(riddles[i].getMinProb(),riddles[i].getMaxProb());
        }
    }
    void initRiddleAnswers(){
        riddles[0].setAnswer(1);
        riddles[1].setAnswer(2);
        riddles[2].setAnswer(2);
        riddles[3].setAnswer(3);
        riddles[4].setAnswer(1);
        riddles[5].setAnswer(2);
        riddles[6].setAnswer(2);
        riddles[7].setAnswer(2);
    }
    void initRiddleText(){
        riddles[0].setRiddleText(riddleOneText);
        riddles[1].setRiddleText(riddleTwoText);
        riddles[2].setRiddleText(riddleThreeText);
        riddles[3].setRiddleText(riddleFourText);
        riddles[4].setRiddleText(riddleFiveText);
        riddles[5].setRiddleText(riddleSixText);
        riddles[6].setRiddleText(riddleSevenText);
        riddles[7].setRiddleText(riddleEightText);
    }
    int getRiddleMinDist(int riddleNum){
        return riddles[riddleNum-1].getMinDist();
    }
    int getRiddleMaxDist(int riddleNum){
        return riddles[riddleNum-1].getMaxDist();
    }
    int getRiddleAnswer(int riddleNum){
        return riddles[riddleNum-1].getAnswer();
    }
    string displayRiddle(int riddleNum){
        return riddles[riddleNum-1].displayRiddleText();
    }
    bool riddleAppears(int riddleNum){
        return riddles[riddleNum-1].getRiddleAppears();
    }
    bool riddlePassed(int riddleNum){
        return riddles[riddleNum-1].riddlePassed();
    }
    void riddleHasBeenPassed(int riddleNum){
        riddles[riddleNum-1].setRiddlePassed(true);
    }
};


// class protagonist
class Protagonist{
private:
    string name;
    int healthLeft;
    int distPerDay;
    int foodPerDay;
    int minusHealthPerDay;
    int applesPicked;
    int plumsPicked;
    int peachesPicked;
public:
    Protagonist(){
        healthLeft=500;
        distPerDay=20;
        foodPerDay=10;
        minusHealthPerDay=10;
        applesPicked=10;
        plumsPicked=20;
        peachesPicked=30;
    }
    void setHealthLeft( int healthLeft ){
        this-> healthLeft = healthLeft;
    }
    int getHealthLeft(){
        return healthLeft;
    }
    void setMinusHealthPerDay( int minusHealthPerDay ){
        this-> minusHealthPerDay = minusHealthPerDay;
    }
    int getMinusHealthPerDay(){
        return minusHealthPerDay;
    }
    void setDistPerDay( int distPerDay ){
        this-> distPerDay = distPerDay;
    }
    int getDistPerDay(){
        return distPerDay;
    }
    void setFoodPerDay( int foodPerDay ){
        this-> foodPerDay = foodPerDay;
    }
    int getFoodPerDay(){
        return foodPerDay;
    }
    void setApplesPicked( int applesPicked ){
        this-> applesPicked = applesPicked;
    }
    int getApplesPicked(){
        return applesPicked;
    }
    void setPlumsPicked( int plumsPicked ){
        this-> plumsPicked = plumsPicked;
    }
    int getPlumsPicked(){
        return plumsPicked;
    }
    void setPeachesPicked( int peachesPicked ){
        this-> peachesPicked = peachesPicked;
    }
    int getPeachesPicked(){
        return peachesPicked;
    }
};


// class god
class God{
private:
    int healthGiven;
    int foodGiven;
    int moneyGiven;
public:
    God(){
        healthGiven=50;
        foodGiven=50;
        moneyGiven=50;
    }
    void setHealthGiven( int healthGiven ){
        this-> healthGiven = healthGiven;
    }
    int getHealthGiven(){
        return healthGiven;
    }
    void setFoodGiven( int foodGiven ){
        this-> foodGiven = foodGiven;
    }
    int getFoodGiven(){
        return foodGiven;
    }
    void setMoneyGiven( int moneyGiven ){
        this-> moneyGiven = moneyGiven;
    }
    int getMoneyGiven(){
        return moneyGiven;
    }
};


// class demon
class Demon{
private:
    int damageToHealth;
    int damageToMoney;
    int damageToFood;
public:
    Demon(){
        damageToHealth=50;
        damageToMoney=50;
        damageToFood=10;
    }
    void setDamageToHealth( int damageToHealth ){
        this-> damageToHealth = damageToHealth;
    }
    int getDamageToHealth(){
        return damageToHealth;
    }
    void setDamageToMoney( int damageToMoney ){
        this-> damageToMoney=damageToMoney;
    }
    int getDamageToMoney(){
        return damageToMoney;
    }
    void setDamageToFood( int damageToFood ){
        this-> damageToFood = damageToFood;
    }
    int getDamageToFood(){
        return damageToFood;
    }
};


// generic menu
void backgroundInfo(){
    string line;
    ifstream myfile ("bginfo.txt");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    cout << "\n\n";
}
void dispMenu(){
    cout << "1. Rest\n";
    cout << "2. Go To Store\n";
    cout << "3. Collect Food\n";
    cout << "4. Pray to Buddha\n";
    cout << "5. Travel\n";
}
void dispStoreMenu(){
    cout << "You have reached a store!\n";
    cout << "1. Buy 10 peaches\n";
    cout << "2. Buy 10 health\n";
    cout << "3. Work 3 days for 500 coins\n";
}
void invalidInput(){
    cout << "Invalid input. Please try again.\n\n";
}
int daysSpentResting(){
    int days=generateRandNum(1,3);
    return days;
}
int foodConsumed(Protagonist protag, int tempDays){
    int food = protag.getFoodPerDay() * tempDays;
    return food;
}
int daysSpentTravelling(){
    int days=generateRandNum(3,5);
}
int distConsumed(Protagonist protag, int tempDays){
    int dist = protag.getDistPerDay() * tempDays;
    return dist;
}
int healthConsumed(Protagonist protag, int tempDays){
    int health = protag.getMinusHealthPerDay() * tempDays;
    return health;
}

// riddles stuff
int foodStolen(){
    int food=generateRandNum(50,100);
    return food;
}
int healthDamage(){
    int health=generateRandNum(50,100);
    return health;
}
int moneyStolen(){
    int money=generateRandNum(50,100);
    return money;
}
void youAreRight(){
    cout << "You are correct! You escape the demons unscathed\n";
}
void youAreWrong(){
    cout << "Incorrect. A demon will damage your stats!\n";
}

// display stats
void dispDistTravelled(int distTravelled){
    cout << "Distance Travelled: " << distTravelled << "\n";
}
void dispFoodLeft(int foodLeft){
    cout << "Food Left: " << foodLeft << "\n";
}
void dispMoneyLeft(int moneyLeft){
    cout << "Money Left: " << moneyLeft << "\n";
}
void dispHealthLeft(int healthLeft){
    cout << "Health Left: " << healthLeft << "\n";
}
void dispDaysTravelled(int daysTravelled){
    cout << "Day " << daysTravelled << "\n";
}
void dispDistLeft(int distLeft){
    cout << "Distance Left: " << distLeft << "\n";
}


// collect food
void dispFoodMenu(){
    cout << "1. Go to apple forest\n";
    cout << "2. Go to plum forest\n";
    cout << "3. Go to peach forest\n";
}
bool appleSuccess(){
    int chance = generateRandNum(1,100);
    if( 1<=chance && chance<=50 )
        return true;
    return false;
}
bool plumSuccess(){
    int chance = generateRandNum(1,100);
    if( 1<=chance && chance<=30 )
        return true;
    return false;
}
bool peachSuccess(){
    int chance = generateRandNum(1,100);
    if( 1<=chance && chance<=10 )
        return true;
    return false;
}


// pray to buddha
void dispPrayMenu(){
    cout << "1. Pray for health\n";
    cout << "2. Pray for food\n";
    cout << "3. Pray for money\n";
}
bool prayHealth(){
    int chance = generateRandNum(1,100);
    if( 1<=chance && chance<=50 )
        return true;
    return false;
}
bool prayFood(){
    int chance = generateRandNum(1,100);
    if( 1<=chance && chance<=30 )
        return true;
    return false;
}
bool prayMoney(){
    int chance = generateRandNum(1,100);
    if( 1<=chance && chance<=10 )
        return true;
    return false;
}


// warnings
void foodLow(){
    cout << "Warning: Food is low!\n";
}
void healthLow(){
    cout << "Warning: Health is low!\n";
}
void moneyLow(){
    cout << "Warning: Money is low!\n";
}

// ways of death
void noFood(){
    cout << "You ran out of food and starved to death!\n";
}
void noHealth(){
    cout << "You ran out of health and died of smallpox!\n";
}
void winGame(){
    cout << "You've reached India and have been granted immortality!\n";
}

// main function
int main() {
    
    Journey journey;
    journey.initRiddleMaxDist();
    journey.initRiddleMinDist();
    journey.initRiddleAnswers();
    journey.initRiddleText();
    journey.initRiddleProb();
    Protagonist protag;
    Demon demon;
    God Buddha;
    Store store;
    bool gameOver=false;
    int choice=0;
    int choiceFood=0;
    int choicePray=0;
    int choiceStore=0;
    int choiceRiddle=0;
    int tempDays=0;
    backgroundInfo();
    
    while( gameOver==false ){
        
        
        // game over
        if(journey.getFoodLeft()<=0){
            noFood();
            gameOver=true;
            break;
        }
        if(protag.getHealthLeft()<=0){
            noHealth();
            gameOver=true;
            break;
        }
        if(journey.getDistLeft()<=0){
            winGame();
            gameOver=true;
            break;
        }
        
        // normal menu
        dispMenu();
        dispDaysTravelled(journey.getDaysTravelled());
        dispDistTravelled(journey.getDistTravelled());
        dispDistLeft(journey.getDistLeft());
        dispFoodLeft(journey.getFoodLeft());
        dispHealthLeft(protag.getHealthLeft());
        dispMoneyLeft(journey.getMoneyLeft());
        // warnings
        if(journey.getFoodLeft()<=100){
            foodLow();
        }
        if(protag.getHealthLeft()<=100){
            healthLow();
        }
        if(journey.getMoneyLeft()<=100){
            moneyLow();
        }
        
        // rest
        cin >> choice;
        if(!cin.good()){ cin.clear(); cin.ignore(100, '\n'); invalidInput(); continue;
        }
        if(choice==1){
            tempDays = daysSpentResting();
            journey.setDaysTravelled(journey.getDaysTravelled()+tempDays);
            journey.setFoodLeft(journey.getFoodLeft() - foodConsumed(protag,tempDays));
            tempDays=0;
        }
        
        // go to store
        else if(choice==2){
            dispStoreMenu();
            cin >> choice;
            if(!cin.good()){ cin.clear(); cin.ignore(100, '\n'); invalidInput(); continue;
            }
            if(choice==1){
                journey.setFoodLeft(journey.getFoodLeft() + store.getFoodAmount());
                journey.setMoneyLeft(journey.getMoneyLeft() - store.getFoodPrice());
            }
            else if(choice==2){
                protag.setHealthLeft(protag.getHealthLeft() + store.getHealthAmount());
                journey.setMoneyLeft(journey.getMoneyLeft() - store.getHealthPrice());
            }
            else if(choice==3){
                journey.setMoneyLeft(journey.getMoneyLeft() + store.getMoneyAmount());
                journey.setDaysTravelled(journey.getDaysTravelled() + store.getDaysWorking());
            }
            else invalidInput();
            choiceStore=0;
        }
        
        // collect food
        else if(choice==3){
            dispFoodMenu();
            cin >> choiceFood;
            if(!cin.good()){
                cin.clear(); cin.ignore(100, '\n'); invalidInput(); continue;
            }
            if(choiceFood==1)
                if(appleSuccess()==true)
                    journey.setFoodLeft(journey.getFoodLeft() + protag.getApplesPicked());
                else
                    cout << "You didn't find food\n";
            else if(choiceFood==2)
                if(plumSuccess()==true)
                    journey.setFoodLeft(journey.getFoodLeft() + protag.getPlumsPicked());
                else
                    cout << "You didn't find food\n";
            else if(choiceFood==3)
                if(peachSuccess()==true)
                    journey.setFoodLeft(journey.getFoodLeft() + protag.getPeachesPicked());
                else
                    cout << "You didn't find food\n";
            else invalidInput();
            choiceFood=0;
        }
        
        // pray to Buddha
        else if(choice==4){
            dispPrayMenu();
            cin >> choicePray;
            if(!cin.good()){
                cin.clear(); cin.ignore(100, '\n'); invalidInput(); continue;
            }
            if(choicePray==1)
                if(prayHealth()==true)
                    protag.setHealthLeft(protag.getHealthLeft()+Buddha.getHealthGiven());
                else
                    cout << "Buddha ignored you\n";
            else if(choicePray==2)
                if(prayFood()==true)
                    journey.setFoodLeft(journey.getFoodLeft()+Buddha.getFoodGiven());
                else
                    cout << "Buddha ignored you\n";
            else if(choicePray==3)
                if(prayMoney()==true)
                    journey.setMoneyLeft(journey.getMoneyLeft()+Buddha.getMoneyGiven());
                else
                    cout << "Buddha ignored you\n";
            else invalidInput();
            choicePray=0;
        }
        
        // travel
        else if(choice==5){
            tempDays = daysSpentTravelling();
            journey.setDaysTravelled(journey.getDaysTravelled() + tempDays);
            journey.setFoodLeft(journey.getFoodLeft() - foodConsumed(protag,tempDays));
            journey.setDistTravelled(journey.getDistTravelled() + distConsumed(protag, tempDays) );
            journey.setDistLeft(journey.getDistLeft() - distConsumed(protag, tempDays));
            protag.setHealthLeft(protag.getHealthLeft() - healthConsumed(protag, tempDays));
            tempDays=0;
        }
        else invalidInput();
        cout << "---------------------------------\n";

        // riddles
        for(int i=1; i<=8; i++){
            while(journey.getRiddleMinDist(i)<=journey.getDistTravelled() &&
                journey.getDistTravelled()<journey.getRiddleMaxDist(i) && journey.riddlePassed(i)==false){
                if(journey.riddleAppears(i)==true){
                    cout << journey.displayRiddle(i);
                    journey.riddleHasBeenPassed(i);
                    cin >> choiceRiddle;
                    if(!cin.good()){
                        cin.clear(); cin.ignore(100, '\n'); invalidInput(); continue;
                    }
                    if(choiceRiddle==journey.getRiddleAnswer(i)){
                        youAreRight();
                    }
                    else{
                        youAreWrong();
                        journey.setFoodLeft(journey.getFoodLeft() - foodStolen());
                        protag.setHealthLeft(protag.getHealthLeft() - healthDamage());
                        journey.setMoneyLeft(journey.getMoneyLeft() - moneyStolen());
                    }
                }
            }
            choiceRiddle=0;
        }
        cout << "\n";
    }
    
    return 0;
    
}
