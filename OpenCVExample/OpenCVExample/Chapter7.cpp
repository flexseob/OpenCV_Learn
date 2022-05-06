#include <iostream>
//#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

//images
using namespace cv;

void getContours(cv::Mat imgDilation, cv::Mat img)
{
	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;



	findContours(imgDilation, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 5);


	std::vector<std::vector<Point>> conPoly(contours.size());
	std::vector<Rect> boundRect(contours.size());
	std::string objectType;
	for(int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		std::cout << area << std::endl;

		
		if(area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			std::cout <<conPoly[i].size() << std::endl;
			boundRect[i] = boundingRect(conPoly[i]);
			

			int objCor = static_cast<int>(conPoly[i].size());

			if(objCor == 3)
			{
				objectType = "Triangle";
			}
			else if(objCor ==4)
			{
				const float aspRatio = static_cast<float>(boundRect[i].width) / static_cast<float>(boundRect[i].height);
				std::cout << aspRatio << std::endl;
				if(aspRatio > 0.95 && aspRatio < 1.05)
				{
					objectType = "Square";
				}
				else
				{
					objectType = "Rect";
				}

			}
			else if (objCor > 4)
			{
				objectType = "Circle";
			}

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 5);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);
		}
	}

}


int main()
{
	
	std::string path = "shapes.png";
	Mat img = imread(path);

	cv::Mat imgGray;
	cv::Mat imgBlur;
	cv::Mat imgCanny;
	cv::Mat imgDiliation;
	cv::Mat imgErode;

	//Preprocessing images
	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDiliation, kernel);
	
	getContours(imgDiliation, img);

	imshow("image", img);
	/*imshow("image Gray", imgGray);
	imshow("image Blur", imgBlur);
	imshow("image Canny", imgCanny);
	imshow("image Dil", imgDiliation);*/

	
	waitKey(0);
	return 0;
}