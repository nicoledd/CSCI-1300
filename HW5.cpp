/* README
  - what does this program do?
    - the main function defines 3 genomes and 1 sequence
    - the analyzer() function takes these strings as parameters,
      calls the length_test() function to check for errors,
      calls the simScore() function to calculate the similarity scores between
        the sequence and each genome,
      and prints out which genomes are most similar to the sequence
  - how to compile:
    g++ -std=c++11 HW5.cpp
    ./a out
*/


#include <iostream>





/* length_test function
  - return 0 if genome lengths are equal
  - return 1 if genome lengths don't match
  - return 2 if sequence is longer than genomes */
int length_test(std::string genome_one, std::string genome_two, std::string genome_three, std::string sequence){

  /* return 2 */
  if(sequence.length() > genome_one.length()){
    return 2;
  }

  /* return 1 */
  else if(genome_one.length() != genome_two.length() || genome_one.length() != genome_three.length() || genome_two.length() != genome_three.length()){
    return 1;
  }

  /* return 0 */
  else{
    return 0;
  }
}










/* simScore function
  - returns the similarity score between given genome and sequence */
double simScore(std::string genome, std::string sequence){

  /* hamming distance: the num of different letters between genome & sequence */
  double hamming_distance = 0;

  /* used for window-swiping the genome, to perform a sim score calculation
    on each substring */
  int swipe = 0;

  /* number of swipes */
  swipe = genome.length() - sequence.length();

  /* array to store all hamming distances, we use the smallest element */
  int array[swipe];
  int small = 0;

  /* variable to store return value */
  double similarity_score = 0;

  /* temp variable to be used while window-swiping */
  int temp_hamm = 0;

  /* these loops window-swipe the genome to perform comparison analysis */
  for(int k = 0; k <= swipe; k++){
    for(int i = k; i < sequence.length() + k; i++){

      /* if genome char and sequence char differ, hamming_distance increases */
      if(genome[i] != sequence[i - k]){
        temp_hamm++;
      }
    }

    /* add temp hamming distance to array, and re-initialize it */
    array[k] = temp_hamm;
    temp_hamm = 0;
  }

  /* find the smallest hamming distance in the array */
  small = array[0];
  for(int j = 0; j < swipe; j++){
    if(small > array[j]){
      small = array[j];
    }
  }
  hamming_distance = small;

  /* calculate and return sim score */
  similarity_score = (sequence.length() - hamming_distance) / sequence.length();
  return similarity_score;
}













/* analyzer function
  - given the 4 genomes, prints the genome(s) most similar to the unknown*/
void analyzer(std::string genome_one, std::string genome_two, std::string genome_three, std::string sequence){

  /* analyzer results */
  std::string results;

  /* simscore comparison between genomes and sequence */
  double simscore_one = 0;
  double simscore_two = 0;
  double simscore_three = 0;

  /* are the 3 genome lengths equal?
    0 = genome lengths are equal
    1 = genome lengths don't match
    2 = sequence is longer than genomes */
  int test = 0;
  test = length_test(genome_one, genome_two, genome_three, sequence);

  /* if any of the genomes are empty, return */
  if(genome_one == "" || genome_two == "" || genome_three == "" || sequence == ""){
    std::cout << "Genome and sequence cannot be empty.";
    return;
  }

  /* if the sequence is longer than genomes, return */
  else if(test == 2){
    std::cout << "Sequence length must be smaller than genome length.";
    return;
  }

  /* if genome lengths don't match, return */
  else if(test == 1){
    std::cout << "Genome length does not match.";
    return;
  }

  /* get the sim score of sequence with all 3 genomes */
  simscore_one = simScore(genome_one, sequence);
  simscore_two = simScore(genome_two, sequence);
  simscore_three = simScore(genome_three, sequence);

  /* print results */
  if(simscore_one >= simscore_two || simscore_one >= simscore_three){
    std::cout << "Genome 1 is the best match.\n";
  }

  if(simscore_two >= simscore_one || simscore_two >= simscore_three){
    std::cout << "Genome 2 is the best match.\n";
  }

  if(simscore_three >= simscore_one || simscore_three >= simscore_two){
    std::cout << "Genome 3 is the best match.\n";
  }
}

















int main(){

  /* initialize genome variables */
  std::string genome_one = "AATGTTTCAC";
  std::string genome_two = "GACCGACTAA";
  std::string genome_three = "AAGGTGCTCC";
  std::string sequence = "TACTA";

  /* Test Case 1 */
  std::cout << "--- Test Case 1 ---\n";
  std::cout << "genome_one = " << genome_one << "\n";
  std::cout << "genome_two = " << genome_two << "\n";
  std::cout << "genome_three = " << genome_three << "\n";
  std::cout << "sequence = " << sequence << "\n";
  std::cout << "--------------------\n";
  std::cout << "Given 3 genomes and 1 sequence, program prints the genome that is most similar to the sequence:\n";
  std::cout << "--------------------\n";
  analyzer(genome_one, genome_two, genome_three, sequence);
  std::cout << "\n\n";

  /* Test Case 2 */
  genome_one = "TAATCCAAAAAAT";
  genome_two = "CATTAAT";
  genome_three = "TAATCCTCC";
  sequence = "ACTAACTA";
  std::cout << "--- Test Case 2 ---\n";
  std::cout << "genome_one = " << genome_one << "\n";
  std::cout << "genome_two = " << genome_two << "\n";
  std::cout << "genome_three = " << genome_three << "\n";
  std::cout << "sequence = " << sequence << "\n";
  std::cout << "--------------------\n";
  std::cout << "If the genome lengths do not match, program prints an error:\n";
  std::cout << "--------------------\n";
  analyzer(genome_one, genome_two, genome_three, sequence);
  std::cout << "\n\n";

  /* Test Case 3 */
  genome_one = "TAATCTCA";
  genome_two = "CATATCAA";
  genome_three = "TAATCACT";
  sequence = "ACTATTTACTCTCA";
  std::cout << "--- Test Case 3 ---\n";
  std::cout << "genome_one = " << genome_one << "\n";
  std::cout << "genome_two = " << genome_two << "\n";
  std::cout << "genome_three = " << genome_three << "\n";
  std::cout << "sequence = " << sequence << "\n";
  std::cout << "--------------------\n";
  std::cout << "If the sequence is longer than the genomes, program prints an error:\n";
  std::cout << "--------------------\n";
  analyzer(genome_one, genome_two, genome_three, sequence);
  std::cout << "\n\n";

  return 0;
}
