/*!
 *  \file vector.h
 *  \brief Declaration of the Vector class
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <sstream>
#include <cmath>
#include "arraylist.h"

#ifndef DOXYGEN
template <typename T>
class Vector;
#endif

/*!
 *  \brief Prints all stored elements in the vector.
 *
 *  \param out The stream where data is printed.
 *  \param v The Vector object being printed.
 *  \pre None.
 *  \post The contents of v are printed to out.
 *  \return Modified ostream object.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v);

/*!
 *  \brief Gets elements for a Vector from an input stream.
 *
 *  \param in The stream where data is retrieved.
 *  \param v The Vector object being modified.
 *  \pre All of the input data must be in one line, each element separated by
 *  whitespace.
 *  \post The contents of v are emptied, then retrieved from in.
 *  \return Modified istream object.
 *  \throws streamErr Thrown if the input stream is bad.
 */
template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& v);

/*!
 *  \brief Scalar Multiplication of a Vector.
 *
 *  \param lhs The scalar value.
 *  \param rhs The Vector being multiplied.
 *  \pre None.
 *  \post The contents of rhs are multiplied by lhs.
 *  \return Modified Vector object.
 */
template <typename T>
Vector<T> operator*(T lhs, Vector<T>& rhs);

/*! \brief A Vector Class
 *
 *  A class that stores and manipulates a Vector of arbitrary size.
 *
 *  \pre T must overload operator=, binary operator*, operator*=, binary
 *  operator+, operator+= and operator<<.
 *
 */
template <typename T>
class Vector: public ArrayList<T>
{
public:
    /*!
     *  \brief Default Constructor.
     *
     *  \post Current size and maximum size set to 0,
     *   and data set to NULL.
     *  \return None.
     */
    Vector();

    /*!
     *  \brief Destructor.
     *
     *  \post Current size and maximum size set to 0,
     *  data deallocated and set to NULL.
     *  \return None.
     */
    ~Vector(){ ArrayList<T>::m_data.reset(); }

    /*!
     *  \brief Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Vector.
     *
     *  \param rhs The Vector object being copied.
     *  \post Current size, maximum size, and elements same as rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Vector<T>& operator=(const Vector<T>& rhs);

    /*!
     *  \brief Move Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' Vector.
     *
     *  \param rhs The Vector object being moved.
     *  \post Current size, maximum size, and elements moved from rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    Vector<T>& operator=(Vector<T>&& rhs) noexcept;

    /*!
     *  \brief Copy Constructor.
     *
     *  \param cpy Vector to be copied.
     *  \post Current size, maximum size, and elements same as cpy.
     *  \return This object with deep copies of data of rhs.
     */
    Vector(const Vector<T>& cpy): ArrayList<T>(cpy) { *this = cpy; }

    /*!
     *  \brief Move Constructor.
     *
     *  \param src Vector to be moved.
     *  \post Current size, maximum size, and data moved from src to new object
     *  \return None.
     */
    Vector(Vector<T>&& src) noexcept;

    /*!
     *  \brief Vector addition.
     *
     *  \param rhs The vector being added to this.
     *  \pre The length of both vectors must be equal.
     *  \post This will remain the same.
     *  \return Modified Vector object, which is an rvalue.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    Vector<T> operator+(Vector<T>& rhs);

    /*!
     *  \brief Vector addition.
     *
     *  \param rhs The vector being added to this.
     *  \pre The length of both vectors must be equal.
     *  \post This will remain the same.
     *  \return Modified Vector object, which is an rvalue.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    Vector<T> operator+(Vector<T>&& rhs);

    /*!
     *  \brief Vector addition.
     *
     *  \param rhs The vector being added to this.
     *  \pre The length of both vectors must be equal.
     *  \post The contents of this are added from rhs.
     *  \return Modified Vector object.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    Vector<T>& operator+=(Vector<T>& rhs);

    /*!
     *  \brief Vector subtraction.
     *
     *  \param rhs The vector being subtracted from this.
     *  \pre The length of both vectors must be equal.
     *  \post This will remain the same.
     *  \return Modified Vector object, which is an rvalue.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    Vector<T> operator-(const Vector<T>& rhs);

    /*!
     *  \brief Vector subtraction.
     *
     *  \param rhs The vector being subtracted from this.
     *  \pre The length of both vectors must be equal.
     *  \post This will remain the same.
     *  \return Modified Vector object, which is an rvalue.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    Vector<T> operator-(Vector<T>&& rhs);

    /*!
     *  \brief Vector subtraction.
     *
     *  \param rhs The vector being subtracted from this.
     *  \pre The length of both vectors must be equal.
     *  \post The contents of this are subtracted by rhs.
     *  \return Modified Vector object.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    Vector<T>& operator-=(const Vector<T>& rhs);

    /*!
     *  \brief Vector transpose multiplication.
     *
     *  \param rhs The transpose vector being multiplied.
     *  \pre The length of both vectors must be equal.
     *  \post This will remain the same.
     *  \return Modified Vector object, which is an rvalue.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    T operator*(Vector<T>& rhs);

    /*!
     *  \brief Vector transpose multiplication.
     *
     *  \param rhs The transpose vector being multiplied.
     *  \pre The length of both vectors must be equal.
     *  \post This will remain the same.
     *  \return Modified Vector object, which is an rvalue.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    T operator*(Vector<T>&& rhs);

    /*!
     *  \brief Vector subtraction.
     *
     *  \param rhs The transpose vector being multiplied by this.
     *  \pre The length of both vectors must be equal.
     *  \post The contents of this are multiplied by the transpose of rhs.
     *  \return Modified Vector object.
     *  \throws numErr Thrown if the vectors are not the same size.
     */
    T operator*=(Vector<T>& rhs);

	/*!
     *  \brief Scalar Multiplication of a Vector.
     *
     *  \param rhs The scalar value.
     *  \pre None.
     *  \post This will remain the same.
     *  \return Modified Vector object, which is an rvalue.
     */
    Vector<T> operator*(T rhs);
	
	/*!
     *  \brief Scalar Multiplication of a Vector.
     *
     *  \param rhs The scalar value.
     *  \pre None.
     *  \post The contents of this are multiplied by rhs.
     *  \return Modified Vector object.
     */
    Vector<T>& operator*=(T rhs);

    /*!
     *  \brief One-norm of a Vector.
     *
     *  \pre None.
     *  \post Returns the sum of all elements in the vector.
     *  \return A sum of type T.
     */
     T oneNorm() const;

#ifndef DOXYGEN
    friend std::ostream& operator<< <>(std::ostream& out,
                                    const Vector<T>& v);

    friend std::istream& operator>> <>(std::istream& in,
                                       Vector<T>& v);
#endif


private:
    /*!
     *  \brief Override of the 'ArrayList<T>::purge()' function. This should
     *  never be called by a 'Vector' object.
     *  
     *  \return None.
     *  \throws numErr Will always throw when function is called
     */
    void purge(){ throw numErr("You shouldn't be calling this function!"); }
};

#include "vector.hpp"

#endif
