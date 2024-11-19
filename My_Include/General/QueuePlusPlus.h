#pragma once
#ifndef QUEUE_PLUS_PLUS   
#define QUEUE_PLUS_PLUS  
#include<iostream>
#include<string>
template<typename gen_t>
struct QueuePP{
    struct QNodePP{
	    gen_t Data;
	    QNodePP* next;
    };
        QNodePP* Head = nullptr;
        QNodePP* Tail = nullptr;
        
        bool IsEmpty(){
            return Head == nullptr;
        }

        void Push(gen_t Value){
            QNodePP* NewNode = new QNodePP({Value, nullptr});
            if(IsEmpty()){
                Head = NewNode;
                Tail = NewNode;
                return;
            }
            Tail -> next = NewNode;
            Tail = NewNode;
        }

        void Pop(){
            if(IsEmpty()){
                return;
            }
            QNodePP* NewNode = Head;
            Head = NewNode -> next;
            delete NewNode;
        }
        size_t Size(){
            if(IsEmpty()){
                return 0;
            }
            size_t Amount = 0;
            QNodePP* ptr = Head;
            while(ptr){
                Amount++;
                ptr = ptr -> next;
            }
            return Amount;
        }

        void Get(){
            if(IsEmpty()){
                return;
            }
            QNodePP* ptr = Head;
            while(ptr){
                std::cout << ptr -> Data << ' ';
                ptr = ptr -> next;
            }
            std::cout << '\n';
            
        }

        gen_t Front(){
            if(IsEmpty()){
                throw "";
            }
            return Head -> Data;
        }
        gen_t Back(){
            if(IsEmpty()){
                throw "";
            }
            return Tail -> Data;
        }
};
    


#endif