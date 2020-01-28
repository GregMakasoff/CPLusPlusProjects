#include "genetic.hpp"

int main() {
    genetic();

    return 0;
}
/**double CityList::findFitness() {
    auto tempX = this->cities.front().x;
    auto tempY = this->cities.front().y;
    auto itr = this->cities.begin();
    while(itr != this->cities.end()) {
        itr++;
        this->fitness += sqrt((itr->x*tempX)+(itr->y*tempY));
        tempX = itr->x;
        tempY = itr->y;
    }
    itr = this->cities.begin();
    fitness += sqrt((itr->x*tempX)+(itr->y*tempY));
    return fitness;
}
 *
 * int NUM_CITIES;
    int POPULATION_SIZE;
    double MUTATION_RATE;
    cout << "Please enter the number of cities you would like to use for this simulation: ";
    cin >> NUM_CITIES;
    cout << endl << "Now enter the number of candidate tours: ";
    cin >>POPULATION_SIZE;
    cout << endl << "Lastly, enter the mutation rate: ";
    cin >> MUTATION_RATE;
 * struct timeval time;
        gettimeofday(&time,NULL);
        srand((time.tv_sec * 1000) + (time.tv_usec / 1000));*/