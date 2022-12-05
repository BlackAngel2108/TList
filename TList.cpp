// TList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TList.h"
int main()
{
    TList<int,10> l;
    l.PushFront(2);
    cout<<l.Front()<<endl;
    l.PushFront(3);
    l.PopFront();
    for (int i = 0; i < 1; i++) {
        cout<<l[i];
    }
    cout<<endl;
    l.PushAfter(0,4);
    for (int i = 0; i < 2; i++) {
        cout << l[i];
    }
    cout<<endl;
    l.EraseAfter(0);
    for (int i = 0; i < 1; i++) {
        cout << l[i];
    }
    cout << endl;
}
