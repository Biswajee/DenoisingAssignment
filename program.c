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
	FILE *fin = fopen("test_images\\feep.pgm", "r");
	
	// output PGM image file
	FILE *fout = fopen("outputs\\new_img.pgm", "w");
	
	int c = getc(fin);
	unsigned int res = 0;
	// Header line count :: generally 4 lines of header in PGM image
	int count;
	
	while (c != EOF) {
		if(count <= 4) {
			fprintf(fout, "%c", c);		// header lines printed in document as is.
			if(c == '\n') count++;
		} else {
			res = (unsigned int)(c-48);	// following lines converted to pixel values
			if(res != -16) {
				if(res == -38) {
					fprintf(fout, "\n");
				} else {
			 		fprintf(fout, "%d  ", res);
			 	}
			}
		}
		c = getc(fin);
	}
	
	// closing input and output files
	fclose(fin);
	fclose(fout);
	
	return 0;
}
