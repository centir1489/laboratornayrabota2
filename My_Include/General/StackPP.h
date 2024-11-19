#pragma once
#ifndef STACK_PLUS_PLUS
#define STACK_PLUS_PLUS

#include<iostream>
#include<string>
#include<cstdint>
#include <initializer_list>
#include"single_include/nlohmann/json.hpp"

template<typename gen_t>
struct StackPP{
    struct  SNodePP{
        gen_t data;
        SNodePP* next = nullptr;
    };
    SNodePP* Top = nullptr;

    StackPP(std::initializer_list<gen_t> list){
        for(gen_t item : list){
            SNodePP* ptr = new SNodePP{item, Top};
            Top = ptr;
        }
    }
    StackPP() : Top(nullptr){}

    bool IsEmpty(){
        return Top == nullptr;
    }

    gen_t top(){
        if(IsEmpty()){
            return ' ';
        }
        return Top -> data;
    }

    void SPUSH(gen_t Value){
        SNodePP* ptr = new SNodePP{Value, Top};
        Top = ptr;
    }

    void SPOP(){
        if(IsEmpty()){
            return;
        }
        SNodePP* ptr = Top;
        Top = ptr -> next;
        delete ptr; 
    }

    void SGET(){
        if(IsEmpty()){
            return;
        }
        SNodePP* ptr = Top;
        while(ptr){
            std::cout << ptr -> data << ' ';
            ptr = ptr -> next;
        }
        // std::cout << '\n';
    }
    
    
    friend std::ostream& operator<<(std::ostream& os, StackPP<gen_t> stack){
        if(stack.IsEmpty()){
            return os;
        }
        SNodePP* ptr = stack.Top;
        while(ptr){
            os << ptr -> data << ' ';
            ptr = ptr -> next;
        }
        return os;
    }    
};





#endif