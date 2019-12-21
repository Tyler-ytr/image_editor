#include "mainwindow.h"
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

    Menu_init();
    Image_init();





}
void MainWindow:: Menu_init(){
    //菜单栏
    QMenu *mfile = menuBar()->addMenu(QStringLiteral("文件"));

    //file子菜单栏
    //QAction(const QIcon &icon, const QString &text, QObject *parent = nullptr)
    //新建
    QAction *afile_new=new QAction(QIcon("../picture/newer.png"),QStringLiteral("新建"),this);
    afile_new->setShortcut(QKeySequence::New);//快捷键
    connect(afile_new,SIGNAL(triggered()),this,SLOT(file_new()));

    //打开
    QAction *afile_open=new QAction(QIcon("../picture/fileopen.png"),QStringLiteral("打开"),this);
    afile_open->setShortcut(QKeySequence::Open);
    connect(afile_open,SIGNAL(triggered()),this,SLOT(file_open()));




    //添加动作到file菜单栏上面
    mfile->addAction(afile_new);
    mfile->addAction(afile_open);



    //工具栏
    QToolBar*toolBar=new QToolBar();
    toolBar->setMovable(false);
    addToolBar(toolBar);

    toolBar->addAction(afile_new);
    toolBar->addAction(afile_open);


    //Tips:
    afile_new->setStatusTip(QStringLiteral("新建"));



}
void MainWindow:: file_new(){
    QImage image=QImage(500,500,QImage::Format_RGB32);//创建图像
    image.fill(Qt::white);
    Image_label->setPixmap(QPixmap::fromImage(image));
    Image_label->resize(image.width(),image.height());
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
        Image_label->setPixmap(QPixmap::fromImage(*temp_image));
        Image_label->resize(temp_image->width(),temp_image->height());
        Image_path=temp_path;
    }
}


void MainWindow::Image_init(){

    Image_window=new QDockWidget(QStringLiteral("图像编辑框"),this);//初始化 Image_window
    setCentralWidget(Image_window);//居中

    //QLabel初始化 用来显示图像
    Image_label=new QLabel(Image_window);
    Image_label->setScaledContents(true);//自适应

    //初始化图像(全白)
    QImage image=QImage(500,500,QImage::Format_RGB32);//新建
    image.fill(Qt::white);
    Image_label->setPixmap((QPixmap::fromImage(image)));
    Image_label->resize(image.width(),image.height());//Imagelabel和图像一样大



    //滚动条
    QScrollArea * scrollArea=new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(Image_label);
    Image_window->setWidget(scrollArea);

}
