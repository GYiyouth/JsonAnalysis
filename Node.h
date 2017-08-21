//
// Created by ge yao on 2017/7/22.
//

#ifndef LINEARLIST_NODE_H
#define LINEARLIST_NODE_H
//友元类要在使用前声明一下，因为没有定义在同一个.h文件里
/**
 * 使用友元类时注意：
 *(1) 友元关系不能被继承。
 *(2) 友元关系是单向的，不具有交换性。若类B是类A的友元，类A不一定是类B的友元，要看在类中是否有相应的声明。
 *(3) 友元关系不具有传递性。若类B是类A的友元，类C是B的友元，类C不一定是类A的友元，同样要看类中是否有相应的申明
 **/
template <class T>
class SimpleLinearList;

template <class T>
class Node {
private:
    T dataNode;
    Node * nextNode = nullptr;
    //设置私有，只允许链表访问


public:
    virtual void setNextNode(Node *nextNode) {
        Node::nextNode = nextNode;
    }

    //友元类，别处不可再访问setNextNode操作
    friend class SimpleLinearList<T>;

    virtual T getDataNode() const {
        return dataNode;
    }

    virtual void setDataNode(T dataNode) {
        Node::dataNode = dataNode;
    }

    virtual Node *getNextNode() const {
        return nextNode;
    }

    //构造函数
    Node() = default;
    Node(T & dataNode, Node *nextNode) : dataNode(dataNode), nextNode(nextNode){};

    Node(T &dataNode){
        this->dataNode = dataNode;
    };


    //析构函数
    virtual ~Node() = default;
};
#endif //LINEARLIST_NODE_H
