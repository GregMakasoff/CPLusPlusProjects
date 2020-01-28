//
// Created by gregm on 2019-09-30.
//

#include "matrix.hpp"

using namespace std;
/**
 * Constructor
 */
Matrix :: Matrix() {
    square = vector<vector<double> >(1, vector<double>(1));
    rows = 1;
    cols = 1;
}
/**
 * Constructor
 * @param n
 */
Matrix :: Matrix(int n) {
    try {
        if (n < 1)
            throw notOverZeroException();
        square.resize(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                square[i][j] = 0.0;
        }
        rows = n;
        cols = n;

    }catch(notOverZeroException e) {
        cout << e.what() << endl;
    }

}
/**
 * Constructor
 * @param r
 * @param c
 */
Matrix :: Matrix(int r, int c) {
    try {
    if(r<1 || c<1)
        throw notOverZeroException();
    square.resize(r, vector<double>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            square[i][j] = 0.0;
    }
    rows = r;
    cols = c;
    } catch(notOverZeroException e) {
        cout << e.what() << endl;
    }
}
/**
 * Constructor
 * @param arr
 */
Matrix :: Matrix(vector<double> arr) {
    int x = sqrt(arr.size());
    int count = 0;
    try {
    if((x*x) != arr.size())
        throw notPerfectSquareException();
    square.resize(x, vector<double>(x));
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++)
            square[i][j] = arr[count++];
    }
    rows = x;
    cols = x;
    } catch(notPerfectSquareException e) {
        cout << e.what() << endl;
    }
}
/**
 * Set specific value of matrix
 * @param row
 * @param col
 * @param newVal
 */
void Matrix :: setValue(const int row,const int col, const double newVal) {
    try {
    if((row < 0 || row >= rows) && (col < 0 || col >= cols))
        throw outOfBoundsException();
    square[row][col] = newVal;
    }
    catch(outOfBoundsException e) {
        cout << e.what() << endl;
    }
}
/**
 * Get specific value from a matrix
 * @param row
 * @param col
 * @return
 */
int Matrix :: getValue(const int row, const int col) const {
    try {
        if((row < 0 || row >= rows) && (col < 0 || col >= cols))
            throw outOfBoundsException();
        return square[row][col];
    }
    catch(outOfBoundsException e) {
        cout << e.what() << endl;
    }
}
/**
 * Sets every value in a matrix to 0
 */
void Matrix :: clearMatrix(Matrix &m) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            m.setValue(i, j, 0.0);
    }
}
/**
 * Destructor
 */
Matrix :: ~Matrix() = default;
/**
 * Overloaded insertion operator
 * @param out
 * @param m
 * @return
 */
ostream & operator<<(ostream& out, const Matrix &m) {
    for(int i = 0; i < m.cols; i++)
        out << "==========";
    out << endl;
    for(int i = 0; i < m.rows; i++) {
        out << "|  ";
        for(int j = 0; j < m.cols; j++) {
            out << fixed << showpoint << setprecision(3) << m.square[i][j] << "  |  ";
        }
        out << endl;
    }
    for(int i = 0; i < m.cols; i++)
        out << "==========";
    out << endl;
    return out;
}
/**
 * Overloaded equality operator
 * @param m1
 * @param m2
 * @return
 */
bool operator==(const Matrix &m1, const Matrix &m2) {
    if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size())) {
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++)
                if(abs(m1.square[i][j] - m2.square[i][j]) > m1.TOLERANCE)
                    return false;
        }
        return true;
    }
    return false;
}
/**
 * Overlaoded equality operator
 * @param m1
 * @param m2
 * @return
 */
bool operator!=(const Matrix &m1, const Matrix &m2) {
    if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size())) {
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++)
                if(m1.square[i][j] != m2.square[i][j])
                    return true;
        }
        return false;
    }
    return true;
}
/**
 * Overlaoded pre-increment operator
 * @param m
 * @return
 */
Matrix &operator++(Matrix &m) {
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++)
            m.square[i][j] += 1;
    }
    return m;
}
/**
 * Overloaded post-increment operator
 * @param m
 * @param x
 * @return
 */
Matrix & operator++(Matrix &m, int x) {
    Matrix &newM = m;
    operator++(m);
    return newM;
}
/**
 * Overloaded pre-decrement operator
 * @param m
 * @return
 */
Matrix & operator--(Matrix &m) {
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++)
            m.square[i][j] -= 1;
    }
    return m;
}
/**
 * Overloaded post-decremented operator
 * @param m
 * @param x
 * @return
 */
Matrix & operator--(Matrix &m, int x) {
    Matrix &newM = m;
    operator--(m);
    return newM;
}
/**
 * Overloaded assignment operator
 * @param m
 * @return
 */
Matrix & Matrix:: operator=(Matrix &m) {
    mySwap(*this, m);
    return *this;
}
/**
 * Used to swap two matrix objects
 * @param m1
 * @param m2
 */
void mySwap(Matrix& m1, Matrix& m2){
    using std::swap;
    swap(m1.square, m2.square);
}
/**
 * Overloaded addition operator
 * @param m1
 * @param m2
 * @return
 */
Matrix& operator+(Matrix& m1, Matrix& m2) {
    try {
    if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size()))
        throw mismatchSizeException();
        Matrix *mat = new Matrix(m1.rows, m1.cols);
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++)
                mat->square[i][j] = m1.square[i][j] + m2.square[i][j];
        }
        return *mat;
    } catch (mismatchSizeException e) {
        cout << e.what() << endl;
    }
}
/**
 * Overloaded addition equals operator
 * @param m1
 * @param m2
 * @return
 */
