#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <time.h>
#include <math.h>

#define varname(x) #x

using namespace std;

class matrix
{
    friend ostream& operator<<(ostream&,const matrix&);
public:
    matrix(int n=0,int m=0);
    ~matrix();
    matrix& operator*(matrix&);
    matrix& operator+(matrix&);
    void t();
    void operator*=(matrix&);
    void operator=(matrix&);
    void setmatrix();
    void reverse();
    bool multipliable(matrix&);
    bool summable(matrix&);
    float determinant();
    bool symmetric();
    void deleteA();
    static int count;
private:
    int r_length;
    int c_length;
    float** A;
};

#endif // MATRIX_H
