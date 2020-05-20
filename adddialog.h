#ifndef ADDDIALOG_H
#define ADDDIALOG_H
#include "mainwindow.h"
#include "task.h"
#include <QDialog>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = nullptr);
    ~addDialog();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::addDialog *ui;
};

//void MainWindow::print_task_on_table();

#endif // ADDDIALOG_H
