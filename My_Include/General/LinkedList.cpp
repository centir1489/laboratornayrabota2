#include"LinkedList.h"

bool IsEmpty(LinkedList List){
    return List.Head == nullptr;
}

void LPUSH_BACK(LinkedList& List, int Value){
    LNode* ptr = new LNode({Value, nullptr});
    if(IsEmpty(List)){
        List.Head = ptr;
        List.Tail = ptr;
        return;
    }
    List.Tail -> next = ptr;
    List.Tail = ptr;
}

void LPUSH_FRONT(LinkedList& List, int Value){
    LNode* ptr = new LNode({Value, List.Head});
    if(IsEmpty(List)){
        List.Head = ptr;
        List.Tail = ptr;
        return;
    }
    List.Head = ptr;
}

void LGET(LinkedList& List){
    if(IsEmpty(List)){ 
        return;
    }
    LNode* ptr = List.Head;
    while(ptr){
        cout << ptr -> Data << ' ';
        ptr = ptr -> next;
    }
    cout << '\n';
}

LNode* Find(LinkedList List, int Value){
    LNode* tmp = List.Head;
    while(tmp && tmp -> Data != Value){ 
        tmp = tmp->next;
    }
    return (tmp && tmp -> Data == Value) ? tmp : nullptr;
}

void LPOP_FRONT(LinkedList& List){
    if(IsEmpty(List)){ 
        return;
    }
    LNode* ptr = List.Head;
    List.Head = ptr -> next;
    delete ptr;
}

void LPOP_BACK(LinkedList& List){
    if(IsEmpty(List)){
        return;
    }
    if(List.Head == List.Tail){
        LPOP_FRONT(List);
        return;
    }
    LNode* ptr = List.Head;
    while(ptr -> next != List.Tail){ 
        ptr = ptr -> next;
    }
    ptr -> next = nullptr;
    delete List.Tail;
    List.Tail = ptr;
}

void LREMOVE_VALUE(LinkedList& List, int Value){
    if (IsEmpty(List)){
        return;
    }
    if(List.Head -> Data == Value){
        LPOP_FRONT(List);
        return;
    }
    else if (List.Tail -> Data == Value) {
        LPOP_BACK(List);
        return;
    }
    LNode* firstPtr = List.Head;
    LNode* secondPtr = List.Head -> next;
    while(secondPtr && secondPtr -> Data != Value) {
        secondPtr = secondPtr -> next;
        firstPtr = firstPtr -> next;
    }
    if(!secondPtr){
        cout << "---" << '\n';
        return;
    }
    firstPtr -> next = secondPtr -> next;
    delete secondPtr;
}