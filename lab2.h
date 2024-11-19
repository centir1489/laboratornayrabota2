#pragma once
#include"lab2.h"
#include"AuxiliaryFile.h"
#include"Task1.h"
#include"Task3.h"
#include"Task4.h"
#include"Task6.h"


enum enumTasks{
    Task1 = 1,
    Task3 = 3,
    Task4 = 4,
    Task5 = 5,
    Task6 = 6
};

enum enumBF{
    BExit = 0,
    BInsert = 1,
    BFind = 2
};


Massiv<std::string> argvToMass(int argc, char* argv[]){
    Massiv<std::string> retMass;
    if(argc < 3 || argc > 5){
        cerr << "Неверный ввод команды!\n\n";
    }
    for(size_t q = 1; q < argc; q++){
        retMass.MPUSH(argv[q]);
    }
    return retMass;
}

void assignmentProcess(int argc, char* argv[], std::string& file, std::string& Task){
     Massiv<std::string> ctrlMass = argvToMass(argc, argv);
     if(ctrlMass[0] == "--file"){
        file = ctrlMass[1];
        if(ctrlMass[2] == "--Task"){
            Task = ctrlMass[3];
        }
    }
    else if(ctrlMass[0] == "--Task"){
        Task = ctrlMass[1];
    }
    else{
        cerr << "\nОШИБКА ВВОДА!\n";
        return;
    }
}

size_t defineTask(std::string task){
    if(task == "Task1"){
        return 1;
    }
    else if(task == "Task3"){
        return 3;
    }
    else if(task == "Task4"){
        return 4;
    }
    else if(task == "Task5"){
        return 5;
    }
    else if(task == "Task6"){
        return 6;
    }
    return 0;
}

Massiv<std::string> readlineInput(std::string command){
    command += ' ';
    string substr;
    Massiv<std::string> controlMass;
    for(size_t q = 0; q < command.size(); q++){
        if(command[q] == ' '){
            controlMass.MPUSH(substr);
            substr.clear();
        }
        substr += command[q];
    }
    return controlMass;
}

void CaseBF(Massiv<std::string> ctrlMass, BloomFilter& HT, bool& exit){
    size_t codeCommand = defineComandBF(ctrlMass);
    switch(codeCommand){
    case enumBF::BExit:{
        exit = true;
        break;
    }
    case enumBF::BInsert:{
        HT.BADD(ctrlMass[1]);
        break;
    }
    case enumBF::BFind:{
        cout << HT.BFIND(ctrlMass[1]) << '\n';
        break;
    }
    default:
        std::cout << "\nНичего не произошло\n";
        break;
    }
}