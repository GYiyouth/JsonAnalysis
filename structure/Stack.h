//
// Created by ge yao on 2017/7/31.
// Stack, based on double linked list
//

#ifndef LINEARLIST_STACK_H
#define LINEARLIST_STACK_H

#include <iostream>
#include "DoubleLinkedLinearList.h"
using namespace std;

template <class T>
class Stack{
private:
    DoubleLinkedLinearList<T>* list = new DoubleLinkedLinearList<T>();
protected:
public:
    virtual bool isEmpty(){
        if (list == nullptr){
            list = new DoubleLinkedLinearList<T>();
            return true;
        } else{
            return list->empty();
        }
    }
    virtual int size(){
        if (list == nullptr){
            list = new DoubleLinkedLinearList<T>();
            return 0;
        } else{
            return list->getSize();
        }
    }
    //push a node to the tail of list
    virtual bool push(T & data){
        if (list == nullptr){
            list = new DoubleLinkedLinearList<T>();
        }
        if (data == (T)NULL){
            return false;
        }
        DNode<T>* node = new DNode<T>();
        node->setDataNode(data);
        list->add(node);
        return true;
    }
    //Get the tail of the list, and remove it from list
    //Notice: If you want to return an element whose type is reference, you need a reference parameter
    virtual T& pop(T& result){
        if (isEmpty()){
            result = (T)NULL;
            return result;
        } else{
            result = list->getTailNode()->getDataNode();
            list->remove(list->getTailNode());
            return result;
        }
    }

    virtual void info(){
        cout << "isEmpty ? " << isEmpty() << endl;
        cout << "size() ? " << size() << endl;
        list->info();
    }
};


#endif //LINEARLIST_STACK_H
