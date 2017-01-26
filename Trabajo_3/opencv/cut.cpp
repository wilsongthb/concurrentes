//#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <iostream>
#include <Windows.h>

using namespace cv;
using namespace std;

int main() {
	Mat image;

	image = imread("img2.jpg", CV_LOAD_IMAGE_COLOR);
	if (!image.data) {
		cout << "No hay imagen!" << endl;
		return -1;
	}

	Rect medida(0, 0, 200, 200);
	Mat parte = image(medida).clone();

	/*cvtColor(parte, parte, CV_BGR2GRAY);*/

	//Mat src(5, 7, CV_8UC1, Scalar(1)); // 5x7
	//Mat dst(10, 10, CV_8UC1, Scalar(0)); // 10x10

	//src.copyTo(dst.rowRange(1, 6).colRange(3, 10));
	//cout << dst;

	/*parte.copyTo(image.rowRange(100, 200).colRange(100, 200));*/
	Rect med1(Point(100, 100), Size(200, 200));
	Mat dst = image(med1);
	parte.copyTo(dst);
	parte.copyTo(image(med1));

	namedWindow("imagen", CV_WINDOW_AUTOSIZE);
	waitKey(0);
	imshow("imagen", image);
	Sleep(1000);
	imshow("imagen", parte);
	
	waitKey(0);

	return 0;
}
