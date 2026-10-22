#include "myhw2.h"

void grayWorldCorrect(cv::Mat &src, cv::Mat &dst)
{
    dst = src.clone();
    std::vector<cv::Mat> channels;
    cv::split(src, channels);
    cv::Mat B = channels[0];
    cv::Mat G = channels[1];
    cv::Mat R = channels[2];

    // 计算三个通道平均值
    double meanB = cv::mean(B)[0];
    double meanG = cv::mean(G)[0];
    double meanR = cv::mean(R)[0];

    double grayMean = (meanB + meanG + meanR) / 3.0;

    // 增益系数
    double kb = grayMean / meanB;
    double kg = grayMean / meanG;
    double kr = grayMean / meanR;

    // 通道乘增益
    B = B * kb;
    G = G * kg;
    R = R * kr;

    cv::merge(std::vector<cv::Mat>{B, G, R}, dst);
}
