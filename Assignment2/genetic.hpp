//
// Created by gregm on 2019-11-24.
//

#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "city.hpp"
#include "city_list.hpp"

class genetic {
public:
    genetic();

    int CITIES_IN_TOUR = 32;
    unsigned long POPULATION_SIZE = 32;
    double MUTATION_RATE = 0.15;
    int SHUFFLES = 64;
    int ITERATIONS = 100;
    unsigned long PARENT_POOL_SIZE = 5;
    unsigned long NUMBER_OF_PARENTS = 2;
    int NUMBER_OF_ELITES = 1;
    int MAP_BOUNDARY = 1000;
    double SCALER = 10000.0;
    double IMPROVEMENT_FACTOR = 0.1;

    void shuffleCities(CityList&);
    double getDistanceCities(City, City);
    int findFitness(vector<CityList>&, int);
    double getDistanceTour(CityList&);
    vector<CityList> getParents(vector<CityList>&);
    CityList crossover(vector<CityList>&);
    bool containsCity(CityList&,int,City&);
    void mutate(vector<CityList>&);
    void swapCities(vector<City>&,int,int);
    void print(CityList&);
};

