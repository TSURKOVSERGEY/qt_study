#include "treemodel.h"

TreeModel::TreeModel(const QString &data, QObject *parent) : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Title" << "Summary";
    rootItem = new TreeItem(rootData);
    setupModelData(data.split(QString("\n")), rootItem);

}

 TreeModel::~TreeModel()
 {
     delete rootItem;
 }

void TreeModel::AddChild(const QString &data)
{

    setupModelData(data.split(QString("\n")),rootItem);

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

 void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
 {
     QList<TreeItem*> parents;
     QList<int> indentations;
     parents << parent;
     indentations << 0;

     int number = 0;

     while (number < lines.count()) {
         int position = 0;
         while (position < lines[number].length()) {
             if (lines[number].mid(position, 1) != " ")
                 break;
             position++;
         }

         QString lineData = lines[number].mid(position).trimmed();

         if (!lineData.isEmpty()) {
             // Read the column data from the rest of the line.
             QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
             QList<QVariant> columnData;
             for (int column = 0; column < columnStrings.count(); ++column)
                 columnData << columnStrings[column];

             if (position > indentations.last()) {
                 // The last child of the current parent is now the new parent
                 // unless the current parent has no children.

                 if (parents.last()->childCount() > 0) {
                     parents << parents.last()->child(parents.last()->childCount()-1);
                     indentations << position;
                 }
             } else {
                 while (position < indentations.last() && parents.count() > 0) {
                     parents.pop_back();
                     indentations.pop_back();
                 }
             }

             // Append a new item to the current parent's list of children.
             parents.last()->appendChild(new TreeItem(columnData, parents.last()));
         }

         number++;
     }
 }




 /*
Model::Node *Model::node(int row, Node *parent) const
{
if (parent && !parent->children)
parent->children = new QVector<Node>(rc, Node(parent));
QVector<Node> *v = parent ? parent->children : tree;
return const_cast<Node*>(&(v->at(row)));
}

Model::Node *Model::parent(Node *child) const
{
return child ? child->parent : 0;
}

  */
