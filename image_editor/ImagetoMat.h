#ifndef IMAGETOMAT_H
#define IMAGETOMAT_H
#include <QtGui>
#include <QtWidgets>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>

using namespace cv;
//class QImage;
class ImagetoMat{
public:
    ImagetoMat();
    ~ImagetoMat();

    //将cv的格式转换成QImage
    static::QImage Mat_to_QImage(const Mat& mat);     // Mat 改成 QImage
    //将QImage的格式转换成cv的mat
    static::Mat QImage_to_Mat(QImage image);



};
#endif // IMAGETOMAT_H
