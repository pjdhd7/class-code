#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include <cmath>
#include "solver.h"

/*! \brief Gauss-Seidel Functor
 *
 * A functor that solves the linear system Ax = b using the Gauss_Seidel
 * iterative method.
 *
 * \pre T must overload operator=, binary operator*, operator*=, binary
 * operator+, operator+=, operator<<, operator>>, binary -, binary -=.
 *
 */
template <typename T>
class Gauss_Seidel: virtual public Solver<T>
{
public:
    /*!
     *  \brief Constructor for the Gauss_Seidel class which sets the
     *  maximum allowable error.
     *
     *  \pre The error must be defined between 0 and 1.
     *  \post m_error is equal to error, and m_iterations and m_time are 0.
     *  \throws numErr Thrown if error is less than 0 or greater than 1.
     */
    Gauss_Seidel(double error)
    {
        if(error > 1 || error < 0) throw numErr("Gauss_Seidel::Constructor:"
                                                " invalid error (error field "
                                                "must be between 0 and 1");

        this->m_error = error;
        this->m_iterations = 0;
        this->m_time = std::chrono::duration_values
                <std::chrono::microseconds>::zero();
    }

    /*!
     *  \brief Approximates the solution of a linear system.
     *
     *  \pre the Matrix must be diagonally dominant.
     *  \param A The Matrix of the Linear System.
     *  \param b The right-hand side of the Linear System.
     *  \post A and b are not modified.
     *  \return A Vector with the approximated values.
     *  \throws numErr Thrown if any of the Matrix or Vector dimensions are not
     *  compatible.
     */
    Vector<T> operator()(const Matrix_Base<T>& A, Vector<T>& b)
    {
        if(A.Matrix_columns() != b.size())
            throw numErr("Gauss_Seidel<T>::operator(): The number of "
                         "columns in Matrix A is not equal to the length of "
                         "Vector b.");

        if(this->is_diag_dom(A) == false)
            throw numErr("Gauss_Seidel<T>::operator(): The Matrix A is not "
                         "diagonally dominant and symmetric.");

        Vector<T> x, r;
        Symmetric_Matrix<T> M(A);
        const int matrix_rows = A.Matrix_rows();
        T sum;
        this->m_iterations = 0; // Zeroed out in case we use the solver multiple
                          // times. Take THAT, Nathan!

        for(int i = 0; i < matrix_rows; i++)
            x.insert_back(1);

        //Gets the starting time before any iterations are ran.
        auto start = std::chrono::high_resolution_clock::now();

        while(this->find_error(M, b, x) > this->m_error)
        {
            for(int i = 0; i < matrix_rows; i++)
            {
                sum = 0;
                for(int j = 0; j < matrix_rows; j++)
                {
                    if(i != j)
                        sum += M.get_element(i, j) * x[j];
                }

                x[i] = (b[i] - sum) / M.get_element(i, i);
            }

            this->m_iterations++;
        }

        //Stores the duration to member variable for later retrieval.
        this->m_time = std::chrono::high_resolution_clock::now() - start;

        return x;
    }
};

#endif
