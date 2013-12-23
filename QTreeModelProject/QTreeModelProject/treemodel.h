#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QXmlAttributes>
#include <QModelIndex>
#include <QString>
#include <QStringList>
#include "treeitem.h"


class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    TreeModel(void);
    ~TreeModel();

    TreeItem* GetRootItem(void);
    void CreateNewItem(const QString &qName,const QXmlAttributes &attribs);

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:

    TreeItem *rootItem;
  //  TreeItem *pItem;
};


#endif // TREEMODEL_H
