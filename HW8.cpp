// not done debugging yet

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

// book class //////////////////////////////////////////////////////////////////
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

// user class //////////////////////////////////////////////////////////////////
class User{
    
private:
    string username;
    int numRatings;
    int size;
    int ratings[200];

public:
    User();
    User(string, int ratings[], int);
    void setUsername(string);
    string getUsername();
    void setNumRatings(int);
    int getNumRatings();
    int getSize();
    bool setRatingAt(int, int);
    int getRatingAt(int);
};

User::User(){
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

bool User::setRatingAt(int index, int value){
    
    if(index <= size && value >= 0 && value <= 5){
        this->ratings[index] = value;
        numRatings++;
        return true;
    }
    else{
        return false;
    }
}

int User::getRatingAt(int index){
    if(index < numRatings){
        return ratings[index];
    }
    else{
        return -1;
    }
}

// library class ///////////////////////////////////////////////////////////////
class Library{
    
private:
    Book Books[200];
    User Users[200];
    int numBooks;
    int numUsers;
    const int sizeBook = 200;
    const int sizeUser = 200;
    
public:
    Library();
    int readBooks(string);
    int readRatings(string);
    void printAllBooks();
    int getCountReadBooks(string);
    double calcAvgRating(string);
    bool addUser(string);
    bool checkOutBook(string, string, int);
    void viewRatings(string);
    void getRecommendations(string);
};

// default constructor
Library::Library(){
    numBooks = 0;
    numUsers = 0;
}

// readBooks ///////////////////////////////////////////////////////////////////
// read books, return num books in database
int Library::readBooks(string booksTxt){
    
    // initialize variables
    ifstream file;
    string line;
    int idxTitle = 0;
    int idxAuthor = 0;
    int idxBook = 0;
    int idxComma = 0;

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
        
        // edge case to stop if numBooks exceeds 200
        if(numBooks < 200){
        
            // store titles in array of Book objects
            Books[numBooks].setTitle(Titles[idxBook]);
        
            // store authors in array of Book objects
            Books[numBooks].setAuthor(Authors[idxBook]);
        
            idxTitle++;
            idxAuthor++;
            idxBook++;
            numBooks++;
        }
    }

    file.close();
    return numBooks;
}


// readRatings /////////////////////////////////////////////////////////////////
// populate User object array, with 1)username 2)numRatings 3)arr of ratings
// return num users in database
int Library::readRatings(string ratingsTxt){
    
    // initialize variables
    ifstream file;
    string line;
    int idxUser = 0;
    int idxRating = 0;
    int idxComma = 0;
    
    string Usernames[200];
    int Ratings[200][50];

    // open ratings.txt
    file.open(ratingsTxt);
    if(file.fail()){
        return -1;
    }
    
    // read ratings.txt
    while(getline(file, line)){
        
        // edge case
        if(numUsers > 199){
            return numUsers;
        }
        
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
                // store ratings in Users objects
                Users[numUsers].setRatingAt(idxRating, Ratings[idxUser][idxRating]);
                
                idxRating++;
            }
        }
        
        // store usernames in Users objects
        Users[numUsers].setUsername(Usernames[idxUser]);
        
        // print users
        cout << Users[numUsers].getUsername() << "...\n";
    
        idxUser++;
        numUsers++;
    }
    
    file.close();
    return numUsers;
}

// Print all books /////////////////////////////////////////////////////////////
void Library::printAllBooks(){
                  
    // if there are no books, return
    if(numBooks == -1 || numBooks == 0){
        cout << "Database has not been fully initialized\n";
        return;
    }
    
    // else print out all books
    cout << "Here is a list of books\n";

    for(int idx = 0; idx < numBooks; idx++){
        cout << Books[idx].getTitle() << " by " << Books[idx].getAuthor() << "\n";
    }
}
    
    

