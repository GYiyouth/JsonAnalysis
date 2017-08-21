//
// Created by 葛尧 on 2017/7/26.
//

#ifndef LINEARLIST_DOUBLELINKEDLINEARLST_H
#define LINEARLIST_DOUBLELINKEDLINEARLST_H

#include "LinearList.h"
#include "DNode.h"
#include <iostream>

using namespace std;
/**
 * LinearList with double linked Node
 * Operations will be easy
 * If there is only one DNode, it's next and before should be itself.
 * @tparam T
 */
template <class T>
class DoubleLinkedLinearList{
private:
    DNode<T>* head = nullptr;
public:
    virtual DNode<T> *getHead() const ;

    virtual void setHead(DNode<T> *head) ;

    virtual bool empty() const ;

    virtual int getSize() const ;

    virtual DNode<T> *getNode(const int index) const ;

    virtual bool insert(const int index, DNode<T> *node) ;

    virtual bool remove(DNode<T> *node) ;

    virtual bool remove(const int index) ;

    virtual bool add(DNode<T> *node) ;

    virtual bool circleJudge() const ;

    virtual DNode<T> *getTailNode() const ;

    virtual void info() const ;

};
template <class T>
DNode<T> *DoubleLinkedLinearList<T>::getHead() const {
    return this->head;
}
template <class T>
void DoubleLinkedLinearList<T>::setHead(DNode<T> *head) {
    if (head == nullptr){
        this->head = nullptr;
        return;
    }
    if (head->getNextNode() == nullptr){
        head->setNextNode(head);
    }
    if (head->getBefore() == nullptr){
        head->setBefore(head);
    }
    this->head = head;
}
template <class T>
bool DoubleLinkedLinearList<T>::empty() const {
    return head == nullptr;
}

/**
 * Count the size of list.
 * It can apply normal list, circle list, empty list.
 * @tparam T
 * @return
 */

template <class T>
int DoubleLinkedLinearList<T>::getSize() const {
    DNode<T>* node = getHead();
    if (node == nullptr){
        return 0;
    }
    DNode<T>const * head = getHead();
    int i = 1;
    while( node->getNextNode() != head
          && node->getNextNode()->getBefore() == node){
        i ++;
        node = node->getNextNode();
    }
    return i;
}

/**
 * get a DNode at the index
 * @tparam T
 * @param index
 * @return
 */
template <class T>
DNode<T> *DoubleLinkedLinearList<T>::getNode(int index) const {
    DNode<T>* target = getHead();

    if (target == nullptr){
        return nullptr;
    }
    if (index >= 0){
        // Traversal the list with next
        int i = 0;
        while (i < index){
            i ++;
            if (target != nullptr){
                target = target->getNextNode();
            } else{
                return nullptr;
            }
        }// After loop, node1 is the target
    } else{
        //Traversal the list with before
        int i = 0;
        while(i > index){
            i--;
            if (target != nullptr){
                target = target->getBefore();
            } else{
                return nullptr;
            }
        }
    }
    return target;
}
/**
 * Insert a not after a clear index
 * @tparam T
 * @param index
 * @param node
 * @return
 */
template <class T>
bool DoubleLinkedLinearList<T>::insert(const int index, DNode<T> *node) {
    DNode<T>* indexNode = getNode(index);
    // empty
    if (indexNode == nullptr){
        node->setNextNode(node);
        node->setBefore(node);
        setHead(node);
        return true;
    } else{
        //Not Empty
        node->setBefore(indexNode);
        node->setNextNode(indexNode->getNextNode());
        indexNode->getNextNode()->setBefore(node);
        indexNode->setNextNode(node);
        return true;
    }
}
/**
 * delete a node from the list
 * @tparam T
 * @param node
 * @return
 */
