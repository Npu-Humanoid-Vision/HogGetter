#ifndef HOG_GETTER_H
#define HOG_GETTER_H

#include "debug.h"

#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class HogGetter {
public:
    enum {
        POS_LABLE = 1,
        NEG_LABLE ,
        HARD_LABLE
    };
    HogGetter() {
        hog_scriptor_ = cv::HOGDescriptor(Size(64,128),Size(16,16),Size(8,8),Size(8,8),9);
    }
    ~HogGetter() {}
private:// 数据成员
    cv::HOGDescriptor hog_scriptor_; // hog检测器
    cv::Size window_size_;           // 检测窗口的大小，即待检测图片的大小
    cv::Size cell_size_;             // cell
    cv::Size block_size_;            // block
    cv::Size block_stride_;          // block 滑动的步长，注意需要两个方向
    int hist_bins_;                  // 直方图的 bin 个数
public:// 设置数据成员的接口
    void set_scriptor(const cv::HOGDescriptor&);    // 直接给一个检测器 
    void set_window_size(const cv::Size&);           
    void set_cell_size(const cv::Size&);
    void set_block_size(const cv::Size&);
    void set_block_stride(const cv::Size&);
    void set_nbins(const int&);
};

#endif