#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
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
	
	
	std::vector<cv::Vec3b> pixels(image.rows * image.cols);
	cv::Mat m(image.rows, image.cols, CV_8UC3, &pixels[0]);
	image.copyTo(m);

	cout << *pixels.begin() << endl;
	
	system("pause");
	return 0;
}