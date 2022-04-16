#pragma once
#include <iostream>
using namespace std;

//#pragma pack(push)  /* push current alignment to stack */
//#pragma pack(1)
class Matrix
{
    int** mat;
    int row, col;
public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix&);
    ~Matrix();
    Matrix& operator = (const Matrix&);

    void set_row(int r){ row = r; };
    void set_col(int c){ col = c; };
    int get_row() const { return row; }
    int get_col() const { return col; }
    
    int* operator[](int i) { return mat[i]; }
    const int* operator[](int i) const { return mat[i]; }
    
    operator string() const;
    friend ostream& operator << (ostream&, const Matrix&);
    friend istream& operator >> (istream&, Matrix&);

    friend Matrix operator * (const Matrix&, const Matrix&);
    friend bool operator == (const Matrix&, const Matrix&);
    double Norm() const;
    
private:
    Matrix(int** mat, int row, int col);
};
//#pragma pack(pop)   /* restore original alignment from stack */
