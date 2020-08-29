#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "advancedialog.h"
#include "databasepresenter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialize();
    void initNodeTable();
    void compposesql(QString data);
public slots:

    void updateData(QString data);
    void pressBtn();
private:
    Ui::MainWindow *ui;
    AdvanceDialog *dialog;
    DatabasePresenter *databasepresenter;




};

#endif // MAINWINDOW_H
