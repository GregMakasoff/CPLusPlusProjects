//
// Created by gregm on 2019-11-10.
//

#pragma once
#include <iostream>
#include <chrono>
#include <algorithm>
#include "city.hpp"

using namespace std;

class CityList {
public:
    CityList();
    int CITIES_IN_TOUR = 32;

    vector<City> cities;
    double fitness;
    friend ostream & operator << (ostream &out, const CityList&);
    CityList &operator=(CityList);
};

