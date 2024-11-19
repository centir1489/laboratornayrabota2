#pragma once
#ifndef BLOOM_FILTR
#define BLOOM_FILTR
#include <iostream>
#include <fstream>
#include <bitset>

using json = nlohmann::json;

const double GoldenRatio_ = 0.6180339887;

struct BloomFilter{
    std::bitset<100> bitset;
    size_t size;
    size_t amountHashFn;
    
    BloomFilter(size_t size, size_t amounthsh) : size(size), amountHashFn(amounthsh) {}


    size_t SummASCI(std::string val){
            size_t Summ;
            for(size_t q = 0; q < val.length(); q++){
                Summ += size_t(val[q]);
            }
            return Summ;
    }    

    size_t hashFn1(std::string val){
        size_t Summ = SummASCI(val);
        double first = Summ * GoldenRatio_;
        double second = first - int(first);
        size_t hash = size_t(size * second);
        return (hash % size);
    }

    size_t hashFn2(const std::string& str){
        size_t hash = 5381;
        for(size_t c : str){
            hash = ((hash << 5) + hash) + c;
        }
        return (hash % size);
    }

    size_t hashFn3(const std::string& str) {
        size_t hash = 0;
        for(size_t q = 0; q < str.size(); q++){
            hash ^= (str[q] << (q % 8));
        }
        return (hash % size);
    }


    void BADD(std::string val){
        for(size_t q = 0; q < amountHashFn; q++){
            size_t hashval;
            if(q % 3 == 1){
                hashval = hashFn1(val);
            } 
            else if(q % 3 == 2){
                hashval = hashFn2(val);
            }
            else{
                hashval = hashFn3(val);
            }
            bitset.set(hashval);
        }
    }
    
    
    bool BFIND(std::string val){
          for(size_t q = 0; q < amountHashFn; q++){
            size_t hashval;
            if(q % 3 == 1){
                hashval = hashFn1(val);
            } 
            else if(q % 3 == 2){
                hashval = hashFn2(val);
            }
            else{
                hashval = hashFn3(val);
            }
            if(!bitset.test(hashval)){
                return false;
            }
        }
        return true;
    }
};

size_t defineComandBF(Massiv<std::string> ctrlMass){
    if(ctrlMass[0] == "exit"){
        return 0;
    }
    else if(ctrlMass[0] == "BINSERT"){
        return 1;
    }
    else if(ctrlMass[0] == "BFIND"){
        return 2;
    }
    return 3;
}


#endif