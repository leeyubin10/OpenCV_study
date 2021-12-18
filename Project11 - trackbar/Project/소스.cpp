#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void on_level_change(int pos, void* userdata);
void on_level_change2(int pos, void* userdata);

int main(void)
{
	Mat img = Mat::zeros(400, 400, CV_8UC1);

	namedWindow("image");

	int value = 0;
	//createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);
	createTrackbar("level", "image", &value, 16, on_level_change, (void*)&img);
	createTrackbar("level2", "image", 0, 4, on_level_change2, (void*)&img);

	imshow("image", img);

	setTrackbarPos("level", "image", 15);
	setTrackbarPos("level2", "image", 1);

	cout << "value: " << value << endl;

	waitKey();

	cout << "value: " << value << endl;

	return 0;
}

void on_level_change(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;

	img.setTo(pos * 16);
	imshow("image", img);
}

void on_level_change2(int pos, void* userdata)
{
	Mat img = *(Mat*)userdata;

	img.setTo(pos = 64);
	imshow("image", img);
}