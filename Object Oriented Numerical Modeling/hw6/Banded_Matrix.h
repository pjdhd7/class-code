#ifndef BANDED_MATRIX_H
#define BANDED_MATRIX_H

#include <iostream>
#include "vector.h"
#include "Matrix_Base.h"

#ifndef DOXYGEN
template <typename T>
class Banded_Matrix;
#endif

/*!
 *  \brief Prints all stored elements in the vector.
 *
 *  \param out The stream where data is printed.
 *  \param m The Banded_Matrix object being printed.
 *  \pre None.
 *  \post The contents of m are printed to out.
 *  \return Modified ostream object.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const Banded_Matrix<T>& m);

/*!
 *  \brief Gets elements for a Banded_Matrix from an input stream.
 *
 *  \param in The stream where data is retrieved.
 *  \param m The Banded_Matrix object being modified.
 *  \pre All of the input data must be on separate lines for each row of the
 *  Banded_Matrix, and each element in the rows separated by whitespace.
 *  \post The contents of m are emptied, then retrieved from in.
 *  \return Modified istream object.
 *  \throws inputErr Thrown if the input format is incorrect.
 *  \throws streamErr Thrown if the input stream is bad.
 */
template <typename T>
std::istream& operator>>(std::istream& in, Banded_Matrix<T>& m);

/*!
 *  \brief Banded_Matrix Addition operator.
 *
 *  \pre T must overload binary operator+ and operator +=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Banded_Matrix on the left-hand side being added.
 *  \param rhs Banded_Matrix on the right-hand side being added.
 *  \return Modified Banded_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to add matrices with different
 *  dimensions.
 */
template <typename T>
Banded_Matrix<T> operator+(const Banded_Matrix<T>& lhs,
                             const Banded_Matrix<T>& rhs);

/*!
 *  \brief Banded_Matrix Subtraction operator.
 *
 *  \pre T must overload binary operator- and operator -=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Banded_Matrix on the left-hand side being subtracted.
 *  \param rhs Banded_Matrix on the right-hand side being subtracted.
 *  \return Modified Banded_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to subtract matrices with
 *  different dimensions.
 */
template <typename T>
Banded_Matrix<T> operator-(Banded_Matrix<T>& lhs,
                             Banded_Matrix<T>& rhs);

/*!
 *  \brief Banded_Matrix Subtraction operator.
 *
 *  \pre T must overload binary operator- and operator -=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Banded_Matrix on the left-hand side being subtracted.
 *  \param rhs Banded_Matrix on the right-hand side being subtracted.
 *  \return Modified Banded_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to subtract matrices with
 *  different dimensions.
 */
template <typename T>
Banded_Matrix<T> operator-(Banded_Matrix<T>& lhs,
                             Banded_Matrix<T>&& rhs);

/*!
 *  \brief Banded_Matrix Subtraction operator.
 *
 *  \pre T must overload binary operator- and operator -=. Both Matrices
 *  must have the same dimensions.
 *  \param lhs Banded_Matrix on the left-hand side being subtracted.
 *  \param rhs Banded_Matrix on the right-hand side being subtracted.
 *  \return Modified Banded_Matrix, which is an rvalue.
 *  \throws numErr Thrown when attempting to subtract matrices with
 *  different dimensions.
 */
template <typename T>
Banded_Matrix<T> operator-(Banded_Matrix<T>&& lhs,
                             Banded_Matrix<T>&& rhs);

/*!
 *  \brief Scalar Multiplication of a Banded_Matrix
 *
 *  \pre T must overload binary operator*
 *  \param lhs Banded_Matrix object being multiplied
 *  \param rhs Scalar value being multiplied
 *  \return Modified Banded_Matrix, which is an rvalue.
 */
template <typename T>
Banded_Matrix<T> operator*(const Banded_Matrix<T>& lhs, const T& rhs);

/*!
 *  \brief Banded_Matrix-Vector Multiplication operator.
 *
 *  \pre T must overload binary operator* and operator *=. The number of
 *  columns in the Banded_Matrix must equal the number of elements in the
 *  Vector.
 *  \param lhs Generic Matrix being multiplied.
 *  \param rhs Vector being multiplied.
 *  \return A Vector.
 *  \throws numErr Thrown when the number of Banded_Matrix columns does not
 *  equal the number of elements in the Vector.
 */
template <typename T>
Vector<T> operator*(const Banded_Matrix<T>& lhs,
                          const Vector<T>& rhs);

/*!
 *  \brief Banded_Matrix-Banded_Matrix Multiplication operator.
 *
 *  \pre T must overload binary operator* and operator *=. The number of
 *  columns in the calling Banded_Matrix must equal the number of rows in
 *  rhs.
 *  \param lhs Banded_Matrix on the left-hand side being multiplied.
 *  \param rhs Banded_Matrix on the right-hand side being multiplied.
 *  \return A Banded_Matrix.
 *  \throws numErr Thrown when the number of columns in the calling
 *  Banded_Matrix does not equal the number of rows in rhs.
 */
