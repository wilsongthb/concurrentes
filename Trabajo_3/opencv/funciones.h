void segmentar(Mat &src, int lowThreshold) {
	/*
		segmenta la imagen usando Canny
	*/

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
Mat _segmentar(Mat fuente, int lowThreshold) {
	/*
		A diferencia de segmentar() este devuelve el Mat
	*/

	Mat src = fuente.clone();
	
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

	return src;
}
void animar(Mat &image) {
	for (int i = 0; i < 100; i++) {
		waitKey(100);
		Mat temp = image.clone();

		/*Rect medida(0, 0, temp.cols / 2, temp.rows / 2);
		Mat parte = temp(medida);

		parte = _segmentar(parte, i);*/

		//// sobre escribir imagen
		//Rect med1(Point(0, 0), Size(image.cols / 2, image.rows / 2));
		///*Mat dst = image(med1);
		//parte.copyTo(dst);*/
		//parte.copyTo(image(med1));
		temp = _segmentar(temp, i);

		imshow("temp", temp);
		/*imshow("imagen", parte);*/
	}
}
void graficar(Mat &frame, int lapso) {
	while(true){
		waitKey(lapso);
		imshow("frame", frame);
	}
}
void segmentacion_lapso(
	Mat &image, // entrada
	Mat &frame, // salida
	int lapso // lapso entre intervalo
	) {
	for (int i = 0; i < 100; i++) {
		Mat temp = image.clone();
		temp = _segmentar(temp, i);
		temp.copyTo(frame);
		waitKey(lapso);
	}
}