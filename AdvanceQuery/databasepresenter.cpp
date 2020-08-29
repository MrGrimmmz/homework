#include "databasepresenter.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSettings>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>


DatabasePresenter::DatabasePresenter(QObject *parent):
    QObject(parent)
{

    this->wherefirstcconditon="";
    this->wheresecondcconditon="";
    this->wherethirdcconditon="";
}


void DatabasePresenter::initdatabase()
{

    QSettings *configIniRead = new QSettings("database.ini", QSettings::IniFormat);

    QString ipResult = configIniRead->value("/ip/first").toString();
    QString userResult = configIniRead->value("/user/first").toString();
    QString passResult = configIniRead->value("/pass/first").toString();
    QString dataResult = configIniRead->value("/ku/first").toString();


    delete configIniRead;

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");//加载驱动
    db.setHostName(""+ipResult+"");//本地连接
    db.setUserName(""+userResult+"");//root用户
    db.setPassword(""+passResult+"");//mysql密码
    db.setDatabaseName(""+dataResult+"");//需要连接的数据库

    bool ok=db.open();//打开
    if(ok)
    {

    }
    else
    {
       return;
    }
}

void  DatabasePresenter::sqlwherefirstcconditon(QString data)
{

    if (data=="equal")
    {
        this->wherefirstcconditon="=";
    }
    else
    {
        this->wherefirstcconditon="!=";
    }



}

void DatabasePresenter::sqlwheresecondcconditon(QString data)
{

    if (data=="equal")
    {
        this->wherefirstcconditon="=";
    }
    else
    {
        this->wherefirstcconditon="!=";
    }

}

void DatabasePresenter::sqlwherethirdcconditon(QString data)
{

    if (data=="contains")
    {
        this->wherefirstcconditon="like ";
    }
    else if(data==">=")
    {
        this->wherefirstcconditon=">=";
    }
    else if(data=="<=")
    {
        this->wherefirstcconditon="<=";
    }


}



