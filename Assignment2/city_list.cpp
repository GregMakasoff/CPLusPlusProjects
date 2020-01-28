//
// Created by gregm on 2019-11-10.
//


#include "city_list.hpp"

CityList::CityList() : fitness(0.0) {
    City city = {0, 0, 0};
    for(int i =0; i < CITIES_IN_TOUR; i++) {
        cities.push_back(city);
    }
}

ostream &operator<<(ostream &out, const CityList &c) {
    auto itr = c.cities.begin();
    out << "List Of Cities" << endl << "==========================" << endl;
    while(itr != c.cities.end())
        operator<<(cout, *itr++);
    out << "==========================" << endl;
    return out;
}

CityList &CityList::operator=(CityList cl) {
    swap(cities, cl.cities);
    swap(fitness, cl.fitness);
    return *this;
}
