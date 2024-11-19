#pragma once
#ifndef QUEUE   
#define QUEUE
#include<iostream>


struct QNode{
	    std::string Data;
	    QNode* next = nullptr;
    };
struct Queue{
        QNode* Head = nullptr;
        QNode* Tail = nullptr;
        

};
    std::string Front(Queue queue);
    bool IsEmpty(Queue queue);
    void QPUSH(Queue& queue, std::string Value);
    void QPOP(Queue& queue);
    void QGET(Queue queue);


#endif