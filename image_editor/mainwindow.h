#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include "PaintWidget.h"
#include "ImagetoMat.h"
#include "Shape.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void helloworld();

private:
    Ui::MainWindow *ui;
    QDockWidget *Image_window;//图像浮动窗口
    QDockWidget *Gray_window;//灰度设置
    QDockWidget *Shape_window;//形状处理;

    QDockWidget *Tool_window;//工具栏
    QScrollArea * scrollArea;//滚动条

    //Tool 中的变量
    int tooltype;
    QButtonGroup *toolbuttons;//tool 按钮组

    //Color Tools
    QToolBar * Color_bar;
    QSpinBox *spinbox_penWidth;
    QFrame *frame_color;

    //形状处理里面的变量
    QLineEdit *size_L, *size_W;











    QString Image_path;// 当前图片的路径
   // QLabel* Image_label;// 图像显示框
    PaintWidget * Image_label;



    void init();
    void layout_init();//窗口布局初始化
    void Menu_init();//初始化菜单
    void Tool_init();//初始化工具栏
    void Image_init();//初始化图像窗口
    void Color_init();//初始化颜色/线宽栏;
    void Shape_init();//形状调整窗口初始化
    void Image_show(QImage Img, bool isSave);//显示图像

private slots:
    void iSlot();
    void file_new();
    void file_open();
    void file_save();
    void file_saveas();
    void tool_clicked(int type);
    void pen_width();//画笔宽度;
    void pen_color();//设置画笔的颜色
    void size_auto();//适应窗口大小
    void size_change();//改变图片大小

};
#endif // MAINWINDOW_H
