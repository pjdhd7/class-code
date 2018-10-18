/*!
 *  \file function_calc.h
 *  \brief Contains the definition of the function_calc class
 */

#ifndef FUNCTION_CALC_H
#define FUNCTION_CALC_H

#include <cmath>

/*! A functor that calculates the function 1/(1+12x^2) at a given point.
 *
 * \pre T must overload operator=, operator/, binary operator+,
 * binary operator*, operator<<, and convert to/from floating point types.
 *
 */
template <typename T>
class function_calc
{
public:
    /*!
     *  \brief Calculates the function 1/(1+12x^2) at x.
     *  
     *  \param x The value being calculated for.
     *  \return Returns the value of 1/(1+12x^2) at x.
     */
    T operator()(const T x)
    {
        return 1 / (1 + 12 * pow(x, 2));
    }
};


#endif