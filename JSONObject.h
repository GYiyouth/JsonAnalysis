//
// Created by candice on 2017/8/20.
//

#ifndef TEST0820_JSONOBJECT_H
#define TEST0820_JSONOBJECT_H

#include <string>
template <typename _Type>
class JSONObject {
private:
    std::string key;
    void* value;
protected:
public:

    virtual _Type get(std::string & key, _Type type){
        return nullptr;
    }

    
    virtual bool put(std::string & key, _Type value){
        return false;
    }

    virtual bool remove(std::string & key){
        return false;
    }

    virtual void print() const {
        return;
    }
};


#endif //TEST0820_JSONOBJECT_H