// getCountReadBooks ///////////////////////////////////////////////////////////
// return num books user has read
int Library::getCountReadBooks(string username){
        
    // initialize variables
    int readCount = 0;
    int foundUserIdx = -1;
    string upperUsername;
    string compareUpper;
    string compare;
    
    // if database has not been fully initialized, return
    if(numBooks == -1 || numBooks == 0 || numUsers == -1 || numUsers == 0){
        cout << "Database has not been fully initialized\n";
        return -1;
    }
    
    // convert input username to all uppercase
    for(int i = 0; username[i] != '\0'; i++){
        upperUsername += toupper(username[i]);
    }
    
    // compare each username in User array to input username
    for(int idxUser = 0; idxUser < numUsers; idxUser++){
            
        compare = Users[idxUser].getUsername();
        
        for(int i = 0; compare[i] != '\0'; i++){
            compareUpper += toupper(compare[i]);
        }
            
        // if input username and existing username match, break
        if(compareUpper == upperUsername){
            foundUserIdx = idxUser;
            break;
        }
            
        compareUpper = "";
    }
    
    // if user not found, return
    if(foundUserIdx == -1){
        cout << username << " does not exist in the database\n";
        return -2;
    }

    // read through ratings array at User object array index, w/o counting zeroes
    for(int idxRating = 0; idxRating < Users[foundUserIdx].getNumRatings(); idxRating++){
            
        if(Users[foundUserIdx].getRatingAt(idxRating) != 0){
            readCount++;
        }
    }

    return readCount;
}
    
    

// calcAvgRating ///////////////////////////////////////////////////////////////
double Library::calcAvgRating( string bookTitle ) {
        
    // initialize variables
    int numZeroes = 0;
    int foundBookIdx = -1;
    double sumBookRatings = 0.0;
        
    // if database has not been initialized, return
    if(numBooks == -1 || numBooks == 0 || numUsers == -1 || numUsers == 0){
        cout << "Database has not been fully initialized\n";
        return -1;
    }
        
    // find index of book title
    for(int idxBook = 0; idxBook < 200; idxBook++){
        
        if(Books[idxBook].getTitle() == bookTitle){
            foundBookIdx = idxBook;
            break;
        }
    }
        
    // if book does not exist, return
    if(foundBookIdx == -1){
        cout << bookTitle << " does not exist in the database\n";
        return -2;
    }
        
    // if book exists, add up all its ratings
    for(int idx = 0; idx < numUsers; idx++){
        
        sumBookRatings += Users[idx].getRatingAt(foundBookIdx);
                        
        // count the number of zeroes
        if ( Users[idx].getRatingAt( foundBookIdx ) == 0 ) {
            numZeroes++;
        }
    }
        
    double avgRating = sumBookRatings / (numUsers - numZeroes);
    return avgRating;
}


// add new user ////////////////////////////////////////////////////////////////
bool Library::addUser(string username){
        
    // initialize variables
    int foundUserIdx = -1;
    string upperUsername;
    string compareUpper;
    string compare;
        
    // if database is already full, return
    if(numUsers > 199){
        cout << "Database full\n";
        return false;
    }
    
    // convert input username to all uppercase
    for(int i = 0; username[i] != '\0'; i++){
        upperUsername += toupper(username[i]);
    }
        
    for(int idxUser = 0; idxUser < numUsers; idxUser++){
            
        compare = Users[idxUser].getUsername();
        
        // convert each username in array of User objects to all uppsercase
        for(int i = 0; compare[i] != '\0'; i++){
            compareUpper += toupper(compare[i]);
        }
            
        // if input username and existing username match, break
        if(compareUpper == upperUsername){
            foundUserIdx = idxUser;
            break;
        }

        compareUpper = "";
    }
        
    // if user index has been found, it means user already exists, return false
    if(foundUserIdx != -1){
        cout << username << " already exists in the database\n";
        return false;
    }
        
    // else add user to database and return true
    Users[numUsers].setUsername(username);
    numUsers++;
    return true;
}


// check out book //////////////////////////////////////////////////////////////
bool Library::checkOutBook(string username, string bookTitle, int newRating){
        
    // initialize variables
    int foundUserIdx = -1;
    int foundBookIdx = -1;
        
    // if num books or num users equals zero, database has not been initialized
    if(numBooks == 0 || numUsers == 0){
        cout << "Database has not been fully initialized\n";
        return false;
    }
        
    // find user index
    for(int idxUser = 0; idxUser < numUsers; idxUser++){
        if(Users[idxUser].getUsername() == username){
            foundUserIdx = idxUser;
            break;
        }
    }
    
    // if user does not exist
    if(foundUserIdx == -1){
        cout << username << " does not exist in the database\n";
    }
        
    // find book index
    for(int idxBook = 0; idxBook < numBooks; idxBook++){
        if(Books[idxBook].getTitle() == bookTitle){
            foundBookIdx = idxBook;
            break;
        }
    }
        
    // if book does not exist
    if(foundBookIdx == -1){
        cout << bookTitle << " does not exist in the database\n";
    }
        
    // if new rating not valid
    if(Users[foundUserIdx].setRatingAt(foundUserIdx, newRating) == false){
        cout << newRating << " is not valid\n";
    }
        
    // if book or user or rating are not valid, return false
    if(foundUserIdx == -1 || foundBookIdx == -1
        || Users[foundUserIdx].setRatingAt(foundUserIdx, newRating) == false){
        return false;
    }
        
    // if book exists, user exists, and rating is valid
    // update rating and return true
    Users[foundUserIdx].setRatingAt(foundBookIdx, newRating);
        
    return true;

}
    

