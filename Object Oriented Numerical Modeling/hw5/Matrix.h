/*!
 *  \file Matrix.h
 *  \brief Declaration of the Matrix Class
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "dolan_vector.h"

#ifndef DOXYGEN
template <typename T>
class Matrix;
#endif

/*!
 *  \brief Prints all stored elements in the vector.
 *
 *  \param out The stream where data is printed.
 *  \param m The Matrix object being printed.
 *  \pre None.
 *  \post The contents of m are printed to out.
 *  \return Modified ostream object.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m);

/*!
 *  \brief Gets elements for a Matrix from an input stream.
 *
 *  \param in The stream where data is retrieved.
 *  \param m The Matrix object being modified.
 *  \pre All of the input data must be on separate lines for each row of the
 *  Matrix, and each element in the rows separated by whitespace. If any rows
 *  are shorter than the longest row, the remainder of the shorter rows are
 *  filled with zeroes.
 *  \post The contents of m are emptied, then retrieved from in.
 *  \return Modified istream object.
 *  \throws inputErr Thrown if the input format is incorrect.
 *  \throws streamErr Thrown if the input stream is bad.
 */
template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& m);

/*!
 *  \brief Scalar Multiplication of a Matrix
 *
 *  \pre T must overload binary operator*
 *  \param lhs Scalar value being multiplied
 *  \param rhs Matrix object being multiplied
 *  \return Modified Matrix, which is an rvalue.
 */
template <typename T>
Matrix<T>& operator*(T lhs, Matrix<T>& rhs) { return rhs * lhs; }

/*! \brief A Matrix Class
 *
 * A class that stores and manipulates a matrix of arbitrary size.
 *
 * \pre T must overload operator=, binary operator*, operator*=, binary
 * operator+, operator+=, operator<<, operator>>, binary -, binary -=.
 *
 */
template <typename T>
class Matrix
{
public:
    /*!
     *  \brief Default constructor for the Matrix class.
     *  
     *  \post m_rows and m_columns set to 0, and m_data is NULL.
     *  \return None.
     */
    Matrix(): m_data(), m_rows(0), m_columns(0) {}

    /*!
     *  \brief Constructor for the Matrix class which sets the dimensions of the
     *  Matrix.
     *
     *  \post m_rows is equal to rows, m_columns is equal to columns, and m_data
     *  contains 0's.
     *  \return None.
     */
    Matrix(int rows, int columns);

    /*!
     *  \brief Copy Constructor
     *  
     *  \param src The Matrix being copied
     *  \post m_rows and m_columns equal to source's m_rows and m_columns, and 
     *  this Matrix object contains a duplicate of source's data
     *  \return None.
     */
    Matrix(Matrix<T>& src): m_data(src.m_data),
                            m_rows(src.m_rows),
                            m_columns(src.m_columns)
    {}

    /*!
     *  \brief Move Constructor.
     *
     *  \param src Matrix to be moved.
     *  \post Row size, column size, and data moved from src to new object
     *  \return None.
     */
    Matrix(Matrix<T>&& src) noexcept : m_data(std::move(src.m_data)),
                                       m_rows(src.m_rows),
                                       m_columns(src.m_columns)
    {}

    /*!
     *  \brief Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Matrix.
     *
     *  \param rhs The Matrix object being copied.
     *  \post Row size, column size, and elements same as rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Matrix<T>& operator=(const Matrix<T>& rhs);

    /*!
     *  \brief Move Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Matrix.
     *
     *  \param rhs The Matrix object being moved.
     *  \post Row size, column size, and elements moved from rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Matrix<T>& operator=(Matrix<T>&& rhs) noexcept;
    
    /*!
     *  \brief Destructor
     *  
     *  \post All allocated data is safely deallocated and the object is 
     *  destroyed
     *  \return None.
     */
    ~Matrix() {}

    /*!
     *  \brief Bracket operator, to retrieve individual rows in the Matrix.
     *
     *  \param i Base-zero index of row being accessed.
     *  \return Reference to a row, stored as a Dolan_Vector.
     *  \throws numErr Thrown when attempting to access an invalid index.
     */
    ArrayList<T>& operator[](int i);

    /*!
     *  \brief Bracket operator, to retrieve individual rows in the Matrix.
     *
     *  \param i Base-zero index of row being accessed.
     *  \return Reference to a row, stored as a Dolan_Vector.
     *  \throws numErr Thrown when attempting to access an invalid index.
     */
    const ArrayList<T>& operator[](int i) const;

    /*!
     *  \brief Scalar Multiplication of a Matrix.
     *
     *  \pre T must overload binary operator* and operator*=.
     *  \param rhs Scalar value being multiplied.
     *  \return Modified Matrix, which is an rvalue.
     */
    Matrix<T> operator*(T rhs);

    /*!
     *  \brief Scalar Multiplication of a Matrix.
     *
     *  \pre T must overload binary operator* and operator*=.
     *  \param rhs Scalar value being multiplied.
     *  \return Modified Matrix.
     */
    Matrix<T>& operator*=(T rhs);

    /*!
     *  \brief Matrix Addition operator.
     *
     *  \pre T must overload binary operator+ and operator +=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Matrix being added.
     *  \return Modified Matrix, which is an rvalue.
     *  \throws numErr Thrown when attempting to add matrices with different
     *  dimensions.
     */
    Matrix<T> operator+(Matrix<T>& rhs);

