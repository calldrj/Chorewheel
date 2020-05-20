#include "global.h"

bool compareName(Task lhs, Task rhs){ 
    QString left = lhs.getName().toLower(), right = rhs.getName().toLower();
    for( QString::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
          if( *lit < *rit )
             return true;
          else if( *lit > *rit )
             return false;
     return left.size() < right.size();
}

bool compareCategory(Task lhs, Task rhs){
    QString left = lhs.getCategory().toLower(), right = rhs.getCategory().toLower();
    for( QString::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
          if( *lit < *rit )
             return true;
          else if( *lit > *rit )
             return false;
     return left.size() < right.size();
}

bool comparePriority(Task lhs, Task rhs){
    return lhs.getPriority() < rhs.getPriority();
}

bool compareStatus(Task lhs, Task rhs){ // from Josh Ortiz
    return lhs.getStatus() < rhs.getStatus();
}
bool compareStartDate(Task lhs, Task rhs){ // From Simran Gill
    if(lhs.getStartDate().year < rhs.getStartDate().year)
        return true;
    if(lhs.getStartDate().year == rhs.getStartDate().year
            && lhs.getStartDate().month < rhs.getStartDate().month)
        return true;
    if(lhs.getStartDate().year == rhs.getStartDate().year
            && lhs.getStartDate().month == rhs.getStartDate().month
               & lhs.getStartDate().day < rhs.getStartDate().day)
        return true;

    return false;

}

void noSort(){ // From Josh Ortiz, used for mapping
}

void alphabeticalSort(){ // from Josh Ortiz
    sort(myTasks.begin(),myTasks.end(),compareName);
}

void categorySort(){ // From Josh Ortiz
    sort(myTasks.begin(),myTasks.end(),compareCategory);
}

void prioritySort(){ // from Tracy's branch
    for (unsigned int i = 0; i < myTasks.size() - 1; i++)
            for (unsigned int j = i; j < myTasks.size() - 1; j++)
                if (myTasks[j].getPriority() > myTasks[j + 1].getPriority())
                    swap(myTasks[j], myTasks[j + 1]);
}

void startDateSort(){ // From Simran Gill

 sort(myTasks.begin(),myTasks.end(),compareStartDate);

}
void endDateSort(){ // from Joshua's Branch
    unsigned int i = 0;
    while(i<myTasks.size()){
        for(unsigned int x = i+1; x< myTasks.size(); x++){
            if(myTasks[i].getEndDate().year > myTasks[x].getEndDate().year)
                swap(myTasks[i],myTasks[x]);
            if(myTasks[i].getEndDate().month > myTasks[x].getEndDate().month){
                if(myTasks[i].getEndDate().year > myTasks[x].getEndDate().year)
                    swap(myTasks[i],myTasks[x]);
                else if(myTasks[i].getEndDate().year < myTasks[x].getEndDate().year){}
                if(myTasks[i].getEndDate().year == myTasks[x].getEndDate().year)
                    swap(myTasks[i],myTasks[x]);
            }
            if(myTasks[i].getEndDate().day > myTasks[x].getEndDate().day){
                if(myTasks[i].getEndDate().year > myTasks[x].getEndDate().year)
                    swap(myTasks[i],myTasks[x]);
                else if(myTasks[i].getEndDate().year < myTasks[x].getEndDate().year){}
                else if(myTasks[i].getEndDate().year == myTasks[x].getEndDate().year){
                    if(myTasks[i].getEndDate().month == myTasks[x].getEndDate().month)
                        swap(myTasks[i],myTasks[x]);
                    else if(myTasks[i].getEndDate().month > myTasks[x].getEndDate().month)
                        swap(myTasks[i],myTasks[x]);
                    else if(myTasks[i].getEndDate().month < myTasks[x].getEndDate().month){}

                }
            }
        }
        i++;
    }
}

void statusSort(){ // From Josh Ortiz
    sort(myTasks.begin(),myTasks.end(),compareStatus);
}