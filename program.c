#include <stdio.h>
#include <stdlib.h>

/*
PGM Header format :
	P5
	# Created by Imlib
	512 512
	255
*/

int main() {
	// input PGM image file
	FILE *fin = fopen("lena512.pgm", "r");
	// output PGM image file
	FILE *fout = fopen("new_img.pgm", "w");
	
	int c = getc(fin);
	
	// Header line count :: generally 4 lines of header in PGM image
	int count, pixel_counter = 0;
	
	while (c != EOF) {
		if(count <= 4) {
			fprintf(fout, "%c", c);		// header lines printed in document as is.
			if(c == '\n') count++;
		} else {
			fprintf(fout, "%d ", (unsigned int)c);	// following lines converted to pixel values
			pixel_counter++;
			if(pixel_counter == 12) {
				fprintf(fout, "\n");
				pixel_counter = 0;
			}
		}
		c = getc(fin);
	}
	
	// closing input and output files
	fclose(fin);
	fclose(fout);
	
	return 0;
}
