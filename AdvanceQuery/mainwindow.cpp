#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "databasepresenter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize();
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(pressBtn()));
    databasepresenter = new DatabasePresenter(this);
    databasepresenter->initdatabase();

}
void MainWindow::initNodeTable()
{
    ui->tableWidget->setColumnCount(7);
    //表头
    QStringList horHeaderStr;
    horHeaderStr << QString::fromLocal8Bit("ID")
                 << QString::fromLocal8Bit("CompanyName")
                 << QString::fromLocal8Bit("ContactName")
                 << QString::fromLocal8Bit("ContactTitle")
                 << QString::fromLocal8Bit("PostalCode")
                 << QString::fromLocal8Bit("Region")
                 << QString::fromLocal8Bit("Country");
    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(horHeaderStr);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    ui->comboBox->addItem("Austria");
    ui->comboBox->addItem("China");
    ui->comboBox->addItem("America");
    ui->comboBox->addItem("Austrlia");
    ui->comboBox_2->addItem("");
    ui->tableWidget->setColumnCount(7);
    //表头
    QStringList horHeaderStr;
    horHeaderStr << QString::fromLocal8Bit("ID")
                 << QString::fromLocal8Bit("CompanyName")
                 << QString::fromLocal8Bit("ContactName")
                 << QString::fromLocal8Bit("ContactTitle")
                 << QString::fromLocal8Bit("PostalCode")
                 << QString::fromLocal8Bit("Region")
                 << QString::fromLocal8Bit("Country");
    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(horHeaderStr);

}

void MainWindow::pressBtn()
{
    dialog=new AdvanceDialog(this);
    connect(dialog,SIGNAL(sendData(QString)),this,SLOT(updateData(QString)));
    dialog->setModal(false);
    if(dialog->exec()==QDialog::Accepted){

    }
    delete dialog;

}

void MainWindow::updateData(QString data)
{

    ui->textEdit->append("查询sql:");
    ui->textEdit->append(data);
    //compposesql(data);
}


void MainWindow::compposesql(QString data)
{

    QSqlQueryModel *model = new QSqlQueryModel(ui->tableWidget);
    //传输完整sql
    model->setQuery(QString(data));
    //列名
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("CompanyName"));
    model->setHeaderData(2, Qt::Horizontal, tr("ContactName"));
    model->setHeaderData(3, Qt::Horizontal, tr("ContactTitle"));
    model->setHeaderData(4, Qt::Horizontal, tr("PostalCode"));
    model->setHeaderData(5, Qt::Horizontal, tr("Region"));
    model->setHeaderData(5, Qt::Horizontal, tr("Country"));
    QSqlQuery query;
    query.exec(data);
    int columns=0;
    if(query.first())
    {
        columns = query.value("columns").toInt();
        ui->tableWidget->setColumnCount(columns);//列
    }
    for(int i = 0; query.next(); i++)
    {
        for(int j = 0; j < columns; j++)
        {
            ui->tableWidget->setItem(i,j, new QTableWidgetItem(query.value(j).toString()));
        }
    }
    ui->tableWidget->verticalHeader()->hide();//不显示序号
    int i =ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(i);
}

