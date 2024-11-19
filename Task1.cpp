#include"Task1.h"

void updateDependence(Massiv<uPair<char, char>>& dependenceTasks, Massiv<char> completeTasks){
    if(completeTasks.isEmpty()){
        return;
    }
    for(size_t q = 0; q < dependenceTasks.MLength(); q++){
        if(completeTasks.FindValue(dependenceTasks[q].second)){
            dependenceTasks.MPOP(q);
        }
    }
}

Massiv<char> updateStatTasks(Massiv<uPair<char, char>>& dependenceTasks, Massiv<char> completeTasks){
    updateDependence(dependenceTasks, completeTasks);
    Massiv<char> updateTasks;
    for(size_t q = 0; q < dependenceTasks.MLength(); q++){
        updateTasks.MPUSH(dependenceTasks[q].first);
    }
    return updateTasks;


}

bool isWorkDone(StackPP<char> ordTasks, Massiv<uPair<char, char>> dependenceTasks){
    Massiv<char> completeTasks;
    Massiv<char> zapretTasks = updateStatTasks(dependenceTasks, completeTasks); 
    while(!ordTasks.IsEmpty()){
        if(!zapretTasks.FindValue(ordTasks.top())){
            completeTasks.MPUSH(ordTasks.top());
            zapretTasks = updateStatTasks(dependenceTasks, completeTasks);
            ordTasks.SPOP();
        }
        else{
            return false;
        }
    }

    return true;

}