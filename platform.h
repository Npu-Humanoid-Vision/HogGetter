#define private public  // just for fun
#define protected public

#ifdef _WIN32 // mingw 环境 _WIN64 是 ming64

#include <io.h>
#include <windows.h>

#endif

#ifdef __linux__ // gun 环境

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#endif


#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

// define functions to get all files' name under the paths
#ifdef __WIN32

#endif
#ifdef __linux__

#endif