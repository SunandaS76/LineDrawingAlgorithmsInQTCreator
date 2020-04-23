#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

  x1 = ui->textEdit->toPlainText().toInt();
  y1 = ui->textEdit_2->toPlainText().toInt();
  x2 = ui->textEdit_3->toPlainText().toInt();
  y2 = ui->textEdit_4->toPlainText().toInt();

  //drawAxis();
  p = ui->comboBox->currentIndex();

  if(flag == 1)
    {
      if(p == 1)
        {
         drawLine(x1,y1,x2,y2);
        }
      if(p == 2)
        {
          drawLine(x1,y1,x2,y2,p);
        }
    }


}

void MainWindow::plotPoint(int x, int y)
{
  QPainter p(this);

  p.drawPoint(x,y);

}

/*void MainWindow::drawAxis()
{
  QPainter p(this);
  drawLine(400,0,400,600);
  drawLine(0,300,800,300);
  char ch[2];
  int xpos=0;

  for(i=-10;i<=10;i++)
    {
      sprintf(ch,"%d",i);
      p.drawText(xpos,300,ch);
      xpos=xpos+60;
    }
  int ypos=0;
  for(i=5;i>=-5;i--)
    {
      sprintf(ch,"%d",i);
      p.drawText(400,ypos,ch);
      ypos=ypos+60;
    }
}
*/

void MainWindow::drawLine(int x1, int y1, int x2, int y2)
{


  int dx, dy, length;
  float x,y,xi,yi;
  dx = x2 - x1;
  dy = y2 - y1;
  length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
  xi = (float)dx/length;
  yi = (float)dy/length;
  x = x1;
  y = y1;
  plotPoint(x,y);
  int i = 1;
  while(i <= length)
    {
      x = x + xi;
      y = y + yi;

      plotPoint(x,y);
      i++;
    }
}

void MainWindow::drawLine(int x1, int y1, int x2, int y2, int p)
{
  int dx,dy,d,i,length,x,y;
  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  int xi = x2>x1 ? 1 : -1 ;
  int yi = y2>y1 ? 1 : -1 ;
  x = x1;
  y = y1;
  length = dx>dy ? dx : dy;
  if(dx > dy)
    {
      d = 2*dy - dx ;
      i = 0;
      while (i<=length)
        {
          plotPoint(x,y);
          if(d >= 0)
            {
              d = d + 2*dy - 2*dx;
              x = x + xi;
              y = y + yi;
            }
          else
            {
            x = x + xi;
            d = d + 2*dy;
            }
           i++;
        }
    }
  else
    {
      d = 2*dx - dy;
      i = 0;
      while(i<=length)
        {
          plotPoint(x,y);
          if(d>=0)
            {
              d = d + 2*dx - 2*dy;
              y = y + yi;
              x = x + xi;
            }
          else
            {
              y = y + yi;
              d = d + 2*dx;
            }
        i++;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    flag = 1;
    update();


}

