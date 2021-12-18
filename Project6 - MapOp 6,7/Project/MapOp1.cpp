#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void MatOp6();
void MatOp7();

int main()
{
	//MatOp6();
	MatOp7();

	return 0;
}

void MatOp6()
{
	float data[] = { 1, 1, 2, 3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;

	cout << "mat1.t():\n" << mat1.t() << endl;
	cout << "mat1 + 3:\n" << mat1 + 3 << endl;
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;

	cout << "mat1 + Scalar(3):\n" << mat1 + Scalar(3) << endl;
	cout << "mat1 * 3:\n" << mat1 * 3 << endl;
	cout << "mat1 / mat2:\n" << mat1 / mat2 << endl;
	cout << "4 / mat1:\n" << 4 / mat1 << endl;
	cout << "mat1.mul(mat2):\n" << mat1.mul(mat2) << endl;
	//float data2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//Mat mat3(2, 4, CV_32FC1, data2);
	float data2[] = { 1,2,3,4,5,6 };
	Mat mat3(2, 3, CV_32FC1, data2);
	cout << "mat3:\n" << mat3 << endl;
	cout << "mat3(pseudoinverse by SVD):\n" << mat3.inv(DECOMP_SVD) << endl;
	cout << "pseudoinverse(left inverse)" << endl;
	cout << (((mat3.t()) * mat3).inv()) * (mat3.t()) << endl;
	cout << "pseudoinverse(right inverse)" << endl;
	cout << (mat3.t()) * ((mat3) * (mat3.t())).inv() << endl << endl;
}

void MatOp7()
{
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Mat img1f;
	img1.convertTo(img1f, CV_32FC1);

	Mat img2f;
	img1.convertTo(img2f, CV_32FC1, 1.0 / 255);	// [0, 1] -> (x255) [0, 255]
	imshow("img1", img1);
	imshow("img1f", img1f);
	imshow("img2f", img2f);
	waitKey();

	uchar data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1);

	cout << "mat1:\n" << mat1 << endl;
	cout << "mat2:\n" << mat2 << endl;

	mat2.at<uchar>(0, 2) = 77;
	cout << "mat1(at):\n" << mat1 << endl;
	cout << "mat2(at):\n" << mat2 << endl;

	Mat mat2_1 = mat1.reshape(3, 2);
	cout << "mat2_1L\n" << mat2_1 << endl;
	cout << "mat2_1(channels): " << mat2_1.channels() << endl;
	cout << "mat2_1(size): " << mat2_1.size() << endl;

	mat1.resize(5, 100);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat3_1 = Mat::ones(3, 4, CV_8UC1) * 128;
	mat1.push_back(mat3_1);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat4(12, 1, CV_8UC1, data1);
	cout << "mat4:\n" << mat4 << endl;
	vector<uchar> mat3_2(2, 50);
	mat4.push_back(mat3_2);
	cout << "mat4:\n" << mat4 << endl;
	mat4.pop_back(3);
	cout << "mat4:\n" << mat4 << endl;

	destroyAllWindows();
}