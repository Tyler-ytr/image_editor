#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include "PaintWidget.h"
#include "ImagetoMat.h"
#include "Shape.h"
#include "Color.h"
#include <vector>



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
    QDockWidget *Color_window;//颜色总体的设置 包括灰度化等
    QDockWidget *Shape_window;//形状处理;

    //目录中的变量;
    QAction *afile_undo;//撤销;
    QAction *afile_redo;//恢复;

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
    QSpinBox *spinbox_rotateangles;
    QSpinBox *spinbox_scaletimes;

    std::vector<std::vector<QImage>> Image_vector;//图片vector 用来实现redo undo功能
    std::vector<QImage>::iterator Image_iter;//迭代器













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
    void Colorchange_init();//颜色调整窗口初始化
    void Image_show(QImage Img, bool isSave);//显示图像
    void undo();
    void redo();
private slots:
    void iSlot();
    void file_new();
    void file_open();
    void file_save();
    void file_saveas();
    void file_undo();
    void file_redo();
    void tool_clicked(int type);
    void pen_width();//画笔宽度;
    void pen_color();//设置画笔的颜色
    void size_auto();//适应窗口大小
    void size_change();//改变图片大小
    void picture_rotate();//旋转一定角度， 根据spinbox_rotateangles里面的值
    void picture_scale();//图像缩放一定的倍数,值shi spinbox_caletims/100;
    void flip_x();
    void flip_y();
    void flip_xy();//镜像
    void Color_gray();//灰度化;
    void Color_binary();//二值化;
    void Color_reversal();//颜色反转;

};
#endif // MAINWINDOW_H
