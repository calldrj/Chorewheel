#ifndef TASK_H
#define TASK_H

#include<string>
#include<vector>
#include<QString>
#include"mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

struct Date { int month, day, year; };
enum Priority_Level { Unset_priority = -1, Extreme = 0, Moderate = 1, Low = 2 };
enum Status { Unset_status = -1, On = 0, Off = 1, Deleted = 2 };
enum Categories { Unset_category = -1, Home = 0, School = 1, Gym = 2 };


class Task
{
private:
    QString         name;
    QString         cate;
    Status          stat;
    Priority_Level  prio;
    Date            start_date;
    Date            end_date;


public:
        // Default Constructor
        Task();

        // Set member functions
        void setName(QString);
        void setCategory(QString);
        void setStatus(Status);
        void setPriority(Priority_Level);
        void setStartDate(Date);
        void setEndDate(Date);




        // Get member functions
        QString         getName();
        QString         getCategory();
        Status          getStatus();
        Priority_Level  getPriority();
        Date            getStartDate();
        Date            getEndDate();

        // Destructor
        ~Task();

};

void checkOff(vector<Task> &, string);

void print_task(Task);

void deleteTask(vector<Task> &, QString);

QString print_date_toQString(Date);


#endif // TASK_H