Matrix &operator+=(Matrix &m1, Matrix &m2) {
    try {
    if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size()))
        throw mismatchSizeException();
    for(int i = 0; i < m1.rows; i++) {
        for(int j = 0; j < m1.cols; j++)
            m1.square[i][j] += m2.square[i][j];
    }
    return m1;
    }
    catch (mismatchSizeException e) {
        cout << e.what() << endl;
    }
}
/**
 * Overloaded subtraction operator
 * @param m1
 * @param m2
 * @return
 */
Matrix &operator-(Matrix &m1, Matrix &m2) {
    try {
        if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size()))
            throw mismatchSizeException();
        Matrix *mat = new Matrix(m1.rows, m1.cols);
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++)
                mat->square[i][j] = m1.square[i][j] - m2.square[i][j];
        }
        return *mat;
    } catch (mismatchSizeException e) {
        cout << e.what() << endl;
    }
}
/**
 * Overloaded subtraction equals operator
 * @param m1
 * @param m2
 * @return
 */
Matrix &operator-=(Matrix &m1, Matrix &m2) {
    try {
        if((m1.square.size() != m2.square.size()) || (m1.square[0].size() != m2.square[0].size()))
            throw mismatchSizeException();
        for(int i = 0; i < m1.rows; i++) {
            for(int j = 0; j < m1.cols; j++)
                m1.square[i][j] -= m2.square[i][j];
        }
        return m1;
    }
    catch (mismatchSizeException e) {
        cout << e.what() << endl;
    }
}
/**
 * Overloaded multiplication operator
 * @param m
 * @param n
 * @return
 */
Matrix &operator*(Matrix &m, Matrix &n) {
    try {
    if(m.cols != n.rows)
        throw wrongDimensionsException();
        Matrix *mat = new Matrix(m.rows, n.cols);
        for(int i = 0; i < m.rows; i++) {
            for(int j = 0; j < m.cols; j++) {
                for(int k = 0; k < m.cols; k++)
                    mat->square[i][j] += m.square[i][k] * n.square[k][j];
            }
        }
        return *mat;
    } catch(wrongDimensionsException e) {
        cout << e.what() << endl;
    }
}
/**
 * Overlaoded multiplication equals operator
 * @param m
 * @param n
 * @return
 */
Matrix & operator*=(Matrix &m, Matrix &n) {
    try {
        if(m.cols == n.rows)
            throw wrongDimensionsException();
        Matrix *mat = new Matrix(m.rows, n.cols);
        for(int i = 0; i < m.rows; i++) {
            for(int j = 0; j < m.cols; j++) {
                for(int k = 0; k < m.cols; k++)
                    mat->square[i][j] += m.square[i][k] * n.square[k][j];
            }
        }
        m.operator=(*mat);
        return m;
    } catch(wrongDimensionsException e) {
        cout << e.what() << endl;
    }
}
/**
 * Overloaded operator to multiply a matrix by a constant value
 * @param m
 * @param value
 * @return
 */
Matrix &operator*=(Matrix &m, double value) {
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++)
            m.square[i][j] *= value;
    }
}
/**
 * Returns a probablity matrix
 * @param m
 * @return
 */
Matrix & Matrix::getProbMatrix(Matrix& m) {
    double total = 0.0;
    auto *mat = new Matrix(m.rows, m.cols);
    mat->operator=(m);
    for(int i = 0; i < m.cols; i++) {
        for(int j = 0; j < m.rows; j++) {
            total += mat->square.at(j).at(i);
        }
        if(total == 0) {
            for (int k = 0; k < m.rows; k++)
                mat->square.at(k).at(i) = (double)(1.0/m.rows);
        }
        else {
            for (int l = 0; l < m.rows; l++)
                mat->square.at(l).at(i) /= total;
        }
        total = 0;
    }
    return *mat;
}
/**
 * Returns a transition matrix
 * @param m
 * @return
 */
Matrix &Matrix::getTransitionMatrix(Matrix &m) {
    operator*=(m, 0.85);
    auto q = new Matrix(m.rows, m.cols);
    auto other = new Matrix(m.rows, m.cols);
    for(int i = 0; i < m.cols; i++) {
        for (int k = 0; k < m.rows; k++)
            q->square.at(k).at(i) = (double) (1.0 / m.rows);
    }
    for(int i = 0; i < m.cols; i++) {
        for (int k = 0; k < m.rows; k++)
            q->square.at(k).at(i) *= 0.15;
    }
    operator+=(m, *q);
    return m;
}
/**
 * Performs the markov process on a matrix
 * @param m
 * @param n
 * @return
 */
Matrix &Matrix::markovProcess(Matrix &m, Matrix &n) {
    double top = n.square.at(0).at(0);
    n = operator*(m, n);
    if(top != n.square.at(0).at(0))
        markovProcess(m, n);
    return n;
}
/**
 * Determines the rank percentages for the pages
 * @param m
 * @return
 */
Matrix &Matrix::getRank(Matrix &m) {
    double total = 0.0;
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++)
            total += m.square.at(i).at(j);
    }
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++) {
            m.square.at(i).at(j) /= total;
            m.square.at(i).at(j) *= 100;
        }
    }
    char letters[]= {'A', 'B', 'C', 'D'};
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++) {
            cout << "Page " << letters[i] << ": " << setprecision(2) << m.square.at(i).at(j) << "%" <<  endl;
        }
    }
    return m;
}










