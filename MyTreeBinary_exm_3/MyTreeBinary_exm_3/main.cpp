#include <QCoreApplication>
#include <iostream>
#include "treeclass.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NodeClass<int> *pnode, *parent;

    TreeClass<int> my_tree(10);

    int node[6] = {5, 15, 25, 20, 30, 35};

    for(int i = 0; i < 6; i++)
    {
        my_tree.Insert(node[i]);
    }

    std::cout << "\n Postorder \n" << std::endl;

    pnode = my_tree.Find(35,parent);
    std::cout << "\n Find " << pnode << "\n" << std::endl;

    my_tree.Postorder();

    my_tree.Delete(15);

    my_tree.Postorder();


    return a.exec();
}
