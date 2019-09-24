# include <stdio.h>
#include <stdlib.h>

// Generate random numbers in a range...
int randomize(int lower, int upper) { 
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num; 
} 

int main() {
	// input RAW image file
	FILE *fin = fopen("lena.raw", "r");
	// output RAW image file
	FILE *fout = fopen("noisy_lena.raw", "w");
	
	int c = getc(fin);
	unsigned int data[512][512];
	int i, j, ten_percent_noise, twenty_percent_noise, fity_percent_noise;
	for(i=0; i<512; i++) {
		for(j=0; j<512; j++) {
			data = (unsigned int)c;	// following lines converted to pixel values
			c = getc(fin);
		}
	}
	
	// Salt pepper noise to the RAW Image...
	ten_percent_noise = 0.10 * 512 * 512;
	twenty_percent_noise = 0.20 * 512 * 512; 
	fifty_percent_noise = 0.50 * 512 * 512;
	
	while(ten_percent_noise--) {
		data[rand()][]
	}
	
	// closing input and output files
	fclose(fin);
	fclose(fout);
	return 0;
}
