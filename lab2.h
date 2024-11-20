#pragma once
#include"lab2.h"
#include"AuxiliaryFile.h"
#include"Task1.h"
#include"Task3.h"
#include"Task4.h"
#include"Task6.h"


enum enumTasks{
    Task1 = 1,
    Task2 = 2,
    Task3 = 3,
    Task4 = 4,
    Task5 = 5,
    Task6 = 6
};

enum enumBF{
    BCLEAR = 0,
    BINSERT = 1,
    BFIND = 2
};

struct inputedData{
    std::string namefile;
    std::string namestructu;
    std::string command; // 3 или task
    std::string value; // 4
     
};

Massiv<std::string> argvToMass(int argc, char* argv[]){
    Massiv<std::string> retMass;
    if(argc < 3 || argc > 7){
        cerr << "Неверный ввод команды!\n\n";
    }
    for(size_t q = 1; q < argc; q++){
        retMass.MPUSH(argv[q]);
    }
    return retMass;
}

void assignmentProcess(int argc, char* argv[], inputedData& listcommd){
    Massiv<std::string> ctrlMass = argvToMass(argc, argv);
    if(ctrlMass.MLength() == 4){
        if(ctrlMass[0] == "--file" && ctrlMass[2] == "--Task"){
            listcommd.namefile = ctrlMass[1];
            listcommd.command = ctrlMass[3];
            return;
        }
    }
    else if(ctrlMass.MLength() == 5){
    if(ctrlMass[0] == "--file" && ctrlMass[2] == "--query"){
            listcommd.namefile = ctrlMass[1];
            listcommd.command = ctrlMass[3];
            listcommd.namestructu = ctrlMass[4];
        }
    }
    else if(ctrlMass.MLength() == 6){
        if(ctrlMass[0] == "--file" && ctrlMass[2] == "--query"){
            listcommd.namefile = ctrlMass[1];
            listcommd.command = ctrlMass[3];
            listcommd.namestructu = ctrlMass[4];
            listcommd.value = ctrlMass[5];
        }
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
    else if(task[0] == 'U'){
        return 2;
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
    else if(task[0] == 'B'){
        return 6;
    }
    return 0;
}

void CaseBF(std::string command, std::string value, BloomFilter& HT){
    size_t codeCommand = defineComandBF(command);
    switch(codeCommand){
        case enumBF::BCLEAR:{
            HT.BCLEAR();
            break;
        }
        case enumBF::BINSERT:{
            HT.BADD(value);
            break;
        }
        case enumBF::BFIND:{
            cout << HT.BFIND(value) << '\n';
            break;
        }
        default:
            std::cout << "\nНичего не произошло\n";
            break;
    }
}