#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H


#include <QAbstractTableModel>

class myTableModel: public QAbstractTableModel
{
public:
    myTableModel(QObject *parent );

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    void setRowCount(int count);
    void setColumnCount(int count);
    QVariant data(const QModelIndex &index, int role) const;
    void addCheckData(std::vector<QString>);
private:

    std::vector<std::vector<QString>>tableData; //The vector that stores the archive check data
    int rowNum=0;
    int colNum=0;

   const QString returnTableData(int row, int column);
};

#endif // MYTABLEMODEL_H
