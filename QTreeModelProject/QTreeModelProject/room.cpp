#include "room.h"


RoomItem::RoomItem()
{
}


RoomItem::RoomItem(const QString &qName,const QXmlAttributes &attribs) : TreeItem(qName,ChildData)
{
    QList<TreeItem*> parent;
    QList<QVariant>  ChildData;


   // parent << pItem;
   // parent.last()->appendChild(pItem);

    pItem->childItems.append(pItem);

    parentItem = pItem;
    itemData   << "AAA";






}

