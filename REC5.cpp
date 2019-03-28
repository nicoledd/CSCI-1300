// prints 2 squares, one empty, one filled, with side length equal to input num
void printSquares(int length){
    
    int x = 0;
    int y = 0;

    // this for-loop iterates through the square's y-coordinate
    for(y = 0; y < length; y++){

        // this for-loop iterates through the square's x-coordinate
        for(x = 0; x < 2*length+1; x++){
            
            // continuously print spaces, making sure to leave blanks for the
            // space between the 2 squares, and the empty square
            if(x == length || (y > 0 && y < length-1 && x > length+1 && x < 2*length) ){
                cout << " ";
            }
            
            else{
                cout << "*";
            }
        }
        
        // new line after each row is finished
        cout << "\n";
    }
}

int main(){
    printSquares(5);
}
