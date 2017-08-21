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
    DNode<T> *getBefore() const {
        return before;
    }

    void setBefore(DNode *before) {
        DNode<T>::before = before;
    }

    void setNextNode(DNode *nextNode) {
        Node<T>::setNextNode(nextNode);
    }

    T getDataNode() const {
        return Node<T>::getDataNode();
    }

    void setDataNode(T dataNode) {
        Node<T>::setDataNode(dataNode);
    }

    DNode<T> *getNextNode() const {
        return (DNode<T>*)Node<T>::getNextNode();
    }

};


#endif //LINEARLIST_DNODE_H
