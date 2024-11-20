#include"lab2.h"


// ./lab2 --file lab2Jsonfile.json --Task Task3
// ./lab2 --file lab2Jsonfile.json --query USETADD mySet ABC324
int main(int argc, char* argv[]){
    inputedData inputed;
    assignmentProcess(argc, argv, inputed);    

    size_t codeTask = defineTask(inputed.command);
    size_t codeStructu = concrectAssigmentStruct(inputed.command);

    switch(codeTask){
        case enumTasks::Task1:{
            strctTask1 entry = readJsonFileT1(inputed.namefile, inputed.command);
            StackPP<char> PlanWorkStack = entry.PlanWork;
            Massiv<uPair<char, char>> dependence = entry.dependence;
            std::cout << "Задание 1\nПорядок задач: ";
            PlanWorkStack.SGET();
            std::cout << "\nЛист зависимости: ";
            dependence.MGET();
            isWorkDone(PlanWorkStack, dependence);
            break;
        }
        case enumTasks::Task2:{
            strData entry = readstrJSON(inputed.namefile, inputed.namestructu, codeStructu);
            uSet<int> set = convertSet(entry);
            CaseSet(set, inputed.command, inputed.value);
            entry = SetToEntry(set);
            entry.Name = inputed.namestructu;
            PushJSON(inputed.namefile, entry);
            break;
        }
        case enumTasks::Task3:{
            strctTask3 entry = readJsonFileT3(inputed.namefile, inputed.command);
            uSet<int> originalSet = entry.set;
            Massiv<uSet<int>> subSets = AllSubSets(originalSet);
            int tsel = (originalSet.summ() % 2 == 0) ? originalSet.summ() / 2 : (originalSet.summ() / 2) + 1;
            uSet<int> Set1 = findSummSet(subSets, tsel, 5);
            uSet<int> Set2 = originalSet - Set1; 
            std::cout << "Задание 3\nИзначальное множество: ";
            originalSet.SETGETLINE();
            std::cout << "Подмножество1: ";
            Set1.SETGETLINE();
            std::cout << "Подмножество2: ";
            Set2.SETGETLINE();
            std::cout << "Разница: " << Set1.summ() - Set2.summ() << '\n'; 
            break;
        }
        case enumTasks::Task4:{
            strctTask4 entry = readJsonFileT4(inputed.namefile, inputed.command);
            Massiv<int16_t> originalMassiv = entry.SubMas;
            int16_t purpose = entry.purpose;
            Massiv<Massiv<int16_t>> SubMas = AllSubMass(originalMassiv);
            Massiv<Massiv<int16_t>> answer = CorrectSubMass(originalMassiv, purpose);
            std::cout << "Задание 4\nЦель: " << purpose << "\nИзначальный массив: ";
            originalMassiv.MGET();
            std::cout << "Линейные подмасивы равные цели:\n";
            cout << answer << '\n';
            break;
        }
        case enumTasks::Task5:{
            strctTask5 entry = readJsonFileT5(inputed.namefile, inputed.command);
            BinaryTree<int16_t> BT = entry.ntree;
            std::cout << "Задание 5\n Простой вывод дерева: ";
            BT.get();
            std::cout << "\nВывод дерева с лева на право: ";
            BT.getZigZag(BT, false);
            std::cout << "\nВывод дерева с права на лево: ";
            BT.getZigZag(BT, true);
            std::cout << '\n';
            break;
        }
        case enumTasks::Task6:{
            strctTask6 entry = readJsonFileT6(inputed.namefile, inputed.namestructu, codeStructu);
            BloomFilter Bl = convertBl(entry);
            CaseBF(inputed.command, inputed.value, Bl);
            entry = BlToEntry(Bl);
            entry.Name = inputed.namestructu;
            PushJSON(inputed.namefile, entry);
            break;
        }
        
        default:
            break;
    }

    return 0;
}
