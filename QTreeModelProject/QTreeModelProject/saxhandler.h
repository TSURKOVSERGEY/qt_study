#ifndef SAXHANDLER_H
#define SAXHANDLER_H

#include<QXmlDefaultHandler>

class TreeModel;
class BaseItem;

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
  bool characters(Qt::DropAction /*action*/, const QString &str);
  bool fatalError(Qt::DropAction /*action*/, const QXmlParseException &exception);

private:

  TreeModel  *pTreeModel;
  BaseItem   *pBase;

};


#endif // SAXHANDLER_H
