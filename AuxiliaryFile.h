#include"My_Include/General/GeneralHeader.h"
#include"Task6.h"
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
            char depChar = dep["1_dependence"].get<std::string>()[0];
            char blockChar = dep["2_Blocker"].get<std::string>()[0];
            strc.dependence.MPUSH({depChar, blockChar});
        }
        
        return strc;
    }
    else{
        throw std::runtime_error("Не нашли то, что хотели");
    }
}



size_t concrectAssigmentStruct(std::string Command){
    char symb = Command[0];
    if(symb == 'M'){
        return 1;
    }
    else if(symb == 'L'){
        return 2;
    }
    else if(symb == 'D'){
        return 3;
    }
    else if(symb == 'S'){
        return 4;
    }
    else if(symb == 'Q'){
        return 5;
    }
    else if(symb == 'H'){
        return 6;
    }
    else if(symb == 'T'){
        return 7;
    }
    else if(symb == 'U'){
        return 8;
    }
    else if(symb == 'B'){
        return 9;
    }
    return 0;
}

std::string definieTypeStructu(size_t codeStructu){
    if(codeStructu == 1){
        return "Massiv";
    }
    else if(codeStructu == 2){
        return "LinkedList";
    }
    else if(codeStructu == 3){
        return "DoubleLinkedList";
    }
    else if(codeStructu == 4){
        return "Stack";
    }
    else if(codeStructu == 5){
        return "Queue";
    }
    else if(codeStructu == 6){
        return "HashTable";
    }
    else if(codeStructu == 7){
        return "AVL-Tree";
    }
    else if(codeStructu == 8){
        return "Set";
    }
    else if(codeStructu == 9){
        return "BloomFiltr";
    }
    return "";
}

void CaseSet(uSet<int>& set, std::string Command, std::string Value1){
    if(Command == "USETADD"){
        set.SETADD(atoi(Value1.c_str()));
    }
    else if(Command == "USETDEL"){
        set.SETDEL(atoi(Value1.c_str()));
    }
    else if(Command == "USET_AT"){
        std::cout << set.SET_AT(atoi(Value1.c_str())) << '\n';
    }
    else if(Command == "USETLENGTH"){
        std::cout << set.SETLength() << '\n';
    }
    else if(Command == "USETGET"){
        set.SETGET();
    }
    else if(Command == "USETGETLINE"){
        set.SETGETLINE();
    }
}


struct strData{
    std::string Name;
    std::string Structu;
    std::string* Data; 
    size_t Size;       
    size_t Capacity;
};

uSet<int> convertSet(strData entry){
    uSet<int> bfSet(entry.Capacity);
    for(size_t q = 0; q < entry.Size; q++){
        if(entry.Data[q] != ""){
            bfSet.SETADD(atoi(entry.Data[q].c_str()));
        }
    }
    return bfSet;
}

strData SetToEntry(uSet<int> set){
    strData entry;
    entry.Structu = "Set";
    entry.Size = set.SETLength();
    entry.Capacity = set.size;
    entry.Data = new std::string[entry.Size];
    size_t pos = 0;
    for(size_t q = 0; q < set.size; q++){
        if(set.table[q] != 0){
            entry.Data[pos++] = to_string(set.table[q]);
        }
    }
    return entry;
}

void PushJSON(const std::string& filename, const strData& structEntry){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }
    json bfMas = json::array();
    for(size_t q = 0; q < structEntry.Size; q++){
        bfMas.push_back(structEntry.Data[q]);
    }

    jsFile[structEntry.Name] = {
        {"Data", bfMas},
        {"Size", structEntry.Size},
        {"Structu", structEntry.Structu},
        {"Capacity", structEntry.Capacity}
    };

    std::ofstream outputFile(filename);
    outputFile << jsFile.dump(4);
    outputFile.close();
}

strData readstrJSON(const std::string& filename, const std::string& name, const size_t codeStructu){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }

    std::string entrstruct = definieTypeStructu(codeStructu);
    if(jsFile.contains(name) && entrstruct == jsFile[name]["Structu"].get<std::string>()){
        strData structEntry;
        structEntry.Name = name;
        structEntry.Structu = jsFile[name]["Structu"].get<std::string>();
        structEntry.Size = jsFile[name]["Size"].get<size_t>();
        structEntry.Capacity = jsFile[name]["Capacity"].get<size_t>();
        
        structEntry.Data = new std::string[structEntry.Capacity];
        for(size_t q = 0; q < structEntry.Size; q++){
            structEntry.Data[q] = jsFile[name]["Data"][q].get<std::string>();
        }
        return structEntry;
    } 
    else{
        throw std::runtime_error("не нашли то что хотели");
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

struct strctTask6{
    std::bitset<100> Bl;
    std::string Name;
    std::string Structu;
    size_t size;
    size_t amountHashFn;
    
};

BloomFilter convertBl(strctTask6 entry){
    BloomFilter retBl(100, 3);
    retBl.amountHashFn = entry.amountHashFn;
    retBl.bitset = entry.Bl;
    retBl.size = entry.size;
    return retBl;
}

strctTask6 BlToEntry(BloomFilter Bl){
    strctTask6 entry;
    entry.amountHashFn = Bl.amountHashFn;
    entry.Bl = Bl.bitset;
    entry.size = Bl.size;
    entry.Structu = "BloomFiltr";
    return entry;
}


void PushJSON(const std::string& filename, const strctTask6& structEntry){
    json jsFile;
    std::ifstream inputFile(filename);
    if(inputFile.is_open()){
        inputFile >> jsFile;
        inputFile.close();
    }
    jsFile[structEntry.Name] = {
        {"Size", structEntry.size},
        {"AmountHashFn", structEntry.amountHashFn},
        {"bitset", structEntry.Bl.to_string()},
        {"Structu", structEntry.Structu}
    };

    std::ofstream outputFile(filename);
    outputFile << jsFile.dump(4);
    outputFile.close();
}

strctTask6 readJsonFileT6(const std::string& filename, const std::string& name, const size_t& codeStructu){
        json jsFile;
        std::ifstream inputFile(filename);
        if(inputFile.is_open()){
            inputFile >> jsFile;
            inputFile.close();
        }
        std::string entrstruct = definieTypeStructu(codeStructu);
        if(jsFile.contains(name) && entrstruct == jsFile[name]["Structu"].get<std::string>()){
            strctTask6 strc;
            strc.size = jsFile[name]["Size"].get<size_t>();
            strc.amountHashFn = jsFile[name]["AmountHashFn"].get<size_t>();
            std::string bitset_str = jsFile[name]["bitset"].get<std::string>();
            strc.Bl = std::bitset<100>(bitset_str);
            return strc;
        } 
        else{
            throw std::runtime_error("не нашли то что хотели");
        }
}