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

	while(true)
	{
		cap.read(img);

		cv::imshow("image", img);
		cv::waitKey(1);


	}


	img = cv::imread("test.jpg");
	cv::imshow("my first opencv window", img);
	cv::waitKey();
	return 0;
}