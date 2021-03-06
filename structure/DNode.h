//
// Created by 葛尧 on 2017/7/26.
//

#ifndef LINEARLIST_DNODE_H
#define LINEARLIST_DNODE_H

#include "Node.h"
/**
 * A node with double pointers.
 * With the two pointers we can get two nodes which before or after itself.
 * This kind of relation leads to Nesting Strategy to allocate memory
 * //TODO
 * DNode{Node, before}
 * Not DNode{next, date, before}
 */

template <class T>
class DNode: protected Node<T>{
private:
    DNode<T> * before = nullptr;
protected:
public:

    DNode() {

    }

    DNode(T &dataNode){

    }

    virtual DNode<T> *getBefore() const {
        return before;
    }

    virtual void setBefore(DNode *before) {
        DNode<T>::before = before;
    }

    virtual void setNextNode(DNode *nextNode) {
        Node<T>::setNextNode(nextNode);
    }

    virtual T getDataNode() const {
        return Node<T>::getDataNode();
    }

    virtual void setDataNode(T dataNode) {
        Node<T>::setDataNode(dataNode);
    }

    virtual DNode<T> *getNextNode() const {
        return (DNode<T>*)Node<T>::getNextNode();
    }

};


#endif //LINEARLIST_DNODE_H
