#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include "opencv2/opencv.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		return -1;
	}

	std::string file_name(argv[1]);

	cv::VideoCapture vc(file_name.c_str());
	if (vc.isOpened() != true)
	{
		std::cout << "open video file failed!\n";
		return -1;
	}

	cv::Mat mat;
	int cur_frame_idx;
	bool is_start = true;
	bool play_by_step = false;
	char c;

	std::thread td_key([&play_by_step, &is_start, &c, &cur_frame_idx, &mat, &vc]()
					   {
		while (true)
		{
			c = cv::waitKey(1);
			cur_frame_idx = vc.get(cv::CAP_PROP_POS_FRAMES);
			if (c == 'f')
			{
				// vc.set(cv::CAP_PROP_POS_FRAMES, ++cur_frame_idx);
				play_by_step = true;
			}
			else if (c == 'b')
			{
				cur_frame_idx -= 2;
				vc.set(cv::CAP_PROP_POS_FRAMES, cur_frame_idx);
				play_by_step = true;
			}
			else if (c == 's')
			{
				is_start = !is_start;
			}
			else if (c == 'q')
			{
				exit(0);
			}
			else
			{
				// do nothing
			}
		} });

	while (true)
	{
		if (play_by_step == true)
		{
			play_by_step = false;
			continue;
		}

		if (!is_start)
		{
			continue;
		}

		vc >> mat;
		if (mat.empty())
		{
			break;
		}

		cv::imshow("mat", mat);
	}

	return 0;
}
