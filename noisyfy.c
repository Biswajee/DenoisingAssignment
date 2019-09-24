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
	
	// variable declaration
	int c, ch, i, j, ten_percent_noise, twenty_percent_noise, fifty_percent_noise;
	unsigned int data[512][512];
	
	
	c = getc(fin);
	
	
	printf("How much noise do you wish to add \n");
	printf("1. 10%% noise \n2. 20%% noise \n3. 50%% noise \n");
	printf("Enter your choice: ");	
	scanf("%d", ch);
	
	for(i=0; i<512; i++) {
		for(j=0; j<512; j++) {
			data[i][j] = (unsigned int)c;	// following lines converted to pixel values
			c = getc(fin);
		}
	}
	
	// Salt pepper noise to the RAW Image...
	ten_percent_noise = 0.10 * 512 * 512;
	twenty_percent_noise = 0.20 * 512 * 512; 
	fifty_percent_noise = 0.50 * 512 * 512;
	
	switch(ch) {
		case 1:
		// adding 10% noise to image
		printf("10% Salt-pepper going in, Sir !");
		while(ten_percent_noise--) {
			data[randomize(512,512)][randomize(512,512)] = randomize(0, 255);
		}
		break;
		
		case 2:
		printf("20% Salt-pepper going in ! That's spicy");
		while(twenty_percent_noise--) {
			data[randomize(512,512)][randomize(512,512)] = randomize(0, 255);
		}
		break;
		
		case 3:
		printf("50% Salt-pepper, Jeez !");
		while(fifty_percent_noise--) {
			data[randomize(512,512)][randomize(512,512)] = randomize(0, 255);
		}
		break;
		
		default:
			printf("Am I a joke to you ?\n");
	}
	
	// writing data array to output file...
	for(i=0; i<512; i++) {
		for(j=0; j<512; j++) {
			fprintf(fout, "%d  ", data[i][j]);
		}
	}
	
	
	// closing input and output files
	fclose(fin);
	fclose(fout);
	return 0;
}
