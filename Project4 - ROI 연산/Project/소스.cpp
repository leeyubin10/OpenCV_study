#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img1;
	img1 = imread("lenna.bmp");

	if (img1.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	
	namedWindow("img1_before", WINDOW_NORMAL);
	resizeWindow("img1_before", 256, 256);
	imshow("img1_before", img1);

	Mat img2 = img1.clone();

	namedWindow("img1_after", WINDOW_NORMAL);
	resizeWindow("img1_after", 256, 256);
	moveWindow("img1_after", 26, 320);

	Mat img3 = img2(Rect(0, 0, 512, 50));
	img3 = Scalar(0,255,0);
	Mat img4 = img2(Rect(0, 462, 512, 50));
	img4 = Scalar(0, 255, 0);
	Mat img5 = img2(Rect(0, 50, 50, 412));
	img5 = Scalar(0, 255, 0);
	Mat img6 = img2(Rect(462, 50, 50, 412));
	img6 = Scalar(0, 255, 0);

	Mat img7 = img2(Rect(100, 100, 312, 50));
	img7 = Scalar(255, 0, 0);
	Mat img8 = img2(Rect(100, 362, 312, 50));
	img8 = Scalar(255, 0, 0);
	Mat img9 = img2(Rect(100, 150, 50, 212));
	img9 = Scalar(255, 0, 0);
	Mat img10 = img2(Rect(362, 150, 50, 212));
	img10 = Scalar(255, 0, 0);
	

	imshow("img1_after", img2);

	waitKey();

	return 0;
}