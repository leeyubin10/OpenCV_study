#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	Mat Atom(400, 400, CV_8UC3, Scalar(255, 255, 255));

	circle(Atom, Point(200, 200), 12, Scalar(0, 0, 255), -1, LINE_AA);

	ellipse(Atom, Point(200, 200), Size(100, 25), 0, 0, 360, Scalar(255, 0, 0), 1, LINE_AA);
	ellipse(Atom, Point(200, 200), Size(100, 25), 45, 0, 360, Scalar(255, 0, 0), 1, LINE_AA);
	ellipse(Atom, Point(200, 200), Size(100, 25), 90, 0, 360, Scalar(255, 0, 0), 1, LINE_AA);
	ellipse(Atom, Point(200, 200), Size(100, 25), -45, 0, 360, Scalar(255, 0, 0), 1, LINE_AA);


	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));

	const String text = "Hello, OpenCV";
	int fontFace = FONT_HERSHEY_TRIPLEX;
	double fontScale = 2.0;
	int thickness = 1;

	int baseline = 0;
	Size sizeText = getTextSize(text, fontFace, fontScale, thickness, &baseline);
	cout << "baseline: " << baseline << endl;
	Size sizeImg = img.size();

	Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);
	putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
	rectangle(img, org + Point(0, baseline), org + Point(sizeText.width, -(sizeText.height)), Scalar(0, 255, 0), 1);
	line(img, org, org + Point(sizeText.width,0), Scalar(0, 0, 255));

	imshow("Atom", Atom);
	imshow("img", img);
	waitKey();

	destroyAllWindows();

	return 0;
}