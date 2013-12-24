#include "treemodel.h"


TreeModel::TreeModel(void)
{
    rootItem = new TreeItem();
}

TreeModel::~TreeModel()
{
    delete rootItem;
}


// Установить свойства для узла index
// в данном случае это: может выбираться и может быть активным
 Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
 {
     if (!index.isValid())
         return 0;

     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
 }


 // Получение индекса класса QModelIndex по номеру строки и номеру колонки для родительского элемента parent
 // примечание: данный метод вызывает виджет отображения при обходе модели данных
 QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)
             const
 {
     if (!hasIndex(row, column, parent))
         return QModelIndex();

     TreeItem *parentItem;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<TreeItem*>(parent.internalPointer());

     TreeItem *childItem = parentItem->child(row);
     if (childItem)
         return createIndex(row, column, childItem);
     else
         return QModelIndex();
 }

 // Получить родительский элемент класса QModelIndex для подчиненного элемента child
 QModelIndex TreeModel::parent(const QModelIndex &index) const
 {
     if (!index.isValid())
         return QModelIndex();

     TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
     TreeItem *parentItem = childItem->parent();

     if (parentItem == rootItem)
         return QModelIndex();

     return createIndex(parentItem->row(), 0, parentItem);
 }

 // получить количество подчиненных элементов для узла parent
 int TreeModel::rowCount(const QModelIndex &parent) const
 {
     TreeItem *parentItem;
     if (parent.column() > 0)
         return 0;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<TreeItem*>(parent.internalPointer());

     return parentItem->childCount();
 }

 // получить количество отображаемых колонок с данными для узла parent
 // здесь можно было установить количество данных, которое содержит каждый узел,
 // например список строк или количество полей из таблицы
 int TreeModel::columnCount(const QModelIndex &parent) const
 {
      if (parent.isValid())
          return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
      else
          return rootItem->columnCount();
 }

 // получить данные узла index для роли данных role
 //примечание: именно здесть виджет получает данные из узла
 QVariant TreeModel::data(const QModelIndex &index, int role) const
 {
      if (!index.isValid())
          return QVariant();

      if (role != Qt::DisplayRole)
          return QVariant();

      TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

      return item->data(index.column());
 }

 // получить данные для заголовка виджета отображения модели с номером колонки или строки section
 // ориентацией по колонкам или по строкам и роли получаемых данных role
 // примечание: чаще всего имеет значение только для корневого узла. Или выдавать значение заголовков для встраиваемых виджетов
 QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                                int role) const
 {
     if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
         return rootItem->data(section);

     return QVariant();
 }


TreeItem* TreeModel::GetRootItem(void)
{
     return rootItem;
}






