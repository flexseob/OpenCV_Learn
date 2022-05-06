#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

//basics function
int main()
{
	using namespace cv;
	cv::VideoCapture cap(0);

	std::string path = "test.jpg";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray;
	cv::Mat imgBlur;
	cv::Mat imgCanny;
	cv::Mat imgDiliation;
	cv::Mat imgErode;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDiliation, kernel);
	erode(imgDiliation, imgErode, kernel);


	imshow("Image GRay", imgGray);
	imshow("Image", img);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dia", imgDiliation);
	imshow("Image erode", imgErode);
	waitKey(0);

	//while (true)
	//{
	//	cap.read(img);

	//	cv::imshow("image", img);
	//	cv::waitKey(1);


	//}

	return 0;
}