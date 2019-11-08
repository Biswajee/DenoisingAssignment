/* Adding Salt pepper noise to image to convert them to noisy images */

#include <stdio.h>
#include <stdlib.h>

// Generate random numbers in a range...
int randomize(int lower, int upper) { 
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num; 
} 

int main() {
	// input RAW image file
	FILE *fin = fopen("test_images\\feep.pgm", "r");
	
	if(fin == NULL) {
		printf("Could not read from source !\n");
		return 0;
	}
	
	// output RAW image file
	FILE *fout = fopen("outputs\\noisy_feep.pgm", "w");
	
	if(fout == NULL) {
		printf("Could not write to file !\n");
		return 0;
	}
	
	
	// variable declaration
	int c, ch, i, j, m, n, ten_percent_noise, twenty_percent_noise, fifty_percent_noise;
	printf("Enter column and row values of PGM image [col row]\n");
	scanf("%d %d", &m, &n);
	printf("m: %d, n: %d\n", m , n);
	fflush(stdin);
	unsigned int data[n][m];
	//fseek(fin, 22, 0);
	
	c = getc(fin);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			data[i][j] = c;	// following lines converted to pixel values (unsigned int) [only incase of uchar PGMs]
			c = getc(fin);
			printf("%d", c);
		}
	}
	
	// Salt pepper noise to the PGM Image...
	ten_percent_noise = 0.10 * m * n;
	twenty_percent_noise = 0.20 * m * n; 
	fifty_percent_noise = 0.50 * m * n;
	
	
	printf("How much noise do you wish to add \n");
	printf("1. 10%% noise \n2. 20%% noise \n3. 50%% noise \n");
	printf("Enter your choice: ");	
	scanf("%d", &ch);
	
	switch(ch) {
		
		case 1:
		// adding 10% noise to image
		printf("10%% Salt-pepper going in, Sir !");
		while(ten_percent_noise--) {
			data[randomize(0,n)][randomize(0,m)] = randomize(3, 15);
		}
		break;
		
		case 2:
		printf("20%% Salt-pepper going in ! That's spicy");
		while(twenty_percent_noise--) {
			data[randomize(0,n)][randomize(0,m)] = randomize(3, 15);
		}
		break;
		
		case 3:
		printf("50%% Salt-pepper, Jeez !");
		while(fifty_percent_noise--) {
			data[randomize(0,n)][randomize(0,m)] = randomize(3, 15);
		}
		break;
		
		default:
			printf("\nAm I a joke to you ?\n");
	}
	
	printf("\n");
	// writing data array to output file...
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			fprintf(fout, "%d  ", data[i][j]);
		}
		fprintf(fout,"\n");
	}
	
	// closing input and output files
	fclose(fin);
	fclose(fout);
	return 0;
}
