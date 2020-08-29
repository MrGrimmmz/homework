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
    void sqlwherefirstcconditon(QString data);
    void sqlwheresecondcconditon(QString data);
    void sqlwherethirdcconditon(QString data);

private:
    QSqlDatabase *db;
    QString wherefirstcconditon;
    QString wheresecondcconditon;
    QString wherethirdcconditon;
    QSqlQuery *completequery;


};

#endif // DATABASEPRESENTER_H
