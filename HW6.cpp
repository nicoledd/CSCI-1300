#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
using namespace std;


// readBooks ///////////////////////////////////////////////////////////////////
// place titles and authors in arrays
// return total num of books in system
int readBooks(string booksTxt, string arrTitles[], string arrAuthors[], 
            int initNumBooks, int maxSize){
    
    // initialize variables
    ifstream file;
    string line;
    int idxTitle = 0;
    int idxAuthor = 0;
    int idxComma = 0;
    int totalNumBooks = 0;
    
    // open books.txt
    file.open(booksTxt);
    if( file.fail() ){
        return -1;
    }
    
    // read books.txt
    while( getline(file, line) ){

        // read authors
        for(int idxCh = 0; line[idxCh] != ','; idxCh++){
            arrAuthors[idxAuthor] += line[idxCh];
            idxComma = idxCh+2;
        }
        
        // read titles
        for(int idxCh = idxComma; line[idxCh] != '\0'; idxCh++){
            arrTitles[idxTitle] += line[idxCh];
        }

        idxTitle++;
        idxAuthor++;
        totalNumBooks++;
    }
    
    return totalNumBooks + initNumBooks;

}


// readRatings /////////////////////////////////////////////////////////////////
// place usernames and ratings in arrays
// return total num of users in database
int readRatings(string ratingsTxt, string arrUsernames[], int arrRatings[][50],
                int initNumUsers, int rowLimit, int columnLimit){
                    
    // initialize variables
    ifstream file;
    string line;
    int idxUser = 0;
    int idxRating = 0;
    int idxComma = 0;
    int totalNumUsers = 0;
    
    // open ratings.txt
    file.open(ratingsTxt);
    if(file.fail()){
        return -1;
    }
    
    while( getline(file, line) ){

        idxRating = 0;
        
        // read usernames
        for(int idxCh = 0; line[idxCh] != ','; idxCh++){
            arrUsernames[idxUser] += line[idxCh];
            idxComma = idxCh+2;
        }
     
        // read ratings
        for(int idxCh = idxComma; line[idxCh] != '\0'; idxCh++){
            if(line[idxCh] != ' '){
                arrRatings[idxUser][idxRating] = stoi( string(1,line[idxCh]));
                idxRating++;
            }
        }
        idxUser++;
        totalNumUsers++;
    }
    
    // print all usernames
    for(int i = 0; i < totalNumUsers; i++){
        cout << arrUsernames[i] << "...\n";
    }
    
    return totalNumUsers + initNumUsers;
}



// print all books /////////////////////////////////////////////////////////////
void printAllBooks(string arrTitles[], string arrAuthors[], int totalNumBooks){
    
    // if no books are stored, print empty
    if(totalNumBooks == -1 || totalNumBooks == 0){
        cout << "No books are stored\n";
    }
    
    // else print all books
    else {
        cout << "Here is a list of books\n";
        
        for(int i = 0; i < totalNumBooks; i++){
            cout << arrTitles[i] << " by " << arrAuthors[i] << "\n";
        }
    }
}




// getUserReadCount ////////////////////////////////////////////////////////////
// given username, return num books read by that user
int getUserReadCount(string username, string arrUsernames[], int arrRatings[][50],              // int arrRatings[useridx][ratings]
        int totalNumUsers, int totalNumBooks_accounted){
    
    int foundUserIdx = -1;
    
    // books read by user
    int curBooksRead = 0;
    
    // find user index
    for(int idxUser = 0; idxUser < totalNumUsers; idxUser++){
        if(arrUsernames[idxUser] == username){
            foundUserIdx = idxUser;
            break;
        }
    }
    
    // if user does not exist, return
    if(foundUserIdx == -1){
        cout << username << " does not exist in the database";
        return -1;
    }
    
    // count num books user has read
    for(int idxBook = 0; idxBook < 50; idxBook++){
        if(arrRatings[foundUserIdx][idxBook] > 0){
            curBooksRead++;
        }
    }
    
    cout << username << " rated " << curBooksRead << " books";
    return curBooksRead;
}



