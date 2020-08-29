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
        // 传输数据库连接的这些信息在实际开发的时都需要通过读取配置文件得到，
        QSettings *configIniRead = new QSettings("database.ini", QSettings::IniFormat);
        //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
        QString ipResult = configIniRead->value("/ip/first").toString();
        QString userResult = configIniRead->value("/user/first").toString();
        QString passResult = configIniRead->value("/pass/first").toString();
        QString dataResult = configIniRead->value("/ku/first").toString();
        //读入完成后删除指针

        delete configIniRead;
        /*加载数据库驱动并且进行连接*/
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


void DatabasePresenter::compposesql()//查询箱子状态
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





