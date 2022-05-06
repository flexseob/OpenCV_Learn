#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

//resize and Crop
int main()
{
	using namespace cv;


	std::string path = "test.jpg";
	Mat img = imread(path);
	Mat imgResize;
	Mat imgCrop;

	//std::cout << img.size() << std::endl;
	resize(img, imgResize, Size(),0.5,0.5);

	Rect roi(100, 100, 300,250);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);

	//while (true)
	//{
	//	cap.read(img);

	//	cv::imshow("image", img);
	//	cv::waitKey(1);


	//}

	return 0;
}