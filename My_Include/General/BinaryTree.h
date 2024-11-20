#ifndef BINARY_TREE
#define BINARY_TREE
#include<iostream>
#include<cstdlib>
#include"StackPP.h"
#include"QueuePlusPlus.h"

template<typename gen_t>
struct BinaryTree{
    struct BNode{
        gen_t data;
        BNode* Left;
        BNode* Right;

        BNode(gen_t value) : data(value), Left(nullptr), Right(nullptr) {}
    };
    BNode* root;

    BinaryTree() : root(nullptr) {}

    bool isEmpty(){
        return root == nullptr;
    }
    
    void insert(gen_t value) {
        root = insertRec(root, value);
    }

    BNode* insertRec(BNode* NTree, gen_t value) {
        if(NTree == nullptr){
            return new BNode(value);
        }
       
        if(value < NTree -> data){
            NTree -> Left = insertRec(NTree -> Left, value);
        } 
        else{
            NTree -> Right = insertRec(NTree -> Right, value);
        }
        return NTree;
    }

    QueuePP<gen_t> BinaryTreeToQueue(BNode* NTree){
        QueuePP<gen_t> retqueue;
        if(NTree == nullptr){
            return retqueue;
        }
        QueuePP<BNode*> queue;
        queue.Push(NTree);
        while(!queue.IsEmpty()){
            BNode* NextNode = queue.Front();
            queue.Pop();

            retqueue.Push(NextNode -> data);

            if(NextNode -> Left != nullptr){
                queue.Push(NextNode -> Left);
            }
            if(NextNode -> Right != nullptr){
                queue.Push(NextNode -> Right);
            }
        }
        return retqueue;
    }



    void get(){
        if(root == nullptr){
            return;
        }
        QueuePP<BNode*> queue;
        queue.Push(root);
        while(!queue.IsEmpty()){
            BNode* NextNode = queue.Front();
            queue.Pop();

            std::cout << NextNode -> data << " ";

            if(NextNode -> Left != nullptr){
                queue.Push(NextNode -> Left);
            }
            if(NextNode -> Right != nullptr){
                queue.Push(NextNode -> Right);
            }
        }
        std::cout << '\n';
    }
    void getZigZag(BinaryTree<int16_t> Tree, bool leftToRight){
        if(Tree.isEmpty()){
            return;
        }

        QueuePP<BNode*> queue;
        StackPP<int16_t> stack;          
        queue.Push(Tree.root);
        size_t levelSize;
        while(!queue.IsEmpty()){
            levelSize = queue.Size();
            for(size_t q = 0; q < levelSize; q++) {
                BNode* nextNode = queue.Front();
                queue.Pop();

                if(leftToRight){
                    std::cout << nextNode -> data << ' ';
                } 
                else{
                    stack.SPUSH(nextNode -> data);
                }

                if(nextNode -> Left){ 
                    queue.Push(nextNode -> Left);
                }
                if(nextNode -> Right){ 
                    queue.Push(nextNode -> Right);
                }
            }

            if(!leftToRight){
                while(!stack.IsEmpty()){
                    std::cout << stack.top() << " ";
                    stack.SPOP();
                }
            }
            leftToRight = !leftToRight;
        }
    }



};

#endif