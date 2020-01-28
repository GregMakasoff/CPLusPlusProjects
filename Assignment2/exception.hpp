//
// Created by gregm on 2019-11-10.
//

#pragma once

#include <exception>

using namespace std;

struct outOfBoundsException : public exception {
    const char * what() const throw() {
        return "The number(s) must be between 0 and 1000(inclusive)!";
    }
};

