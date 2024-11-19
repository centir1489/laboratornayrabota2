#pragma once
#ifndef MASSIV
#define MASSIV
#include<iostream>
#include<cstdint>
#include <initializer_list>

template<typename gen_t>
    struct Massiv{
        gen_t* Data;
        size_t Size; 
        size_t Capacity;
        
        Massiv() : Capacity(1), Size(0), Data(new gen_t[1]){}
        
        Massiv(size_t initCapacity) : Capacity(initCapacity), Size(0), Data(new gen_t[initCapacity]) {}

        Massiv(std::initializer_list<gen_t> mass){
            Data = new gen_t[mass.size()];
		    Size = mass.size();
		    Capacity = mass.size();
		    size_t q = 0;
		    for(gen_t item : mass){
			    Data[q++] = item;
		    }
        }
        
        
        Massiv(const Massiv& othrMass){
            Size = othrMass.Size;
            Capacity = othrMass.Capacity;
            Data = new gen_t[Size];
            for (size_t q = 0; q < Size; q++) {
                Data[q] = othrMass.Data[q];
            }
        }

        Massiv<gen_t>& operator=(const Massiv<gen_t>& othrMass){
            if(this != &othrMass){
                delete[] Data;
                Size = othrMass.Size;
                Capacity = othrMass.Capacity;
                if(Size > 0){
                    Data = new gen_t[Size];
                    for(size_t q = 0; q < Size; q++){
                        Data[q] = othrMass.Data[q];
                    }
                } 
                else{
                    Data = nullptr;
                }
            }
            return *this;
        }

        gen_t& operator[](size_t index) {
            if(index < 0 || index >= Size){
                throw std::out_of_range("INDEX_OUT");
            }
            return Data[index];
        }

        void MGET(){
            if(Size == 0){
                return;
            }
            for(size_t q = 0; q < Size; q++){
                std::cout << Data[q] << ' ';
            }
            std::cout << '\n';
        }

        bool isEmpty(){
            if(Size == 0){
                return true;
            }
            return false;
        }

        size_t MLength(){
            return Size;
        }

        void Resize(size_t Capacity) {
            gen_t* Data = new gen_t[Capacity];
            for(size_t q = 0; q < Size; q++) {
                Data[q] = this -> Data[q];
            }
            delete[] this -> Data;
            this -> Data = Data;
            this -> Capacity = Capacity;
        }

        void MPUSH(gen_t Value){
            if(Size == Capacity){
                Resize(2 * Capacity);
            }
            Data[Size++] = Value;
        }

        bool FindValue(gen_t Value){
            if(Size == 0){
                return false;
            }
            for(size_t q = 0; q < Size; q++){
                if(Data[q] == Value){
                    return true;
                }
            }
            return false;
        }

        void MPushIndex(size_t index, gen_t Value){
            if(index >= Size || index < 0){
                return;
            }
            gen_t bf = Data[index + 1];
            Data[index] = Value;
            for(size_t q = index + 1; q < Size; q++){
                Data[q] = bf;
                bf = Data[q + 1];
            }
            Size++;
        }

        void MPOP(size_t index){
            if(index >= Size || index < 0){
                return;
            }
            for(size_t q = index; q < Size - 1; q++) {
                Data[q] = Data[q + 1];
            }
            Size--;
        }


        friend std::ostream& operator<<(std::ostream& os, Massiv<gen_t> mass){
            if(mass.MLength() == 0){
                return os;
            }
            for(size_t q = 0; q < mass.MLength(); q++){
                os << mass[q] << ' ';
            }
            os << '\n';
            return os;

        }
    
        
        gen_t summ(){
            if(Size == 0){
                return 0;
            }
            gen_t summ = 0;
            for(size_t q = 0; q < Size; q++){
                summ += Data[q];
            }
            return summ;
        }

    };


#endif