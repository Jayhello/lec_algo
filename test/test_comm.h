//
// Created by wenwen on 2022/5/1.
//
#pragma once

#include <sstream>
#include <string>
using namespace std;

template<typename Container>
string tostr(const Container& c){
    stringstream ss;
    ss << "{";
    for(const auto& item : c){
        ss << item << "|";
    }
    ss << "}";
    return ss.str();
}
