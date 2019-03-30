// main function performs test cases on different genomes
// analyzer function compares similarity scores of genomes
// simScore function calculates similarity scores of genomes
// length function compares input genome lengths

#include <iostream>
using namespace std;

// returns the similarity score between given genome and unknown genome
double simScore(string genome, string unknown){

    // hamming distance is the num of different letters
    // between the given genome and unknown
    double hammingDistance = 0;
    
    // window-swiping the genome, performing a simScore calculation on each one
    int swipe;
    
    // # of swipes
    swipe = genome.length() - unknown.length();
    
    // array to store all hamming distances, we use the smallest element
    int array[swipe];

    int tempHamm = 0;
                        
    double similarityScore;

    // window-swiping the genome to perform comparison analysis
    for(int k = 0; k <= swipe; k++){
        
        for(int i = k; i < unknown.length() + k; i++){
            
            // if genome char and unknown char are different, hammDist increases
            if(genome[i] != unknown[i-k]){
                tempHamm++;
            }
        }
        
        // add temp hammDist to array
        array[k] = tempHamm;
        tempHamm = 0;
    }
    
    // find the smallest hammDist in the array
    int small = array[0];
    
    for(int j = 0; j < swipe; j++){
        if(small > array[j]){
            small = array[j];
        }
    }

    // smallest hammDist has been found
    hammingDistance = small;

    // calculate and return simScore
    similarityScore = (unknown.length() - hammingDistance) / unknown.length();

    return similarityScore;
}



// returns number to verify if genome lengths match
int length(string genomeOne, string genomeTwo, string genomeThree, string unknown){

    // if unknown length is longer, return 2
    if( unknown.length() > genomeOne.length() ){
        return 2;
    }
    
    // if the genome lengths are not equal, return 1
    else if( genomeOne.length() != genomeTwo.length()
        || genomeOne.length() != genomeThree.length()
        || genomeTwo.length() != genomeThree.length() ){
        return 1;
    }
    
    // else return 0
    else{
        return 0;
    }
}



// analyzes 3 genomes and an unknown, prints which genomes are most similar to
// the unknown
void analyzer(string genomeOne, string genomeTwo, string genomeThree, string unknown){
    
    // genome analyzer results
    string results;
    
    // verification for whether the 3 genome lengths are equal
    int test = 0;

    test = length(genomeOne, genomeTwo, genomeThree, unknown);

    // if any of the genomes are empty, return
    if(genomeOne == "" || genomeTwo == "" || genomeThree == "" || unknown == ""){
        cout << "Genome and sequence cannot be empty." ;
        return;
    }
    
    // if sequence is longer than genome, return
    else if(test == 2){
        cout << "Sequence length must be smaller than genome length.";
        return;
    }
    
    // if genome lengths don't match, return
    else if(test == 1){
        cout << "Genome length does not match."; 
        return;
    }
    
    else{
        
        // initialize counter
        int var = 0;
        
        // initialize simscore comparison between unknown and genomes
        double compareOne;
        double compareTwo;
        double compareThree;
        
        // compare unknown with genomeOne
        if(var == 0){
            compareOne = simScore(genomeOne, unknown);
            var ++;
        }
        
        // compare unknown with genomeTwo
        if(var == 1){
            compareTwo = simScore(genomeTwo, unknown);
            var ++;
        }

        // compare unknown with genomeThree
        if(var == 2){
            compareThree = simScore(genomeThree, unknown);
            var++;
        }

        if(var == 3){

            string a;   // a means genomeOne is best match
            string b;   // b means genomeTwo is best match
            string c;   // c means genomeThree is best match

            if(compareOne >= compareTwo || compareOne >= compareThree){
                a = "Genome 1 is the best match.\n";
            }
            else{
                a = "";
            }
            
            if(compareTwo >= compareOne || compareTwo >= compareThree){
                b = "Genome 2 is the best match.\n";
            }
            else{
                b = "";
            }

            if(compareThree >= compareOne || compareThree >= compareTwo){
                c = "Genome 3 is the best match.\n";
            }
            else{
                c = "";
            }
            
            results = a + b + c;
            cout << results;
            return;
        }
    }
}



int main () {

    string genomeOne;
    string genomeTwo;
    string genomeThree;
    string unknown;
    
    // test case 1
    cout << "Test Case 1: \n";
    genomeOne = "AATGTTTCAC";
    genomeTwo = "GACCGACTAA";
    genomeThree = "AAGGTGCTCC";
    unknown = "TACTA";
    analyzer(genomeOne, genomeTwo, genomeThree, unknown);

    // test case 2
    cout << "\nTest Case 2: \n";
    genomeOne = "AACT";
    genomeTwo = "AACT";
    genomeTwo = "AATG";
    unknown = "AACT";
    analyzer(genomeOne, genomeTwo, genomeThree, unknown);
    
    // test case 3
    cout << "\nTest Case 3: \n";
    genomeOne = "";
    genomeTwo = "CATTA";
    genomeTwo = "TAATC";
    unknown = "ACTA";
    analyzer(genomeOne, genomeTwo, genomeThree, unknown);

    // test case 4
    cout << "\nTest Case 4: \n";
    genomeOne = "TAATC";
    genomeTwo = "CATTAA";
    genomeTwo = "TAATC";
    unknown = "ACTA";
    analyzer(genomeOne, genomeTwo, genomeThree, unknown);

    // test case 5
    cout << "\nTest Case 5: \n";
    genomeOne = "TAATC";
    genomeTwo = "CATA";
    genomeTwo = "TAATC";
    unknown = "ACTATTT";
    analyzer(genomeOne, genomeTwo, genomeThree, unknown);

    // test case 6
    cout << "\nTest Case 6: \n";
    genomeOne = "ACATC";
    genomeTwo = "ACTTA";
    genomeTwo = "TACAT";
    unknown = "AACT";
    analyzer(genomeOne, genomeTwo, genomeThree, unknown);
    return 0;
}
