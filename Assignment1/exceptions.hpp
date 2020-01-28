//
// Created by gregm on 2019-10-13.
//

#pragma once

using namespace std;

struct notOverZeroException : public exception {
    const char * what() const throw() {
        return "The number(s) must be above zero!";
    }
};

struct notPerfectSquareException : public exception {
    const char * what() const throw() {
        return "The size of the array must be a perfect square!";
    }
};

struct outOfBoundsException : public exception {
    const char * what() const throw() {
        return "The index provided is out of bounds!";
    }
};

struct mismatchSizeException : public exception {
    const char * what() const throw() {
        return "Those arrays are not the same size!";
    }
};

struct wrongDimensionsException : public exception {
    const char * what() const throw() {
        return "Those columns of the first matrix do not match the rows of the second!";
    }
};
