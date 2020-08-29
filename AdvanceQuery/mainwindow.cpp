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
   // databasepresenter = new DatabasePresenter(this);
    //databasepresenter->initdatabase();

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
}




