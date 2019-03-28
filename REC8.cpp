// counts num lines in given file
int fileLoadRead(string fileName){

    // initialize file
    ifstream file;

    // initialize variables
    string line;
    int numLines = 0;
    
    // open file
    file.open(fileName);

    // read file
    while( getline(file, line) ){
      numLines++;
    }
    
    // close file
    file.close();
        
    // return num lines in file
    return numLines;
}

int main(){
  fileLoadRead("fileREC8.txt");
}
