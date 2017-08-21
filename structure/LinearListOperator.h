//
// Created by ge yao on 2017/7/24.
// 用来写单链表上的各种操作
//

#include "Node.h"

//已知单链表中有一个环路，获取它的成环节点
/**
 *链起点到环入口点间的距离为x
 * 环入口点到fast与low重合点的距离为y
 * 又设在fast与low重合时fast已绕环n周（n>0）
 * 且此时low移动总长度为s，则fast移动总长度为2s，环的长度为r。则
 * s + nr = 2s,n>0 ①
 * s = x + y ②
 * 由①式得 s = nr
 * 代入②式得
 * nr = x + y
 * x = nr - y ③
 * 现让一指针p1从链表起点处开始遍历，指针p2从encounter处开始遍历
 * 且p1和p2移动步长均为1。
 * 则当p1移动x步即到达环的入口点，由③式可知，此时p2也已移动x步即nr - y步。
 * 由于p2是从encounter处开始移动，故p2移动nr步是移回到了encounter处
 * 再退y步则是到了环的入口点。
 * 也即，当p1移动x步第一次到达环的入口点时，p2也恰好到达了该入口点。
 * */
//已知单链表中有一个环路，获取它的环节点
template <class T>
Node<T> * getCircleNode(Node<T> *head, Node<T> *encounter){
    Node <T>*p1 = head, *p2 = encounter;
    while(p1 != p2)
    {
        p1 = p1->getNextNode();
        p2 = p2->getNextNode();
    }
    return p1;
}

//获取入环节点
template <class T>
Node<T> * getCircleEnterNode(Node<T> * head, Node<T>* encounter){
    Node <T> *p1 = head, *p2 = encounter;
    //自己指向自己，或长度为2时尾节点指向头节点
    if (p1 == p2){
        return p1;
    }
    while(p1->getNextNode() != p2->getNextNode())
    {
        p1 = p1->getNextNode();
        p2 = p2->getNextNode();
    }
    return p1;
}

//获取环尾节点
template <class T>
Node<T> * getCircleTailNode(Node<T> * head, Node<T>* encounter){
    Node  <T>*p1 = head, *p2 = encounter;
    //自己指向自己，或长度为2时尾节点指向头节点
    if (p1 == p2){
        return p1;
    }
    while(p1->getNextNode() != p2->getNextNode())
    {
        p1 = p1->getNextNode();
        p2 = p2->getNextNode();
    }
    return p2;
}