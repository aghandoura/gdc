#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace cv;

void undistord(Mat_<Vec3b>& src_image, Mat_<Vec3b>& dst_image, double correction)
{

    int width  = src_image.rows;
    int height = src_image.cols;
    int center_x = width / 2;
    int center_y = height / 2;
    int crX = 0; //x relative to center
    int crY = 0; //y relative to center
    double dist; 
    double angle; 
    int srcX; 
    int srcY; 
    double r;
    double correctionRadius;

    if (correction == 0)
    {
      correction = 1.0;
    }


    correctionRadius = sqrt(pow(width, 2) + pow(height, 2)) / correction;

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            crX = i - center_x; 
            crY = j - center_y;
            dist = sqrt(pow(crX, 2) + pow(crY, 2));
            r = dist / correctionRadius;

            if (r == 0.0)
                angle = 1;
            else
                angle = atan(r) / r;

            srcX = (int)floor(center_x + angle * crX );
            srcY = (int)floor(center_y + angle * crY );

            if (srcX>width) 
              srcX = width;

            if (srcY>height) 
              srcY = height;

            dst_image(i, j) [0] = src_image(srcX, srcY)[0]; //B
            dst_image(i, j) [1] = src_image(srcX, srcY)[1]; //G
            dst_image(i, j) [2] = src_image(srcX, srcY)[2]; //R
        }
    }
}

int main()
{
    Mat_<Vec3b> src_image;
    double correction = 4.1;
    string image_path;

    std::cout << "please enter input image path" << std::endl;
    std::cin >> image_path;
    std::cout << "please enter correction stregth value" << std::endl;
    std::cin >> correction;

    src_image = imread(image_path, 1);
    if (!src_image.data)
    {
        std::cout << "Could not open src image" << std::endl;
        return -1;
    }

    namedWindow("src Image", CV_WINDOW_NORMAL);
    imshow("src Image", src_image);

    Mat_<Vec3b> dst_image = src_image.clone();

    undistord(src_image, dst_image, correction);

    namedWindow("undistorted image", CV_WINDOW_NORMAL);
    imshow("undistorted image", dst_image);

    imwrite("./output.jpg", dst_image);

    waitKey(0);

    return 0;
}
