#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QObject>
#include <QFileSystemModel>
#include <QTreeView>
#include <QSplitter>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QFileSystemModel *model;
    QSplitter        *splitter;
    QTreeView        *tree;


public slots:
    void OpenFile(void);

  // void TreeItemHandler(const QModelIndex &index);
    void TreeItemHandler(const QModelIndex &index);

};

#endif // MAINWINDOW_H
