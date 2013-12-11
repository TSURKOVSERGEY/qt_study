#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel;

    model->setRootPath(QDir::currentPath());

    splitter = new QSplitter;

    tree = new QTreeView(splitter);


    QObject::connect(ui->OpenFileButton,SIGNAL(clicked()),this,SLOT(OpenFile()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenFile()
{
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));
    splitter->setWindowTitle("Two views onto the same file system model");
    splitter->show();

    //connect(tree->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
      //      this,SLOT(TreeItemHandler(QItemSelection,QItemSelection)));

    connect(tree->actionEvent(),SIGNAL(activated(const QModelIndex &index)),
          this,SLOT(TreeItemHandler(const QModelIndex &index)));



    //connect(table->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
      //       this,SLOT(updateSelection(QItemSelection,QItemSelection)));

}

void MainWindow::TreeItemHandler(const QModelIndex &index)
{
    qDebug() << "done";

}
/*
void MainWindow::TreeItemHandler(const QItemSelection &selected, const QItemSelection &deselected)
{
    qDebug() << "done";

}
*/
