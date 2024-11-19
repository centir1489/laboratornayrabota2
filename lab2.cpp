#include"lab2.h"



int main(int argc, char* argv[]){
    std::string Choice, file;
    assignmentProcess(argc, argv, file, Choice);    
    size_t codeTask = defineTask(Choice);
    switch(codeTask){
        case enumTasks::Task1:{
            strctTask1 entry = readJsonFileT1(file, Choice);
            StackPP<char> PlanWorkStack = entry.PlanWork;
            Massiv<uPair<char, char>> dependence = entry.dependence;
            std::cout << "Задание 1\nПорядок задач: ";
            PlanWorkStack.SGET();
            std::cout << "\nЛист зависимости: ";
            dependence.MGET();
            if(isWorkDone(PlanWorkStack, dependence)){
                cout << "Возможно!\n";
            }
            else{
                cout << "Невозможно!\n";
            }
            break;
        }
        case enumTasks::Task3:{
            strctTask3 entry = readJsonFileT3(file, Choice);
            uSet<int> originalSet = entry.set;
            Massiv<uSet<int>> subSets = AllSubSets(originalSet);
            int tsel = (originalSet.summ() / 2);
            uSet<int> Set1 = findSummSet(subSets, tsel, 5);
            uSet<int> Set2 = originalSet - Set1; 
            std::cout << "Задание 3\nИзначальное множество: ";
            originalSet.SETGETLINE();
            std::cout << "Подмножество1: ";
            Set1.SETGETLINE();
            std::cout << "Подмножество2: ";
            Set2.SETGETLINE();
            break;
        }
        case enumTasks::Task4:{
            strctTask4 entry = readJsonFileT4(file, Choice);
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
            strctTask5 entry = readJsonFileT5(file, Choice);
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
            std::string command;
            BloomFilter HT(100, 3);
            bool isExit = false;
            std::cout << "Задание 6\n Вводите команды для фильтра Блума:\n";
            while(true){
                cout << '>';
                getline(cin, command);
                Massiv<std::string> ctrlMas = readlineInput(command);
                CaseBF(ctrlMas, HT, isExit);
                if(isExit){
                    break;
                }
            }
            break;
        }
        
        default:
            break;
    }

    return 0;
}
