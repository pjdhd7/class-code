#ifndef SOLVER_H
#define SOLVER_H

#include <chrono>
#include "vector.h"
#include "Matrix_Base.h"
#include "Symmetric_Matrix.h"

template <typename T>
class Solver
{
public:
    /*!
     *  \brief Finds the approximate solution to a given Linear system.
     *
     *  \pre The Matrix must be diagonally dominant.
     *  \param A The Matrix of the Linear System.
     *  \param b The right-hand side of the Linear System.
     *  \return A Vector containing the approximate x values that solve the
     *  Linear system.
     */
    virtual Vector<T> operator()(const Matrix_Base<T>& A, Vector<T>& b) = 0;

    /*!
     *  \brief Returns the number of iterations of the latest execution.
     *
     *  \return An unsigned int representing the number of iterations.
     */
    unsigned int get_iterations() const { return m_iterations; }

    /*!
     *  \brief Returns the duration of the latest execution.
     *
     *  \return A long long int representing the number of microseconds.
     */
    long long get_time() const
    {
        return std::chrono::duration_cast
                <std::chrono::microseconds>(m_time).count();
    }

protected:
    /*! The relative error that is being solved for. */
    double m_error;

    /*! The number of iterations for the given solver. */
    unsigned int m_iterations;

    /*! The time duration for a given execution */
    std::chrono::high_resolution_clock::duration m_time;

    /*!
     *  \brief Finds the fractional relative error of an approximated vector.
     *
     *  \param A The Matrix of the Linear System.
     *  \param b The right-hand side of the Linear System.
     *  \param x The vector being approximated for.
     *  \post The Matrix entry at [row][column] will be set to the passed data
     *  value.
     *  \return None.
     *  \throws numErr Thrown if any of the Matrix or Vector dimensions are not
     *  compatible.
     */
    double find_error(const Symmetric_Matrix<T>& A,
                      const Vector<T>& b,
                      const Vector<T>& x)
    {
        if(A.Matrix_columns() != x.size())
            throw numErr("Steepest_Descent<T>::find_error: Matrix A and vector "
                         "x do not have compatible dimensions.");
        if(A.Matrix_columns() != b.size())
            throw numErr("Steepest_Descent<T>::find_error: Matrix A and vector "
                         "b do not have compatible dimensions.");

        Vector<T> compare_value = (A * x) - b;

        return fabs(compare_value.oneNorm() / b.oneNorm());
    }

    /*!
     *  \brief Determines if a Matrix is Diagonally Dominant.
     *
     *  \param A The Matrix of the Linear System.
     *  \post None.
     *  \return True if the Matrix is Diagonally Dominant, False otherwise
     */
    bool is_diag_dom(const Matrix_Base<T>& A)
    {
        const int columns = A.Matrix_columns();
        const int rows = A.Matrix_rows();
        T temp_sum = 0;

        //The Matrix must be square
        if(columns != rows)
            return false;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(j != i)
                {
                    //The Matrix must be symmetric
                    if(A.get_element(i, j) != A.get_element(j, i))
                        return false;
                    else
                        temp_sum += fabs(A.get_element(i, j));
                }
            }

            //The absolute value of the elements on the main diagonal must be
            //greater than the sum of the absolute values of the rest of the row
            if(temp_sum >= fabs(A.get_element(i, i)))
                return false;
            else
                temp_sum = 0;
        }

        return true;
    }
};

#endif
