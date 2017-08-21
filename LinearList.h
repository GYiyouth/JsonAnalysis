//
// Created by ge yao on 2017/7/22.
//

#ifndef LINEARLIST_LINEARLIST_H
#define LINEARLIST_LINEARLIST_H

#include "Node.h"
template <class T>
class LinearList {
public:
    //获取头结点
    virtual Node<T> *getHead() const = 0;
    //设置头结点
    virtual void setHead(Node<T> *head) = 0;
    //判断链表是否为空
    virtual bool empty() const = 0;
    //获取当前节点个数，从0开始
    virtual int getSize() const = 0;
    //获取指定位置的节点，从0开始
    virtual Node<T>* getNode(int index) const = 0;
    //指定位置的后面，插入指定节点
    virtual bool insert(int index, Node<T>* node) = 0;
    //移除某个节点
    virtual bool remove(Node<T> *node) = 0;
    //移除某个节点
    virtual bool remove(int index) = 0;
    //在尾部添加一个节点
    virtual bool add(Node<T> *node) = 0;
    //判断是否有环路
    virtual bool circleJudge() const = 0;
    //获取尾节点，如果有环路，则是快慢指针相遇的节点
    virtual Node<T> * getTailNode() const = 0;
};


#endif //LINEARLIST_LINEARLIST_H