    /*!
     *  \brief Matrix Addition operator.
     *
     *  \pre T must overload binary operator+ and operator+=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Matrix being added.
     *  \return Modified Matrix.
     *  \throws numErr Thrown when attempting to add matrices with different
     *  dimensions.
     */
    Matrix<T>& operator+=(Matrix<T>& rhs);

    /*!
     *  \brief Matrix Subtraction operator.
     *
     *  \pre T must overload binary operator- and operator -=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Matrix being subtracted.
     *  \return Modified Matrix, which is an rvalue.
     *  \throws numErr Thrown when attempting to asubtract matrices with
     *  different dimensions.
     */
    Matrix<T> operator-(Matrix<T>& rhs);

    /*!
     *  \brief Matrix Subtraction operator.
     *
     *  \pre T must overload binary operator- and operator -=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Matrix being subtracted.
     *  \return Modified Matrix.
     *  \throws numErr Thrown when attempting to asubtract matrices with
     *  different dimensions.
     */
    Matrix<T>& operator-=(Matrix<T>& rhs);

    /*!
     *  \brief Matrix-Vector Multiplication operator.
     *
     *  \pre T must overload binary operator* and operator *=. The number of
     *  columns in the Matrix must equal the number of elements in the Vector.
     *  \param rhs Vector being multiplied.
     *  \return A Dolan_Vector.
     *  \throws numErr Thrown when the number of Matrix columns does not equal
     *  the number of elements in the Dolan_Vector.
     */
    Dolan_Vector<T> operator*(Dolan_Vector<T>& rhs);

    /*!
     *  \brief Matrix-Matrix Multiplication operator.
     *
     *  \pre T must overload binary operator* and operator *=. The number of
     *  columns in the calling Matrix must equal the number of rows in rhs.
     *  \param rhs Matrix being multiplied.
     *  \return A Matrix.
     *  \throws numErr Thrown when the number of columns in the calling Matrix
     *  does not equal the number of rows in rhs.
     */
    Matrix<T> operator*(Matrix<T>& rhs);

    /*!
     *  \brief Matrix-Matrix Multiplication operator.
     *
     *  \pre T must overload binary operator* and operator *=. The number of
     *  columns in the calling Matrix must equal the number of rows in rhs.
     *  \param rhs Matrix being multiplied.
     *  \return A Matrix.
     *  \throws numErr Thrown when the number of columns in the calling Matrix
     *  does not equal the number of rows in rhs.
     */
    Matrix<T> operator*(Matrix<T>&& rhs);

    /*!
     *  \brief Matrix Transpose operator.
     *
     *  \post The calling Matrix object is not modified. The calling Matrix
     *  object can be modified by using 'A = ~A;'
     *  \return A Transpose of the calling Matrix, which is an rvalue.
     */
    Matrix<T> operator~() const;

    /*!
     *  \brief Allows for the direct insertion of data.
     *
     *  \pre The row and column parameters must be a valid position in the
     *  Matrix
     *  \param data Data being inserted into the Matrix.
     *  \param row The row the data will reside in.
     *  \param column The column the data will reside in.
     *  \post The Matrix entry at [row][column] will be set to the passed data
     *  value.
     *  \return None.
     *  \throws numErr Thrown if the index is not valid in the Matrix.
     */
    void insert_data(T data, int row, int column);

    /*!
     *  \brief Will swap two rows in the Matrix.
     *
     *  \pre i and j must be between 0 and m_rows
     *  \post The rows indexed at i and j will be swapped.
     *  \return None.
     *  \throws numErr Thrown if the index is not valid in the Matrix.
     */
    void swap_rows(int i, int j);

    /*!
     *  \brief Will swap two columns in the Matrix.
     *
     *  \pre i and j must be between 0 and m_columns
     *  \post The columns indexed at i and j will be swapped.
     *  \return None.
     *  \throws numErr Thrown if the index is not valid in the Matrix.
     */
    void swap_columns(int i, int j);

    /*!
     *  \brief Shows how many rows are in the Matrix.
     *
     *  \return The number of rows in the Matrix as an int.
     */
    int Matrix_rows() const { return m_rows; }

    /*!
     *  \brief Shows how many columns are in the Matrix.
     *
     *  \return The number of columns in the Matrix as an int.
     */
    int Matrix_columns() const { return m_columns; }

    /*!
     *  \brief Allows the dimensions of the Matrix to be directly set.
     *
     *  \param rows The number of rows in the new Matrix.
     *  \param columns The number of columns in the new Matrix.
     *  \pre rows and columns should be positive numbers.
     *  \post The Matrix will have its dimensions set to rows and columns.
     *  All elements in the new Matrix will be zero.
     *  \return None.
     *  \throws numErr Thrown if either dimension is not a positive number.
     */
    void set_dimensions(int rows, int columns);

#ifndef DOXYGEN
    friend std::ostream& operator<< <>(std::ostream& out, const Matrix<T>& m);

    friend std::istream& operator>> <>(std::istream& in, Matrix<T>& m);
#endif

private:
    /*! Contains the matrix data */
    ArrayList< ArrayList<T> > m_data;

    /*! Holds the number of rows in the matrix*/
    int m_rows;

    /*! Holds the number of columns in the matrix */
    int m_columns;

    /*!
     *  \brief Adds a new all-zero row to the matrix
     *
     *  \post The Matrix has a new row
     *  \return None.
     */
    void new_row();
};

#include "Matrix.hpp"

#endif
