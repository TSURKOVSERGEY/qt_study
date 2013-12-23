#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>


class TreeItem
{
public:
    TreeItem(const QList<QVariant> &data, TreeItem *parent = 0);
    TreeItem(void);
    ~TreeItem();

    void appendChild(TreeItem *child);
    bool insertChild(int row, TreeItem *item);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();

    static TreeItem *pItem;

    QList<TreeItem*> childItems;
    QList<QVariant> itemData;
    TreeItem *parentItem;

private:





};


#endif // TREEITEM_H