// calcAvgRating ///////////////////////////////////////////////////////////////
// returns avg rating, given a book title
double calcAvgRating(string bookTitle, string arrTitles[], int arrRatings[][50],
        int totalNumUsers, int totalNumBooks_accounted){
    
    // initialize variables
    int foundBookIdx = -1;
    double sumBookRatings = 0.0;
    int numZeroes = 0;
    
    // find book index
    for(int idxBook = 0; idxBook < 50; idxBook++){
        if(arrTitles[idxBook] == bookTitle){
            foundBookIdx = idxBook;
            break;
        }
    }
    
    // if book doesn't exist, return
    if(foundBookIdx == -1){
        cout << bookTitle << " does not exist in the database\n";
        return -1;
    }
    
    // according to foundBookIdx, add all corresponding ratings in arrRatings
    for(int idxUser = 0; idxUser < totalNumUsers; idxUser++){
        if(arrRatings[idxUser][foundBookIdx] != 0){
            sumBookRatings += arrRatings[idxUser][foundBookIdx];
        }
        else{
            numZeroes++;
        }
    }
    
    double avgRating = sumBookRatings / (totalNumUsers - numZeroes);
    return avgRating;
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


// driver function
int main(int argc, char const *argv[]){
    
    // initialize variables
    string choice;
    string booksTxt;
    string ratingsTxt;
    string username;
    string bookTitle;
    int initNumBooks = 0;
    int initNumUsers = 0;
    int totalNumBooks = 0;
    int totalNumUsers = 0;
    
    // total num books user has rated
    int totalNumBooks_accounted = 0;
    
    // total num books user has read
    int curBooksRead = 0;
    
    // avg rating given to each book
    // doesn't include users who haven't read the book yet
    // because if a user hasn't read a book, they automatically rate it 0
    double avgRating = 0;
                                
    // dimensions of arrRatings[][]
    int rowLimit = 100;
    int columnLimit = 50;
    
    // size of arrTitles and arrAuthors
    int maxSize = 100;
 
    // arrays of titles, authors, and usernames
    string arrTitles[maxSize];
    string arrAuthors[maxSize];
    string arrUsernames[maxSize];
    
    // array of user ratings: [user idx][book ratings]
    int arrRatings[maxSize][50];
    

    while(choice != "6"){

        // get user's choice
        displayMenu();
        getline(cin, choice);
        

        switch( stoi(choice) ){
            
            // 1. Read book file: books.txt
            case 1:
            cout << "Enter a book file name:\n";
            getline(cin,booksTxt); 
            totalNumBooks = readBooks(booksTxt, arrTitles, arrAuthors,
                            initNumBooks, maxSize);
                
            // print totalNumBooks in database
            if(totalNumBooks != -1){
                cout << "Total books in the database: " << totalNumBooks << "\n";
            }
            
            // if database is empty, print empty
            if(totalNumBooks == -1){
                cout << "No books saved to the database\n";
            }
            cout << "\n";
            break;
                
            // 2. Read user file: ratings.txt
            case 2:
            cout << "Enter a rating file name:\n";
            getline(cin, ratingsTxt);
            totalNumUsers = readRatings(ratingsTxt, arrUsernames, arrRatings,
                            initNumUsers, rowLimit, columnLimit);
                
            // print totalNumUsers in database                
            if(totalNumUsers != -1){
                cout << "Total users in the database: " << totalNumUsers << "\n";
            }
            
            // if database is empty, print empty                                
            if(totalNumUsers == -1){
                cout << "No users saved to database\n";
            }
            cout << "\n";
            break;
            
            // 3. Print book list
            case 3:
            printAllBooks(arrTitles, arrAuthors, totalNumBooks);
            cout << "\n";
            break;
            
            // 4. Find number of books user rated
            case 4:
            cout << "Enter username:\n";
            getline(cin, username);
            curBooksRead = getUserReadCount(username, arrUsernames, arrRatings,
                            totalNumUsers, totalNumBooks_accounted);
            cout << "\n";
            break;
            
            // 5. Get average rating
            case 5:
            cout << "Enter book title:\n";
            getline(cin, bookTitle);
            avgRating = calcAvgRating(bookTitle, arrTitles, arrRatings,
                        totalNumUsers, totalNumBooks_accounted);
            
            // print average rating for input book title
            if(avgRating != -1){
                cout << "The average rating for " << bookTitle << " is ";
                cout << setprecision(3) << avgRating << "\n";
            }
            cout << "\n";
            break;
            
            // 6. Quit
            case 6:
            cout << "good bye!\n";
            break;
                
            // Default: invalid input
            default:
            cout << "invalid input\n\n";
        }
    }
    return 0;
}
