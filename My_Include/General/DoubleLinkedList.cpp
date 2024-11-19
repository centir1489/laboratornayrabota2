#include"DoubleLinkedList.h"

bool IsEmpty(DoubleLinkedList List){
    return List.Head == nullptr;
}

void DPUSH_BACK(DoubleLinkedList& DList, int Value){
    DNode* ptr = new DNode({Value, nullptr, DList.Tail});
    if(IsEmpty(DList)){
        DList.Head = ptr;
        DList.Tail = ptr;
        return;
    }
    DList.Tail -> next = ptr;
    DList.Tail = ptr;
}

void DPUSH_FRONT(DoubleLinkedList& DList, int Value){
    DNode* ptr = new DNode({Value, DList.Head, nullptr});
    if(IsEmpty(DList)){
        DList.Head = ptr;
        DList.Tail = ptr;
        return;
    }
    DList.Head = ptr;

}

void DPOP_FRONT(DoubleLinkedList& DList){
    if(IsEmpty(DList)){
        return;
    }
    DNode* ptr = DList.Head;
    DList.Head = ptr -> next;
    delete ptr;
    // DList.Head = DList.Head -> next;
    // DList.Head -> prev = nullptr;
}

void DPOP_BACK(DoubleLinkedList& DList){
    if(IsEmpty(DList)){
        return;
    }
    if(DList.Head == DList.Tail){
        DPOP_FRONT(DList);
        return;
    }
    DList.Tail = DList.Tail -> prev;
    DList.Tail -> next = nullptr;
}

DNode* Find(DoubleLinkedList List, int Value){
    DNode* tmp = List.Head;
    while(tmp && tmp -> Data != Value){ 
        tmp = tmp->next;
    }
    return (tmp && tmp -> Data == Value) ? tmp : nullptr;
}

void LREMOVE_VALUE(DoubleLinkedList& List, int Value){
    if (IsEmpty(List)){
        return;
    }
    if(List.Head -> Data == Value){
        DPOP_FRONT(List);
        return;
    }
    else if (List.Tail -> Data == Value) {
        DPOP_BACK(List);
        return;
    }
    DNode* firstPtr = List.Head;
    DNode* secondPtr = List.Head -> next;
    while(secondPtr && secondPtr -> Data != Value) {
        secondPtr = secondPtr -> next;
        firstPtr = firstPtr -> next;
    }
    if(!secondPtr){
        std::cout << "---" << '\n';
        return;
    }
    firstPtr -> next = secondPtr -> next;
    delete secondPtr;
}

void DGET(DoubleLinkedList DList){
    if(IsEmpty(DList)){
        return;
    }
    DNode* ptr = DList.Head;
    while(ptr){
        std::cout << ptr -> Data << ' ';
        ptr = ptr -> next;
    }
    std::cout << '\n';
}