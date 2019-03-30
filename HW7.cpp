#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
using namespace std;

// Book class //////////////////////////////////////////////////////////////////
class Book{
    
private:
    string title;
    string author;

public:
    Book();
    Book(string, string);
    void setTitle(string);
    string getTitle();
    void setAuthor(string);
    string getAuthor();
};

Book::Book(){
    title = "";
    author = "";
}

Book::Book(string title, string author){
    this->title = title;
    this->author = author;
}

void Book::setTitle(string title){
    this->title = title;
}

string Book::getTitle(){
    return title;
}

void Book::setAuthor(string author){
    this->author = author;
}

string Book::getAuthor(){
    return author;
}

// User class //////////////////////////////////////////////////////////////////
class User{
    
private:
    string username;
    int numRatings = 0;
    int size = 200;
    int ratings[200];

public:
    User();
    User(string, int ratings[], int);
    void setUsername(string);
    string getUsername();
    void setNumRatings(int);
    int getNumRatings();
    int getSize();
    int getRatingAt(int);
    bool setRatingAt(int, int);
};

User::User() {
    username = "";
    numRatings = 0;
    size = 200;

    for(int idx = 0; idx < 200; idx++){
        ratings[idx] = -1;
    }
}

User::User(string username, int ratings[], int numRatings){
    this->username = username;
    this->numRatings = numRatings;
    
    for(int idx = 0; idx < numRatings; idx++){
        this->ratings[idx] = ratings[idx];
    }
}

void User::setUsername(string username){
    this->username = username;
}
        
string User::getUsername(){
    return username;
}


void User::setNumRatings(int numRatings){
    this->numRatings = numRatings;
}


int User::getNumRatings(){
    return numRatings;
}


int User::getSize(){
    return size;
}

int User::getRatingAt(int index){
    if(index < numRatings){
        return ratings[index];
    }
    else {
        return -1;
    }
}

bool User::setRatingAt(int index, int value){
                            
    if(index <= size && value >= 0 && value <= 5){
        ratings[index] = value;
        return true;
    }
    else{
        return false;
    }
}

// readBooks ///////////////////////////////////////////////////////////////////
// place titles and authors in arrays
// return total num of books in system
int readBooks(string booksTxt, Book Books[], int initNumBooks, int size){
    
    // initialize variables
    ifstream file;
    string line;
    
    int idxTitle = 0;
    int idxAuthor = 0;
    int idxComma = 0;
    int totalNumBooks = 0;
    
    // initialize titles and authors array
    string Titles[200];
    string Authors[200];
    
    // open books.txt
    file.open(booksTxt);
    if(file.fail()){
        return -1;
    }
    
    // read books.txt
    while(getline(file, line)){
        
        // read authors
        for(int ch = 0; line[ch] != ','; ch++){
            Authors[idxAuthor] += line[ch];
            idxComma = ch + 2;
        }
        
        // read titles
        for(int ch = idxComma; line[ch] != '\0'; ch++){
            Titles[idxTitle] += line[ch];
        }
        
        idxTitle++;
        idxAuthor++;
        totalNumBooks++;
    }
    
    // place titles and authors in Book objects
    for(int idx = 0; idx < totalNumBooks; idx++){
        Books[idx].setTitle(Titles[idx]);
        Books[idx].setAuthor(Authors[idx]);
    }

    file.close();
    return totalNumBooks + initNumBooks;
}











// readRatings /////////////////////////////////////////////////////////////////
// place usernames and ratings in arrays
// return total num of users in database
int readRatings(string ratingsTxt, User Users[], int initNumUsers, int size){

    // initialize variables
    ifstream file;
    string line;
    int idxUser = 0;
    int idxRating = 0;
    int idxComma = 0;
    int totalNumUsers = 0;
    
    // initialize usernames and ratings array
    string Usernames[200];
    int Ratings[200][50];
    
    // open ratings.txt
    file.open(ratingsTxt);
    if(file.fail()){
        return -1;
    }
    
    // read ratings.txt
    while(getline(file, line)){
        
        idxRating = 0;
        
        // read usernames
        for(int ch = 0; line[ch] != ','; ch++){
            Usernames[idxUser] += line[ch];
            idxComma = ch + 2;
        }
     
        // read ratings
        for(int ch = idxComma; line[ch] != '\0'; ch++){

            if(line[ch] != ' '){
                Ratings[idxUser][idxRating] = stoi(string(1, line[ch]));
                idxRating++;
            }
        }
        
        idxUser++;
        totalNumUsers++;
    }
    
    // store usernames and ratings in Users objects
    for(int idx = 0; idx < totalNumUsers; idx++){
        Users[idx].setUsername(Usernames[idx]);
    }
    
    // print all users
    for(int i = 0; i < totalNumUsers; i++){
        cout << Usernames[i] << "...\n";
    }
    
    file.close();
    return totalNumUsers + initNumUsers;
}



// print all books /////////////////////////////////////////////////////////////
void printAllBooks(Book Books[], int totalNumBooks){

    // if database is empty, return   
    if(totalNumBooks == -1 || totalNumBooks == 0){
        cout << "No books are stored\n";
        return;
    }
    
    // print all books
    cout << "Here is a list of books\n";
    
    for(int idx = 0; idx < totalNumBooks; idx++){
        cout << Books[idx].getTitle() << " by " << Books[idx].getAuthor() << "\n";
    }
}





// display menu
void displayMenu () {
    cout << "Select a numerical option:\n";
    cout << "======Main Menu=====\n";
    cout << "1. Read book file\n";
    cout << "2. Read user file\n";
    cout << "3. Print book list\n";
    cout << "4. Find number of books user rated\n";
    cout << "5. Get average rating\n";
    cout << "6. Quit\n";
}

int main( int argc, char const*argv[] ) {
    
    // initialize variables
    string choice;
    int size = 200;
    string booksTxt;
    string ratingsTxt;
    int initNumBooks = 0;
    int totalNumBooks = 0;
    int initNumUsers = 0;
    int totalNumUsers = 0;
    
    // initialize arrays of Book and User objects
    Book Books[200];
    User Users[200];
    
    while(choice != "6"){

        displayMenu();
        getline(cin, choice);
    
        switch(stoi(choice)){
            
            // 1. Read book file
            case 1:
            cout << "Enter a book file name:\n";
            getline(cin,booksTxt); 
            totalNumBooks = readBooks(booksTxt, Books, initNumBooks, size);
            
            // print total num books in database
            if(totalNumBooks != -1 && totalNumBooks != 0){
                cout << "Total books in the database: " << totalNumBooks << "\n";
            }
            else{
                cout << "No books saved to the database\n";
            }
            cout << "\n";
            break;
            
            // 2. Read user file
            case 2:
            cout << "Enter a rating file name:\n";
            getline(cin, ratingsTxt);
            totalNumUsers = readRatings(ratingsTxt, Users, initNumUsers, size);
                                
            // print total num users in database
            if(totalNumUsers != -1 && totalNumUsers != 0){
                cout << "Total users in the database: " << totalNumUsers << "\n";
            }
            else{
                cout << "No users saved to database\n";
            }
            cout << "\n";
            break;
            
            // 3. Print book list
            case 3:
            printAllBooks(Books, totalNumBooks );
            cout << "\n";
            break;
            
            // 6. Quit
            case 6:
            cout << "good bye!\n";
            break;

            default:    
            cout << "invalid input\n\n";
        }
    }
    return 0;
}
