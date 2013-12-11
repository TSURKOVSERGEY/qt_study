#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QLabel *label = new QLabel(this);
    // label->setGeometry(240,350,300,400);
    // ui->label->setText("LABEL");
    // ui->label->show();

    //model = new TableModel(2,2,this);
    model = new TableModel(2,this);
    table = new QTableView(0);
    table->setModel(model);
    setCentralWidget(table);


    QItemSelectionModel *selectionModel = table->selectionModel();
    QModelIndex topLeft;
    QModelIndex bottomRight;
    topLeft = model->index(0, 0, QModelIndex());
    bottomRight = model->index(3, 1, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);
    selectionModel->select(selection, QItemSelectionModel::Select);

    connect(table->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
             this,SLOT(updateSelection(QItemSelection,QItemSelection)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index;
    QModelIndexList items = selected.indexes();

    foreach (index, items) {
        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
        model->setData(index, text);
    }

    items = deselected.indexes();

    foreach (index, items)
        model->setData(index, "");

}
