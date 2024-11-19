#include"AVLTree.h"


size_t Height(ANode* Root){
    if(Root == NULL){
        return 0;
    }
    else{
        size_t LeftHeight = Height(Root -> Left);
        size_t RightHeight = Height(Root -> Right);
        if(LeftHeight > RightHeight){
            return LeftHeight + 1;
        }
        else{
            return RightHeight + 1;
        }
    }
}

void FixHeight(ANode* NTree){
	size_t HeightLeft = Height(NTree -> Left);
	size_t HeightRight = Height(NTree -> Right);
	NTree -> height = (HeightLeft > HeightRight ? HeightLeft : HeightRight) + 1;
}

ANode* RightRotate(ANode* NTree){
    ANode* NewNode = NTree -> Left;
	NTree -> Left = NewNode -> Right;
	NewNode -> Right = NTree;
	FixHeight(NTree);
	FixHeight(NewNode);
	return NewNode;
}

ANode* LeftRotate(ANode* NTree){
    ANode* NewNode = NTree -> Right;
	NTree -> Right = NewNode -> Left;
	NewNode -> Left = NTree;
	FixHeight(NTree);
	FixHeight(NewNode);
	return NewNode;
}

ANode* BalanceNode(ANode* NTree){
    FixHeight(NTree);
	if(Height(NTree -> Right) - Height(NTree -> Left) == 2){
		if(Height(NTree -> Right -> Right) - Height(NTree -> Right -> Left) < 0){
			NTree -> Right = RightRotate(NTree -> Right);
        }
		return LeftRotate(NTree);
	}

	if(Height(NTree -> Right) - Height(NTree -> Left) == -2){
		if(Height(NTree -> Left -> Right) - Height(NTree -> Left -> Left) > 0){
			NTree -> Left = LeftRotate(NTree -> Left);
        }
		return RightRotate(NTree);
	}
	return NTree;
}

ANode* TPUSH(ANode* NTree, int Val){
    if(!NTree){
        return new ANode(Val);
    }
	if(Val < NTree -> Data){
		NTree -> Left = TPUSH(NTree -> Left, Val);
    }
    else{
		NTree -> Right = TPUSH(NTree -> Right, Val);
    }
	return BalanceNode(NTree);
}


ANode* FindMin(ANode* NTree){
	return NTree -> Left ? FindMin(NTree -> Left) : NTree;
}

ANode* RemoveMin(ANode* NTree){
	if(NTree -> Left == 0){
		return NTree -> Right;
	}
	NTree -> Left = RemoveMin(NTree -> Left);
	return BalanceNode(NTree);
}


ANode* TDEL(ANode* NTree, int Val){
	if(!NTree){ 
		return 0;
	}
	if(Val < NTree -> Data){
		NTree -> Left = TDEL(NTree -> Left, Val);
	}
	else if( Val > NTree -> Data){
		NTree -> Right = TDEL(NTree -> Right, Val);	
	}
	else //  если нашли 
	{
		ANode* q = NTree -> Left;
		ANode* p = p -> Right;
		delete NTree;
		if(!p) {
			return q;
		}
		ANode* min = FindMin(NTree);
		min -> Right = RemoveMin(NTree);
		min -> Left = q;
		return BalanceNode(min);
	}
	return BalanceNode(NTree);
}

ANode* Find(ANode* NTree, int Val){
	if(NTree == nullptr){
		return nullptr;
	}
	if(NTree -> Data == Val){
		return NTree;
	}
	if(Val < NTree -> Data){
		return Find(NTree -> Left, Val);
	}
	return Find(NTree -> Right, Val);
}

int TFIND(ANode* NTree, int Val){
	ANode* node = Find(NTree, Val);
	if(node != nullptr){
		return node -> Data; 
	}
	else{
		return 0;
	}
	return 0;
}

void TGET(ANode* NTree){
	if(NTree == nullptr){
		return;
	}
	QueuePP<ANode*> queue;
	queue.Push(NTree);
	while(!queue.IsEmpty()){
		ANode* NextNode = queue.Front();
        queue.Pop();

        std::cout << NextNode -> Data << " ";

        if(NextNode -> Left != nullptr){
            queue.Push(NextNode -> Left);
        }
        if(NextNode -> Right != nullptr){
            queue.Push(NextNode -> Right);
        }
	}
	std::cout << "\n\n";
}

