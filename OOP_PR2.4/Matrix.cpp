#include "Matrix.hpp"
#include <sstream>
#include <math.h>

Matrix::Matrix()
{
    row = 0;
    col = 0;
    mat = nullptr;
}

Matrix::Matrix(int row, int col)
{
    set_row(row);
    set_col(col);

    if (row == 0 || col == 0)
        mat = nullptr;
    else
    {
        mat = new int* [row];
        for (size_t i = 0; i < row; i++) {
            mat[i] = new int[col];
            for (size_t j = 0; j < col; j++)
                mat[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& m)
{
    *this = m;
}

Matrix::~Matrix()
{
    if (mat)
    {
        for (size_t i = 0; i < row; i++)
            delete[] mat[i];
        delete[] mat;
    }
}

Matrix::Matrix(int** mat, int row, int col)
{
    this->row = row;
    this->col = col;
    this->mat = new int* [row];
    for (size_t i = 0; i < row; i++) {
        this->mat[i] = new int[col];
        for (size_t j = 0; j < col; j++)
            this->mat[i][j] = mat[i][j];
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    if (&m == this) return *this;
    if (!(m.row == 0 || m.col == 0))
    {
        row = m.row;
        col = m.col;

        mat = new int* [row];
        for (size_t i = 0; i < row; i++) {
            mat[i] = new int[col];
            for (size_t j = 0; j < col; j++)
                mat[i][j] = m.mat[i][j];
        }
    }
    else
    {
        row = 0;
        col = 0;
        mat = nullptr;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Matrix& m)
{
    out << (string)m;
    return out;
}

Matrix::operator string() const
{
    stringstream ss;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
            ss << " " << mat[i][j] << (j == col - 1 ? "" : " ");
        ss << endl;
    }
    return ss.str();
}

istream& operator>>(istream& in, Matrix& m)
{
    if (m.mat)
    {
        for (size_t i = 0; i < m.row; i++)
            delete[] m.mat[i];
        delete[] m.mat;
    }
    cout << " Set cols: "; cin >> m.col;
    cout << " Set rows: "; cin >> m.row;

    if (!(m.row == 0 || m.col == 0))
    {
        m.mat = new int* [m.row];
        for (size_t i = 0; i < m.row; i++) {
            m.mat[i] = new int[m.col];
            for (size_t j = 0; j < m.col; j++)
            {
                cout << " [" << i << "][" << j << "] = ";
                cin >> m.mat[i][j];
            }
        }
    }
    else
    {
        m.row = 0;
        m.col = 0;
        m.mat = nullptr;
    }
    return in;
}

Matrix operator * (const Matrix& m1, const Matrix& m2)
{
    Matrix m;
    if (m1.col == m2.col && m1.row == m2.row)
    {
        m = m1;
        for (size_t i = 0; i < m1.row; i++)
            for (size_t j = 0; j < m1.col; j++)
                m[i][j] *= m2[i][j];
        return Matrix(m.mat, m.row, m.col);
    }
    else
        return Matrix(m);
}

bool operator == (const Matrix& m1, const Matrix& m2)
{
    if (m1.col == m2.col && m1.row == m2.row)
    {
        for (size_t i = 0; i < m1.row; i++)
            for (size_t j = 0; j < m1.col; j++)
                if (m1[i][j] != m2[i][j])
                    return false;
        return true;
    }
    else
        return false;
}

double Matrix::Norm() const
{
    int sum = 0;
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
        {
            sum+= mat[i][j];
        }

    return sqrt(sum);
}
