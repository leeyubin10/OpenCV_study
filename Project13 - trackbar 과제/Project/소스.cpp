#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

void on_level_change(int pos, void* userdata);
void on_level_change2(int pos, void* userdata);

int main()
{
	int value = 0;

	// img1 Mat 객체 생성
	Mat img = imread("lenna.bmp");
	Mat img1 = img.clone();
	img = Scalar(255, 0, 0);

	// img1 배경
	double e, f = 0;
	double pi = 3.14159;

	for (int i = 0; i < 10000; i++)
	{
		double degree = i * 2 * pi / 10000;
		e = 256 + 200 * cos(degree);
		f = 256 + 200 * sin(degree);
		degree += 0.036;
		double p = f;
		for (int j = 256; j < f; j++)
		{
			Vec3b& v1 = img.at<Vec3b>(e, p);
			v1 = img1.at<Vec3b>(e, p);
			p--;
		}
		for (int k = 256; k > f; k--)
		{
			Vec3b& v2 = img.at<Vec3b>(e, p);
			v2 = img1.at<Vec3b>(e, p);
			p++;
		}
	}
	putText(img, "Lenna", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 2, LINE_AA);

	// img2 Mat 객체 생성
	Mat img2(Size(256, 256), CV_8UC1);
	img2 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	img2 = Scalar(96);

	Mat img3 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	// img2 배경
	double z, w = 0;

	for (int i = 0; i < 10000; i++)
	{
		double degree = i * 2 * pi / 10000;
		z = 256 + 200 * cos(degree);
		w = 256 + 200 * sin(degree);
		degree += 0.036;
		double p = w;
		for (int j = 256; j < w; j++)
		{
			uchar& v1 = img2.at<uchar>(z, p);
			v1 = img3.at<uchar>(z, p);
			p--;
		}
		for (int k = 256; k > w; k--)
		{
			uchar& v2 = img2.at<uchar>(z, p);
			v2 = img3.at<uchar>(z, p);
			p++;
		}
	}
	putText(img2, "96", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, 255, 2, LINE_AA);

	//img1 트랙바 생성
	namedWindow("img1", WINDOW_NORMAL);
	moveWindow("img1", 573, 27);

	createTrackbar("Color", "img1", &value, 5, on_level_change, (void*)&img);
	imshow("img1", img);

	// img2 트랙바 출력
	namedWindow("img2", WINDOW_NORMAL);
	moveWindow("img2", 573, 400);

	createTrackbar("Intensity", "img2", &value, 64, on_level_change2, (void*)&img2);
	imshow("img2", img2);

	waitKey();

	return 0;
}

void on_level_change(int pos, void* userdata)
{
	Mat img = imread("lenna.bmp");
	namedWindow("img1", WINDOW_NORMAL);
	resizeWindow("img1", 256, 256);

	Mat img1 = img.clone();

	double e, f = 0;
	double pi = 3.14159;

	if (pos == 0)
		img = Scalar(255, 0, 0);
	else if (pos == 1)
		img = Scalar(0, 255, 0);
	else if (pos == 2)
		img = Scalar(0, 0, 255);
	else if (pos == 3)
		img = Scalar(255, 255, 0);
	else if (pos == 4)
		img = Scalar(0, 255, 255);
	else if (pos == 5)
		img = Scalar(255, 0, 255);

	for (int i = 0; i < 10000; i++)
	{
		double degree = i * 2 * pi / 10000;
		e = 256 + 200 * cos(degree);
		f = 256 + 200 * sin(degree);
		degree += 0.036;
		double p = f;
		for (int j = 256; j < f; j++)
		{
			Vec3b& v1 = img.at<Vec3b>(e, p);
			v1 = img1.at<Vec3b>(e, p);
			p--;
		}
		for (int k = 256; k > f; k--)
		{
			Vec3b& v2 = img.at<Vec3b>(e, p);
			v2 = img1.at<Vec3b>(e, p);
			p++;
		}
	}

	if (pos == 0) 
		putText(img, "Lenna", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 2, LINE_AA);
	else if (pos == 1)
		putText(img, "Lenna", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 0), 2, LINE_AA);
	else if (pos == 2)
		putText(img, "Lenna", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 2, LINE_AA);
	else if (pos == 3)
		putText(img, "Lenna", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 255, 0), 2, LINE_AA);
	else if (pos == 4)
		putText(img, "Lenna", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 255), 2, LINE_AA);
	else if (pos == 5)
		putText(img, "Lenna", Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 255), 2, LINE_AA);

	imshow("img1", img);
}

void on_level_change2(int pos, void* userdata)
{
	Mat img2(Size(256, 256), CV_8UC1);
	img2 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	int color = 0;
	int val = 96;

	for (int i = 0; i < 65; i++)
	{
		if (pos == i)
		{
			color = val + i;
		}
	}
	img2 = color;
	String num = to_string(color);

	Mat img3 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	// mask2, 배경:0, 원:255
	double z, w = 0;
	double pi = 3.14159;

	for (int i = 0; i < 10000; i++)
	{
		double degree = i * 2 * pi / 10000;
		z = 256 + 200 * cos(degree);
		w = 256 + 200 * sin(degree);
		degree += 0.036;
		double p = w;
		for (int j = 256; j < w; j++)
		{
			uchar& v1 = img2.at<uchar>(z, p);
			v1 = img3.at<uchar>(z, p);
			p--;
		}
		for (int k = 256; k > w; k--)
		{
			uchar& v2 = img2.at<uchar>(z, p);
			v2 = img3.at<uchar>(z, p);
			p++;
		}
	}

	putText(img2, num, Point(200, 256), FONT_HERSHEY_SIMPLEX, 2, 255, 2, LINE_AA);

	// img2_after 출력
	namedWindow("img2", WINDOW_NORMAL);
	resizeWindow("img2", 256, 256);

	imshow("img2", img2);
}