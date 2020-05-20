#include "adddialog.h"
#include "ui_adddialog.h"
#include "task.h"
#include "global.h"
#include "mainwindow.h"
#include <QInputDialog>
#include <QComboBox>

using namespace std;

//vector<Task> myTasks;

addDialog::addDialog(QWidget *parent) :QDialog(parent),ui(new Ui::addDialog){
    ui->setupUi(this);
    this->setWindowTitle("Add Task");
    setWindowIcon(QIcon(":/icons/icons/chorewheelicon.png"));

    QStringList priorContent = {"Low", "Moderate", "Extreme"};
    ui->comboBox->addItems(priorContent);

}

addDialog::~addDialog(){
    delete ui;
}

// Setting Tasks when accepted
void addDialog::on_buttonBox_accepted(){
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

    // Push to myTasks
    myTasks.push_back(ex);

}
