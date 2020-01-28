#include "matrix.hpp"
/**
 * opens the text file containing the connectivity matrix
 * @param title used for file name
 * @return a vector filled the matrix
 */
static vector<double> openFile(const string& title) {
    fstream file;
    vector<double> matrix;
    matrix.resize(16);
    file.open(title);
    if (!file.is_open()) {
        cerr<< "Unable to open file" << endl;
        exit(1);
    }
    int count = 0;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            file >> matrix[count++];
        }
    }
    file.close();
    return matrix;
}
/**
 * calls the matrix functions to get our ranks of the matrix
 */
static void run() {
    vector<double> testArray = openFile("connectivity.txt");
    auto testMatrix = new Matrix(testArray);
    operator<<(cout, *testMatrix);
    auto testProb = testMatrix->getProbMatrix(*testMatrix);
    operator<<(cout, testProb);
    testProb.getTransitionMatrix(testProb);
    operator<<(cout, testProb);

    auto rankMatrix = new Matrix(4, 1);
    for(int i =0; i < testProb.rows; i++) {
        rankMatrix->square.at(i).at(0) = 1.0;
    }
    auto *markov = new Matrix(4, 1);
    *markov = testProb.markovProcess(testProb, *rankMatrix);
    operator<<(cout, *markov);
    markov->getRank(*markov);

    delete markov;
    delete testMatrix;
    delete rankMatrix;
}
/**
 *
 * @return 0 when the program runs successfully
 */
int main() {
    run();
    return 0;
}