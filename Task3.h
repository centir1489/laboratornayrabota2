#pragma once
#include"My_Include/General/uSet.h"
#include"My_Include/General/Massiv.h"
#include"My_Include/General/uPair.h"

Massiv<uSet<int>> AllSubSets(const uSet<int>& inputSet);
bool isEqualSumm(uSet<int> subset, int tsel);
uSet<int> findSummSet(Massiv<uSet<int>> subsets, int tsel, size_t estimDiffrnc);