#include "saxhandler.h"
#include "treemodel.h"
#include "treeitem.h"
#include "room_item.h"
#include "desktop_item.h"
#include "hdd_item.h"
#include "cpu_item.h"

SaxHandler::SaxHandler(TreeModel *ptree)
{
    pTreeModel = ptree;
}

bool SaxHandler::startElement(const QString &,const QString &,const QString &qName,const QXmlAttributes &attribs)
{
    if(qName == "root")
    {
        return true;
    }
    else if(qName == "room")
    {
        QList<QVariant> ChildData;
        ChildData << QString(qName).append(" ").append(attribs.value(0));
        pBase = new RoomItem(ChildData);
    }
    else if(qName == "desktop")
    {
        QList<QVariant> ChildData;
        ChildData << QString(qName).append(" ").append(attribs.value(0));
        pBase = new DesktopItem(ChildData);
    }
    else if(qName == "hdd")
    {
        QList<QVariant> ChildData;
        ChildData << QString(qName).append(" ").append(attribs.value(0));
        pBase = new HddItem(ChildData);
    }
    else if(qName == "cpu")
    {
        QList<QVariant> ChildData;
        ChildData << QString(qName).append(" ").append(attribs.value(0));
        pBase = new CpuItem(ChildData);
    }


    pBase->PushItemPointer();

   return true;
}

bool SaxHandler::endElement(const QString &, const QString &,const QString &qName)
{

    if(qName == "root")
    {
        return true;
    }
    else
    {
        pBase->PullItemPointer();
    }

  return true;
}


bool SaxHandler::fatalError(Qt::DropAction /*action*/,const QXmlParseException &/*exception*/)
{
  return false;
}

bool SaxHandler::characters(Qt::DropAction /*action*/,const QString &/*str*/)
{
  return true;
}
