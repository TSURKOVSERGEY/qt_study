#include "tablemodel.h"
#include <QColor>
#include <QBrush>
#include <qDebug>
#include <QString>


//TableModel::TableModel(int row, int col, QObject *parent) : QAbstractTableModel(parent)
TableModel::TableModel(int row, QObject *parent) : QAbstractTableModel(parent)
{
    max_row = row;
    max_col = col;
}


int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return max_row;
}

#ifdef EXAMPLE_1
int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return max_col;
}



QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
           return QString("red %1").arg(index.row());
        else if (index.column() == 1)
           return QString("yelow %1").arg(index.row());
        else if (index.column() == 2)
           return QString("green %1").arg(index.row());
    }
    if(role == Qt::BackgroundRole)
    {
        if (index.column() == 0)
            return QVariant(QColor(Qt::red));
        else if (index.column() == 1)
            return QVariant(QColor(Qt::yellow));
        else if (index.column() == 2)
            return QVariant(QColor(Qt::green));

    }

    return QVariant();
}

#endif

#ifdef EXAMPLE_2

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
            return QVariant();

        if (index.row() >= stringList.size())
            return QVariant();

        if (role == Qt::DisplayRole || role == Qt::EditRole)
            return stringList.at(index.row());
        else
            return QVariant();
}

#endif

#ifdef EXAMPLE_1

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return tr("Name");
                case 1:
                    return tr("Address");

                case 2:
                    return tr("Phone");


                default:
                    return QVariant();
            }
        }
    }


    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Vertical) {
            switch (section) {
                case 0:
                    return tr("edge");
                case 1:
                    return tr("mas");

                case 2:
                    return tr("nation");


                default:
                    return QVariant();
            }
        }
    }


    if(role == Qt::ForegroundRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
                case 0:
                    return QVariant(QColor(Qt::red));
                case 1:
                    return QVariant(QColor(Qt::yellow));
                case 2:
                    return QVariant(QColor(Qt::green));

              default:
                    return QAbstractTableModel::headerData(section,orientation,role);
            }
        }
    }
    if(role ==Qt::BackgroundRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
                case 0:
                    qDebug() << "case 0";
                    return  QBrush(QColor(Qt::red));
                case 1:
                    qDebug() << "case 1";
                    return  QVariant(QColor(Qt::red));
                default:
                    qDebug() << "default";
                    return QAbstractTableModel::headerData(section,orientation,role);
            }
        }
    }

    return QVariant();
}

#endif

bool TableModel::setData(const QModelIndex &index,const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        stringList.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
