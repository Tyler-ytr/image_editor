﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWidgets>
#include "opencv2/opencv.hpp"
//#pragma execution_character_set("utf-8")
using namespace cv;
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();



      // helloworld();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::helloworld(){
    QPushButton *button = new QPushButton(this);
    button->setText(tr("Hello!"));
button->move(100,100) ;
connect(button,SIGNAL(clicked()),this,SLOT(iSlot()));
}

void MainWindow::iSlot()                       // 槽函数
{
    QMessageBox::information(this, tr("hello"), tr("Hello World!"));
}
void MainWindow::init(){
    //图标和标题;
    setWindowIcon(QIcon("../picture/icon.png"));
    setWindowTitle(QStringLiteral("图片编辑器 by Larry"));
    //界面大小和位置
    resize(QApplication::desktop()->width()*0.9, QApplication::desktop()->height()*0.9);
    move(QApplication::desktop()->width()*0.05, QApplication::desktop()->height()*0.05);



    layout_init();
    Menu_init();
    Tool_init();
    Image_init();
    Color_init();

}
void MainWindow:: Menu_init(){
    //菜单栏
    QMenu *mfile = menuBar()->addMenu(QStringLiteral("文件"));

    //file子菜单栏
    //QAction(const QIcon &icon, const QString &text, QObject *parent = nullptr)
    //新建
   // QAction *afile_new=new QAction(QIcon("../picture/painter.jpg"),QStringLiteral("新建"),this);
    QAction *afile_new=new QAction(QIcon("../picture/newer.png"),QStringLiteral("新建"),this);
    afile_new->setShortcut(QKeySequence::New);//快捷键
    connect(afile_new,SIGNAL(triggered()),this,SLOT(file_new()));

    //打开
    QAction *afile_open=new QAction(QIcon("../picture/fileopen.png"),QStringLiteral("打开"),this);
    afile_open->setShortcut(QKeySequence::Open);
    connect(afile_open,SIGNAL(triggered()),this,SLOT(file_open()));

    //保存
    QAction *afile_save=new QAction(QIcon("../picture/save.png"),QStringLiteral("保存"),this);
    afile_save->setShortcut(QKeySequence::Save);
    connect(afile_save,SIGNAL(triggered()),this,SLOT(file_save()));

    //另存为
    QAction *afile_saveas=new QAction(QIcon("../picture/saveas.png"),QStringLiteral("另存为"),this);
    afile_saveas->setShortcut(QKeySequence::SaveAs);
    connect(afile_saveas,SIGNAL(triggered()),this,SLOT(file_saveas()));





    //添加动作到file菜单栏上面
    mfile->addAction(afile_new);
    mfile->addAction(afile_open);
    mfile->addAction(afile_save);
    mfile->addAction(afile_saveas);



    //工具栏
    QToolBar*toolBar=new QToolBar();
    toolBar->setMovable(false);
    addToolBar(toolBar);

    toolBar->addAction(afile_new);
    toolBar->addAction(afile_open);
    toolBar->addAction(afile_save);



    //Tips:
    afile_new->setStatusTip(QStringLiteral("新建图像"));
    afile_open->setStatusTip(QStringLiteral("打开文件"));
    afile_save->setStatusTip(QStringLiteral("保存文件"));




}
void MainWindow:: file_new(){
    QImage image=QImage(500,500,QImage::Format_RGB32);//创建图像
    image.fill(Qt::white);
    Image_show(image,true);
    //Image_label->setPixmap(QPixmap::fromImage(image));
    //Image_label->resize(image.width(),image.height());
    Image_path="";//路径为空;

}
void MainWindow::file_open(){

    QString temp_path=QFileDialog::getOpenFileName(this,QStringLiteral("选择图像"),".",tr("Images(*.jpg *.png *.bmp)"));
    if(!temp_path.isEmpty()){
        QImage* temp_image=new QImage();
        if(!(temp_image->load(temp_path))){
            QMessageBox::information(this,QStringLiteral("Wrong"),QStringLiteral("打开图像失败"));
            delete temp_image;
            return;
        }
//        Image_label->setPixmap(QPixmap::fromImage(*temp_image));
//        Image_label->resize(temp_image->width(),temp_image->height());
        Image_show(*temp_image,true);
        Image_path=temp_path;
    }
}
void MainWindow::file_save(){
    if(Image_path.isEmpty()){//新建就保存它
        QString temp_path=QFileDialog::getSaveFileName(this,QStringLiteral("保存图像"),".",tr("Images(*.jpg *.png *.bmp)"));
        if(!(temp_path.isEmpty())){
            //Image_path=temp_path;
            QImage temp_image=Image_label->getImage();
            temp_image.save(temp_path);
            Image_path=temp_path;
            Image_show(temp_image,true);

        }
    }else{
        QImage temp_image=Image_label->getImage();
        temp_image.save(Image_path);
        Image_show(temp_image,true);
    }
//    QImage temp_image=Image_label->pixmap()->toImage();//读取
//    temp_image.save(Image_path);
}
void MainWindow::file_saveas(){
     QString temp_path=QFileDialog::getSaveFileName(this,QStringLiteral("保存图像"),".",tr("Images(*.jpg *.png *.bmp)"));
    if(!(temp_path.isEmpty())){
        QImage temp_image=Image_label->getImage();
        temp_image.save(temp_path);
        Image_path=temp_path;
        Image_show(temp_image,true);
//        QImage temp_image=Image_label->pixmap()->toImage();//读取
//        temp_image.save(temp_path);
//        Image_path=temp_path;
    }
}


