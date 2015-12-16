#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
	std::ofstream myfile;
	// Open File
	myfile.open ("output.mem", std::ios::out | std::ios::binary);
	int word_width;
	int word_bytes;
	int mem_depth;
	int status = 0;
	unsigned char *data;
	unsigned char *data_arr;
	// Get user intput for paramters 
	std::cout << "Word size in bits? \n";
	std::cin  >> word_width;
	// Check if bits is divisible by a byte evenly
	if (word_width%8 != 0){
		std::cout << "Word width must be a multiple of 8";
		return 1;
	}
	// Bytes per word
	word_bytes = (word_width/8);
	std::cout << "Number of memory entries? \n"; 
	std::cin  >> mem_depth;
	// Data allocation
	data = (unsigned char*) calloc ((mem_depth*word_bytes), sizeof(unsigned char));
	data_arr = (unsigned char*) calloc (word_bytes, sizeof(unsigned char));
	// Generation of data
	for (int i = 0; i < (mem_depth); i++){
		for (int j = 0; j < word_bytes; j++){
			data_arr[(word_bytes - 1) - j] = (i >> j*8);
			data[(i * word_bytes) + j] = data_arr[j];	
		}
	}
	// Write Data to file 
	for(int i = 0; i < ((mem_depth)*word_bytes); i++){
        myfile << (data[i]);
    }
	// Close File
	myfile.close();
	return (status); 
}