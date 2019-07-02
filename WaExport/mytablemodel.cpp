#include "mytablemodel.h"

myTableModel::myTableModel(QObject *parent)
    :QAbstractTableModel (parent)
{

}

int myTableModel::rowCount(const QModelIndex &parent) const
{
    return tableData.size();
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    return colNum;
}

void myTableModel::setRowCount(int count)
{
    rowNum=count;

}

void myTableModel::setColumnCount(int count)
{
    colNum=count;
}

const QString myTableModel::returnTableData(int row,int column)
{

    if(row>=0&&row<tableData.size())
    {
        if(column<=tableData.at(row).size())
        {
            return tableData.at(row).at(column);
        }
        else {
            return "";
        }
    }
    else {
        return "";
    }
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if(role== Qt::DisplayRole)
    {
        if(index.row()<tableData.size())
        {
            if(index.column()<tableData.at(index.row()).size())
            {
                return tableData.at(index.row()).at(index.column());
            }
            else {
                return "--";
            }
        }
        else {
            return "--";
        }
    }

    return QVariant();
}

void myTableModel::addCheckData(std::vector<QString>data)
{
    tableData.push_back(data);
    emit layoutChanged();
}

void myTableModel::resetTable()
{
    tableData.clear();
}
