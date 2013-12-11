#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
#include <QTableView>
#include "tablemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    TableModel *model;
    QTableView *table;

private:
    Ui::MainWindow *ui;

public slots:

    void updateSelection(const QItemSelection &selected,const QItemSelection &deselected);
    \
};



#endif // MAINWINDOW_H
