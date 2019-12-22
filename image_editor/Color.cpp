#include "Color.h"
#include <vector>


Colorchange::Colorchange(){
    ;
}



Colorchange::~Colorchange(){
    ;
}
Mat convert_to_threechannels(const Mat&binImg){
    Mat three_channel = Mat::zeros(binImg.rows,binImg.cols,CV_8UC3);
       std::vector<Mat> channels;
        for (int i=0;i<3;i++)
        {
            channels.push_back(binImg);
        }
        merge(channels,three_channel);
        return three_channel;

}
QImage Colorchange::Gray(QImage image){
    Mat src,dst;
    src=ImagetoMat::QImage_to_Mat(image);
    if (src.channels() != 1){
    cvtColor(src,dst,COLOR_BGR2GRAY);
    }
    else{
        dst=src.clone();
    }
    Mat three_channel=convert_to_threechannels(dst);
   // return three_channel;


    QImage result=ImagetoMat::Mat_to_QImage(three_channel);
   // QImage result=ImagetoMat::Mat_to_QImage(dst);


    return result;

}

QImage Colorchange::Binary(QImage image){
;
    Mat src,dst1,dst2;
    src=ImagetoMat::QImage_to_Mat(image);
    if (src.channels() != 1){
    cvtColor(src,dst1,COLOR_BGR2GRAY);
    }
    else{
        dst1=src.clone();
    }
    threshold(dst1, dst2, 100, 255, THRESH_BINARY);
    Mat three_channel=convert_to_threechannels(dst2);
    QImage result=ImagetoMat::Mat_to_QImage(three_channel);
    return result;

}
QImage Colorchange:: Reversal(QImage image){
    Mat src,dst;
    src=ImagetoMat::QImage_to_Mat(image);
    if(src.channels()==1){
        Mat src1=convert_to_threechannels(src);
        bitwise_xor(src1,Scalar(255),dst);
    }else{
        bitwise_xor(src,Scalar(255),dst);
    }


    //bitwise_xor(src,Scalar(255),dst);
  //  Mat three_channel=convert_to_threechannels(dst);
    if(dst.channels()==1){
        Mat three_channel=convert_to_threechannels(dst);
        QImage result=ImagetoMat::Mat_to_QImage(three_channel);
        return result;
    }
    QImage result=ImagetoMat::Mat_to_QImage(dst);
    return result;
}
