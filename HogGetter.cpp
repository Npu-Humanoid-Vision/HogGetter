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
    hog_scriptor_ = cv::HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
} 

void HogGetter::set_cell_size(const cv::Size& s) {
    cell_size_ = s;
    hog_scriptor_ = cv::HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
}

void HogGetter::set_block_size(const cv::Size& s) {
    block_size_ = s;
    hog_scriptor_ = cv::HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
} 

void HogGetter::set_block_stride(const cv::Size& s) {
    block_stride_ = s;
    hog_scriptor_ = cv::HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
} 

void HogGetter::set_nbins(const int& i) {
    hist_bins_ = i;
    hog_scriptor_ = cv::HOGDescriptor(window_size_, block_size_, block_stride_, cell_size_, hist_bins_);
}

void HogGetter::ImageReader_(const string& folder_path, const string& postfix = "/*.jpg") {
    __int64 file_handle = 0;
    struct _finddata_t file_info;
    string image_path;
    file_handle = _findfirst(image_path.assign(folder_path).append(postfix).c_str(), &file_info);
    cout<<image_path<<endl;
    if (file_handle != -1) {
        do {
            raw_images_.push_back(cv::imread(folder_path + file_info.name));
            cout<<raw_images_.size()<<endl;
        } while (_findnext(file_handle, &file_info) == 0);
    }

    _findclose(file_handle);
}

cv::Mat HogGetter::RandomCutter_(cv::Mat image) {
    if (image.cols < window_size_.width 
     || image.rows < window_size_.height) {
        cerr<<"Error:"<<__FILE__
                <<":line"<<__LINE__<<endl
                <<"     Complied on"<<__DATE__
                <<"at"<<__TIME__<<endl;
        return cv::Mat();
    }
    else if(image.cols == window_size_.width 
     || image.rows == window_size_.height) {
         return image;
    }

    int cols_margin = window_size_.width - image.cols;
    int rows_margin = window_size_.height - image.rows;

    cv::Rect rect;
    srand((int) time(0));
    
    rect.x = rand() % cols_margin;
    rect.y = rand() % rows_margin;
    rect.width = window_size_.width;
    rect.height = window_size_.height;

    return (image(rect).clone());
}

cv::Mat HogGetter::HogComputter_() {

    vector<float> descrip_vec;

    for (std::vector<cv::Mat>::iterator iter = raw_images_.begin();
        iter != raw_images_.end(); iter++) {
        
        // cv::imshow("233", *iter);
        // cv::waitKey();
        cv::Mat t_img = RandomCutter_((*iter));
        (*iter) = t_img;

        hog_scriptor_.compute(*iter, descrip_vec);

        if (iter == raw_images_.begin()) {
            sample_features_ = cv::Mat::zeros(raw_images_.size(), descrip_vec.size(), CV_32FC1);

            // 对训练数据相关的数据进行初始化
            feature_vector_dimesion_ = (int)descrip_vec.size();
            sample_nums_ = raw_images_.size();
        }
        else {
            for (int i = 0; i < descrip_vec.size(); i++) {
                sample_features_.at<float>(iter-raw_images_.begin(), i) = descrip_vec[i];
                // cout<<descrip_vec[i]<<' ';
            }
            // cout<<endl;
        }
    }
    cout<<"All the Computed images num: "<< sample_nums_<<endl;
    cout<<"Hog Features' vector dim: "<<feature_vector_dimesion_<<endl;
    cout<<"Feature Mat size: "<<sample_features_.size()<<endl;
    return sample_features_;
}