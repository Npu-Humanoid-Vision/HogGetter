#include "HogGetter.h"

void HogGetter::set_scriptor(const cv::HOGDescriptor& d) {
    hog_scriptor_ = d;
    window_size_ = hog_scriptor_.winSize;
    cell_size_ = hog_scriptor_.cellSize;
    block_size_ = hog_scriptor_.blockSize;
    block_stride_ = hog_scriptor_.blockStride;
    hist_bins_ = hog_scriptor_.nbins;
}

void HogGetter::set_window_size(const cv::Size& s) {
    window_size_ = s;
    hog_scriptor_ = HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
} 

void HogGetter::set_cell_size(const cv::Size& s) {
    cell_size_ = s;
    hog_scriptor_ = HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
}

void HogGetter::set_block_size(const cv::Size& s) {
    block_size_ = s;
    hog_scriptor_ = HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
} 

void HogGetter::set_block_stride(const cv::Size& s) {
    block_stride_ = s;
    hog_scriptor_ = HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
} 

void HogGetter::set_nbins(const int& i) {
    hist_bins_ = i;
    hog_scriptor_ = HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
}
