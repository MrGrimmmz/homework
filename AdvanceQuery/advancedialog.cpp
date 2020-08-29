#include "advancedialog.h"
#include "ui_advancedialog.h"
#include <QFile>
#include <QtXml\QtXml>
#include <QtXml\QDomDocument>
#include <QtXml/QDomNode>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomText>
#include <QFile>
#include <QString>


AdvanceDialog::AdvanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdvanceDialog)
{
    ui->setupUi(this);
    init();
    initconnection();
    ui->comboBox->addItem("CompanyName");
    ui->comboBox->addItem("Country");
    ui->comboBox->addItem("ContactName");
    ui->comboBox_2->addItem("equal");
    ui->comboBox_2->addItem("not equal");
    ui->comboBox_4->addItem("ContactTitle");
    ui->comboBox_4->addItem("Region");
    ui->comboBox_6->addItem("Phone");
    ui->comboBox_6->addItem("PostalCode");
    ui->comboBox_7->addItem("Contains");
    ui->comboBox_7->addItem(">=");
    ui->comboBox_7->addItem("<=");
    ui->comboBox_9->addItem("equal");
    ui->comboBox_9->addItem("not equal");

}



AdvanceDialog::~AdvanceDialog()
{
    delete ui;
}


void AdvanceDialog::init()
{
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_3->clear();
    ui->comboBox_8->clear();
    ui->comboBox_5->clear();
    ui->comboBox_4->setCurrentIndex(0);
    ui->comboBox_5->setCurrentIndex(0);
    ui->comboBox_8->setCurrentIndex(0);
    ui->comboBox_6->setCurrentIndex(0);
    ui->comboBox_7->setCurrentIndex(0);
    ui->comboBox_9->setCurrentIndex(0);
}


void AdvanceDialog::readXml()
{
    //int currentindex=i;
    QDomDocument doc;

    QFile file("D:/016903/Documents/AdvanceQuery/AdvanceQuery.xml");

    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    doc.setContent(&file);

    QDomElement root = doc.documentElement();
    //qDebug() <<root.toElement().tagName();
    QDomNode domNode = root.firstChild();

    QStringList QList;
    QList.clear();

    while (!domNode.isNull())
    {
        if (domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
            QDomNodeList list = domElement.childNodes();

            for (int i = 0; i<list.count(); i++) //遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode nodeIndex = list.at(i);
                if (domNode.isElement())
                {
                    QDomElement indexElement = nodeIndex.toElement();
                    QString s1=nodeIndex.toElement().attribute(ui->comboBox->currentText());
                    QList.append(s1);
                }
            }

        }
        domNode = domNode.nextSibling();
    }
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(QList);
}

void AdvanceDialog::readXml1()
{

    QDomDocument doc;
    QFile file("D:/016903/Documents/AdvanceQuery/AdvanceQuery.xml");
    if (!file.open(QIODevice::ReadOnly))
    {

        return;
    }
    doc.setContent(&file);

    QDomElement root = doc.documentElement();
    // qDebug() <<root.toElement().tagName();
    QDomNode domNode = root.firstChild();

    QStringList QList;
    QList.clear();

    while (!domNode.isNull())
    {
        if (domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
            QDomNodeList list = domElement.childNodes();

            for (int i = 0; i<list.count(); i++) //遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode nodeIndex = list.at(i);
                if (domNode.isElement())
                {
                    QDomElement indexElement = nodeIndex.toElement();
                    QString s1=nodeIndex.toElement().attribute(ui->comboBox_4->currentText());
                    QList.append(s1);
                }
            }
        }
        domNode = domNode.nextSibling();
    }
    ui->comboBox_5->clear();
    ui->comboBox_5->addItems(QList);
}


void AdvanceDialog::readXml2()
{
    QDomDocument doc;
    QFile file("D:/016903/Documents/AdvanceQuery/AdvanceQuery.xml");


    if (!file.open(QIODevice::ReadOnly))
    {

        return;
    }
    doc.setContent(&file);
    QDomElement root = doc.documentElement();
    //qDebug() <<root.toElement().tagName();
    QDomNode domNode = root.firstChild();

    QStringList QList;
    QList.clear();

    while (!domNode.isNull())
    {
        if (domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
            QDomNodeList list = domElement.childNodes();

            for (int i = 0; i<list.count(); i++) //遍历子元素，count和size都可以用,可用于标签数计数
            {
                QDomNode nodeIndex = list.at(i);
                if (domNode.isElement())
                {
                    QDomElement indexElement = nodeIndex.toElement();
                    QString s1=nodeIndex.toElement().attribute(ui->comboBox_6->currentText());
                    QList.append(s1);
                }
            }

        }
        domNode = domNode.nextSibling();
    }
    ui->comboBox_8->clear();
    ui->comboBox_8->addItems(QList);
}
void AdvanceDialog::initconnection()
{

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),
            this,SLOT(combox_onChanged()));
    connect(ui->comboBox_4,SIGNAL(currentIndexChanged(int)),
            this,SLOT(combox2_onChanged()));
    connect(ui->comboBox_6,SIGNAL(currentIndexChanged(int)),
            this,SLOT(combox3_onChanged()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_clicked()));

}

void AdvanceDialog::combox_onChanged()
{
    readXml();
}

void AdvanceDialog::combox2_onChanged()
{
    readXml1();
}

void AdvanceDialog::combox3_onChanged()
{
    readXml2();
}




void AdvanceDialog::on_pushButton_clicked()
{
    //拼接sql并显示
    QString firstcompare="";
    QString secondcompare="";
    QString thirdcompare="";
    if ((ui->comboBox->currentText())=="equal")
    {
        firstcompare="=";
    }
    else
    {
        firstcompare="!=";
    }
    if ((ui->comboBox_9->currentText())=="equal")
    {
        secondcompare="=";
    }
    else
    {
        secondcompare="!=";
    }

    thirdcompare=ui->comboBox_7->currentText()+" "+ui->comboBox_8->currentText();
    if ((ui->comboBox_7->currentText())=="Contains")
    {
        thirdcompare="like %"+ui->comboBox_8->currentText()+"%";
    }

    QString completeSQL= "select * from customers where ( "+ui->comboBox->currentText()+" "+firstcompare+" "+"'"+ui->comboBox_3->currentText()+"'"+
            +" ) and ( "+ui->comboBox_4->currentText()+" "+secondcompare+" "+"'"+ui->comboBox_5->currentText()+"'"
            +" ) or ( "
            +ui->comboBox_6->currentText()+" "+thirdcompare
            +" )";
    emit sendData(completeSQL);
    this->close();

}

void AdvanceDialog::on_pushButton_2_clicked()
{
    //重载所有选项
    init();

}
