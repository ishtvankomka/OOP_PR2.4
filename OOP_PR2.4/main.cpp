#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main()
{
    Matrix m1, m2(2, 2);
    cout << "1st matrix" << endl;
    cin >> m1;
    cout << m1;
    cout << "Norma: " <<  m1.Norm() << endl << endl;
    cout << "2nd matrix" << endl;
    cin >> m2;
    cout << m2;
    cout << "Norma: " <<  m2.Norm() << endl << endl;

    cout << "1st matrix * 2nd matrix" << endl;
    cout << m1 * m2 << endl;

    if(m1 == m2)
    {
        cout << "1st matrix = 2nd matrix" << endl;
    }
    else
    {
        cout << "1st matrix != 2nd matrix" << endl;
    }
    
    m1 = m2;
    if(m1 == m2)
    {
        cout << "1st matrix = 2nd matrix" << endl;
    }
    else
    {
        cout << "1st matrix != 2nd matrix" << endl;
    }
    
    cout << "1st element of 1st matrix: " << m1[0][0] << endl;

    cout << "Class size: " << sizeof(m1) << endl << endl;
    return 0;
}
