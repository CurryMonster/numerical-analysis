#include "matrix.h"

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t columns) : rows_(rows), columns_(columns), data_(new T[rows_ * columns_])
{
    for (size_t i {0}; i < rows_ * columns_; i++)
    {
        data_[i] = static_cast<T>(0);
    }
}

template<typename T>
Matrix<T>::Matrix(initializer_list<T> data, size_t rows, size_t columns) : rows_(rows), columns_(columns), data_(new T[rows_ * columns_])
{
    size_t i {0};
    for (const T& x: data)
    {
        data_[i] = x;
        i += 1;
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& source) : rows_(source.rows_), columns_(source.columns_), data_(new T[rows_ * columns_])
{
    for (size_t i {0}; i < rows_ * columns_; i++)
    {
        data_[i] = source.data_[i];
    }
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& source)
{

    if (this == &source)
    {
        return *this;
    }

    if (data_)
    {
        delete[] data_;
    }

    rows_ = source.rows_;
    columns_ = source.columns_;
    data_ = new T[rows_ * columns_];

    for (size_t i {0}; i < rows_ * columns_; i++)
    {
        data_[i] = source.data_[i];
    }

    return *this;
}

template<typename T>
Matrix<T>::~Matrix()
{
    if (data_)
    {
        delete[] data_;
    }
}

template<typename T>
T Matrix<T>::operator()(size_t i, size_t j) const
{
    size_t index {i * columns_ + j};
    size_t size {rows_ * columns_};
    assert(i < rows_ && j < columns_ && index < size);
    return data_[index];
}

template<typename T>
T& Matrix<T>::operator()(size_t i, size_t j)
{
    size_t index {i * columns_ + j};
    size_t size {rows_ * columns_};
    assert(i < rows_ && j < columns_ && index < size);
    return data_[index];
}

template class Matrix<int>;
template class Matrix<double>;