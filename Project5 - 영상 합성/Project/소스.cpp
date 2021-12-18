#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

int main()
{
	// img1_before
	Mat img1(256, 256, CV_8UC3);
	img1 = imread("lenna.bmp");

	namedWindow("img1_before", WINDOW_NORMAL);
	resizeWindow("img1_before", 256, 256);
	imshow("img1_before", img1);

	// mask, 배경:255, 원:0
	Mat mask(Size(256, 256), CV_8UC1);
	mask = imread("lenna.bmp", IMREAD_GRAYSCALE);
	mask = Scalar(255);

	Mat m2 = mask;

	// mask, 배경:255, 원:0
	double x, y = 0;
	double pi = 3.14159;

	for (int i = 0; i < 10000; i++)
	{
		double degree = i * 2 * pi / 10000;
		x = 256 + 200 * cos(degree);
		y = 256 + 200 * sin(degree);
		degree += 0.036;
		double p = y;
		for (int j = 256; j < y; j++)
		{
			m2.at<uchar>(x, p)++;
			p--;
		}
		for (int k = 256; k > y; k--)
		{
			m2.at<uchar>(x, p)++;
			p++;
		}
	}

	// mask2, 배경:0, 원:255
	Mat mask2(Size(256, 256), CV_8UC1);
	mask2 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	mask2 = Scalar(0);

	Mat m3 = mask2;

	// mask2, 배경:0, 원:255
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
			m3.at<uchar>(z, p)+=255;
			p--;
		}
		for (int k = 256; k > w; k--)
		{
			m3.at<uchar>(z, p)+=255;
			p++;
		}
	}

	// mask 출력
	namedWindow("mask", WINDOW_NORMAL);
	resizeWindow("mask", 256, 256);
	moveWindow("mask", 300, 27);
	imshow("mask", mask);

	// img1_after
	Mat img = imread("lenna.bmp");
	//img = Scalar(0, 256, 0);

	Mat img2 = img.clone();

	img = Scalar(0, 255, 0);

	// img1_after
	double e, f = 0;

	for (int i = 0; i < 10000; i++)
	{
		double degree = i * 2 * pi / 10000;
		e = 256 + 200 * cos(degree);
		f = 256 + 200 * sin(degree);
		degree += 0.036;
		double p = f;
		for (int j = 256; j < f; j++)
		{
			Vec3b& v1 = img.at<Vec3b>(e, p) ;
			v1 = img2.at<Vec3b>(e, p);
			p--;
		}
		for (int k = 256; k > f; k--)
		{
			Vec3b& v2 = img.at<Vec3b>(e, p);
			v2 = img2.at<Vec3b>(e, p);
			p++;
		}
	}

	// img2_before
	Mat img3 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	// img2_after
	Mat img4 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	img4 = mask2 & img4;

	// img1_after 출력
	namedWindow("img1_after", WINDOW_NORMAL);
	resizeWindow("img1_after", 256, 256);
	moveWindow("img1_after", 573, 27);

	imshow("img1_after", img);

	waitKey();

	// img2_before 출력

	namedWindow("img2_before", WINDOW_NORMAL);
	resizeWindow("img2_before", 256, 256);
	moveWindow("img2_before", 27, 330);

	imshow("img2_before", img3);

	// img2_after 출력
	namedWindow("img2_after", WINDOW_NORMAL);
	resizeWindow("img2_after", 256, 256);
	moveWindow("img2_after", 573, 330);

	imshow("img2_after", img4);

	waitKey();

	return 0;
}