void MainWindow::Image_init(){

    //Image_window=new QDockWidget(QStringLiteral("图像编辑框"),this);//初始化 Image_window
    setCentralWidget(Image_window);//居中

    //QLabel初始化 用来显示图像
    Image_label=new PaintWidget(Image_window);
    Image_label->setScaledContents(true);//自适应

    //初始化图像(全白)
    QImage image=QImage(500,500,QImage::Format_RGB32);//新建
    image.fill(Qt::white);
    Image_label->setPenWidth(1);//默认笔宽
    Image_label->setPenColor(Qt::black);
    Image_label->setPixmap(QPixmap::fromImage(image));
//    Image_label->setPixmap((QPixmap::fromImage(image)));
//    Image_label->resize(image.width(),image.height());//Imagelabel和图像一样大



    //滚动条
    QScrollArea * scrollArea=new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(Image_label);
    Image_window->setWidget(scrollArea);

}
void MainWindow::Image_show(QImage Img, bool isSave){
    Image_label->setImage(Img);
    Image_label->setPixmap(QPixmap::fromImage(Img));
    Image_label->resize(Img.width(),Img.height());
//    if(isSave==true){

//    }
}

void MainWindow::layout_init(){

    QWidget* p = takeCentralWidget();	//删除中央窗体
        if (p)
            delete p;
    setDockNestingEnabled(true);		//允许嵌套dock

    Image_window=new QDockWidget(QStringLiteral("图像编辑框"),this);//初始化 Image_window
    Image_window->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);//可以移动可以浮动，不能关闭
    Image_window->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);//可以左右移动
    Image_window->setMinimumSize(500,500);//最小长宽高

    Shape_window=new QDockWidget(QStringLiteral("形状处理"),this);
    Gray_window=new QDockWidget(QStringLiteral("灰度处理"),this);
    Tool_window=new QDockWidget(QStringLiteral("工具栏"),this);

    setCentralWidget(Image_window);
    addDockWidget(Qt::TopDockWidgetArea,Tool_window);
    addDockWidget(Qt::RightDockWidgetArea,Gray_window);
    addDockWidget(Qt::RightDockWidgetArea,Shape_window);
    //合并
    tabifyDockWidget(Gray_window,Shape_window);

}
void MainWindow::Tool_init(){
    //画笔
    QPushButton *pen_button=new QPushButton(QIcon("../picture/painter.png"),tr(""),this);
    pen_button->setToolTip(QStringLiteral("画笔"));
    pen_button->setObjectName("toolButton");
    pen_button->setFixedSize(30,30);//设置小部件长宽高

    //直线
    QPushButton *line_button=new QPushButton(QIcon("../picture/line.png"),tr(""),this);
    line_button->setToolTip(QStringLiteral("直线"));
    line_button->setObjectName("toolButton");
    line_button->setFixedSize(30,30);

    //矩形

    QPushButton *rec_button=new QPushButton(QIcon("../picture/rec.png"),tr(""),this);
    rec_button->setToolTip(QStringLiteral("矩形"));
    rec_button->setObjectName("toolButton");
    rec_button->setFixedSize(30,30);

    //六边形
    QPushButton *hex_button=new QPushButton(QIcon("../picture/hex.png"),tr(""),this);
    hex_button->setToolTip(QStringLiteral("矩形"));
    hex_button->setObjectName("toolButton");
    hex_button->setFixedSize(30,30);


    //圆形
    QPushButton *cycle_button=new QPushButton(QIcon("../picture/round.png"),tr(""),this);
    cycle_button->setToolTip(QStringLiteral("圆形"));
    cycle_button->setObjectName("toolButton");
    cycle_button->setFixedSize(30,30);

    //按钮布局设置
    QGridLayout *tools_layout=new QGridLayout();
    tools_layout->setAlignment(Qt::AlignLeft);//水平靠左对齐
    tools_layout->addWidget(pen_button,0,0);
    tools_layout->addWidget(line_button,0,1);
    tools_layout->addWidget(rec_button,0,2);
    tools_layout->addWidget(hex_button,0,3);
    tools_layout->addWidget(cycle_button,0,4);

    //加入Tool_window
    QWidget *tools_widget=new QWidget(Tool_window);
    tools_widget->setLayout(tools_layout);
    Tool_window->setWidget(tools_widget);

    //按钮组
    toolbuttons=new QButtonGroup();
    toolbuttons->addButton(pen_button,1);
    toolbuttons->addButton(line_button,2);
    toolbuttons->addButton(rec_button,3);
    toolbuttons->addButton(hex_button,4);
    toolbuttons->addButton(cycle_button,5);


    //连接槽函数
    connect(toolbuttons,SIGNAL(buttonClicked(int)),this,SLOT(tool_clicked(int)));


}

