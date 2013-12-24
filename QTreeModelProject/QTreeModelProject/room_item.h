#ifndef ROOM_H
#define ROOM_H

#include "base_item.h"
#include <QXmlAttributes>

class RoomItem : public BaseItem
{
public:

    RoomItem();
    RoomItem(const QList<QVariant> data);

    virtual void PushItemPointer(void);
    virtual void PullItemPointer(void);

};

#endif // ROOM_H
