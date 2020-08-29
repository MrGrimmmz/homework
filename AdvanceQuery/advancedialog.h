#ifndef ADVANCEDIALOG_H
#define ADVANCEDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QtCore/qvariant.h>
namespace Ui {
class AdvanceDialog;
}

class AdvanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdvanceDialog(QWidget *parent = nullptr);
    ~AdvanceDialog();
     void init ();
     void readXml();
     void readXml1();
     void readXml2();
     void initconnection();



signals:
    //void on_Combox_Changeed();

     void sendData(QString data);

public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void combox_onChanged();
    void combox2_onChanged();
    void combox3_onChanged();

private:
    Ui::AdvanceDialog *ui;
};

#endif // ADVANCEDIALOG_H
