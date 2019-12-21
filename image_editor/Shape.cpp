#include "Shape.h"

Shape::Shape(){
    ;
}
Shape::~Shape(){
    ;
}
QImage Shape::Resize(QImage image, int length, int width){
    Mat matSrc, matDst;
    matSrc = ImagetoMat::QImage_to_Mat(image);
    resize(matSrc,matDst,Size(length,width),0,0,INTER_LINEAR);
    QImage tmp=ImagetoMat::Mat_to_QImage(matDst);
    return tmp;

    ;
}
QImage Shape::Scale(QImage image, int times){
    QImage tmp=QImage();
    return tmp;;
}
QImage Shape::Rotate(QImage image, int angle){
    QImage tmp=QImage();
    return tmp;;
}
