## Denoising assignment

This repository holds denoising assignment in course project for **CSE 791**. The aim of this assignment was to grab an image in PGM format with unsigned characters and convert it into PGM Image with integral gray levels. 

### Prerequisites

+ C programming

### Images
Images introduced in the repository are typically **512 x 512** array with gray scale **[0...255]**. All images used in project are standard test image : [Lenna](https://en.wikipedia.org/wiki/Lenna).

### Result

The converted image can only be read in _Matlab_ which produces the following result:
![Converted Image](outputs/mat_figure.jpg =250x)

Using the complementary _GNU Octave_ or any other imaging software to open the converted image results in error. 