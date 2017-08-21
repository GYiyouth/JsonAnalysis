//
// Created by candice on 2017/8/20.
//

#ifndef JsonStructure_JSONOBJECT_H
#define JsonStructure_JSONOBJECT_H

#include <string>
#include <iostream>
#include "DoubleLinkedLinearList.h"
#include "DNode.h"

/**
 * 用来作为json中的每一个键值对存在
 * @tparam _Type
 */
template <typename _Type>
class entry {
private:
    std::string key;
    _Type* value;
    entry* next;
protected:
public:
    virtual bool put(std::string & key, _Type value){
        return false;
    }

    virtual bool remove(std::string & key){
        return false;
    }

    virtual void print() const {
        std::cout << "\"" << key << "\":" << *value << "," << std::endl;
        ;
        return ;
    }

    const std::string &getKey() const {
        return key;
    }

    void setKey(const std::string &key) {
        entry::key = key;
    }

    _Type *getValue() const {
        return value;
    }

    void setValue(_Type *value) {
        entry::value = value;
    }
};

class JSONObject{
private:
    static const int default_size = 16;
    static const int default_empty_size = 0;
    int size = 0;
    entry<int>* head;
protected:
public:
};


class JSONArray{
private:
protected:
public:
};

#endif //JsonStructure_JSONOBJECT_H
