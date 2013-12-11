#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer* ptimer = new QTimer(this);

    ptimer->start(500);

    connect(ptimer,SIGNAL(timeout()),this,SLOT(OnTimeOut()));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#define EX3

void MainWindow::OnTimeOut()
{

#ifdef EX1

    ui->timer_label->setText(QTime::currentTime().toString());

#endif
#ifdef EX2

    QLabel *label = new QLabel(this);
    label->setText(QTime::currentTime().toString());
    label->setGeometry(rand()%this->width(),rand()%this->height(),100,100);
    label->show();

#endif
#ifdef EX3

    QLabel *label = new QLabel(this);
    label->setPixmap(QPixmap("smale.bmp").scaledToHeight(rand()%80+20));
    label->setGeometry(rand()%this->width(),rand()%this->height(),100,100);
    label->show();

#endif


}
