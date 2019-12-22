#include "Color.h"



Colorchange::Colorchange(){
    ;
}



Colorchange::~Colorchange(){
    ;
}
QImage Colorchange::Gray(QImage image){
    Mat src,dst;
    src=ImagetoMat::QImage_to_Mat(image);
    cvtColor(src,dst,COLOR_BGR2GRAY);
    QImage result=ImagetoMat::Mat_to_QImage(dst);
    return result;

}
QImage Colorchange::Binary(QImage image){
;
    Mat src,dst1,dst2;
    src=ImagetoMat::QImage_to_Mat(image);
    cvtColor(src,dst1,COLOR_BGR2GRAY);

    threshold(dst1, dst2, 100, 255, THRESH_BINARY);
    QImage result=ImagetoMat::Mat_to_QImage(dst2);
    return result;

}
QImage Colorchange:: Reversal(QImage image){
    Mat src,dst;
    src=ImagetoMat::QImage_to_Mat(image);
    //dst=255-src;
//    dst=src.clone();

//    for(int i=0;i<src.rows;i++){
//        for(int j=0;j<src.cols;j++){
//            Vec3b pixel=src.at<Vec3b>(i,j);
//            for(int k=0;k<3;k++){
//                pixel[k]=255-pixel[k];
//            }
//            dst.at<Vec3b>(i,j)=pixel;
//        }
//    }
//    QImage result=ImagetoMat::Mat_to_QImage(dst);
//    return result;

    bitwise_xor(src,Scalar(255),dst);
    QImage result=ImagetoMat::Mat_to_QImage(dst);
    return result;
}