template <class T>
bool DoubleLinkedLinearList<T>::remove(DNode<T> *node) {
    if (empty()){
        return false;
    }
    if (getSize() == 1 && node == getHead()){
        setHead(nullptr);
        return true;
    }
    if (node->getBefore()== nullptr){ // this Node may probably not in this list
        return false;
    } else{
        if (node->getNextNode() == nullptr){
            node->setNextNode(this->getHead());
        }
        node->getBefore()->setNextNode(node->getNextNode());
        node->getNextNode()->setBefore(node->getBefore());
        if (node == getHead()){
            this->setHead(node->getNextNode());
        }
        return true;
    }
}

/**
 * Delete a node from the list and memory
 * @tparam T
 * @param index
 * @return
 */
template <class T>
bool DoubleLinkedLinearList<T>::remove(const int index) {
    DNode<T>* node1 = getHead();
    DNode<T>* target = nullptr;
    if (node1 == nullptr){
        return false;
    }
    if (index >= 0){
        // Traversal the list with next
        int i = 0;
        while (i <= index){
            i ++;
            if (node1 != nullptr){
                node1 = node1->getNextNode();
            } else{
                return false;
            }
        }// After loop, node1 is the target
    } else{
        //Traversal the list with before
        int i = 0;
        while(i > index){
            i--;
            if (node1 != nullptr){
                node1 = node1->getBefore();
            } else{
                return false;
            }
        }
    }
    target = node1;
    //delete the target
    target->getBefore()->setNextNode(target->getNextNode());
    target->getNextNode()->setBefore(target->getBefore());
    if (target == getHead()){
        if (getSize() == 1){
            setHead(nullptr);
        } else{
            setHead(target->getNextNode());
        }
    }
    delete target;
    target = nullptr;
    return false;
}
/**
 * Add a new DNode after the tail, before the head.
 * If this is an empty node, set this node as head.
 * I strongly suggest that this node is a single node which means that you cannot get other nodes from this node.
 * Next and before of this node will be reset to apply this linearList, unless the linearList is empty.
 * @tparam T
 * @param node
 * @return
 */
template <class T>
bool DoubleLinkedLinearList<T>::add(DNode<T> *node) {
    DNode<T>* tail = getTailNode();
    if (tail == nullptr){
        setHead(node);
        return true;
    }
    node->setNextNode(getHead());
    node->setBefore(tail);
    getHead()->setBefore(node);
    tail->setNextNode(node);
    return true;
}
/**
 * If headNode -> next -> before is not itself, there must be a circle
 * @tparam T
 * @return
 */
template <class T>
bool DoubleLinkedLinearList<T>::circleJudge() const {
    DNode<T>* head = getHead();
    return head != nullptr && head->getBefore()->getNextNode() != head;
}
template <class T>
DNode<T> *DoubleLinkedLinearList<T>::getTailNode() const {
    //Empty
    if (getHead() == nullptr){
        return nullptr;
    }
    DNode<T>* node1 = getHead();
    //Normally situation, no circle
    if (node1->getBefore()->getNextNode() == node1){
        while (node1->getNextNode() != getHead() && node1->getNextNode() != nullptr){
            node1 = node1->getNextNode();
        }
    } else{
        // circle occur
        // if a node -> next -> before is not himself, the node is the tail
        while( node1->getNextNode()->getBefore() != node1 ){
            node1 = node1->getNextNode();
        }
    }
    return node1;
}

/**
 * print information
 */
template <class T>
void DoubleLinkedLinearList<T>::info() const {
    cout << "\n  ---  now print info  ---  \n";
    cout << "  -   size  : " << this->getSize() << endl;
    if (this->getSize() == 0){
        return;
    }
    cout << "  -   head  : " << this->getHead()->getDataNode() << endl;
    cout << "  -   circle: " << this->circleJudge()<< endl;
    cout << "  -   tail  : " << this->getTailNode()->getDataNode() << endl;
    for (int i = 0; i < getSize(); ++i) {
        const int j = i;
        //FIXME
        cout << "  -   index = " << i<< " DNode's value is " << getNode(j)->getDataNode() << endl;
    }
}

#endif //LINEARLIST_DOUBLELINKEDLINEARLST_H
