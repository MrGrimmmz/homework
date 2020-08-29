#ifndef DATABASEPRESENTER_H
#define DATABASEPRESENTER_H

#include <QSqlDatabase>
#include <QObject>

class DatabasePresenter: public QObject
{
   Q_OBJECT
public:

    DatabasePresenter( QObject *parent);
    void compposesql();
    void initdatabase();

signals:
    void signalChange();
public slots:
    void slotChange();

private:
    QSqlDatabase *db;


};

#endif // DATABASEPRESENTER_H
