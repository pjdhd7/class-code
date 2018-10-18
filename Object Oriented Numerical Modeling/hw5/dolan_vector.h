/*!
 *  \file dolan_vector.h
 *  \brief Declaration of the Dolan_Vector class
 */

#ifndef DOLAN_VECTOR_H
#define DOLAN_VECTOR_H

#include <sstream>
#include "arraylist.h"

#ifndef DOXYGEN
template <typename T>
class Dolan_Vector;
#endif

/*!
 *  \brief Prints all stored elements in the vector.
 *
 *  \param out The stream where data is printed.
 *  \param v The Dolan_Vector object being printed.
 *  \pre None.
 *  \post The contents of v are printed to out.
 *  \return Modified ostream object.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const Dolan_Vector<T>& v);

/*!
 *  \brief Gets elements for a Dolan_Vector from an input stream.
 *
 *  \param in The stream where data is retrieved.
 *  \param v The Dolan_Vector object being modified.
 *  \pre All of the input data must be in one line, each element separated by
 *  whitespace.
 *  \post The contents of v are emptied, then retrieved from in.
 *  \return Modified istream object.
 *  \throws streamErr Thrown if the input stream is bad.
 */
template <typename T>
std::istream& operator>>(std::istream& in, Dolan_Vector<T>& v);

/*!
 *  \brief Scalar Multiplication of a Dolan_Vector.
 *
 *  \param lhs The scalar value.
 *  \param rhs The Dolan_Vector being multiplied.
 *  \pre None.
 *  \post The contents of rhs are multiplied by lhs.
 *  \return Modified Dolan_Vector object.
 */
template <typename T>
Dolan_Vector<T> operator*(T lhs, Dolan_Vector<T>& rhs);

/*! \brief A Vector Class
 *
 *  A class that stores and manipulates a Vector of arbitrary size.
 *
 *  \pre T must overload operator=, binary operator*, operator*=, binary
 *  operator+, operator+= and operator<<.
 *
 */
template <typename T>
class Dolan_Vector: public ArrayList<T>
{
public:
    /*!
     *  \brief Default Constructor.
     *
     *  \post Current size and maximum size set to 0,
     *   and data set to NULL.
     *  \return None.
     */
    Dolan_Vector();

    /*!
     *  \brief Destructor.
     *
     *  \post Current size and maximum size set to 0,
     *  data deallocated and set to NULL.
     *  \return None.
     */
    ~Dolan_Vector(){ ArrayList<T>::m_data.reset(); }

    /*!
     *  \brief Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Dolan_Vector.
     *
     *  \param rhs The Dolan_Vector object being copied.
     *  \post Current size, maximum size, and elements same as rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Dolan_Vector<T>& operator=(const Dolan_Vector<T>& rhs);

    /*!
     *  \brief Move Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Dolan_Vector.
     *
     *  \param rhs The Dolan_Vector object being moved.
     *  \post Current size, maximum size, and elements moved from rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Dolan_Vector<T>& operator=(Dolan_Vector<T>&& rhs) noexcept;

    /*!
     *  \brief Copy Constructor.
     *
     *  \param cpy Dolan_Vector to be copied.
     *  \post Current size, maximum size, and elements same as cpy.
     *  \return This object with deep copies of data of rhs.
     */
    Dolan_Vector(const Dolan_Vector<T>& cpy): ArrayList<T>(cpy) { *this = cpy; }

    /*!
     *  \brief Move Constructor.
     *
     *  \param src Dolan_Vector to be moved.
     *  \post Current size, maximum size, and data moved from src to new object
     *  \return None.
     */
    Dolan_Vector(Dolan_Vector<T>&& src) noexcept;

	/*!
     *  \brief Scalar Multiplication of a Dolan_Vector.
     *
     *  \param rhs The scalar value.
     *  \pre None.
     *  \post The contents of this are multiplied by rhs.
     *  \return Modified Dolan_Vector object, which is an rvalue.
     */
    Dolan_Vector<T> operator*(T rhs);
	
	/*!
     *  \brief Scalar Multiplication of a Dolan_Vector.
     *
     *  \param rhs The scalar value.
     *  \pre None.
     *  \post The contents of this are multiplied by rhs.
     *  \return Modified Dolan_Vector object.
     */
    Dolan_Vector<T>& operator*=(T rhs);

#ifndef DOXYGEN
    friend std::ostream& operator<< <>(std::ostream& out,
                                    const Dolan_Vector<T>& v);

    friend std::istream& operator>> <>(std::istream& in,
                                       Dolan_Vector<T>& v);
#endif


private:
    /*!
     *  \brief Override of the 'ArrayList<T>::purge()' function. This should
     *  never be called by a 'Dolan_Vector' object.
     *  
     *  \return None.
     *  \throws numErr Will always throw when function is called
     */
    void purge(){ throw numErr("You shouldn't be calling this function!"); }
};

#include "dolan_vector.hpp"

#endif
