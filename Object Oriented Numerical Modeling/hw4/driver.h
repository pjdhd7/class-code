/*!
 *  \file driver.h
 *  \brief Header for the main driver.
 */

#ifndef DRIVER_H
#define DRIVER_H

#include <fstream>
#include <iomanip>
#include "Newton_Poly.h"
#include "function_calc.h"
#include "Cheby_nodes.h"

/*!
 *  \brief Compares the error for two interpolations based on a passed function.
 *  
 *  \param uniform_poly A Newton Interpolation using uniformly spaced data 
 *  points.
 *  \param cheby_poly A Newton Interpolation using data points spaced according
 *  to Chebyshev polynomials.
 *  \param the_func A functor used to calculate true function values that are 
 *  compared against.
 *  \pre T must overload operator==, operator=, binary operator-, operator/,
 *  binary operator+, binary operator*, operator<<, and convert to/from
 *  floating point types.
 *  \return None.
 */
template <typename T>
void compare_error(const Newton_Poly<T> uniform_poly,
                   const Newton_Poly<T> cheby_poly,
                   function_calc<T> the_func);

#include "driver_funcs.hpp"

#endif