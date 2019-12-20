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
    //waiting for ^_^
    ;
}
void MainWindow::file_open(){
    //waiting for ……
    ;
}