// viewRatings /////////////////////////////////////////////////////////////////
// view all books and ratings of input user
void Library::viewRatings(string username){
        
    int foundUserIdx = -1;
    int readCount = 0;
        
    // if num users or num books equals zero
    if(numBooks == 0 || numUsers == 0){
        cout << "Database has not been fully initialized\n";
        return;
    }
        
    // find user index
    for(int idxUser = 0; idxUser < numUsers; idxUser++){
        if(Users[idxUser].getUsername() == username){
            foundUserIdx = idxUser;
            break;
        }
    }
    
    // if user does not exist, return
    if(foundUserIdx == -1){
        cout << username << " does not exist in the database";
        return;
    }
        
    // count books user has read
    for(int idxRating = 0; idxRating < Users[foundUserIdx].getNumRatings(); idxRating++){
        if(Users[foundUserIdx].getRatingAt(idxRating) != 0){
            readCount++;
        }
    }
        
    // if user has rated no books, return
    if(readCount == 0){
        cout << username << " has not rated any books yet\n";
        return;
    }
        
    // for user index in array of User objects
    // print all books and corresponding ratings
    cout << "Here are the books that " << username << " rated\n";
    
    for(int idxRating = 0; idxRating < Users[foundUserIdx].getNumRatings(); idxRating++){
        if(Users[foundUserIdx].getRatingAt(idxRating) != 0){
            cout << "Title : " << Books[idxRating].getTitle() << "\n";
            cout << "Rating : " << Users[foundUserIdx].getRatingAt(idxRating) << "\n";
            cout << "-----\n";
        }
    }
}
    

// getRecommendations //////////////////////////////////////////////////////////
// given input user, prints most similar user's books
void Library::getRecommendations(string username){
    
    // initialize variables
    int foundUserIdx = -1;
    int idxMostSimilarUser = -1;
    int ssd = 0;
    int lowestSSD = 999999;
    int numBooksToRecommend = 0;
        
    // if num users or num books is zero, database has not been initialized
    if(numBooks == 0 || numUsers == 0){
        cout << "Database has not been fully initialized\n\n";
        return;
    }
        
    // find user index
    for(int idxUser = 0; idxUser < numUsers; idxUser++){
        if(Users[idxUser].getUsername() == username){
            foundUserIdx = idxUser;
            break;
        }
    }
    
    // if user does not exist, return
    if(numBooks != 0 && numUsers != 0 && foundUserIdx == -1){
        cout << username << " does not exist in the database\n\n";
        return;
    }
    
    // for each user and book
    for(int idxUser = 0; idxUser < numUsers; idxUser++){

        // idxUser are the users being compared with input user
        // skip the comparison with input user
        if(idxUser != foundUserIdx){
            ssd = 0;
            
            // calculate the ssd
            for(int idxBook = 0; idxBook < numBooks; idxBook++){
                ssd += pow(Users[foundUserIdx].getRatingAt(idxBook)
                - Users[idxUser].getRatingAt(idxBook), 2);
            }
            
            // if ssd is by far the lowest
            // and skip the index of the input user
            // and skip the users who have read zero books
            if(ssd < lowestSSD && getCountReadBooks(Users[idxUser].getUsername()) > 0){
                // record the index of this "most similar user"
                lowestSSD = ssd;
                idxMostSimilarUser = idxUser;
            }
        }
    }

    // recommend books
    for(int idxBook = 0; idxBook < numBooks; idxBook++){
        
        if( (Users[foundUserIdx].getRatingAt(idxBook) == 0
            || Users[ foundUserIdx ].getRatingAt(idxBook) == -1)
            && numBooksToRecommend < 5
            && Users[idxMostSimilarUser].getRatingAt(idxBook) >= 3){
            
            numBooksToRecommend++;
            
            if(numBooksToRecommend == 1){
                cout << "Here are the list of recommendations:\n"; //
            }
            
            cout << Books[idxBook].getTitle() << " by " << Books[idxBook].getAuthor() << "\n";
        }
    }
    
    // if there are no books to be recommended
    if(numBooksToRecommend == 0){
        cout << "There are no recommendations for " << username << " at the present\n\n";
    }
    
    else{
        cout << "\n";
    }
}

