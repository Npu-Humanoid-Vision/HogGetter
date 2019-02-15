#include "HogGetter.h"

string trainPath = "./";

//遍历每个文件夹下的图片，并保存为fileList
// void getImages(string path, vector<string>& imagesList)
// {
//     intptr_t hFile = 0;
//     struct _finddata_t fileinfo;
//     string p;

//     hFile = _findfirst(p.assign(path).append("//*.cpp").c_str(), &fileinfo);

//     if (hFile != -1) {
//         do {
//             imagesList.push_back(fileinfo.name);//保存类名
//             } while (_findnext(hFile, &fileinfo) == 0);
//     }
// }

//列出一个目录下所有文件
void scan_one_dir( const char * dir_name) {  
    if( NULL == dir_name ) {  
        cout<<" dir_name is null ! "<<endl;
        return;
    }

    struct stat s;  
    lstat( dir_name , &s );  
    if( ! S_ISDIR( s.st_mode ) )  {
        return;
    }
      
    struct dirent * filename;
    DIR * dir;
    dir = opendir( dir_name );  
    if( NULL == dir )  {  
        return;  
    }  

    int iName=0;
    while( ( filename = readdir(dir) ) != NULL ) {  
        if( strcmp( filename->d_name , "." ) == 0 ||
            strcmp( filename->d_name , "..") == 0)
            continue;

        char wholePath[128] = {0};
        sprintf(wholePath, "%s/%s", dir_name, filename->d_name);

        cout << "wholePath= " << wholePath << endl;
    }
}

int main(int argc, char const *argv[]) {
    // vector<string> fileLists;
    // // getAllImages(trainPath, fileLists);
    // getImages(trainPath, fileLists);

    // for (auto p = fileLists.begin(); p != fileLists.end(); p++)
    //     cout << *p << endl;
    // HogGetter hg;
    
    // tested image_reader

    // hg.ImageReader_("D:/baseRelate/code/svm_trial/BackUpSource/Triangle/RawImgs/", "*.jpg");
    // cout<<hg.raw_images_.size()<<endl;
    // for (auto img_ptr = hg.raw_images_.begin(); img_ptr != hg.raw_images_.end(); img_ptr++) {
        // cv::imshow("233", *img_ptr);
    //     cv::Mat image = img_ptr->clone();
    //     cv::imshow("322", hg.RandomCutter_(image));
    //     cv::waitKey();
    
        

        // cv::imshow("244", *img_ptr);
        // cv::waitKey(50);
    // }
    // Sleep(1000);
    // cv::Mat t = hg.HogComputter_();
    // cout<<hg.feature_vector_dimesion_<<endl;
    // cout<<hg.sample_nums_<<endl;
#ifdef __linux__    // gun cpp 环境 
    cout<<"ye"<<endl;
    scan_one_dir(".");
#endif
#ifdef _WIN32       // mingw 环境
    cout<<"ya"<<endl;
#endif
    return 0;
}