#ifndef SHAPE_H
#define SHAPE_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc.hpp"

#include "ImagetoMat.h"
using namespace cv;
class Shape{

public:
    Shape();
    ~Shape();

    static QImage Resize(QImage image,int length,int width);//改变大小
    static QImage Scale(QImage image,double scale);//缩放
    static QImage Rotate(QImage image,int angle);//旋转
    static QImage Flip(QImage image,int type);//type=0:x轴;1 y轴;2 xy;


//private:
//   // ImagetoMat*imgchange;


};









#endif // SHAPE_H