// display menu ////////////////////////////////////////////////////////////////
void displayMenu(){
    cout << "Select a numerical option:\n";
    cout << "======Main Menu=====\n";
    cout << "1. Read book file\n";
    cout << "2. Read user file\n";
    cout << "3. Print book list\n";
    cout << "4. Find number of books user rated\n";
    cout << "5. Get average rating\n";
    cout << "6. Make a new account\n";
    cout << "7. Check out book\n";
    cout << "8. View ratings\n";
    cout << "9. Get recommendations\n";
    cout << "10. Quit\n";
}


// main function ///////////////////////////////////////////////////////////////
int main(int argc, char const *argv[]){
    
    // initialize variables
    string choice;
    int size = 200;
    string booksTxt;
    string ratingsTxt;
    string username;
    string bookTitle;
    
    int numBooks = 0;
    int numUsers = 0;
    string newRating = 0;
    double avgRating = 0;
    
    Library myLibrary;
    
    while(choice != "10"){
        
        displayMenu();
        getline(cin, choice);
        
        switch(stoi(choice)){


            // 1. Read book file
            case 1:
            cout << "Enter a book file name:\n";
            getline(cin,booksTxt);
            numBooks = myLibrary.readBooks(booksTxt);
            
            // print num books in library database
            if(numBooks != -1 && numBooks != 0){
                cout << "Total books in the database: " << numBooks << "\n";
            }
            else{
                cout << "No books saved to the database\n"; // c.
            }
            cout << "\n";
            break;
                

            // 2. Read user file
            case 2:
            cout << "Enter a rating file name:\n";
            getline(cin, ratingsTxt);
            numUsers = myLibrary.readRatings( ratingsTxt );
            
            // print num users in library database
            if(numUsers != -1 && numUsers != 0){
                cout << "Total users in the database: " << numUsers << "\n";
            }
            else{
                cout << "No users saved to database\n";
            }
            cout << "\n";
            break;

            // 3. Print book list
            case 3:
            myLibrary.printAllBooks();
            cout << "\n";
            break;
            
            // 4. Find number of books user rated
            case 4:
            cout << "Enter username:\n";
            getline(cin, username);
            myLibrary.getCountReadBooks(username);
            cout << "\n";
            username = "";
            break;
                
            // 5. Get average rating
            case 5:
            cout << "Enter book title:\n";
            getline(cin, bookTitle);
            avgRating = myLibrary.calcAvgRating(bookTitle);

            if(avgRating != -1){
                cout << "The average rating for " << bookTitle;
                cout << " is " << setprecision(3) << avgRating << "\n";
            }
            cout << "\n";
            bookTitle = "";
            break;
            
            // 6. Make a new account
            case 6:
            cout << "Enter a username:\n";
            getline(cin, username);
                
            if(myLibrary.addUser(username) == true){
                cout << "Welcome to the library " << username << "\n";
            }
                
            else{
                cout << username << " could not be added in the database\n";
            }
            username = "";
            break;
                

            // 7. Check out book
            case 7:
            cout << "Enter a username:\n";
            getline(cin, username);
            
            cout << "Enter a book title:\n";
            getline(cin, bookTitle);
            
            cout << "Enter a rating for the book:\n";
            getline(cin, newRating);
            bookTitle = "";
            username = "";
            break;

            // 8. View ratings
            case 8:
            cout << "Enter a username:\n";
            getline(cin, username);
            myLibrary.viewRatings(username);
            username = "";
            break;
                
            // 9. Get recommendations
            case 9:
            cout << "Enter a username:\n";
            getline(cin, username);
            myLibrary.getRecommendations(username);
            username = "";
            break;
                
            // 10. Quit
            case 10:
            cout << "good bye!\n";
            break;
            
            // Invalid input
            default:    
            cout << "invalid input\n\n";
            break;
        }
    }
    return 0;
}
