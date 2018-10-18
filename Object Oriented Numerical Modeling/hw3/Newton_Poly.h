/*!
 *  \file Newton_Poly.h
 *  \brief Header declaring the Newton_Poly class
 */

#ifndef NEWTON_POLY_H
#define NEWTON_POLY_H

#include <iostream>
#include <cmath>
#include "inputErr.h"
#include "streamErr.h"
#include "numErr.h"
#include "arraylist.h"

#ifndef DOXYGEN
template <typename T>
class Newton_Poly;
#endif

#ifndef DOXYGEN
template <typename T>
std::istream& operator>>(std::istream& is, Newton_Poly<T>& poly);
#endif

#ifndef DOXYGEN
template <typename T>
std::ostream& operator<<(std::ostream& os, const Newton_Poly<T>& poly);
#endif

/*! A Newton Interpolated Polynomial class.
 *
 * A class that can be used to find an interpolant for some dataset.
 *
 * \pre T must overload operator==, operator=, binary operator-, operator/,
 * binary operator+, binary operator*, operator<<, and convert to/from
 * floating point types
 *
 */
template <typename T>
class Newton_Poly
{
public:
    /*!
     *  \brief Default Constructor for Newton_Poly.
     *
     *  \pre None.
     *  \return Creates an empty Newton_Poly object.
     */
    Newton_Poly() {}
    
    /*!
     *  \brief Constructor for Newton_Poly that takes an (x,y) pair.
     *  
     *  \param x The x value of an (x,y) pair.
     *  \param y The y value of an (x,y) pair.
     *  \pre None.
     *  \post Newton_Poly has one data point and the interpolant for that point.
     *  \return Creates a Newton_Poly object with one data point.
     *  \throws numErr Contains a string describing the error.
     */
    Newton_Poly(const T& x, const T& y) { add_data(x,y); }
    
    /*!
     *  \brief Destructor for Newton_Poly.
     *
     *  \pre None.
     *  \post Newton_Poly is deleted.
     *  \return None.
     */
    ~Newton_Poly() {}

    /*!
     *  \brief Add a row to the table and expand the power form of the 
     *  polynomial for every new point.
     *  
     *  \param x The x value of an (x,y) pair.
     *  \param y The y value of an (x,y) pair.
     *  \pre The given x value should not already exist in the interpolant.
     *  \post Newton_Poly has one new data point and the interpolant for all 
     *  stored data points.
     *  \return None
     *  \throws numErr Contains a string describing the error.
     */
    void add_data(const T& x, const T& y);

    /*!
     *  \brief Returns the value of the polynomial at x.
     *  
     *  \param x The value being calculated.
     *  \pre None.
     *  \post Does not modify Newton_Poly. Use add_data() if that's your goal
     *  \return A T value
     */
    T compute(const T& x);

    /*!
     *  \brief Reads data in and adds it to the interpolant.
     *  
     *  \param is The source of the data.
     *  \param poly An interpolant object being modified.
     *  \pre Input is in the form of "x y \n", assuming x and y are numbers.
     *  \post Newton_Poly has one new data point and the interpolant for all 
     *  stored data points.
     *  \return Modified istream object.
     *  \throws inputErr Contains a string describing the error.
     *  \throws streamErr Contains a string describing the error.
     *  \throws numErr Contains a string describing the error.
     */
    friend std::istream& operator>> <>(std::istream& is, Newton_Poly<T>& poly);
    
    /*!
     *  \brief Prints all stored data points and the power form of the 
     *  polynomial.
     *  
     *  \param os The stream where data is printed.
     *  \param poly The interpolant object being printed.
     *  \pre None.
     *  \post os receives output data from poly
     *  \return Modified ostream object.
     */
    friend std::ostream& operator<< <>(std::ostream& os,
                                       const Newton_Poly<T>& poly);


private:
    
    /*! Stores the x values */
    ArrayList<T> m_x;
    
    /*! Stores the Divided Difference Table */
    ArrayList< ArrayList<T> > m_dd_table;
    
    /*! Used to represent the power form */
    ArrayList<T> m_expanded_poly;
     
    /*! Used to calculate new additions to the expanded polynomial. 
     *  Since every new point uses (x-x0)*.....*(x-x(n-1))*an to add to 
     *  the Newton form, this vector shall represent the (x-x0)*.....*(x-x(n-1))
     *  That is used for the next data point. 
     *  I swear, this makes sense in my head. 
     */
    ArrayList<T> m_forward_poly;
};

#include "Newton_Poly.hpp"

#endif //NEWTON_POLY_H
