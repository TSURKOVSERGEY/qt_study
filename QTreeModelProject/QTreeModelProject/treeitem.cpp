#include "treeitem.h"

// Конструктор
TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parent)
{
    parentItem = parent;
    itemData = data;
}

TreeItem::TreeItem(void)
{
    parentItem = NULL;
    itemData << "root";
}

// Деструктор
TreeItem::~TreeItem()
{
    qDeleteAll(childItems);
}

// Добавление дочерних эллементов
void TreeItem::appendChild(TreeItem *item)
{
    childItems.append(item);
}

bool TreeItem::insertChild(int row, TreeItem *item)
{
    if (row < 0 || row > childItems.count())
        return false;

    childItems.insert(row, item);
    return true;
}

// Возвращает номер строки в списке child_item
TreeItem *TreeItem::child(int row)
{
    return childItems.value(row);
}

// Возвращает колличество дочерних эллементов
int TreeItem::childCount() const
{
    return childItems.count();
}

// Возвращает колличество строк для данного родительского эллемента
int TreeItem::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

// Возвращает число столбцов
int TreeItem::columnCount() const
{
    return itemData.count();
}

// Возвращает данные
QVariant TreeItem::data(int column) const
{
    return itemData.value(column);
}

// Возвращает указатель на родительный объект
TreeItem *TreeItem::parent()
{
    return parentItem;
}
