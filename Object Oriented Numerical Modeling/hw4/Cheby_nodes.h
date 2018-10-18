/*!
 *  \file Cheby_nodes.h
 *  \brief Functor that generates Chebyshev nodes.
 */

#ifndef CHEBY_NODES_H
#define CHEBY_NODES_H

#include <cmath>
#include "arraylist.h"

/*! A Chebyshev Node Generator class.
 *
 * A class that can be used to find a given number Chebyshev nodes.
 *
 * \pre T must overload operator==, operator=, binary operator-, operator/,
 * binary operator+, binary operator*, operator<<, and convert to/from
 * floating point types.
 *
 */
template <typename T>
class Cheby_nodes {
public:
    /*!
     *  \brief Generates the Chebyshev nodes for degree+1 Chebyshev polynomials.
     *  
     *  \param degree The degree of the polynomial being interpolated.
     *  \return Returns an ArrayList object with the Chebyshev nodes.
     */
    ArrayList<T> operator()(const int& degree);
};

#include "Cheby_nodes.hpp"

#endif