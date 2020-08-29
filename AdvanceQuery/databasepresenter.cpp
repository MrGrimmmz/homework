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
    connect(this, &DatabasePresenter::signalChange, this, &DatabasePresenter::slotChange);
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
            compposesql();
        }
        else
        {

        }
}


void DatabasePresenter::compposesql()
{

//        QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
////传输完整sql

//        model->setQuery(QString("select box_id,case box_state when 1 then '待取' "
//                                "else '已取' end as box_state,case box_size when 1 "
//                                "then '大' when 2 then '中' else '小' end as box_size "
//                                "from box;"));
//        //列名
//        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
//        model->setHeaderData(1, Qt::Horizontal, tr("状态"));
//        model->setHeaderData(2, Qt::Horizontal, tr("型号"));
//        ui->tableView->setModel(model);//数据放置进去
//        ui->tableView->verticalHeader()->hide();//不显示序号

}

void DatabasePresenter::slotChange()
{

}

void DatabasePresenter::signalChange()
{

}





