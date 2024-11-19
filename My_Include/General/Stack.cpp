
#include"Stack.h"

bool IsEmpty(Stack stack){
    return stack.Top == nullptr;
}

void SPUSH(Stack& stack, std::string Value){
    SNode* ptr = new SNode{Value, stack.Top};
    stack.Top = ptr;
}

void SPOP(Stack& stack){
    if(IsEmpty(stack)){
        return;
    }
    SNode* ptr = stack.Top;
    stack.Top = ptr -> next;
    delete ptr; 
}

void SGET(Stack stack){
    if(IsEmpty(stack)){
        return;
    }
    SNode* ptr = stack.Top;
    while(ptr){
        std::cout << ptr -> Data << ' ';
        ptr = ptr -> next;
    }
    std::cout << '\n';
}
