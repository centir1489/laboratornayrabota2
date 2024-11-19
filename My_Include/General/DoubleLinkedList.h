#pragma once
#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include<iostream>

    struct DNode{
        int Data;
        DNode* next = nullptr;
        DNode* prev = nullptr;
    };

    struct DoubleLinkedList{
        DNode* Head = nullptr;
        DNode* Tail = nullptr;
    };

    bool IsEmpty(DoubleLinkedList List);
    void DGET(DoubleLinkedList DList);
    void DPUSH_BACK(DoubleLinkedList& DList, int Value);
    void DPUSH_FRONT(DoubleLinkedList& DList, int Value);
    void DPOP_FRONT(DoubleLinkedList& DList);
    void DPOP_BACK(DoubleLinkedList& DList);


#endif