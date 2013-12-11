#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QStringListModel>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList numbers;

    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QAbstractItemModel *model      = new QStringListModel(numbers);
  //  QTableView         *TableView  = new QTableView;
    QListView          *ListView   = new QListView;

    ListView->setModel(model);
 //   TableView->setModel(model);

  //  TableView->setSelectionModel(ListView->selectionModel());

    ListView->show();
  //  TableView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
