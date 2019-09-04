#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
	string imageName("../../lena.raw"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}
	Mat image;
	image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	// namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	// imshow("Display window", image);                // Show our image inside it.
	// waitKey(0); // Wait for a keystroke in the window
	
	
	cv::Mat grayMat, *p;
	cv::cvtColor(image, grayMat, cv::COLOR_BGR2GRAY);
	// cout << grayMat.size() << endl;

	/*
	for (int i = 0; i < grayMat.rows; i++) {
		for (int j = 0; j < grayMat.cols; j++) {
			cout << grayMat.row(i).col(j) << " ";
		}
		cout << endl;
	}
	*/

	// int *a = grayMat.row(0).col(0).data;

	//cout << a << endl;



	
	
	//cout << image.size() << endl;
	//cout << *pixels.begin() << endl;
	//cout << "size: " << pixels.size() << endl;
	
	/*
	// vector<cv::Vec3b> im_matrix;
	int count = 0;
	for (auto it = pixels.begin(); it != pixels.end(); it++) {
		cout << *it << endl;
		count++;
	}
	
	cout << "Count = " << count << endl;
	/*
	int count = 0;
	for (int x = 1; x < image.cols; x++)
	{
		for (int y = 1; y < image.rows; y++)
		{
			if (image.at<Vec3b>(x, y)[0] == 255)
			{
				count++;
				cout << "in loop" << endl;
			}

		}
	}
	*/
	cout << grayMat << endl;
	
	system("pause");
	return 0;
}