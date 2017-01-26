/*
	Wilson Pilco Nuñez
	Sistemas Concurrentes
	26/01/2017
*/


#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <iostream>
#include <Windows.h>
#include <thread>

using namespace cv;
using namespace std;

#include "funciones.h"

int main() {
	Mat image; // imagen original
	image = imread("img/img3.jpg", CV_LOAD_IMAGE_COLOR);
	if (!image.data) {
		cout << "No hay imagen!" << endl;
		return -1;
	}
	Mat frame = image.clone(); // imagen usada para mostrar la salida en video

	// definicion de area a segmentar
	int r1x = 0;
	int r1y = 0;
	int rw = image.cols / 2;
	int rh = image.rows;
	int r2x = image.cols / 2;
	int r2y = 0;
	//cout << "rows:" << image.rows << "\n" << "cols:" << image.cols << endl;
	//cout << "r1x:" << r1x << endl;
	//cout << "r1y:" << r1y << endl;
	//cout << "r2x:" << r2x << endl;
	//cout << "r2y:" << r2y << endl;
	//cout << "rw:" << rw << endl;
	//cout << "rh:" << rh << endl;
	//system("pause");

	Rect medida[2];
	medida[0] = Rect(r1x, r1y, rw, rh);
	medida[1] = Rect(r2x, r2y, rw, rh);

	thread t1(segmentacion_lapso, image(medida[0]), frame(medida[0]), 1);
	thread t3(segmentacion_lapso, image(medida[1]), frame(medida[1]), 1);
	thread t2(graficar, frame, 30);

	// incia la ejecucion
	imshow("original", image);
	waitKey(0);
	t1.join();

	waitKey(0);
	

	return 0;
}
