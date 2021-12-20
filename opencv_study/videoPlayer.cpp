#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

int main()
{
	cv::VideoCapture vc("./test.mp4");
	if (vc.isOpened() != true)
	{
		std::cout << "open video file failed!\n";
		return -1;
	}

	int idx = 0;
	cv::Mat mat;
	vc >> mat;
	while (mat.empty() == false)
	{
		cv::Mat dst;
		// cv::Canny(mat, dst, 17, 45);
		cv::cvtColor(mat, dst, cv::COLOR_RGB2GRAY);
		cv::imshow("mat", dst);
		cv::waitKey(1);
		vc >> mat;
	}

	return 0;
}
