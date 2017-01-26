#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image;

	image = imread("img2.jpg", CV_LOAD_IMAGE_COLOR);
	if (!image.data) {
		cout << "No hay imagen!" << endl;
		return -1;
	}

	namedWindow("imagen", CV_WINDOW_AUTOSIZE);
	imshow("imagen", image);

	waitKey(0);

	return 0;
}