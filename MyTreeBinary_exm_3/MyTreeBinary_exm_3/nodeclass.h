#pragma once

#include <QCoreApplication>
#include <iostream>

template <class T>
class TreeClass;

template <class T>
class NodeClass
{

private:

    NodeClass<T> *lp;
    NodeClass<T> *rp;

public:

    T data;

    // конструктор инициализирует поля данных и указателей значение NULL соответствует пустому поддереву
    NodeClass(const T& item, NodeClass<T> *lptr, NodeClass<T> *rptr) : data(item), lp(lptr), rp(rptr) { }

    // методы доступа к полям указателей
    NodeClass* Left(void)  const;
    NodeClass* Right(void) const;

    // создать объект с указательными полями lptr и rptr.
    static NodeClass* GetNode(T item, NodeClass *lptr = NULL, NodeClass *rptr = NULL);

    // освободить динамическую память, занимаемую данным узлом
    static void FreeNode(NodeClass<T> *p);

    // симметричное рекурсивное прохождение узлов дерева
    static void Inorder (NodeClass<T> *p, void visit (T& item));
        \
    // обратное рекурсивное прохождение узлов дерева
    static void Postorder (NodeClass<T> *p, void visit (T& item));

    static void CountLeaf (NodeClass<T> *p, int &count);

    static void CoutData (T& item);

    // сделать класс BinSTree дружественным, поскольку необходим доступ к полям left и right
    friend class TreeClass<T>;

};


template <class T>
void NodeClass<T>::CoutData (T& item)
{
    std::cout << item << std::endl;
}

template <class T>
NodeClass<T>* NodeClass<T>::Left(void) const
{
    return lp;
}

template <class T>
NodeClass<T>* NodeClass<T>::Right(void) const
{
    return rp;
}

template <class T>
NodeClass<T>* NodeClass<T>::GetNode(T item, NodeClass *lptr, NodeClass *rptr)
{
  NodeClass<T> *p = new NodeClass<T>(item, lptr, rptr);

  if(p == NULL) std::cerr << "Ошибка при выделении памяти" << std::endl;

  return p;
}

template <class T>
void NodeClass<T>::FreeNode(NodeClass<T> *p)
{
  delete p;
}

template <class T>
void NodeClass<T>::Inorder (NodeClass<T> *p, void visit (T& item))
{
  if(p != NULL)
  {
    Postorder(p->Left(), visit);
    visit(p->data);
    Postorder(p->Right(), visit);

  }
}

template <class T>
void NodeClass<T>::Postorder (NodeClass<T> *p, void visit (T& item))
{
  if(p != NULL)
  {
    Postorder(p->Left(), visit);
    Postorder(p->Right(), visit);
    visit(p->data);
  }
}

template <class T>
void NodeClass<T>::CountLeaf (NodeClass<T> *p, int &count)
{
  if (p != NULL)
  {
    CountLeaf(p->Left(), count);
    CountLeaf(p->Right(), count);

    if (p->Left() == NULL && p->Right() == NULL)
      count++;
  }
}

