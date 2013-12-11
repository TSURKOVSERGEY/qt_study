#include "delegate.h"

Delegate::Delegate(QObject *parent) : QItemDelegate(parent)
{
}



QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/*option*/, const QModelIndex &/*index*/) const
{

// мы не нуждаемся в хранении указателя на виджет-редактор (option), так как представление берет на себя ответственность за его уничтожение когда он станет не нужен.

    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// функция копирования данных модели в редактор.
///////////////////////////////////////////////////////////////////////////////////////////////
void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();

    QSpinBox *spinbox = static_cast<QSpinBox*>(editor);

    spinbox->setValue(value);

}

///////////////////////////////////////////////////////////////////////////////////////////////
// функция копирования данных в модель
///////////////////////////////////////////////////////////////////////////////////////////////
void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
      QSpinBox *spinbox = static_cast<QSpinBox*>(editor);
      spinbox->interpretText();
      int value = spinbox->value();
      model->setData(index,value,Qt::EditRole);

}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);

}
