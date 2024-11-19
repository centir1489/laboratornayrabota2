#pragma once
#ifndef HASHTABLE
#define HASHTABLE

#include<iostream>
#include<math.h>

const double GoldenRatio = 0.6180339887;

struct HNode{
    std::string Key = "";
    std::string Data = "";
};

struct HashTable{
    HNode* Table;
    size_t Capacity;
    size_t Size = 0;


    HashTable(size_t Size){
        Table = new HNode[Size];      
        Capacity = Size;
    }

    bool CheckSizeTable(std::string Key){
        Size = HSize();
        if(Size == Capacity && HFind(Key) == ""){
            return true;
        }
        return false;
    }

    size_t HSize(){
        size_t Amount = 0;
        for(size_t q = 0; q < Capacity; q++){
            if(Table[q].Key != ""){
                Amount += 1;
            }
        }
        return Amount;
    }   

    bool CheckIndex(size_t Index, std::string Key){
        if(Table[Index].Key == Key || Table[Index].Key == ""){
            return true;
        }
        return false;
    }

    size_t FindIndex(std::string Key){
        size_t Index = HashFn(Key);
        size_t Capacity = this -> Capacity;
        bool isFreeIndex = CheckIndex(Index, Key);
        while(!isFreeIndex && Capacity--){
            if(!CheckIndex(Index, Key)){
                Index++;
                Index %= this -> Capacity;
                isFreeIndex = CheckIndex(Index, Key);
                continue;   
            }
        }
        return Index;
    }


    HNode& operator[](std::string Key){
        size_t FreeIndex = FindIndex(Key);
        return *(Table + FreeIndex);
    }

    size_t SummASCI(std::string Key){
        size_t Summ;
        for(size_t q = 0; q < Key.length(); q++){
            Summ += size_t(Key[q]);
        }
        return Summ;
    }    

    size_t HashFn(std::string Key){
        size_t Summ = SummASCI(Key);
        double first = Summ * GoldenRatio;
        double second = first - int(first);
        size_t Pos = size_t(Capacity * second);
        return Pos;
    }

    void HGET(){
        Size = HSize();
        if(Size == 0){
            return;
        }
        for(size_t q = 0; q < Capacity; q++){
            if(Table[q].Key == ""){
                continue;
            }
            std::cout << q << '\t' << Table[q].Key << '\t' << Table[q].Data << '\n';
        }  
    }

    void HPUSH(std::string Key, std::string Value){
        if(CheckSizeTable(Key)){
            std::cout << "filled table\n";
            return;
        }
        size_t Pos = FindIndex(Key);
        Table[Pos] = {Key, Value};
    }


    void HDEL(std::string Key){
        size_t Pos = FindIndex(Key);
        if(Table[Pos].Key == ""){
            return;
        }
        Table[Pos] = {"", ""};
    }

    std::string HFind(std::string Key){
        size_t Pos = FindIndex(Key);
        if(Table[Pos].Key == Key){
            return Table[Pos].Data;
        }
        return "";
    }

};

#endif