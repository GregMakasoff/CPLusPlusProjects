//
// Created by gregm on 2019-11-10.
//

#include "city.hpp"

City::City(int id, int x, int y) : id(id), x(x), y(y){}

ostream &operator<<(ostream &out, const City &c) {
    out << "ID: " << c.id << " Lat: " << c.x << " Long: " << c.y << endl;

    return out;
}

