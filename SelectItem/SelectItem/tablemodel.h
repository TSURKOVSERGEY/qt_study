#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>


#define EXAMPLE_2

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

 //   TableModel(int row, int col, QObject *parent = 0);
    TableModel(int row, QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;



    QVariant data(const QModelIndex &index, int role) const;


#ifdef EXAMPLE_1

    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
#endif


    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole);

    Qt::ItemFlags flags(const QModelIndex &index) const;

protected:

    int max_row,max_col;

    QStringList stringList;


};

#endif // TABLEMODEL_H
