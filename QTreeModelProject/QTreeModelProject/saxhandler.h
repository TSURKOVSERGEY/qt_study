#ifndef SAXHANDLER_H
#define SAXHANDLER_H

#include<QXmlDefaultHandler>

class TreeModel;
class TreeItem;

class SaxHandler : public QXmlDefaultHandler
{
public:
    SaxHandler(TreeModel *ptree);

  bool startElement(const QString &namespaceURI,
                    const QString &localName,
                    const QString &qName,
                    const QXmlAttributes &attribs);
  bool endElement(const QString &namespaceURI,
                  const QString &localName,
                  const QString &qName);
  bool characters(const QString &str);
  bool fatalError(const QXmlParseException &exception);

private:

  TreeModel       *pTreeModel;

  TreeItem        *pRootItem;
  TreeItem        *pRoomItem;
  TreeItem        *pDeskTopItem;

  int             room_child;
  int             desktop_child;




};


#endif // SAXHANDLER_H
