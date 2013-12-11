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
    else
    {
        if(index < MyTree->index)
        {
            add_node(index,MyTree->lp)
        }
        else if(index > MyTree->index)
        {
            add_node(index,MyTree->rp)
        }


    }
}

// ********************************************************************************************
// ( порядковая выборка )
// значение в узле не обрабатываются, до тех пор пока не будут обработаны
// значения в его левом подереве
// ********************************************************************************************

void inOrder(Node *&Tree)
{
    if(Tree != NULL)
    {
        inOrder(Tree->lp);
        std::cout << Tree->index << std::endl;
        inOrder(Tree->rp);
    }
}

// ********************************************************************************************
// ( предварительная выборка )
// значение в узле обрабатываются при остановке в этом узле
// ********************************************************************************************

void preOrder(Node *&Tree)
{
    if(Tree != NULL)
    {   std::cout << Tree->index << std::endl;
        inOrder(Tree->lp);
        inOrder(Tree->rp);
    }
}

// ********************************************************************************************
// ( отложенная выборка )
// значение в узле обрабатываются до тех пор пока не будут обработаны значения его потомков
// ********************************************************************************************

void postOrder(Node *&Tree)
{
    if(Tree != NULL)
    {
        inOrder(Tree->lp);
        inOrder(Tree->rp);
        std::cout << Tree->index << std::endl;
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



