#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    char path_in[64], path_out[64], *rev, px;
    int width, height, read, row, i;

    printf("Input file name: ");
    scanf("%s", path_in);
    printf("Output file name: ");
    scanf("%s", path_out);

    printf("Width of image (in pixels): ");
    scanf("%d", &width);
    printf("Height of image (in pixels): ");
    scanf("%d", &height);

    fin = fopen(path_in, "rb");
    fout = fopen(path_out, "wb");

    row = 0;
    rev = (char *)malloc(width * sizeof(char));
    while(row < height)
    {
        for(i = 0; i < width; i++)
        {
            read = fread(&px, sizeof(char), 1, fin);
            rev[i] = px;
        }
        row++;
    }


    row = 0;
    while(row < height) {
        for(i = 0; i < width; i++)
            if(i < width && row < height)
                fwrite(&rev[i], sizeof(char), 1, fout);
        row++;
    }

    fclose(fout);
    fclose(fin);

    return 0;
}