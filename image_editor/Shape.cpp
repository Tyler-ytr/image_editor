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
QImage Shape::Scale(QImage image, double scale){
    //https://blog.csdn.net/guyuealian/article/details/85097633#2.3%20INTER_LINEAR(%E7%BA%BF%E6%80%A7%E6%8F%92%E5%80%BC)
//    QImage tmp=QImage();
//    return tmp;;
    Mat src,dst;
    if(scale==1.0){
        return image;
    }
    else {
        src=ImagetoMat::QImage_to_Mat(image);
        if(scale>1.0){
            resize(src,dst,Size(),scale,scale,INTER_CUBIC);

    }else{
            resize(src,dst,Size(),scale,scale,INTER_AREA);
        }
        QImage result=ImagetoMat::Mat_to_QImage(dst);
        return result;
    }



}
QImage Shape::Rotate(QImage image, int angle){


    Mat src,dst;
    src=ImagetoMat::QImage_to_Mat(image);
    cv::Size dst_sz(src.cols, src.rows);
    Point2f center(static_cast<float>(src.cols / 2.), static_cast<float>(src.rows / 2.));
    Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0);
    warpAffine(src, dst, rot_mat, dst_sz, cv::INTER_LINEAR, cv::BORDER_REPLICATE);

    QImage result=ImagetoMat::Mat_to_QImage(dst);
    return result;

}
QImage Shape::Flip(QImage image, int type){
    Mat src,dst;
    src=ImagetoMat::QImage_to_Mat(image);
    switch (type){
        case 0:
            flip(src,dst,0);//x
            break;
        case 1:
            flip(src,dst,1);//y
            break;
        case 2:
            flip(src,dst,-1);
            break;
        default:
            dst=src;
        break;
    }
    QImage result=ImagetoMat::Mat_to_QImage(dst);
    return result;

}
