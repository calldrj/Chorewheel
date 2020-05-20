#pragma warning(disable : 4996)
/*
    Project_380.cpp
    Created by TUAN NGUYEN on 10/11/19.
*/

// Implementation of Task class
#include <string>
#include <ctime>
#include <iostream>
#include <algorithm> // std::shuffle
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock
#include <map>
#include "task.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;


// Default constructor sets an empty task with default dates
Task::Task()
{
    QString name = "";
    cate = Unset_category; prio = Unset_priority; stat = Unset_status;
    auto    t = time(0);
    tm* now = localtime(&t);
    // Set default starting date
    start_date = { start_date.month = now->tm_mon + 1,        // Set current month
                   start_date.day = now->tm_mday,           // Set current day
                   start_date.year = now->tm_year + 1900 };  // Set current year
    // Set default ending date
    end_date = { end_date.month = now->tm_mon + 1,        // Set current month
                   end_date.day = now->tm_mday,           // Set current day
                   end_date.year = now->tm_year + 2000 };  // Set 100 years ahead current year

}

void Task::setName(QString task_id) { name = task_id; }
void Task::setCategory(QString task_category) { cate = task_category; }
void Task::setStatus(Status task_status) { stat = task_status; }
void Task::setPriority(Priority_Level task_priority) { prio = task_priority; }
void Task::setStartDate(Date task_start_date) {
    start_date = { start_date.month = task_start_date.month,
                   start_date.day = task_start_date.day,
                   start_date.year = task_start_date.year };
}
void Task::setEndDate(Date task_end_date) {
    end_date = { end_date.month = task_end_date.month,
                 end_date.day = task_end_date.day,
                 end_date.year = task_end_date.year };
}
/*void Task::setCompleted(bool check_off) {
    completed = check_off;
}*/


QString         Task::getName() { return name; }
QString         Task::getCategory() { return cate; }
Status          Task::getStatus() { return stat; }
Priority_Level  Task::getPriority() { return prio; }
Date            Task::getStartDate() { return start_date; }
Date            Task::getEndDate() { return end_date; }

// Destructor does nothing
Task::~Task() { }

void checkOff(vector<Task> &my_todo_list, QString name) {
    /* Purpose : Finds index of "name" in my_todo_list
                 Sets Status to [Off] */

    unsigned int cOff; // cOff = check off
    bool found = false;

    for (unsigned int i = 0; i < my_todo_list.size(); i++) {
        if (my_todo_list[i].getName() == name) {
            found = true;
            cOff = i;
        }
    }

    if (found == true) {
        my_todo_list[cOff].setStatus(Off);
    }
    else {
        cout << "ERROR: name of Task not found.\n";
    }
}

void swap(Task &a, Task &b)
{
    Task temp;
    temp = a;
    a = b;
    b = temp;
    return;
}

QString print_date_toQString(Date dateNum){

    QString QDate = QString::number(dateNum.month) + '/' + QString::number(dateNum.day) + '/' + QString::number(dateNum.year);

    return QDate;
}

/*****************************************************************************************/
//beginning of delteTask function written by Sarah
//this function will delete a given task in the todo list when provided
//with the task name that the user is looking to delete
void deleteTask(vector<Task> &my_todo_list, QString task_name) {
    for (int i = 0; i < my_todo_list.size(); i++) {
        Task temp = my_todo_list[i];
        QString name = temp.getName();
        int check = task_name.compare(name);
        if (check == 0) {
            my_todo_list.erase(my_todo_list.begin() + i);
        }
    }
}

//end of deleteTask function
