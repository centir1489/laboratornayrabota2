#include"Task1.h"

bool RemoveFact(uPair<char, char>& firstPairDepen, uPair<char, char>& secondPairDepen){
    if((firstPairDepen.first == secondPairDepen.first && firstPairDepen.second == secondPairDepen.second) || (firstPairDepen.first == firstPairDepen.second)){
        return true;
    }
    return false;
}

void RemovePovtor(Massiv<uPair<char, char>>& dependenceTasks){
    for(size_t q = 0; q < dependenceTasks.MLength(); q++){
        for(size_t p = q; p < dependenceTasks.MLength(); p++){
            if(RemoveFact(dependenceTasks[q], dependenceTasks[p])){
                dependenceTasks.MPOP(q);
            }
        }
    }
}

void updateDependence(Massiv<uPair<char, char>>& dependenceTasks, Massiv<char> completeTasks){
    if(completeTasks.isEmpty()){
        return;
    }
    for(size_t q = 0; q < dependenceTasks.MLength(); q++){
        if(completeTasks.FindValue(dependenceTasks[q].second)){
            dependenceTasks.MPOP(q);
        }
    }
    RemovePovtor(dependenceTasks);
}

Massiv<char> updateStatTasks(Massiv<uPair<char, char>>& dependenceTasks, Massiv<char> completeTasks){
    updateDependence(dependenceTasks, completeTasks);
    Massiv<char> updateTasks;
    for(size_t q = 0; q < dependenceTasks.MLength(); q++){
        updateTasks.MPUSH(dependenceTasks[q].first);
    }
    return updateTasks;


}

void isWorkDone(StackPP<char> ordTasks, Massiv<uPair<char, char>> dependenceTasks){
    Massiv<char> completeTasks;
    Massiv<char> zapretTasks = updateStatTasks(dependenceTasks, completeTasks);
    while(!ordTasks.IsEmpty()){
        // std::cout << "Check: " << ordTasks.top() << "\nzapret " << zapretTasks << "compl: " << completeTasks << '\n';
        if(!zapretTasks.FindValue(ordTasks.top())){
            completeTasks.MPUSH(ordTasks.top());
            zapretTasks = updateStatTasks(dependenceTasks, completeTasks);
            ordTasks.SPOP();
        }
        else{
            std::cout << "Невозможно!\n";
            return;
        }
    }
    std::cout << "Возможно!\n";
}