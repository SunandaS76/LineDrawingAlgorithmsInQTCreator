#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class myPixel
{
public:
  void virtual plotPoint(int x, int y) = 0 ;
};

class MainWindow : public QMainWindow, public myPixel
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  int p,flag,x1,x2,y1,y2,flag1;
  int i;
  void paintEvent(QPaintEvent *);
  void drawLine(int x1,int x2,int y1,int y2);
  void drawLine(int, int, int, int, int);
  void plotPoint(int,int);
  void drawAxis();
private slots:
  void on_pushButton_clicked();



private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
