//
// Created by gregm on 2019-09-30.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "exceptions.hpp"

using namespace std;

class Matrix {
    public :
    Matrix();
    Matrix(int);
    Matrix(int, int);
    Matrix(vector<double>);
    ~Matrix();
    void setValue(const int,const int, const double);
    int getValue(const int, const int) const;
    void clearMatrix(Matrix &m);
    friend ostream & operator << (ostream &out, const Matrix &m);
    friend bool operator==(const Matrix &m1, const Matrix &m2);
    friend bool operator!=(const Matrix &m1, const Matrix &m2);
    friend Matrix& operator++(Matrix &m);
    friend Matrix& operator++(Matrix &m, int);
    friend Matrix& operator--(Matrix &m);
    friend Matrix& operator--(Matrix &m, int);
    Matrix& operator=(Matrix &m);
    friend void mySwap(Matrix& m1, Matrix& m2);
    friend Matrix& operator+(Matrix& m, Matrix& n);
    friend Matrix& operator+=(Matrix& m, Matrix& n);
    friend Matrix& operator-(Matrix& m, Matrix& n);
    friend Matrix& operator-=(Matrix& m, Matrix& n);
    friend Matrix& operator*(Matrix& m, Matrix& n);
    friend Matrix& operator*=(Matrix& m, Matrix& n);
    friend Matrix& operator*=(Matrix& m, Matrix& n);
    friend Matrix& operator*=(Matrix& m, double);
    Matrix& getProbMatrix(Matrix& m);
    Matrix& getTransitionMatrix(Matrix& m);
    Matrix& markovProcess(Matrix& m, Matrix & n);
    Matrix& getRank(Matrix& m);
    int rows;
    int cols;
    vector< vector<double>> square;
    double const TOLERANCE = 0.01;
};


#endif //ASSIGNMENT1_MATRIX_HPP
