#include "saxhandler.h"
#include "treemodel.h"
#include "treeitem.h"

SaxHandler::SaxHandler(TreeItem *pti)
{
    pRootItem = pti;
    room_child = 0;
    desktop_child = 0;

}

bool SaxHandler::startElement(const QString &,const QString &,const QString &qName,const QXmlAttributes &attribs)
{

  if(qName == "room")
  {
      QList<TreeItem*> parent;
      QList<QVariant>  ChildData;
      parent << pRootItem;
      ChildData << QString(qName).append(" ").append(attribs.value(0));
      parent.last()->appendChild(new TreeItem(ChildData,pRootItem));
      pRoomItem = pRootItem->child(room_child++);
      desktop_child = 0;
  }
  else if(qName == "desktop")
  {
      QList<TreeItem*> parent;
      QList<QVariant>  ChildData;
      parent << pRoomItem;
      ChildData << QString(qName).append(" ").append(attribs.value(0));
      parent.last()->appendChild(new TreeItem(ChildData,pRoomItem));
      pDeskTopItem = pRoomItem->child(desktop_child++);
  }
  else if(qName == "hdd")
  {
      QList<TreeItem*> parent;
      QList<QVariant>  ChildData;
      parent << pDeskTopItem;
      ChildData << QString(qName).append(" ").append(attribs.value(0));
      parent.last()->appendChild(new TreeItem(ChildData,pDeskTopItem));
  }

  else if(qName == "cpu")
  {
      QList<TreeItem*> parent;
      QList<QVariant>  ChildData;
      parent << pDeskTopItem;
      ChildData << QString(qName).append(" ").append(attribs.value(0));
      parent.last()->appendChild(new TreeItem(ChildData,pDeskTopItem));
  }
  return true;
}

bool SaxHandler::endElement(const QString &, const QString &,const QString &qName)
{
  if(qName == "hdd")
  {
      printf("");
  }
  else if(qName == "cpu")
  {
      printf("");
  }
  return true;
}


bool SaxHandler::fatalError(const QXmlParseException &exception)
{
  return false;
}

bool SaxHandler::characters(const QString &str)
{
  return true;
}
