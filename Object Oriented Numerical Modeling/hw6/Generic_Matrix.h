/*!
 *  \file Generic_Matrix.h
 *  \brief Declaration of the Generic_Matrix Class
 */

#ifndef GENERIC_MATRIX_H
#define GENERIC_MATRIX_H

#include <iostream>
#include "vector.h"
#include "Matrix_Base.h"

#ifndef DOXYGEN
template <typename T>
class Generic_Matrix;
#endif

/*!
 *  \brief Prints all stored elements in the vector.
 *
 *  \param out The stream where data is printed.
 *  \param m The Generic_Matrix object being printed.
 *  \pre None.
 *  \post The contents of m are printed to out.
 *  \return Modified ostream object.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const Generic_Matrix<T>& m);

/*!
 *  \brief Gets elements for a Generic_Matrix from an input stream.
 *
 *  \param in The stream where data is retrieved.
 *  \param m The Generic_Matrix object being modified.
 *  \pre All of the input data must be on separate lines for each row of the
 *  Generic_Matrix, and each element in the rows separated by whitespace. If any
 *  rows are shorter than the longest row, the remainder of the shorter rows are
 *  filled with zeroes.
 *  \post The contents of m are emptied, then retrieved from in.
 *  \return Modified istream object.
 *  \throws inputErr Thrown if the input format is incorrect.
 *  \throws streamErr Thrown if the input stream is bad.
 */
template <typename T>
std::istream& operator>>(std::istream& in, Generic_Matrix<T>& m);

/*!
 *  \brief Generic_Matrix Addition operator.
 *
 *  \pre T must overload binary operator+ and operator +=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Generic_Matrix on the left-hand side being added.
 *  \param rhs Generic_Matrix on the right-hand side being added.
 *  \return Modified Generic_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to add matrices with different
 *  dimensions.
 */
template <typename T>
Generic_Matrix<T> operator+(const Generic_Matrix<T>& lhs,
                            const Matrix_Base<T>& rhs);

/*!
 *  \brief Generic_Matrix Subtraction operator.
 *
 *  \pre T must overload binary operator- and operator -=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Generic_Matrix on the left-hand side being subtracted.
 *  \param rhs Generic_Matrix on the right-hand side being subtracted.
 *  \return Modified Generic_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to subtract matrices with
 *  different dimensions.
 */
template <typename T>
Generic_Matrix<T> operator-(Generic_Matrix<T>& lhs,
                            Matrix_Base<T>& rhs);

/*!
 *  \brief Generic_Matrix Subtraction operator.
 *
 *  \pre T must overload binary operator- and operator -=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Generic_Matrix on the left-hand side being subtracted.
 *  \param rhs Generic_Matrix on the right-hand side being subtracted.
 *  \return Modified Generic_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to subtract matrices with
 *  different dimensions.
 */
template <typename T>
Generic_Matrix<T> operator-(Generic_Matrix<T>& lhs,
                            Matrix_Base<T>&& rhs);

/*!
 *  \brief Generic_Matrix Subtraction operator.
 *
 *  \pre T must overload binary operator- and operator -=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Generic_Matrix on the left-hand side being subtracted.
 *  \param rhs Generic_Matrix on the right-hand side being subtracted.
 *  \return Modified Generic_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to subtract matrices with
 *  different dimensions.
 */
template <typename T>
Generic_Matrix<T> operator-(Generic_Matrix<T>&& lhs,
                            Matrix_Base<T>&& rhs);

/*!
 *  \brief Scalar Multiplication of a Generic_Matrix
 *
 *  \pre T must overload binary operator*
 *  \param lhs Generic_Matrix object being multiplied
 *  \param rhs Scalar value being multiplied
 *  \return Modified Generic_Matrix, which is an rvalue.
 */
template <typename T>
Generic_Matrix<T> operator*(const Generic_Matrix<T>& lhs, const T& rhs);

