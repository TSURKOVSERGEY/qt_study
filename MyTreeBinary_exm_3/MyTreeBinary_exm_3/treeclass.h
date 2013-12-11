#pragma once

#include <QCoreApplication>
#include <iostream>
#include "nodeclass.h"

template <class T>
class TreeClass
{

protected:

    NodeClass<T> *root;
    NodeClass<T> *current;

  int size;

  NodeClass<T> *GetTree(const T& item,NodeClass<T> *lptr, NodeClass<T> *rptr);
  void FreeTree(NodeClass<T> *p);


public:

  TreeClass(T item);
  ~TreeClass(void);\

  void Insert(const T& item);\
  NodeClass<T>* Find(const T& item, NodeClass<T>* &parent) const;
  void Delete(const T& item);

  void Inorder(void);
  void Postorder(void);

};

template <class T>
void TreeClass<T>::Inorder(void)
{
    std::cout << "\n" << std::endl;
    NodeClass<T>::Inorder(root,NodeClass<T>::CoutData);
}

template <class T>
void TreeClass<T>::Postorder(void)
{
    std::cout << "\n" << std::endl;
    NodeClass<T>::Postorder(root,NodeClass<T>::CoutData);
}

template <class T>
TreeClass<T>::TreeClass(T item)
{
    root = NodeClass<T>::GetNode(item, NULL,NULL);
}


template <class T>
TreeClass<T>::~TreeClass(void)
{
}

template <class T>
void TreeClass<T>::Insert(const T& item)
{
    NodeClass<T> *p = root, *parent = NULL;

  while(p != NULL)
  {
    parent = p;
    if (item < p->data)
      p = p->lp;
    else
      p = p->rp;
  }

  if (parent == NULL)
  {
    root = NodeClass<T>::GetNode(item);
    current = root;
  }
  else if (item < parent->data)
  {
    parent->lp = NodeClass<T>::GetNode(item);
    current = parent->lp;
  }
  else
  {
    parent->rp = NodeClass<T>::GetNode(item);
    current = parent->rp;
  }

  size++;
}


template <class T>
NodeClass<T> *TreeClass<T>::Find(const T& item, NodeClass<T>* &parent) const
{
  NodeClass<T> *p = root;

  parent = NULL;

  while(p != NULL)
  {
      if (item == p->data)
      {
          break;
      }
      else
      {
          parent = p;

          if (item < p->data)
          {
              p = p->lp;
          }
          else
          {
              p = p->rp;
          }
      }
  }

  return p;
}


template <class T>
void TreeClass<T>::Delete(const T& item)
{
  // DNodePtr  - указатель на удаляемый узел D
  // PNodePtr  - указатель на родительский узел P узла D
  // RNodePtr  - указатель на узел R, замещающий узел D

  NodeClass<T> *DNodePtr, *PNodePtr, *RNodePtr;


  if((DNodePtr = Find(item, PNodePtr)) == NULL)
  {
    return;
  }

  if (DNodePtr->rp == NULL)
  {
      RNodePtr = DNodePtr->lp;
  }
  else if (DNodePtr->lp == NULL)
  {
      RNodePtr = DNodePtr->rp;
  }
  else // узел D имеет двух сыновей
  {
    // найти и отсоединить заменяющий узел R для узла D.
    // в левом поддереве узла D найти максимальный узел из всех узлов, меньших чем узел D.
    // отсоединить этот узел от дерева.

    NodeClass<T> *PofRNodePtr = DNodePtr;

    // первой возможной заменой является левый сын узла D
    RNodePtr = DNodePtr->lp;

    // спуститься вниз по правому поддереву левого сына узла D,
    // сохраняя указатель на текущий узел и его родителя.
    // остановившись, мы будем иметь заменяющий узел
    while(RNodePtr->rp != NULL)
    {
      PofRNodePtr = RNodePtr;
      RNodePtr = RNodePtr->rp;
    }

    if (PofRNodePtr == DNodePtr)
    {
      // левый сын удаляемого узла является заменяющим
      // присоединить правое поддерево узла D к узлу R
      RNodePtr->rp = DNodePtr->rp;
    }
    else
    {
      // мы спустились вниз по правой ветви как минимум на один узел.
      // удалить заменяющий узел из дерева,
      // присоединив его правую ветвь к родительскому узлу
      PofRNodePtr->rp = RNodePtr->lp;
    }
  }

  if (RNodePtr == NULL)
  {
    root = RNodePtr;
  }
  else if (DNodePtr->data < PNodePtr->data)
  {
      PNodePtr->lp = RNodePtr;
  }
  else
  {
      PNodePtr->rp = RNodePtr;
  }

  NodeClass<T>::FreeNode(DNodePtr);
  size--;

}
