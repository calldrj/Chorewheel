#include "editdialog.h"
#include "ui_editdialog.h"
#include "task.h"
#include "global.h"
#include "mainwindow.h"
#include <QInputDialog>
#include <QComboBox>

using namespace std;

editDialog::editDialog(QWidget *parent) :QDialog(parent),ui(new Ui::editDialog){
    ui->setupUi(this);
    this->setWindowTitle("Edit Task");
    setWindowIcon(QIcon(":/icons/icons/chorewheelicon.png"));

    QStringList priorContent = {"Low", "Moderate", "Extreme"};
    ui->comboBox->addItems(priorContent);
}

editDialog::~editDialog(){
    delete ui;
}

void editDialog::taskToEdit(const int & taskNum){
    this->taskNum = taskNum;
    Task ex = myTasks[this->taskNum];
    ui->lineEdit->setText(ex.getName());
    ui->lineEdit_2->setText(ex.getCategory());
    ui->comboBox->setCurrentText(priorityToStr[ex.getPriority()]);
    ui->lineEdit_4->setText(QString::number(ex.getStartDate().month));
    ui->lineEdit_5->setText(QString::number(ex.getStartDate().day));
    ui->lineEdit_6->setText(QString::number(ex.getStartDate().year));
    ui->lineEdit_7->setText(QString::number(ex.getEndDate().month));
    ui->lineEdit_8->setText(QString::number(ex.getEndDate().day));
    ui->lineEdit_9->setText(QString::number(ex.getEndDate().year));
}

// Setting Tasks when accepted
void editDialog::on_buttonBox_accepted(){
    Task ex;

    // Task name input
    QString QtaskName = ui->lineEdit->text();
    ex.setName(QtaskName);

    // Category input
    QString Qcategory = ui->lineEdit_2->text();
    ex.setCategory(Qcategory);

    // Priority input
    QString Qpriority = ui->comboBox->currentText();
    ex.setPriority(strToPriority[Qpriority]);

    Date startDate, endDate;

    // Start Date input
    QString QstartMonth = ui->lineEdit_4->text();
    int startMonth = QstartMonth.toInt();
    startDate.month = startMonth;

    QString QstartDay = ui->lineEdit_5->text();
    int startDay = QstartDay.toInt();
    startDate.day = startDay;

    QString QstartYear = ui->lineEdit_6->text();
    int startYear = QstartYear.toInt();
    startDate.year = startYear;

    ex.setStartDate(startDate);

    // End Date input
    QString QendMonth = ui->lineEdit_7->text();
    int endMonth = QendMonth.toInt();
    endDate.month = endMonth;

    QString QendDay = ui->lineEdit_8->text();
    int endDay = QendDay.toInt();
    endDate.day = endDay;

    QString QendYear = ui->lineEdit_9->text();
    int endYear = QendYear.toInt();
    endDate.year = endYear;

    ex.setEndDate(endDate);

    // Default set status On
    ex.setStatus(On);

    myTasks[this->taskNum] = ex;
}
