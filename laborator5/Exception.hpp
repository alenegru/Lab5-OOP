#pragma once
#include <stdio.h>
//#import <exception>
//#import <string>
#include <iostream>

#include <typeinfo>       
using namespace std;

class Exception : public exception {
private:
    string message;
public:
    explicit Exception(string message) : exception() {
        this->message = std::move(message);
    }
    const char* what() const noexcept override {
        return ( message ).c_str();
    }
};