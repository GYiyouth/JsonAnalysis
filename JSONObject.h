//
// Created by candice on 2017/8/20.
//

#ifndef JsonStructure_JSONOBJECT_H
#define JsonStructure_JSONOBJECT_H

#include <string>
#include <iostream>
#include "structure/DoubleLinkedLinearList.h"
#include "structure/DNode.h"

/**
 * 用来作为json中的每一个键值对存在
 * @tparam _Type
 */

class Entry {
private:
    std::string key = nullptr;
    void* value = nullptr;
    Entry* next = nullptr;
protected:
public:

    Entry() {
        key = nullptr;
        value = nullptr;
        next = nullptr;
    }

    Entry(const string &key, void *value) : key(key), value(value) {
        next = nullptr;
    }

    Entry(const string &key, void *value, Entry *next) : key(key), value(value), next(next) {

    }

    template <class _Type>
    static bool put(Entry& entry, std::string & key, _Type value){
        return false;
    }

    template <class _Type>
    static bool remove(Entry& entry, std::string & key){
        return false;
    }

    virtual void print() const {
        ;
        return ;
    }

    const std::string &getKey() const {
        return key;
    }

    void setKey(const std::string &key) {
        Entry::key = key;
    }

    template <class _Type>
    static _Type *getValue(Entry& entry) {
        return entry.value;
    }

    template <class _Type>
    static void setValue(Entry& entry, _Type *value) {
        entry.value = value;
    }
};

/**
 * JSONObject，支持放置任意可以转换为字符串的类型
 */
class JSONObject{
private:
    static const int default_size = 16;
    static const int default_empty_size = 0;
    int size = 0;
    DoubleLinkedLinearList<Entry> entryList;
protected:
public:
    template <class T>
    static bool put(JSONObject* jsonObject ,std::string key ,T& value){
        if (jsonObject == nullptr){
            throw "nullptr: this JSONObject is nullptr";
        }
        auto entry = new Entry(key, &value);
        auto dNode = new DNode<Entry>(* entry);
        return jsonObject->entryList.add(dNode);
    }
};


class JSONArray{
private:

protected:
public:
};

void JSONTest1(){
    auto jsonObject = new JSONObject();
    int a = 1;
    jsonObject->put(jsonObject, "key", a);
}


#endif //JsonStructure_JSONOBJECT_H