/*!
 *  \brief Generic_Matrix-Vector Multiplication operator.
 *
 *  \pre T must overload binary operator* and operator *=. The number of
 *  columns in the Generic_Matrix must equal the number of elements in the
 *  Vector.
 *  \param lhs Generic Matrix being multiplied.
 *  \param rhs Vector being multiplied.
 *  \return A Vector.
 *  \throws numErr Thrown when the number of Generic_Matrix columns does not
 *  equal the number of elements in the Vector.
 */
template <typename T>
Vector<T> operator*(const Generic_Matrix<T>& lhs,
                          const Vector<T>& rhs);

/*!
 *  \brief Generic_Matrix-Generic_Matrix Multiplication operator.
 *
 *  \pre T must overload binary operator* and operator *=. The number of
 *  columns in the calling Generic_Matrix must equal the number of rows in
 *  rhs.
 *  \param lhs Generic_Matrix on the left-hand side being multiplied.
 *  \param rhs Generic_Matrix on the right-hand side being multiplied.
 *  \return A Generic_Matrix.
 *  \throws numErr Thrown when the number of columns in the calling
 *  Generic_Matrix does not equal the number of rows in rhs.
 */
template <typename T>
Generic_Matrix<T> operator*(const Generic_Matrix<T>& lhs,
                            const Matrix_Base<T>& rhs);

/*!
 *  \brief Generic_Matrix-Generic_Matrix Multiplication operator.
 *
 *  \pre T must overload binary operator* and operator *=. The number of
 *  columns in the calling Generic_Matrix must equal the number of rows in
 *  rhs.
 *  \param lhs Generic_Matrix on the left-hand side being multiplied.
 *  \param rhs Generic_Matrix on the right-hand side being multiplied.
 *  \return A Generic_Matrix.
 *  \throws numErr Thrown when the number of columns in the calling
 *  Generic_Matrix does not equal the number of rows in rhs.
 */
template <typename T>
Generic_Matrix<T> operator*(const Generic_Matrix<T>&& lhs,
                             const Matrix_Base<T>&& rhs);

/*!
 *  \brief Generic_Matrix Transpose operator.
 *
 *  \param src Generic_Matrix being transposed.
 *  \post The calling Generic_Matrix object is not modified. The calling
 *  Generic_Matrix object can be modified by using 'A = ~A;'
 *  \return A Transpose of the calling Generic_Matrix, which is an rvalue.
 */
template <typename T>
Generic_Matrix<T> operator~(const Generic_Matrix<T>& src);

/*!
 *  \brief Scalar Multiplication of a Generic_Matrix.
 *
 *  \pre T must overload binary operator*.
 *  \param lhs Scalar value being multiplied.
 *  \param rhs Generic_Matrix object being multiplied.
 *  \return Modified Generic_Matrix, which is an rvalue.
 */
template <typename T>
Generic_Matrix<T> operator*(const T lhs, const Generic_Matrix<T>& rhs)
        { return rhs * lhs; }

/*! \brief A Generic Matrix Class
 *
 * A class that stores and manipulates a Generic matrix of arbitrary size.
 *
 * \pre T must overload operator=, binary operator*, operator*=, binary
 * operator+, operator+=, operator<<, operator>>, binary -, binary -=.
 *
 */
template <typename T>
class Generic_Matrix: public Matrix_Base<T>
{
public:
    /*!
     *  \brief Default constructor for the Generic_Matrix class.
     *  
     *  \post m_rows and m_columns set to 0, and m_data is NULL.
     *  \return None.
     */
    Generic_Matrix(): m_data()
    {
        this->m_rows = 0;
        this->m_columns = 0;
    }

    /*!
     *  \brief Constructor for the Generic_Matrix class which sets the
     *  dimensions of the Generic_Matrix.
     *
     *  \pre Both parameters must be non-negative integers.
     *  \param columns The number of columns for the new Matrix.
     *  \param rows The number of rows for the new Matrix.
     *  \post m_rows is equal to rows, m_columns is equal to columns, and m_data
     *  contains 0's.
     *  \return None.
     *  \throws numErr Thrown if either dimension is negative.
     */
    Generic_Matrix(int rows, int columns);
    /*!
     *  \brief Copy Constructor
     *
     *  \param src The Matrix being copied.
     *  \post m_rows and m_columns equal to source's m_rows and m_columns, and
     *  this Generic_Matrix object contains a duplicate of source's data.
     *  \return None.
     */
    Generic_Matrix(const Matrix_Base<T>& src);

