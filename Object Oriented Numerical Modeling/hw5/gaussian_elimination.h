/*!
 *  \file gaussian_elimination.h
 *  \brief Contains the Gaussian_Elimination class definition.
 */

#ifndef GAUSSIAN_ELIMINATION_H
#define GAUSSIAN_ELIMINATION_H

#include <cmath>
#include "Matrix.h"

/*!
 *  \brief Functor that solves for the linear system A * x = b.
 *  \pre T must implement binary operator>, binary operator-, binary operator*, 
 *  and binary operator/
 */
template <typename T>
class Gaussian_Elimination
{
public:

    /*!
     *  \brief Solves the linear system A * x = b.
     *
     *  \param A The coefficient Matrix, passed by value.
     *  \param b The Dolan_Vector with values on the right-hand side of the
     *  system, passed by value.
     *  \pre The number of columns in the Matrix A must equal the number of
     *  elements in the Dolan_Vector b.
     *  \post A and b from the calling scope are not modified.
     *  \return The values of the vector x as a Dolan_Vector. Will throw a
     *  numErr if no solution exists.
     *  \throws numErr Contains a string describing the error. Can be thrown if
     *  no solution exists, or if the Vector and Matrix dimensions are not
     *  compatible.
     */
    Dolan_Vector<T> operator()(Matrix<T> A, Dolan_Vector<T> b)
    {

        const int total_rows = A.Matrix_rows();
        const int total_columns = A.Matrix_columns();
        Dolan_Vector<T> x;
        int current_row = 0;
        int current_column = 0;
        int i_max = -1;
        T f;

        if(total_columns != b.size())
            throw numErr("Gaussian_Elimination: Attempting to multiply a Matrix"
                         " by a vector with unequal dimensions. (Number of "
                         "Matrix columns must equal number of elements in the "
                         "vector)");

        /* Start by forward eliminating using partial pivoting */
        while(current_row < total_rows && current_column < total_columns)
        {
            /* Start by finding a pivot value in our current column.
             * We want to find the largest non-zero value in the column and use
             * it as our pivot value.
             * */
            for(int i = current_row; i < total_rows; i++)
            {
                if(A[i][current_column] != 0)
                {
                    if(i_max == -1)
                    {
                        i_max = i;
                    }
                    else
                    {
                        if (fabs(A[i][current_column])
                            > fabs(A[i_max][current_column]))
                            i_max = i;
                    }
                }
            }

            if(i_max == -1)
            {
                /* Current Column has no pivot, move to next column */
                current_column++;
            }
            else
            {
                /* Swap rows, then multiply all rows beneath the current row so
                 * that the pivot column is zero, and the remaining elements of
                 * each row is scaled accordingly
                 * */
                A.swap_rows(i_max, current_row);
                b.swap(i_max, current_row);

                for(int i = current_row + 1; i < total_rows; i++)
                {
                    f = A[i][current_column] / A[current_row][current_column];
                    A[i][current_column] = 0;

                    b[i] = b[i] - b[current_row] * f;

                    for(int j = current_column+1; j < total_columns; j++)
                    {
                        A[i][j] = A[i][j] - A[current_row][j] * f;
                    }
                }

                current_column++;
                current_row++;
                i_max = -1;
            }
        }

        /* Now we carry out back substitution, starting by filling the x vector
         * with zeroes and pushing the last x value to the back
         * */
        for(int i = 0; i < total_rows - 1; i++)
            x.insert_back(0);

        x.insert_back(b[total_rows-1] / A[total_rows-1][total_rows-1]);

        for(int i = total_rows - 2; i >=0; i--)
        {
            x[i] = b[i];
            for(int j = i+1; j < total_rows; j++)
            {
                x[i] = x[i] - A[i][j] * x[j];
            }

            /* Make sure we don't divide by zero, or continue solving a matrix
             * that has no solution set
             */
            if(A[i][i] != 0) x[i] = x[i] / A[i][i];
            else if(x[i] != 0) throw numErr("The Matrix is inconsistent.");
        }

        //std::cout << std::endl << A << std::endl;

        return x;
    }
};

#endif
