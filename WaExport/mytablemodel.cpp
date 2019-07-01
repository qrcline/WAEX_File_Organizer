#include "mytablemodel.h"

myTableModel::myTableModel(QObject *parent)
    :QAbstractTableModel (parent)
{

}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    return rowNum;
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    return colNum;
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if(role== Qt::DisplayRole)
    {
        return QString ("Row%1,Column%2")
                .arg(index.row())
                .arg(index.column());
    }

    return QVariant();
}

void myTableModel::addCheckData(std::vector<QString>data)
{
    tableData.push_back(data);
}
