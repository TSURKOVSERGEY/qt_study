#ifndef BASEITEM_H
#define BASEITEM_H

#include "treeitem.h"
#include <QXmlAttributes>

class BaseItem : public TreeItem
{
public:
    BaseItem();\
    BaseItem(const QList<QVariant> data,void* pVitem);

    virtual void PushItemPointer(void);
    virtual void PullItemPointer(void);


};

#endif // BASEITEM_H
