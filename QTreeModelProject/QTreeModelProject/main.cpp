#include "mainwindow.h"
#include <QApplication>
#include <QTreeView>
#include "treemodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    TreeModel model("root");

    model.AddChild("A");
    model.AddChild("B");
    model.AddChild("C");


    QTreeView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("Simple Tree Model"));
    view.show();

    return a.exec();
}