    /*!
     *  \brief Copy Constructor
     *  
     *  \param src The Generic_Matrix being copied.
     *  \post m_rows and m_columns equal to source's m_rows and m_columns, and 
     *  this Generic_Matrix object contains a duplicate of source's data.
     *  \return None.
     */
    Generic_Matrix(const Generic_Matrix<T>& src):
            m_data(src.m_data)
    {
        this->m_rows = src.Matrix_rows();
        this->m_columns = src.Matrix_columns();
    }

    /*!
     *  \brief Move Constructor.
     *
     *  \param src Generic_Matrix to be moved.
     *  \post Row size, column size, and data moved from src to new object
     *  \return None.
     */
    Generic_Matrix(Generic_Matrix<T>&& src) noexcept :
            m_data(std::move(src.m_data))
    {
        this->m_rows = src.Matrix_rows();
        this->m_columns = src.Matrix_columns();
    }

    /*!
     *  \brief Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Generic_Matrix.
     *
     *  \param rhs The Generic_Matrix object being copied.
     *  \post Row size, column size, and elements same as rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Generic_Matrix<T>& operator=(const Generic_Matrix<T>& rhs);

    /*!
     *  \brief Move Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Generic_Matrix.
     *
     *  \param rhs The Generic_Matrix object being moved.
     *  \post Row size, column size, and elements moved from rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Generic_Matrix<T>& operator=(Generic_Matrix<T>&& rhs) noexcept;
    
    /*!
     *  \brief Destructor
     *  
     *  \post All allocated data is safely deallocated and the object is 
     *  destroyed
     *  \return None.
     */
    ~Generic_Matrix() {}

    /*!
     *  \brief Bracket operator, to retrieve individual rows in the
     *  Generic_Matrix.
     *
     *  \param i Base-zero index of row being accessed.
     *  \return Reference to a row, stored as a Vector.
     *  \throws numErr Thrown when attempting to access an invalid index.
     */
    ArrayList<T>& operator[](int i);

    /*!
     *  \brief Bracket operator, to retrieve individual rows in the
     *  Generic_Matrix.
     *
     *  \param i Base-zero index of row being accessed.
     *  \return Reference to a row, stored as a Vector.
     *  \throws numErr Thrown when attempting to access an invalid index.
     */
    const ArrayList<T>& operator[](int i) const;

    /*!
     *  \brief Scalar Multiplication of a Generic_Matrix.
     *
     *  \pre T must overload binary operator* and operator*=.
     *  \param rhs Scalar value being multiplied.
     *  \return Modified Generic_Matrix.
     */
    Generic_Matrix<T>& operator*=(T rhs);

    /*!
     *  \brief Generic_Matrix Addition operator.
     *
     *  \pre T must overload binary operator+ and operator+=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Generic_Matrix being added.
     *  \return Modified Generic_Matrix.
     *  \throws numErr Thrown when attempting to add matrices with different
     *  dimensions.
     */
    Generic_Matrix<T>& operator+=(const Matrix_Base<T>& rhs);

    /*!
     *  \brief Generic_Matrix Subtraction operator.
     *
     *  \pre T must overload binary operator- and operator -=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Generic_Matrix being subtracted.
     *  \return Modified Generic_Matrix.
     *  \throws numErr Thrown when attempting to asubtract matrices with
     *  different dimensions.
     */
    Generic_Matrix<T>& operator-=(Matrix_Base<T>& rhs);

