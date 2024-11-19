#include"Task3.h"
#include <iostream>

Massiv<int> initmasset(const uSet<int>& set){
    Massiv<int> massSet;
    for(size_t q = 0; q < set.size; q++){
        if(set.table[q] != 0){
            massSet.MPUSH(set.table[q]);
        }
    }
    return massSet;
}


Massiv<uSet<int>> AllSubSets(const uSet<int>& inputSet){
    Massiv<int> mass = initmasset(inputSet);
    size_t n = mass.MLength();
    Massiv<uSet<int>> subsets;

    for(size_t q = 0; q < (1 << n); ++q){
        uSet<int> currentSubset;
        for(size_t p = 0; p < n; ++p){
            if(q & (1 << p)){// Если pй бит q равен 1 включаем элеменn
                currentSubset.SETADD(mass[p]);
            }
        }
        subsets.MPUSH(currentSubset);
    }
    return subsets;
}

void getSubSet(Massiv<uSet<int>> subsets){
    for(size_t q = 0; q < subsets.MLength(); q++){
        std::cout << "{ ";
        for (size_t p = 0; p < subsets[q].SETLength(); p++){
            if(subsets[q][p] != 0){
                std::cout << subsets[q][p] << " ";
            }
        }
        std::cout << "}\n";
    }
}

bool isEqualSumm(uSet<int> subset, int tsel){
    if(subset.summ() == tsel){
        return true;
    }
    return false;
}

uSet<int> findSummSet(Massiv<uSet<int>> subsets, int tsel, size_t estimDiffrnc){
    while(estimDiffrnc--){
        for(size_t q = 0; q < subsets.MLength(); q++){
            if(isEqualSumm(subsets[q], tsel)){
                return subsets[q];
            }
        }
        tsel++;    
    }
    return subsets[0];
}

