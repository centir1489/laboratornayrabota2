#pragma once
#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

    struct LNode {
        int Data;
        LNode* next = nullptr;
    };

    struct LinkedList{
        LNode* Head = nullptr;
        LNode* Tail = nullptr;
    };

    bool IsEmpty(LinkedList List);
    void LPUSH_BACK(LinkedList& List, int Value);
    void LPUSH_FRONT(LinkedList& List, int Value);
    void LGET(LinkedList& List);
    LNode* Find(LinkedList List, int Value);
    void LPOP_FRONT(LinkedList& List);
    void LPOP_BACK(LinkedList& List);
    void LREMOVE_VALUE(LinkedList& List, int Value);

#endif