    /*!
     *  \brief Allows for the direct insertion of data.
     *
     *  \pre The row and column parameters must be a valid position in the
     *  Generic_Matrix
     *  \param data Data being inserted into the Generic_Matrix.
     *  \param row The row the data will reside in.
     *  \param column The column the data will reside in.
     *  \post The Generic_Matrix entry at [row][column] will be set to the
     *  passed data value.
     *  \return None.
     *  \throws numErr Thrown if the index is not valid in the Generic_Matrix.
     */
    void insert_data(T data, int row, int column);

    /*!
     *  \brief Will swap two rows in the Generic_Matrix.
     *
     *  \pre i and j must be between 0 and m_rows
     *  \post The rows indexed at i and j will be swapped.
     *  \return None.
     *  \throws numErr Thrown if the index is not valid in the Generic_Matrix.
     */
    void swap_rows(int i, int j);

    /*!
     *  \brief Will swap two columns in the Generic_Matrix.
     *
     *  \pre i and j must be between 0 and m_columns
     *  \post The columns indexed at i and j will be swapped.
     *  \return None.
     *  \throws numErr Thrown if the index is not valid in the Generic_Matrix.
     */
    void swap_columns(int i, int j);

    /*!
     *  \brief Allows the dimensions of the Generic_Matrix to be directly set.
     *
     *  \param rows The number of rows in the new Generic_Matrix.
     *  \param columns The number of columns in the new Generic_Matrix.
     *  \pre rows and columns should be positive numbers.
     *  \post The Generic_Matrix will have its dimensions set to rows and
     *  columns. All elements in the new Generic_Matrix will be zero.
     *  \return None.
     *  \throws numErr Thrown if either dimension is not a positive number.
     */
    void set_dimensions(int rows, int columns);

    /*!
     *  \brief Allows data to be retrieved.
     *
     *  \pre The row and column parameters must be a valid position in the
     *  Matrix
     *  \param row The row the data resides in.
     *  \param column The column the data resides in.
     *  \post The Matrix entry at [row][column] will be returned.
     *  \return A T object.
     */
    const T get_element(int row, int column) const;

#ifndef DOXYGEN
    friend std::ostream& operator<< <>(std::ostream& out,
                                       const Generic_Matrix<T>& m);

    friend std::istream& operator>> <>(std::istream& in, Generic_Matrix<T>& m);

    friend Generic_Matrix<T> operator+ <>(const Generic_Matrix<T>& lhs,
                                       const Matrix_Base<T>& rhs);

    friend Generic_Matrix<T> operator- <>(Generic_Matrix<T>& lhs,
                                          Matrix_Base<T>& rhs);

    friend Generic_Matrix<T> operator- <>(Generic_Matrix<T>& lhs,
                                          Matrix_Base<T>&& rhs);

    friend Generic_Matrix<T> operator- <>(Generic_Matrix<T>&& lhs,
                                          Matrix_Base<T>&& rhs);

    friend Generic_Matrix<T> operator* <>(const Generic_Matrix<T>& lhs,
                                           const T& rhs);

    friend Vector<T> operator* <>(const Generic_Matrix<T>& lhs,
                                     const Vector<T>& rhs);

    friend Generic_Matrix<T> operator* <>(const Generic_Matrix<T>& lhs,
                                       const Matrix_Base<T>& rhs);

    friend Generic_Matrix<T> operator* <>(const Generic_Matrix<T>&& lhs,
                                       const Matrix_Base<T>&& rhs);

    friend Generic_Matrix<T> operator~ <>(const Generic_Matrix<T>& src);
#endif

protected:
    /*! Contains the Generic_matrix data */
    ArrayList< Vector<T> > m_data;

private:
    /*!
     *  \brief Adds a new all-zero row to the Generic_Matrix.
     *
     *  \post The Generic_Matrix has a new row.
     *  \return None.
     */
    void new_row();

    /*!
     *  \brief Modifies the stored value for number of columns in the
     *  Generic_Matrix.
     *
     *  \pre columns must be greater than or equal to zero.
     *  \param columns The new number of columns in the Matrix.
     *  \post The stored columns value of the Matrix is altered.
     *  \return None.
     */
    void set_columns(int columns);
};

#include "Generic_Matrix.hpp"

#endif
