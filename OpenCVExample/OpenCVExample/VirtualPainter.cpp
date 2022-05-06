#include <iostream>
//#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
int main()
{



	cv::VideoCapture cap(0);

	cv::Mat img;

	while (true)
	{
		cap.read(img);
		cv::imshow("VirtualPainter", img);
		cv::waitKey(1);


	}

	return 0;
}