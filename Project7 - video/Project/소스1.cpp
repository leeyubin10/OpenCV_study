#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void camera_in_video_out();

int main()
{
	camera_in_video_out();
}

void camera_in_video_out()
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Video Open Failed!";
		return;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);
	int fourcc = cap.get(CAP_PROP_FOURCC);
	int delay = cvRound(1000 / fps);

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));

	if (!outputVideo.isOpened())
	{
		cout << "File Open Failed!" << endl;
		return;
	}

	Mat frame, inversed;
	while (true)
	{
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;
		outputVideo << inversed;

	}

}