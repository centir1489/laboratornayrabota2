#pragma once
#include<iostream>


const double GoldenRatio2 = 0.6180339887;

template<typename gen_t>
struct uSet{
    gen_t* table;
    size_t size;
    size_t length;

    uSet(): size(100), length(0), table(new gen_t[100]){
        for(size_t q = 0; q < size; q++){
            table[q] = 0;
        }
    }
    
    uSet(size_t size){ 
        this -> size = size;
        length = 0; 
        table = new gen_t[size];
        for(size_t q = 0; q < size; q++){
            table[q] = 0;
        }
    }

    uSet<gen_t>& operator=(uSet<gen_t>& othrSet){
        if(this != &othrSet){
            delete[] table;
            length = othrSet.length;
            size = othrSet.size;
            if(size > 0){
                table = new gen_t[size];
                for(size_t q = 0; q < size; q++){
                    table[q] = othrSet.table[q];
                }
            } 
            else{
                table = nullptr;
            }
        }
        return *this;
    }


    uSet(std::initializer_list<gen_t> mass) : size((2 * mass.size())), length(mass.size()), table(new gen_t[2 * mass.size()]){
        for(gen_t item : mass){
            if(CheckLengthTable(item)){
                std::cout << "filled Set\n";
                return;
            }
            size_t Index = FindIndex(item);
            table[Index] = item;
        }
    }

    gen_t& operator[](size_t index){
        if(index < 0 || index >= size){
                throw std::out_of_range("INDEX_OUT");
            }
            return table[index];
    }

    uSet<gen_t> operator-(uSet<gen_t> other){
        uSet<gen_t> result;
        for(size_t q = 0; q < size; q++){
            if((table[q] != -1 || table[q] != 0) && !other.SET_AT(table[q])){
                result.SETADD(table[q]);
            }
        }
        return result;
    }

    bool CheckLengthTable(gen_t Value){
        length = SETLength();
        if(size == length && SET_AT(Value) == true){
            return true;
        }
        return false;
    }


    size_t HashFn(gen_t Value){
        double first = Value * GoldenRatio2;
        double second = first - int(first);
        size_t Pos = size_t(size * second);
        return Pos;
    }
    size_t SETLength(){
        size_t Amount = 0;
        for(size_t q = 0; q < size; q++){
            if(table[q] != -1 && table[q] != 0){
                Amount += 1;
            }
        }
        return Amount;
    }   

    bool CheckIndex(size_t Index, gen_t Value){
        if(table[Index] != Value){
            return false;
        }
        return true;
    }

    size_t FindIndex(gen_t Value){
        size_t Index = HashFn(Value);
        size_t size = this -> size;
        bool isFreeIndex = CheckIndex(Index, Value);
        while(!isFreeIndex && size--){
            if(!CheckIndex(Index, Value)){
                Index++;
                Index %= this -> size;
                isFreeIndex = CheckIndex(Index, Value);
                continue;   
            }
        }
        return Index;
    }

    void SETADD(gen_t Value){
        if(CheckLengthTable(Value)){
            std::cout << "filled Set\n";
            return;
        }
        size_t Index = FindIndex(Value);
        table[Index] = Value;
    }

    void SETGET(){
        length = SETLength();
        if(length == 0){
            return;
        }
        for(size_t q = 0; q < size; q++){
            if(table[q] == -1){
                continue;
            }
            std::cout << q << '\t' << table[q] << '\n';
        }  
        std::cout << '\n';
    }

    void SETGETLINE(){
        length = SETLength();
        if(length == 0){
            return;
        }
        for(size_t q = 0; q < size; q++){
            if(table[q] == -1 || table[q] == 0){
                continue;
            }
            std::cout << table[q] << ' ';
        }  
        std::cout << '\n';
    }

    void SETDEL(gen_t Value){
        table[FindIndex(Value)] = -1;
    }

    bool SET_AT(gen_t Value){
        if(table[FindIndex(Value)] == Value){
            return true;
        }
        return false;
    }

    int summ(){
        length = SETLength();
        if(length == 0){
            return 0;
        }
        int summ = 0;
        for(size_t q = 0; q < size; q++){
            if(table[q] != 0){
                summ += table[q];
            }
        }
        return summ;
    }

};