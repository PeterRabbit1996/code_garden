#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

int main()
{
	cv::Mat mat_test = cv::imread("test.png");
	if (mat_test.data == nullptr)
	{
		perror("picture is not exited!\n");
		exit(-1);
	}

	cv::imshow("mat_test", mat_test);
	cv::waitKey(0);

	exit(0);
}
