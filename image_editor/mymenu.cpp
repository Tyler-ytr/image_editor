
//#include "mymenu.h"
//Mymenu::Mymenu(QWidget * par,MainWindow* p):QMenuBar(par){

//    mymainwindow=p;

//    mytoolbar=new QToolBar();
//    mytoolbar=mymainwindow->addToolBar(QStringLiteral("文件工具栏"));
//    mytoolbar->setMovable(false);


//   file_Menu_init();



//}
//void Mymenu:: file_Menu_init(){
//    //新建
//    QAction *afile_new=new QAction(QIcon("../picture/newer.png"),QStringLiteral("新建"),this);
//    afile_new->setShortcut(QKeySequence::New);//快捷键
//    connect(afile_new,SIGNAL(triggered()),this,SLOT(file_new()));

//    //打开
//    QAction *afile_open=new QAction(QIcon("../picture/fileopen.png"),QStringLiteral("打开"),this);
//    afile_open->setShortcut(QKeySequence::Open);
//    connect(afile_open,SIGNAL(triggered()),this,SLOT(file_open()));

//    //保存
//    QAction *afile_save=new QAction(QIcon("../picture/save.png"),QStringLiteral("保存"),this);
//    afile_save->setShortcut(QKeySequence::Save);
//    connect(afile_save,SIGNAL(triggered()),this,SLOT(file_save()));

//    //另存为
//    QAction *afile_saveas=new QAction(QIcon("../picture/saveas.png"),QStringLiteral("另存为"),this);
//    afile_saveas->setShortcut(QKeySequence::SaveAs);
//    connect(afile_saveas,SIGNAL(triggered()),this,SLOT(file_saveas()));

//}
//void Mymenu:: file_new(){
//    QImage image=QImage(500,500,QImage::Format_RGB32);//创建图像
//    image.fill(Qt::white);
//    Image_label->setPixmap(QPixmap::fromImage(image));
//    Image_label->resize(image.width(),image.height());
//    Image_path="";//路径为空;

//}
//void Mymenu::file_open(){

//    QString temp_path=QFileDialog::getOpenFileName(this,QStringLiteral("选择图像"),".",tr("Images(*.jpg *.png *.bmp)"));
//    if(!temp_path.isEmpty()){
//        QImage* temp_image=new QImage();
//        if(!(temp_image->load(temp_path))){
//            QMessageBox::information(this,QStringLiteral("Wrong"),QStringLiteral("打开图像失败"));
//            delete temp_image;
//            return;
//        }
//        Image_label->setPixmap(QPixmap::fromImage(*temp_image));
//        Image_label->resize(temp_image->width(),temp_image->height());
//        Image_path=temp_path;
//    }
//}
//void Mymenu::file_save(){
//    if(Image_path.isEmpty()){//新建就保存它
//        QString temp_path=QFileDialog::getSaveFileName(this,QStringLiteral("保存图像"),".",tr("Images(*.jpg *.png *.bmp)"));
//        if(!(temp_path.isEmpty())){
//            Image_path=temp_path;
//        }
//    }
//    QImage temp_image=Image_label->pixmap()->toImage();//读取
//    temp_image.save(Image_path);
//}
//void Mymenu::file_saveas(){
//    QString temp_path=QFileDialog::getSaveFileName(this,QStringLiteral("另存为图像"),".",tr("Images(*.jpg *.png *.bmp)"));
//    if(!(temp_path.isEmpty())){
//        QImage temp_image=Image_label->pixmap()->toImage();//读取
//        temp_image.save(Image_path);
//        Image_path=temp_path;
//    }
//}

//v
