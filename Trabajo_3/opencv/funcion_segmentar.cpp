#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>

#include <Windows.h>
#include <iostream>

using namespace cv;

void segmentar(Mat &src, int lowThreshold) {
	/*int lowThreshold = 99;*/
	int edgeThresh = 1;

	int const max_lowThreshold = 100;
	int ratio = 3;
	int kernel_size = 3;
	Mat dst, detected_edges, src_gray;

	/// Create a matrix of the same type and size as src (for dst)
	dst.create(src.size(), src.type());

	/// Convert the image to grayscale
	cvtColor(src, src_gray, CV_BGR2GRAY);

	/// Reduce noise with a kernel 3x3
	blur(src_gray, detected_edges, Size(3, 3));

	/// Canny detector
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

	/// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);
	src.copyTo(dst, detected_edges);
	dst.copyTo(src);
}

/** @function main */
int main(int argc, char** argv)
{
	Mat src;
	
	char* window_name = "Edge Map";

	/// Load an image
	src = imread("img3.jpg", CV_LOAD_IMAGE_COLOR);

	segmentar(src, 1);

	// Create a window
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	imshow(window_name, src);

	/// Wait until user exit program by pressing a key
	waitKey(0);

	return 0;
}