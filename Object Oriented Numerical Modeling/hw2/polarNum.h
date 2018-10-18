/*!
 * \file: polarNum.h
 * \brief Class Description of polarNum
 */

#ifndef POLARNUM_H
#define POLARNUM_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "streamErr.h"
#include "inputErr.h"
#include "numerr.h"
using namespace std;

#ifndef DOXYGEN
template <typename T>
class polarNum;
#endif

/*! Stream extraction operator for `polarNum`.
 *
 * \pre Two numbers are separated by whitespace on a single line.
 * \post Data from the input stream is converted into a polarNum<T>.
 * \return the modified input stream.
 * \throws inputErr Contains a string describing the error.
 * \throws streamErr Contains a string describing the error.
 */
template <typename T>
istream& operator>>(istream& is, polarNum<T>& p);

/*! Stream insertion operator for `polarNum`.
 *
 * \pre None.
 * \post The contents of the polarNum are printed to the output stream.
 * \return the modified output stream.
 */
template <typename T>
ostream& operator<<(ostream& os, const polarNum<T>& p);

/*! A Polar Coordinates class.
 *
 * A class that can be used to represent Polar Coordinates
 *
 * \pre T must be a basic C++ type
 *
 */
template <typename T>
class polarNum
{
    public:
        /*! Default Constructor for polarNum
         *
         * \pre None.
         * \post Creates a polarNum set to (0, 0).
         *
         */
        polarNum(): 
            m_modulus(static_cast<T>(0)), m_argument(static_cast<T>(0)) {}
            
        /*! Constructor for polarNum
         *
         * \param r Sets the modulus of the polar pair.
         * \param theta Sets the argument of the polar pair in radians.
         * \pre None.
         * \post Creates a polarNum set to (r, theta).
         *
         */
        polarNum(const T& r, const T& theta): 
            m_modulus(r), m_argument(theta) {}
        
        /*! Copy Constructor for polarNum
         *
         * \param p A polarNum object that gets copied.
         * \pre None.
         * \post Creates a copy of p.
         *
         */
        polarNum(const polarNum<T>& p): 
            m_modulus(p.m_modulus), m_argument(p.m_argument) {}
        
        /*! Destructor for polarNum
         *
         * \pre None.
         * \post The object is destroyed.
         *
         */
        ~polarNum() {}
        
        /*! Unary Negation Operator
         *
         * \pre None.
         * \post Negates the modulus of polarNum.
         * \return Returns a polarNum with value (-r, theta).
         *
         */
        polarNum<T>& operator-() const;
        
        /*! Binary Multiplication Operator
         *
         * \param p2 a polarNum object.
         * \pre None.
         * \post Calculates the product of two polarNum objects.
         * \return A polarNum object equal to.
         *
         */
        const polarNum<T> operator*(const polarNum<T>& p2);
        
        /*! Binary Division Operator
         *
         * \param p2 a polarNum object.
         * \pre p2's modulus should not be zero.
         * \post Calculates the quotient of two polarNum objects.
         * \return A polarNum object equal to p1 * p2.
         * \throws numErr Thrown when p2's modulus is zero.
         *
         */
        const polarNum<T> operator/(const polarNum<T>& p2);
        
        /*! Unary Magnitude Operator
         *
         * \pre None.
         * \post Returns the absolute value of the modulus.
         * \return A T object.
         *
         */
        const T operator~();
        
        /*! Unary Conjugate Operator
         *
         * \pre None.
         * \post Negates the argument of the polarNum.
         * \return A polarNum object set to (r, -theta).
         *
         */
        const polarNum<T>& operator!();
        
        /*! The Assignment Operator
         *
         * \param rhs A polarNum that data is being copied from.
         * \pre None.
         * \post Assigns the value of rhs to lhs.
         * \return A polarNum, lhs, with copied values from rhs.
         *
         */
        const polarNum<T>& operator=(const polarNum<T>& rhs);
        
        /*! The Bracket Operator
         *
         * \param i A short int to signal which value to retrieve.
         * \pre i must be either 0 or 1.
         * \post Returns either the modulus or argument of polarNum.
         * \return The modulus if i is 0, the argument if i is 1.
         * \throws numErr Thrown if i is not either 0 or 1.
         *
         */
        const T& operator[](const short i) const;
        
        /*! Greater Than Comparison Operator
         *
         * \param rhs The polarNum being compared to.
         * \pre None.
         * \post Returns a boolean value.
         * \return 1 if the modulus of lhs is greater than the modulus of rhs,
         * \return 0 otherwise.
         *
         */
        bool operator>(const polarNum<T>& rhs);
        
        /*! Less Than Comparison Operator
         *
         * \param rhs The polarNum being compared to.
         * \pre None.
         * \post Returns a boolean value.
         * \return 1 if the modulus of lhs is less than the modulus of rhs,
         * \return 0 otherwise.
         *
         */
        bool operator<(const polarNum<T>& rhs);
        
        /*! Equal To Comparison Operator
         *
         * \param rhs The polarNum being compared to.
         * \pre None.
         * \post Returns a boolean value.
         * \return 1 if the modulus of lhs is equal to the modulus of rhs,
         * \return 0 otherwise.
         *
         */
        bool operator==(const polarNum<T>& rhs);
        
        /*! Not Equal To Comparison Operator
         *
         * \param rhs The polarNum being compared to.
         * \pre None.
         * \post Returns a boolean value.
         * \return 1 if the modulus of lhs is not equal to the modulus of rhs,
         * \return 0 otherwise.
         *
         */
        bool operator!=(const polarNum<T>& rhs);
        
        #ifndef DOXYGEN
        
        //Comments for these exist above the class template
        friend istream& operator>> <>(istream& is, polarNum<T>& p);
        friend ostream& operator<< <>(ostream& os, const polarNum<T>& p);
        
        #endif
        
        /*! Get Modulus
         *
         * \pre None.
         * \post Returns the value of the modulus.
         * \return Returns a T object.
         *
         */
        T getModulus() const { return m_modulus; }
        
        /*! Get Argument
         *
         * \pre None.
         * \post Returns the value of the argument.
         * \return Returns a T object.
         *
         */
        T getArgument() const { return m_argument; }
        
        /*! Set Modulus
         *
         * \pre None.
         * \post Changes the modulus value in the calling polarNum object.
         *
         */
        void setModulus(const T& r);
        
        /*! Set Argument
         *
         * \pre None.
         * \post Changes the argument value in the calling polarNum object.
         *
         */
        void setArgument(const T& theta);
        
    private:
    
        /*! Modulus member variable */
        T m_modulus;
        
        /*! Argument member variable */
        T m_argument;
};

#include "polarNum.hpp"

#endif
