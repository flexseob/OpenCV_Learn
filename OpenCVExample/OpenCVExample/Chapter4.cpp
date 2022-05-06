#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

// Draw Shapes and Text 
int main()
{
	using namespace cv;

													//B G R
	Mat img(512, 512, CV_8UC3, Scalar(255,255,255));
	
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255),FILLED);
	line(img, Point(130, 296), Point(382, 450), Scalar(255, 255, 255),2);
	std::string path = "test.jpg";

	putText(img, "WorkShop", Point(137, 262), FONT_HERSHEY_DUPLEX,0.75,Scalar(0,69,255),2);

	imshow("image", img);


	waitKey(0);

	//while (true)
	//{
	//	cap.read(img);

	//	cv::imshow("image", img);
	//	cv::waitKey(1);


	//}

	return 0;
}