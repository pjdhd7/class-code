#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include "vector.h"

/*! \brief An Abstract Matrix Base Class.
 *
 * A class that creates a common interface for specialized Matrices of
 * different types.
 *
 * \pre T must overload operator=, binary operator*, operator*=, binary
 * operator+, operator+=, operator<<, operator>>, binary -, binary -=.
 *
 */
template <typename T>
class Matrix_Base
{
public:

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
    virtual const T get_element(int row, int column) const = 0;

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
     */
    virtual void insert_data(T data, int row, int column) = 0;

    /*!
     *  \brief Shows how many rows are in the Matrix_Base.
     *
     *  \return The number of rows in the Matrix_Base as an int.
     */
    int Matrix_rows() const { return m_rows; }

    /*!
     *  \brief Shows how many columns are in the Matrix_Base.
     *
     *  \return The number of columns in the Matrix_Base as an int.
     */
    int Matrix_columns() const { return m_columns; }

    /*!
     *  \brief Allows the dimensions of the Matrix_Base to be directly set.
     *
     *  \param rows The number of rows in the new Matrix_Base.
     *  \param columns The number of columns in the new Matrix_Base.
     *  \pre rows and columns should be positive numbers.
     *  \post The Matrix_Base will have its dimensions set to rows and
     *  columns. All elements in the new Matrix_Base will be zero.
     *  \return None.
     */
    virtual void set_dimensions(int rows, int columns) = 0;

protected:
    /*! Holds the number of rows in the matrix*/
    int m_rows;

    /*! Holds the number of columns in the matrix */
    int m_columns;
};

#endif
