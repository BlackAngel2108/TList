// TList.h: This file contains class TList

#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct TNode {
    T value;
    int iNext;
};
template <typename T, size_t sz>
class TList
{
    TNode<T> list[sz];
    int iFirst;
    int iFirstFree;
    int currentIndex;
    int currentPos;
public:
    TList() : iFirst(-1), iFirstFree(0), currentIndex(sz), currentPos(sz) {
        for (size_t i=0;i<sz-1;i++)
            list[i].iNext=i+1;
        list[sz-1].iNext=-1;
    }
    T& Front() {
        return list[iFirst].value;
    }
    void PopFront() {
        int ind=iFirst;
        iFirst = list[iFirst].iNext;
        list[ind].iNext=iFirstFree;
        iFirstFree=ind;
    }
    void PushFront(const T& val) {
        int ind = iFirstFree;
        iFirstFree = list[iFirstFree].iNext;
        list[ind].value = val;
        list[ind].iNext = iFirst;
        iFirst = ind;
    }
    void PushAfter(size_t pos, const T& val) {
        int ind = iFirst;
        for (int i=0; i<pos;i++)
            ind= list[ind].iNext;
        int iNew = iFirstFree;
        iFirstFree = list[iFirstFree].iNext;
        list[iNew].value = val;
        list[iNew].iNext = list[ind].iNext;
        list[ind].iNext=iNew;
    }
    void EraseAfter(size_t pos) {
        int ind = iFirst;
        for (int i = 0; i < pos; i++)
            ind = list[ind].iNext;
        int iDel= list[ind].iNext;
        list[ind].iNext=list[iDel].iNext;
        list[iDel].iNext=iFirstFree;
        iFirstFree=iDel;
    }
    T& operator[](size_t pos) {
        if (pos < currentPos) {
            currentPos = 0;
            currentIndex=iFirst;
        }
        int ind = currentIndex;
        for(int i= currentPos;i<pos;i++)
            ind = list[ind].iNext;
        currentIndex = ind;
        currentPos = pos;
        return list[ind].value;
    }
};

