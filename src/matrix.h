#pragma once

#include <iostream>
#include <cassert>
#include <iomanip>
#include <initializer_list>

using std::size_t;
using std::initializer_list;
using std::ostream;
using std::cout;
using std::setprecision;
using std::setw;
using std::left;

template<typename T>
class Matrix
{
    public:
        Matrix(size_t rows, size_t columns);
        Matrix(initializer_list<T> data, size_t rows, size_t columns);
        ~Matrix();
        Matrix(const Matrix<T>& source);
        Matrix<T>& operator=(const Matrix<T>& source);
        T operator()(size_t i, size_t j) const;
        T& operator()(size_t i, size_t j);
        size_t rows() const {return rows_;}
        size_t columns() const {return columns_;}
    private:
        size_t rows_;
        size_t columns_;
        T*     data_;        
};

template<typename T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    assert(lhs.rows() == rhs.rows() && lhs.columns() == rhs.columns());

    Matrix<T> m (lhs.rows(), lhs.columns());

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            m(i, j) = lhs(i, j) + rhs(i, j);
        }
    }

    return m;
}

template<typename T>
Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    assert(lhs.rows() == rhs.rows() && lhs.columns() == rhs.columns());

    Matrix<T> m (lhs.rows(), lhs.columns());

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            m(i, j) = lhs(i, j) - rhs(i, j);
        }
    }

    return m;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    assert(lhs.columns() == rhs.rows());

    Matrix<T> m {lhs.rows(), rhs.columns()};
    
    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < rhs.columns(); j++)
        {
            for (size_t k {0}; k < lhs.columns(); k++)
            {
                m(i, j) += lhs(i, k) * rhs(k, j);
            }
        }
    }

    return m;
}

template<typename T>
Matrix<T> operator/(const Matrix<T>& lhs, const T& rhs)
{
    const T inv_rhs {1 / rhs};

    Matrix<T> m {lhs.rows(), lhs.columns()};

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            m(i, j) = lhs(i, j) * inv_rhs;
        }
    }

    return m;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const T& rhs)
{
    Matrix<T> m {lhs.rows(), lhs.columns()};

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            m(i, j) = lhs(i, j) * rhs;
        }
    }

    return m;    
}

template<typename T>
Matrix<T> operator*(const T& lhs, const Matrix<T>& rhs)
{
    Matrix<T> m {rhs.rows(), rhs.columns()};

    for (size_t i {0}; i < rhs.rows(); i++)
    {
        for (size_t j {0}; j < rhs.columns(); j++)
        {
            m(i, j) = lhs * rhs(i, j);
        }
    }

    return m;       
}

template<typename T> ostream& operator<<(ostream& os, const Matrix<T>& rhs)
{
    cout << "\n";
    for (size_t i {0}; i < rhs.rows(); i++)
    {
        for (size_t j {0}; j < rhs.columns(); j++)
        {
            cout << setprecision(3) << setw(5) << left << rhs(i, j) << " ";
        }
        cout << "\n";
    }
    return os;
}