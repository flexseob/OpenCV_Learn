#include <iostream>
//#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <string>
int main()
{
	using namespace cv;

	cv::Mat img;
	 cv::VideoCapture webcam = VideoCapture(0);

	CascadeClassifier faceCascade;
	faceCascade.load("haarcascade_frontalface_default.xml");

	if(faceCascade.empty())
	{
		std::cout << "Xml file not loaded!" << std::endl;
	}

	while (1)
	{
		webcam.read(img);
		std::vector<Rect> faces;

		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
		}



		cv::imshow("my first opencv window", img);
		cv::waitKey(2);
	}
	return 0;
}