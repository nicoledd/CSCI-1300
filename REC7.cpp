// creates file, and writes squares of numbers 1-10 to it
int fileLoadWrite(string fileName) {
    
    // initialize file
    ofstream file;
    
    // open file
    file.open(fileName);
    
    // if file open, write squares to it
    if(file.is_open() ) {
        for(int num = 1; num <= 10; num++){
            file << num * num << "\n";
        }
    }
    return 0;
}

int main(){
  fileLoadWrite("fileREC7.txt");
}
