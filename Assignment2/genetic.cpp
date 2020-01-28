//
// Created by gregm on 2019-11-24.
//

#include "genetic.hpp"
#include "city_list.hpp"
#include "city.hpp"

genetic::genetic(){
    CityList mainList;
    vector<CityList> popList{POPULATION_SIZE};
    vector<CityList> crossList{POPULATION_SIZE-NUMBER_OF_ELITES};
    double bestDist = 0.0;
    srand(static_cast<unsigned int>(time(nullptr)));

    for(int i=0; i<CITIES_IN_TOUR; i++) {
        City city{i, rand() % 1001, rand() % 1001};
        mainList.cities[i] = city;
    }
    for(int i = 0; i < POPULATION_SIZE; i++) {
        for(int j = 0; j < CITIES_IN_TOUR; j++)
            popList[i].cities[j] = mainList.cities[j];
        shuffleCities(popList[i]);
        popList[i].fitness = 0.0;
    }
    int index = findFitness(popList, static_cast<int>(POPULATION_SIZE));
    int startRoute = index;
    double startDist = 10000.0 / popList[index].fitness;
    double initDist = startDist;
    cout << "Initial Shortest Distance: " << fixed << setprecision(3) << startDist << endl;

    int count = 0;
    while(count++ < 1000 && (startDist/bestDist) > 0.1) {
        if(index != 0) {
            const CityList temp = popList[0];
            popList[0] = popList[index];
            popList[index] = temp;
        }
        for(int i = 0; i < (POPULATION_SIZE - NUMBER_OF_ELITES); i++) {
            vector<CityList> tours = getParents(popList);
            crossList[i] = crossover(tours);
        }
        for(int i = NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
            popList[i] = crossList[i - NUMBER_OF_ELITES];
            popList[i].fitness = 0.0;
        }

        mutate(popList);
        index = findFitness(popList, POPULATION_SIZE);
        bestDist = getDistanceTour(popList[index]);

        if((startDist - bestDist)  > 0.1) {
            startDist = bestDist;
            print(popList[index]);
            cout << bestDist << endl;
        }
    }
    cout << "Iterations: " << count << endl;
    cout << "Best Distance: " << 10000.0 / popList[index].fitness << endl;
    cout << "Base Distance: " << initDist << endl;
    cout << "Improved By: " << ((10000.0 / popList[index].fitness) / initDist) * 100 <<"%" << endl;
    cout << "Base Route: " << endl;
    print(popList[startRoute]);
    cout << "Best Route: " << endl;
    print(popList[index]);
}

double genetic::getDistanceCities(City city1, City city2) {
    return sqrt(pow((double) (city1.x-city2.x), 2) + pow((double) (city1.y-city2.y), 2));
}

void genetic::shuffleCities(CityList &tour) {
    shuffle(begin(tour.cities), end(tour.cities), mt19937(random_device()()));
}

int genetic::findFitness(vector<CityList> & tourList, int size) {
    int index = 0;
    auto shotestTour =(double) RAND_MAX;
    double minDist = 0.0;

    for(int i = 0; i < size; i++) {
        minDist = getDistanceTour(tourList[i]);
        tourList[i].fitness = 10000 / minDist;
        if(minDist <= shotestTour) {
            index = i;
            shotestTour = minDist;
        }
    }

    return index;
}

double genetic::getDistanceTour(CityList & tour) {
    double dist = 0.0;
    for(int i = 0; i < CITIES_IN_TOUR; i++)
        dist += getDistanceCities(tour.cities[i], tour.cities[(i + 1) % CITIES_IN_TOUR]);
    return dist;
}

vector<CityList> genetic::getParents(vector<CityList> &tourList) {
    int index = 0;
    vector<CityList> parents{NUMBER_OF_PARENTS};
    vector<CityList> pool{PARENT_POOL_SIZE};

    for(int i = 0; i < NUMBER_OF_PARENTS; i++) {
        for(int j = 0; j < PARENT_POOL_SIZE; j++) {
            int k = static_cast<int>(rand() % POPULATION_SIZE);
            pool[j] = tourList[k];
        }
        index = findFitness(pool, static_cast<int>(PARENT_POOL_SIZE));
        parents[i] = pool[index];
    }
    return parents;
}

CityList genetic::crossover(vector<CityList> &tourList) {
    CityList temp;
    int index = rand() % CITIES_IN_TOUR;

    for(int i = 0; i < index; i++)
        temp.cities[i] = tourList[0].cities[i];

    while(index < CITIES_IN_TOUR) {
        for(int i = 0; i < CITIES_IN_TOUR; i++) {
            if(!containsCity(temp, index, tourList[1].cities[i])) {
                temp.cities[index] = tourList[1].cities[i];
                index++;
            }
        }
    }

    return temp;
}

bool genetic::containsCity(CityList & tour, int size, City & city) {
    for(int i = 0; i < size; i++) {
        if(tour.cities[i].id == city.id && tour.cities[i].x == city.x && tour.cities[i].y == city.y)
            return true;
    }
    return false;
}

void genetic::mutate(vector<CityList> & tourList) {
    for(int i = 0 + NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
        for(int j = 0; j < CITIES_IN_TOUR; j++) {
            if((double) rand() / (double) RAND_MAX <= MUTATION_RATE)
                swapCities(tourList[i].cities, j, rand() % CITIES_IN_TOUR);
        }
    }
}

void genetic::swapCities(vector<City> &tourList,int m, int n) {
    City temp = tourList[m];
    tourList[m] = tourList[n];
    tourList[n] = temp;
}

void genetic::print(CityList &tour) {
    for(auto city : tour.cities)
        cout << city.id << " ";
    cout << endl;
}
