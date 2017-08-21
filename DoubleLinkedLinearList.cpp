//
// Created by ge yao on 2017/7/26.
// Do some exam to verify my operation of DoubleLinkedLinearList.h is correct
//
#include "DoubleLinkedLinearList.h"
#include "DNode.h"

using namespace std;

int DoubleLinkedLinearListExecute(){
    auto list = new DoubleLinkedLinearList<int>();
    cout << "insert test \n";
    auto head = new DNode<int>();
    head->setDataNode(0);
    cout << " - setHead and Add 9 DNode \n";
    list->setHead(head);
    for (int i = 1; i < 10; ++i) {
        auto node = new DNode<int>();
        node->setDataNode(i);
        list->add(node);
    }
    list->info();

    cout << "getNode(int index) Test" << endl;
    for (int j = 0; j < 20; ++j) {
        cout << list->getNode(j)->getDataNode() << "   ";
    }
    cout << "insert Test " << endl;
    for (int k = 0; k < 10; ++k) {
        DNode<int>* temp = new DNode<int>();
        temp->setDataNode(k);
        list->insert(k*2, temp);
    }
    list->info();
    cout << "remove(DNode<T>* node) test" << endl;
    for (int l = 0; l < 20; ++l) {
        DNode<int>* temp = list->getNode(l);
        list->remove(temp);
    }
    list->info();
    cout << "insert Test " << endl;
    for (int k = 0; k < 10; ++k) {
        DNode<int>* temp = new DNode<int>();
        temp->setDataNode(k);
        list->insert(k*2, temp);
    }
    list->info();
    cout << "delete Test " << endl;
    for (int m = 0; m > -5; --m) {
        list->remove(m * 2);
    }
    list->info();
    return 0;
}

