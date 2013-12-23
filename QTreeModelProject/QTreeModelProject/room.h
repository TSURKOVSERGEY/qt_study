#ifndef ROOM_H
#define ROOM_H

#include "treeitem.h"
#include <QXmlAttributes>

class RoomItem : public TreeItem
{
public:
    RoomItem();
    RoomItem(const QString &qName,const QXmlAttributes &attribs);


};

#endif // ROOM_H
