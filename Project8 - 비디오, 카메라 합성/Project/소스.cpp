#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

	VideoWriter outputVideo("output.avi", fourcc, 30, Size(640, 480));

	if (!outputVideo.isOpened()) {
		cout << "File open failed!" << endl;
		return 0;
	}

	VideoCapture cap("stopwatch.avi");

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return 0;
	}

	VideoCapture cap2(0);

	if (!cap2.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return 0;
	}

	double fps = cap.get(CAP_PROP_FPS);

	int delay = cvRound(1000 / fps);

	Mat frame;
	while (cap.get(CAP_PROP_POS_FRAMES) < 60) {
		cap >> frame;
		if (frame.empty())
			break;

		outputVideo << frame;

		imshow("frame", frame);

		if (waitKey(delay) == 27) // ESC key
			break;
	}
	destroyAllWindows();

	/*
	VideoCapture cap2(0);

	if (!cap2.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return 0;
	}
	*/

	double fps2 = cap2.get(CAP_PROP_FPS);

	Mat frame2, inversed;
	while (waitKey(33) != 27) {
		cap2 >> frame2;
		if (frame2.empty())
			break;

		inversed = ~frame2;
		outputVideo << inversed;

		imshow("inversed", inversed);
	}

	destroyAllWindows();

	cap.set(CAP_PROP_POS_FRAMES, 120);
	while (cap.get(CAP_PROP_POS_FRAMES) < 180) {
		cap >> frame;
		if (frame.empty())
			break;

		outputVideo << frame;
		imshow("frame", frame);

		if (waitKey(delay) == 27) // ESC key
			break;
	}
	destroyAllWindows();
}