template <typename T>
Banded_Matrix<T> operator*(const Banded_Matrix<T>& lhs,
                             const Banded_Matrix<T>& rhs);

/*!
 *  \brief Banded_Matrix-Banded_Matrix Multiplication operator.
 *
 *  \pre T must overload binary operator* and operator *=. The number of
 *  columns in the calling Banded_Matrix must equal the number of rows in
 *  rhs.
 *  \param lhs Banded_Matrix on the left-hand side being multiplied.
 *  \param rhs Banded_Matrix on the right-hand side being multiplied.
 *  \return A Banded_Matrix.
 *  \throws numErr Thrown when the number of columns in the calling
 *  Banded_Matrix does not equal the number of rows in rhs.
 */
template <typename T>
Banded_Matrix<T> operator*(const Banded_Matrix<T>&& lhs,
                             const Banded_Matrix<T>&& rhs);

/*!
 *  \brief Banded_Matrix Transpose operator.
 *
 *  \param src Banded_Matrix being transposed.
 *  \post The calling Banded_Matrix object is not modified. The calling
 *  Banded_Matrix object can be modified by using 'A = ~A;'
 *  \return A Transpose of the calling Banded_Matrix, which is an rvalue.
 */
template <typename T>
Banded_Matrix<T> operator~(const Banded_Matrix<T>& src);

/*!
 *  \brief Scalar Multiplication of a Banded_Matrix.
 *
 *  \pre T must overload binary operator*.
 *  \param lhs Scalar value being multiplied.
 *  \param rhs Banded_Matrix object being multiplied.
 *  \return Modified Banded_Matrix, which is an rvalue.
 */
template <typename T>
Banded_Matrix<T> operator*(const T lhs, const Banded_Matrix<T>& rhs)
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
class Banded_Matrix: public Matrix_Base<T>
{
public:
    /*!
     *  \brief Default constructor for the Banded_Matrix class.
     *
     *  \post m_rows and m_columns set to 0, and m_data is NULL.
     *  \return None.
     */
    Banded_Matrix(): m_data()
    {
        this->m_rows = 0;
        this->m_columns = 0;
    }

    /*!
     *  \brief Constructor for the Banded_Matrix class which sets the
     *  dimensions of the Banded_Matrix.
     *
     *  \pre Both parameters must be non-negative integers.
     *  \param columns The number of columns for the new Matrix.
     *  \param rows The number of rows for the new Matrix.
     *  \post m_rows is equal to rows, m_columns is equal to columns, and m_data
     *  contains 0's.
     *  \return None.
     *  \throws numErr Thrown if either dimension is negative.
     */
    Banded_Matrix(int rows, int columns);
    /*!
     *  \brief General Copy Constructor
     *
     *  \param src The Matrix being copied.
     *  \post m_rows and m_columns equal to source's m_rows and m_columns, and
     *  this Banded_Matrix object contains a duplicate of source's data.
     *  \return None.
     *  \throws numErr Thrown if the Matrix being copied is not a Banded Matrix.
     */
    Banded_Matrix(const Matrix_Base<T>& src);

    /*!
     *  \brief Copy Constructor
     *
     *  \param src The Banded_Matrix being copied.
     *  \post m_rows and m_columns equal to source's m_rows and m_columns, and
     *  this Banded_Matrix object contains a duplicate of source's data.
     *  \return None.
     */
    Banded_Matrix(const Banded_Matrix<T>& src):
            m_data(src.m_data)
    {
        this->m_rows = src.Matrix_rows();
        this->m_columns = src.Matrix_columns();
    }

    /*!
     *  \brief Move Constructor.
     *
     *  \param src Banded_Matrix to be moved.
     *  \post Row size, column size, and data moved from src to new object
     *  \return None.
     */
    Banded_Matrix(Banded_Matrix<T>&& src) noexcept :
            m_data(std::move(src.m_data))
    {
        this->m_rows = src.Matrix_rows();
        this->m_columns = src.Matrix_columns();
    }

    /*!
     *  \brief Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Banded_Matrix.
     *
     *  \param rhs The Banded_Matrix object being copied.
     *  \post Row size, column size, and elements same as rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Banded_Matrix<T>& operator=(const Banded_Matrix<T>& rhs);

    /*!
     *  \brief Move Assignment Operator
     *
     *  Performs a deep copy of 'rhs' into 'this' Banded_Matrix.
     *
     *  \param rhs The Banded_Matrix object being moved.
     *  \post Row size, column size, and elements moved from rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Banded_Matrix<T>& operator=(Banded_Matrix<T>&& rhs) noexcept;

    /*!
     *  \brief Destructor
     *
     *  \post All allocated data is safely deallocated and the object is
     *  destroyed
     *  \return None.
     */
    ~Banded_Matrix() {}

    /*!
     *  \brief Scalar Multiplication of a Banded_Matrix.
     *
     *  \pre T must overload binary operator* and operator*=.
     *  \param rhs Scalar value being multiplied.
     *  \return Modified Banded_Matrix.
     */
    Banded_Matrix<T>& operator*=(T rhs);

