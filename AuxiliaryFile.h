#include"My_Include/General/GeneralHeader.h"
#include<fstream>

using json = nlohmann::json;


struct strctTask1{
    StackPP<char> PlanWork;
    Massiv<uPair<char, char>> dependence;
};

strctTask1 readJsonFileT1(const std::string& filename, const std::string& name){
    json jsFile;
    std::ifstream inputFile(filename);
    
    if(!inputFile.is_open()){
        throw std::runtime_error("Не удалось открыть файл");
    }

    inputFile >> jsFile;

    if(jsFile.contains(name)){
        strctTask1 strc;
        size_t Plansize = jsFile[name]["PlanSize"].get<size_t>();
        size_t Depensize = jsFile[name]["DependenceSize"].get<size_t>();

        if (Plansize > jsFile[name]["PlanWork"].size()){
            throw std::runtime_error("Размер PlanSize больше доступных элементов");
        }

        for(size_t q = 0; q < Plansize; q++){
            strc.PlanWork.SPUSH(jsFile[name]["PlanWork"][q].get<std::string>()[0]);
        }

        if(Depensize > jsFile[name]["DependenceList"].size()){
            throw std::runtime_error("Размер DependenceSize больше доступных элементов");
        }

        for(size_t q = 0; q < Depensize; q++){
            auto dep = jsFile[name]["DependenceList"][q];
            char depChar = dep["dependence"].get<std::string>()[0];
            char blockChar = dep["block"].get<std::string>()[0];
            strc.dependence.MPUSH({depChar, blockChar});
        }
        
        return strc;
    }
    else{
        throw std::runtime_error("Не нашли то, что хотели");
    }
}


struct strctTask3{
    uSet<int> set;
};

strctTask3 readJsonFileT3(const std::string& filename, const std::string& name){
        json jsFile;
        std::ifstream inputFile(filename);
        if(inputFile.is_open()){
            inputFile >> jsFile;
            inputFile.close();
        }

        if(jsFile.contains(name)){
            strctTask3 strc;
            size_t sizeSet = jsFile[name]["Size"].get<size_t>();
            
            for(size_t q = 0; q < sizeSet; q++){
                strc.set.SETADD(jsFile[name]["OriginalSet"][q].get<int>());
            }
            return strc;
        } 
        else{
            throw std::runtime_error("не нашли то что хотели");
        }
}

struct strctTask4{
    Massiv<int16_t> SubMas;
    int16_t purpose;
};

strctTask4 readJsonFileT4(const std::string& filename, const std::string& name){
        json jsFile;
        std::ifstream inputFile(filename);
        if(inputFile.is_open()){
            inputFile >> jsFile;
            inputFile.close();
        }

        if(jsFile.contains(name)){
            strctTask4 strc;
            size_t sizeMass = jsFile[name]["Size"].get<size_t>();
            strc.purpose = jsFile[name]["Purpose"].get<int16_t>();
            for(size_t q = 0; q < sizeMass; q++){
                strc.SubMas.MPUSH(jsFile[name]["OriginalMassiv"][q].get<int16_t>());
            }
            return strc;
        } 
        else{
            throw std::runtime_error("не нашли то что хотели");
        }
}

struct strctTask5{
    BinaryTree<int16_t> ntree;
};

strctTask5 readJsonFileT5(const std::string& filename, const std::string& name){
        json jsFile;
        std::ifstream inputFile(filename);
        if(inputFile.is_open()){
            inputFile >> jsFile;
            inputFile.close();
        }

        if(jsFile.contains(name)){
            strctTask5 strc;
            size_t sizeBT = jsFile[name]["Size"].get<size_t>();
            
            for(size_t q = 0; q < sizeBT; q++){
                strc.ntree.insert(jsFile[name]["OriginalTree"][q].get<int16_t>());
            }
            return strc;
        } 
        else{
            throw std::runtime_error("не нашли то что хотели");
        }
}