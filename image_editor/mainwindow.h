#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>


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









    QString Image_path;// 当前图片的路径
    QLabel* Image_label;// 图像显示框



    void init();
    void layout_init();//窗口布局初始化
    void Menu_init();//初始化菜单
    void Tool_init();//初始化工具栏
    void Image_init();//初始化图像窗口
private slots:
    void iSlot();
    void file_new();
    void file_open();
    void file_save();
    void file_saveas();

};
#endif // MAINWINDOW_H
