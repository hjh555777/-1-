#include <opencv2/opencv.hpp>
#include "hw2/myhw2.h"

int main()
{
    cv::Mat src = cv::imread("test.jpg");
    if(src.empty())
    {
        printf("图片读取失败\n");
        return -1;
    }
    cv::Mat dst;
    grayWorldCorrect(src, dst);

    cv::imshow("原图", src);
    cv::imshow("灰度世界矫正结果", dst);
    cv::waitKey(0);
    return 0;
}