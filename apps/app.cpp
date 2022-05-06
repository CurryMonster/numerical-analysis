#include "matrix.h"

int main() 
{
    Matrix<double> m ({1,   2,  3,
                       4,   5,  6, 
                       7,   8,  9,
                       10, 11, 12,
                       13, 14, 15}, 5, 3);

    Matrix<double> x {{2.45, 1.34, 1.23}, 3, 1};

    cout << m * x;

    return 0;
}