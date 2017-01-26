#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/video/background_segm.hpp"
#include <stdio.h>
#include <string>
using namespace std;
using namespace cv;
int main(int argc, char** argv)
{

	Mat image1 = imread("img.jpg");
	Mat image2 = imread("img2.jpg");
	bool est = true;
	for (;;) // salida de video
	{
		if (est) {
			imshow("video", image1);
			est = false;
		}
		else {
			imshow("video", image2);
			est = true;
		}
		waitKey(1000);
	}
	return 0;
}