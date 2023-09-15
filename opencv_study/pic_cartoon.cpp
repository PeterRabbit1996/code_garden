// #include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("test.jpeg");
    if (img.empty())
        exit(-1);
    Mat imgMedian;
    medianBlur(img, imgMedian, 7);
    imshow("medianBlur", imgMedian); // 中值滤波去除噪声
    Mat imgCanny;
    Canny(imgMedian, imgCanny, 20, 150);
    imshow("imgCanny", imgCanny); // 用Canny检测边缘
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgCanny, kernel);
    imshow("边缘膨胀", imgCanny); // 用于边缘膨胀
    imgCanny = imgCanny / 255;
    imgCanny = 1 - imgCanny; // 边缘值缩放到1，并将值反转
    Mat imgCannyf;
    imgCanny.convertTo(imgCannyf, CV_32FC3);
    blur(imgCannyf, imgCannyf, Size(5, 5)); // 模糊边缘实现平滑效果
    Mat imgBF;
    bilateralFilter(img, imgBF, 9, 150.0, 150.0); // 色彩均匀化
    Mat result = imgBF / 25;
    result = result * 25;
    imshow("result01", result);
    Mat imgCanny3c;
    Mat cannyChannels[] = {imgCannyf, imgCannyf, imgCannyf};
    merge(cannyChannels, 3, imgCanny3c);
    Mat resultf;
    result.convertTo(resultf, CV_32FC3);
    imshow("resultf", resultf);
    multiply(resultf, imgCanny3c, resultf);
    imshow("result02", result);
    resultf.convertTo(result, CV_8UC3);
    imshow("卡通效果", result);

    waitKey(0);
    return 0;
}