void MainWindow::tool_clicked(int type){
    QList<QAbstractButton*>buttons=toolbuttons->buttons();
    foreach(QAbstractButton *button,buttons){
        if(toolbuttons->button(type)!=button){
            button->setChecked(false);//互斥
        }else if(tooltype==type){
            tooltype=0;//点两次取消;
        }else{
            tooltype=type;
        }

    }


    switch (tooltype){
    case 0:
        Image_label->setShape(PaintWidget::null_state);
            //QMessageBox::information(this,QStringLiteral("画笔没有做!"),QStringLiteral("退出绘制"));
        break;
    case 1:
            //QMessageBox::information(this,QStringLiteral("画笔没有做!"),QStringLiteral("画笔"));
        Image_label->setShape(PaintWidget::Pen);
        break;
    case 2:
           //QMessageBox::information(this,QStringLiteral("直线没有做!"),QStringLiteral("直线"));
        Image_label->setShape(PaintWidget::Line);
        break;
    case 3:
       // QMessageBox::information(this,QStringLiteral("直线没有做!"),QStringLiteral("矩形"));
        Image_label->setShape(PaintWidget::Rec);
        break;
    case 4:
       // QMessageBox::information(this,QStringLiteral("直线没有做!"),QStringLiteral("六边形"));
        Image_label->setShape(PaintWidget::Hex);
        break;
    case 5:
        //QMessageBox::information(this,QStringLiteral("直线没有做!"),QStringLiteral("圆"));
        Image_label->setShape(PaintWidget::Cycle);
        break;
    default:
        break;


    }


}


void MainWindow::Color_init(){
   Color_bar=new QToolBar();
   Color_bar=addToolBar(QStringLiteral("画笔属性栏"));
   Color_bar->setMovable(true);

   QLabel *label_penWidth = new QLabel(QStringLiteral("画笔宽度"));
   spinbox_penWidth = new QSpinBox;
   spinbox_penWidth->setRange(1, 50);
   spinbox_penWidth->setValue(2);

   QPushButton *color_botton=new QPushButton(QStringLiteral("画笔颜色"));
   //取色框
   frame_color = new QFrame;
   frame_color->setObjectName("colorFrame");
   frame_color->setFrameShape(QFrame::Box);
   frame_color->setPalette(QPalette(Qt::black));
   frame_color->setAutoFillBackground(true);
   frame_color->setFixedSize(30, 30);
   frame_color->setStyleSheet("QFrame{background-color: rgba(" + QString::number(0) + "," + QString::number(0) + "," + QString::number(0) + ",1);border:none}");

   //槽函数
   connect(spinbox_penWidth, SIGNAL(valueChanged(int)), this, SLOT(pen_width()));
   connect(color_botton,SIGNAL(clicked()), this, SLOT(pen_color()));

    QHBoxLayout *color_layout = new QHBoxLayout();//水平布局
    color_layout->setAlignment(Qt::AlignLeft);

    color_layout->addWidget(label_penWidth);
    color_layout->addWidget(spinbox_penWidth);
    color_layout->addWidget(color_botton);
    color_layout->addWidget(frame_color);

    QWidget *color_Widget=new QWidget();
    color_Widget->setLayout(color_layout);
    Color_bar->addWidget(color_Widget);






}
void MainWindow::pen_width(){
    int x=spinbox_penWidth->text().toInt();
    Image_label->setPenWidth(x);

}
void MainWindow::pen_color(){
    QColor c = QColorDialog::getColor(Qt::yellow);
    if (c.isValid())
        {
            frame_color->setPalette(QPalette(c));
            Image_label->setPenColor(c);
            frame_color->setStyleSheet("QFrame{background-color: rgba(" + QString::number(c.red()) + "," + QString::number(c.green()) + "," + QString::number(c.blue()) + ",1);border:none}");
        }
}



