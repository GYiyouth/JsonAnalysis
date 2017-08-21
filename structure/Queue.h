//
// Created by ge yao on 2017/7/29.
// Queue
//

#ifndef LINEARLIST_QUEUE_H
#define LINEARLIST_QUEUE_H
#include "DoubleLinkedLinearList.h"
using namespace std;

template <class T>
class Queue{
private:
    DoubleLinkedLinearList<T>* dList = new DoubleLinkedLinearList<T>();
public:
    virtual T pop(){
        if (isEmpty()){
            return (T) NULL; //TODO
        } else{
            DNode<T> head = * dList->getHead();
            dList->remove(dList->getHead());
            return head.getDataNode();
        }
    }
    virtual bool push(T* dataNode){
        if (dList == nullptr){
            dList = new DoubleLinkedLinearList<T>();
        }
        DNode<T>* dNode = new DNode<T>();
        dNode->setDataNode(* dataNode);
        return dList->add(dNode);
    }
    virtual bool isEmpty(){
        if (dList == nullptr){
            dList = new DoubleLinkedLinearList<T>();
            return true;
        } else{
            return dList->empty();
        }
    }
    virtual int size(){
        if (dList == nullptr){
            dList = new DoubleLinkedLinearList<T>();
            return 0;
        } else{
            return dList->getSize();
        }
    }
    virtual void info(){
        cout << "Queue info" << endl;
        cout << "Size " << size() << endl;
        cout << "isEmpty " << isEmpty() << endl;
        cout << "List inside Info ----- " << endl;
        this->dList->info();
    }
};
#endif //LINEARLIST_QUEUE_H
