#ifndef EDDDIALOG_H
#define EDDDIALOG_H
#include "mainwindow.h"
#include "task.h"
#include <QDialog>

namespace Ui {
    class editDialog;
}

class editDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editDialog(QWidget *parent = nullptr);
    ~editDialog();
    void taskToEdit(const int & taskNum);
private slots:

    void on_buttonBox_accepted();

private:
    Ui::editDialog *ui;
    int taskNum;
};

//void MainWindow::print_task_on_table();

#endif // EDDDIALOG_H
