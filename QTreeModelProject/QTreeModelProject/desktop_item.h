#ifndef DESKTOP_H
#define DESKTOP_H

#include "base_item.h"
#include <QXmlAttributes>

class DesktopItem : public BaseItem
{
public:
    DesktopItem();
    DesktopItem(const QList<QVariant> data);

    virtual void PushItemPointer(void);
    virtual void PullItemPointer(void);


};

#endif // DESKTOP_H
