/*!
 * \file norm.h
 * \brief Class description of oneNorm
 */

#ifndef NORM_H
#define NORM_H

#include <iostream>
#include <vector>
#include "polarnum.h"
using namespace std;


/*! A 1-norm class.
 *
 * Functor that calculates the 1-norm of Polar Coordinates
 *
 * \pre None.
 */
template <typename T>
class oneNorm
{
    public:
        /*! Functor that calculates the 1-norm of Polar Coordinates
         *
         * \param v a Vector containing some polarNum objects of type T.
         * \return The sum of absolute values of the Polar Pairs in Vector v.
         *
         * \pre Ensure that 'T + float' and 'fabs(T)' are defined
         * \post a copy of the 1-norm is returned
         *
         */
        T operator()(vector<polarNum<T> > v);
};

#include "norm.hpp"

#endif
