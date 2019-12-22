#ifndef COLOR_H
#define COLOR_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc.hpp"
#include "ImagetoMat.h"
using namespace cv;
class Colorchange{
public:
    Colorchange();
    ~Colorchange();

    static QImage Gray(QImage image);
    static QImage Binary(QImage image);
    static QImage Reversal(QImage image);



};





#endif // COLOR_H
