#pragma once

#include <iostream>
#include <assert.h>
#include <initializer_list>

using std::size_t;
using std::initializer_list;

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

    Matrix<T> t (lhs.rows(), lhs.columns());

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            t(i, j) = lhs(i, j) + rhs(i, j);
        }
    }

    return t;
}

template<typename T>
Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    assert(lhs.rows() == rhs.rows() && lhs.columns() == rhs.columns());

    Matrix<T> t (lhs.rows(), lhs.columns());

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            t(i, j) = lhs(i, j) - rhs(i, j);
        }
    }

    return t;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    assert(lhs.columns() == rhs.rows());
    Matrix<T> t {lhs.rows(), rhs.columns()};
    
    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < rhs.columns(); j++)
        {
            for (size_t k {0}; k < lhs.columns(); k++)
            {
                t(i, j) += lhs(i, k) * rhs(k, j);
            }
        }
    }

    return t;
}

template<typename T>
Matrix<T> operator/(const Matrix<T>& lhs, const T& rhs)
{
    const T inv_rhs {1 / rhs};

    Matrix<T> t {lhs.rows(), lhs.columns()};

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            t(i, j) = lhs(i, j) * inv_rhs;
        }
    }

    return t;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const T& rhs)
{
    Matrix<T> t {lhs.rows(), lhs.columns()};

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            t(i, j) = lhs(i, j) * rhs;
        }
    }

    return t;    
}

template<typename T>
Matrix<T> operator*(const T& lhs, const Matrix<T>& rhs)
{
    Matrix<T> t {lhs.rows(), lhs.columns()};

    for (size_t i {0}; i < lhs.rows(); i++)
    {
        for (size_t j {0}; j < lhs.columns(); j++)
        {
            t(i, j) = lhs * rhs(i, j);
        }
    }

    return t;       
}