    /*!
     *  \brief Banded_Matrix Addition operator.
     *
     *  \pre T must overload binary operator+ and operator+=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Banded_Matrix being added.
     *  \return Modified Banded_Matrix.
     *  \throws numErr Thrown when attempting to add matrices with different
     *  dimensions.
     */
    Banded_Matrix<T>& operator+=(const Banded_Matrix<T>& rhs);

    /*!
     *  \brief Banded_Matrix Subtraction operator.
     *
     *  \pre T must overload binary operator- and operator -=. Both Matrices
     *  must have the same dimensions
     *  \param rhs Banded_Matrix being subtracted.
     *  \return Modified Banded_Matrix.
     *  \throws numErr Thrown when attempting to asubtract matrices with
     *  different dimensions.
     */
    Banded_Matrix<T>& operator-=(Banded_Matrix<T>& rhs);

    /*!
     *  \brief Allows for the direct insertion of data.
     *
     *  \pre The row and column parameters must be a valid position in the
     *  Banded_Matrix
     *  \param data Data being inserted into the Banded_Matrix.
     *  \param row The row the data will reside in.
     *  \param column The column the data will reside in.
     *  \post The Banded_Matrix entry at [row][column] will be set to the
     *  passed data value.
     *  \return None.
     *  \throws numErr Thrown if the index is not valid in the Banded_Matrix.
     */
    void insert_data(T data, int row, int column);

    /*!
     *  \brief Allows the dimensions of the Banded_Matrix to be directly set.
     *
     *  \param rows The number of rows in the new Banded_Matrix.
     *  \param columns The number of columns in the new Banded_Matrix.
     *  \pre rows and columns should be positive numbers.
     *  \post The Banded_Matrix will have its dimensions set to rows and
     *  columns. All elements in the new Banded_Matrix will be zero.
     *  \return None.
     *  \throws numErr Thrown if either dimension is not a positive number.
     */
    void set_dimensions(int rows, int columns);

    /*!
     *  \brief Allows data to be retrieved.
     *
     *  \pre The row and column parameters must be a valid position in the
     *  Matrix.
     *  \param row The row the data resides in.
     *  \param column The column the data resides in.
     *  \post The Matrix entry at [row][column] will be returned.
     *  \return A T object.
     */
    const T get_element(int row, int column) const;

    /*!
     *  \brief Checks if a passed Matrix is diagonal.
     *
     *  \pre None.
     *  \param A The Matrix being examined.
     *  \post None.
     *  \return True if the Matrix is diagonal, False otherwise.
     */
    bool is_banded(const Matrix_Base<T> &A);

#ifndef DOXYGEN
    friend std::ostream& operator<< <>(std::ostream& out,
                                       const Banded_Matrix<T>& m);

    friend std::istream& operator>> <>(std::istream& in, Banded_Matrix<T>& m);

    friend Banded_Matrix<T> operator+ <>(const Banded_Matrix<T>& lhs,
                                           const Banded_Matrix<T>& rhs);

    friend Banded_Matrix<T> operator- <>(Banded_Matrix<T>& lhs,
                                           Banded_Matrix<T>& rhs);

    friend Banded_Matrix<T> operator- <>(Banded_Matrix<T>& lhs,
                                           Banded_Matrix<T>&& rhs);

    friend Banded_Matrix<T> operator- <>(Banded_Matrix<T>&& lhs,
                                           Banded_Matrix<T>&& rhs);

    friend Banded_Matrix<T> operator* <>(const Banded_Matrix<T>& lhs,
                                           const T& rhs);

    friend Vector<T> operator* <>(const Banded_Matrix<T>& lhs,
                                        const Vector<T>& rhs);

    friend Banded_Matrix<T> operator* <>(const Banded_Matrix<T>& lhs,
                                           const Banded_Matrix<T>& rhs);

    friend Banded_Matrix<T> operator* <>(const Banded_Matrix<T>&& lhs,
                                           const Banded_Matrix<T>&& rhs);

    friend Banded_Matrix<T> operator~ <>(const Banded_Matrix<T>& src);
#endif

protected:
    /*! Contains the Banded_matrix data */
    ArrayList< ArrayList<T> > m_data;

private:
    /*!
     *  \brief Adds a new all-zero row to the Banded_Matrix.
     *
     *  \post The Banded_Matrix has a new row.
     *  \return None.
     */
    void new_row();

    /*!
     *  \brief Modifies the stored value for number of columns in the
     *  Banded_Matrix.
     *
     *  \pre columns must be greater than or equal to zero.
     *  \param columns The new number of columns in the Matrix.
     *  \post The stored columns value of the Matrix is altered.
     *  \return None.
     */
    void set_columns(int columns);

    /*!
     *  \brief Modifies the stored value for number of rows in the
     *  Banded_Matrix.
     *
     *  \pre rows must be greater than or equal to zero.
     *  \param rows The new number of rows in the Matrix.
     *  \post The stored rows value of the Matrix is altered.
     *  \return None.
     */
    void set_rows(int rows);
};

#include "Banded_Matrix.hpp"

#endif
