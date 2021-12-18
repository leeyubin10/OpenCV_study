#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void PointOp();
void SizeOp();
void RectOp();
void RotatedRectOp();

int main()
{
	cout << "<-- 1¹ø -->" << endl;
	cout << "Hello OpenCV " << CV_VERSION << endl << endl;

	Mat img;
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", img);

	namedWindow("image2", WINDOW_NORMAL);
	moveWindow("image2", 100, 100);
	imshow("image2", img);

	waitKey();

	cout << "<-- 2¹ø -->" << endl;
	PointOp();
	SizeOp();
	RectOp();
	RotatedRectOp();

	return 0;
}

void PointOp()
{
	Point pt1;				// pt1 = (0, 0)
	pt1.x = 5; pt1.y = 10;	// pt1 = (5, 10)
	Point pt2(10, 30);		// pt2 = (10, 30)

	Point pt3 = pt1 + pt2;	// pt3 = [15, 40]
	Point pt4 = pt1 * 2;	// pt4 = [10, 20]
	int d1 = pt1.dot(pt2);	// d1 = 350
	bool b1 = (pt1 == pt2);	// b1 = false

	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;

	cout << "dot product: " << d1 << endl;
	cout << "cross product: " << pt1.cross(pt2) << endl << endl;
}

void SizeOp()
{
	Size sz1, sz2(10, 20);			// sz1 = [0 x 0], sz2 = [10 x 20]
	sz1.width = 5; sz1.height = 10;	// sz1 = [5 x 10]

	Size sz3 = sz1 + sz2;	// sz3 = [15 x 30]
	Size sz4 = sz1 * 2;		// sz4 = [10 x 20]
	int area1 = sz4.area();	// area1 = 200

	cout << "sz3: " << sz3 << endl;
	cout << "sz4: " << sz4 << endl;

	cout << "area(sz4): " << area1 << endl << endl;
}

void RectOp()
{
	Rect rc1;					// rc1 = [0 x 0 from (0, 0)]
	Rect rc2(10, 10, 60, 40);	// rc2 = [60 x 40 from (10, 10)]

	Rect rc3 = rc1 + Size(50, 40);	// rc3 = [50 x 40 from (0, 0)]
	Rect rc4 = rc2 + Point(10, 10);	// rc4 = [60 x 40 from (20, 20)]

	Rect rc5 = rc3 & rc4;		// rc5 = [30 x 20 from (10, 10)]
	Rect rc6 = rc3 | rc4;		// rc6 = [80 x 60 from (0, 0)]

	cout << "rc5: " << rc5 << endl;
	cout << "rc6: " << rc6 << endl;

	cout << "rc3: " << rc3 << endl;
	cout << "rc4: " << rc4 << endl << endl;
}

void RotatedRectOp()
{
	RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f);

	Point2f pts[4];
	rr1.points(pts);

	Rect br = rr1.boundingRect();

	for (int i = 0; i < 4; i++)
		cout << "ptr[" << i << "]" << pts[i] << endl;
	cout << "br: " << br << endl;
	Rect2f br_f = rr1.boundingRect2f();
	cout << "br_f: " << br_f << endl << endl;
}