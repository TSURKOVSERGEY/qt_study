#include <QCoreApplication>
#include <iostream>
#include <conio.h>

#define EXAMPLE_1

#ifdef EXAMPLE_1

struct Node
{
    int index;

    Node *lp,*rp;
};

void show(Node *&Tree)
{
    if (Tree != NULL)
    {
       show(Tree->lp);

       std::cout << Tree->index << std::endl;

       show(Tree->rp);
    }
}

void add_node(int index, Node *&MyTree)
{
    if(MyTree == NULL)
    {
        MyTree=new Node;
        MyTree->index = index;
        MyTree->lp = NULL;
        MyTree->rp = NULL;
    }

    if(index < MyTree->index)
    {
        if(MyTree->lp != NULL)
        {
            add_node(index, MyTree->lp);
        }
        else
        {
            MyTree->lp = new Node;
            MyTree->lp->lp = NULL;
            MyTree->lp->rp = NULL;
            MyTree->lp->index = index;
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Node *Tree = NULL;

    for(int i = 5; i > 0 ; i--)
    {
        add_node(i,Tree);

    }


    show(Tree);




    return a.exec();
}

#endif

#ifdef EXAMPLE_2

struct MyStruct
{
    int x;
    int *Ptr;
};

void myfunc(MyStruct *obj)
//void myfunc(MyStruct *&obj)
{
  std::cout << &obj << "\t" << &obj->x << "\t" << &obj->Ptr << std::endl;
}

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    MyStruct *obj = new MyStruct;
    obj->x = 12345;
    obj->Ptr = &obj->x;

    std::cout << &obj << "\t" << &obj->x << "\t" << &obj->Ptr << std::endl;
    std::cout<<"\n" << std::endl;
    myfunc(obj);
    delete obj;
    return 0;
}

#endif



