#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pTreeModel  = new TreeModel();
    pFile       = new QFile("DefaultTree.xml");
    pXmlReader  = new QXmlSimpleReader();
    pSource     = new QXmlInputSource(pFile);
    pHandler    = new SaxHandler(pTreeModel);
    pView       = new QTreeView(this);


    pXmlReader->setContentHandler(pHandler);
    pXmlReader->parse(pSource);

    pView->setGeometry(10,10,450,350);

    pView->setModel(pTreeModel);
    pView->setWindowTitle(QObject::tr("Simple Tree Model"));
    pView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}



