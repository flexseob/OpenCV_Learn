#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

// Warp and Cut
int main()
{
	using namespace cv;

	float w = 250, h = 350;

	Mat matrix, imgWarp;
	std::string path = "cards.png";
	Mat img = imread(path);

	Point2f src[4] = { {251,70},{363,93},{194,186},{317,214} };
	Point2f dst[4] = { {0.f,0.f},{w,0.f},{0.f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for(int i = 0; i < 4; i++)
	{
		circle(img, src[i], 2, Scalar(0, 0, 255), FILLED);
	}


	imshow("image", img);
	imshow("image Warp", imgWarp);
	waitKey(0);
	return 0;
}