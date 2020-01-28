//
// Created by gregm on 2019-11-10.
//

#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <random>
#include <list>


using namespace std;

class City {
public:
    City(int id, int x, int y);

    int x;
    int y;
    int id;
    static const int MAX = 1000;

    friend ostream & operator << (ostream &out, const City &m);
};


