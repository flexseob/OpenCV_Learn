#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

// Color Detection
int main()
{
	using namespace cv;
	std::string path = "shapes.png";
	Mat img = imread(path);
	Mat imgHSV;
	Mat mask;

	int hmin = 0;int smin = 0;int vmin = 0;

	int hmax = 179, smax = 255, vmax = 255;

	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("TrackBars", (640, 200));
	createTrackbar("Hue Min", "TrackBars", &hmin, 179);
	createTrackbar("Hue Max", "TrackBars", &hmax, 179);
	createTrackbar("Sat Min", "TrackBars", &smin, 255);
	createTrackbar("Sat Max", "TrackBars", &smax, 255);
	createTrackbar("Val Min", "TrackBars", &vmin, 255);
	createTrackbar("Val Max", "TrackBars", &vmax, 255);
	while (true)
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);


		imshow("image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		waitKey(1);
	}
	return 0;
}