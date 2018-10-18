/*!
 *  \file arraylist.h
 *  \brief Declarations for the ArrayList class
 */
 
//Full Disclosure: This class was originally written for a Data Structures 
//project. I've added move semantics and smart pointers to make it smarter.

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <memory>
#include "streamErr.h"
#include "inputErr.h"
#include "numErr.h"


#ifndef DOXYGEN
template <typename T>
class ArrayList;                       
#endif

/*!
 *  \brief Prints all stored elements in the array.
 *  
 *  \param out The stream where data is printed.
 *  \param alist The ArrayList object being printed.
 *  \pre None.
 *  \post The contents of alist are printed to os.
 *  \return Modified ostream object.
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const ArrayList<T>& alist);

/*!
 *  \brief Reads data in and adds it to the ArrayList.
 *
 *  \param is The source of the data.
 *  \param alist An ArrayList object being modified.
 *  \pre Input must be able to convert to type T.
 *  \post ArrayList has one new element at the end of the array
 *  \return Modified istream object.
 *  \throws inputErr Thrown if the input format is incorrect.
 *  \throws streamErr Thrown if the input stream is bad.
 */
template <typename T>
std::istream& operator>>(std::istream& is, ArrayList<T>& alist);

/*! \brief A Dynamic Array class
 *
 * A class that stores an array and expands or contracts it at runtime
 *
 * \pre T must overload operator= and operator<<
 *
 */
template <typename T>
class ArrayList
{
public:
    /*!
     *  \brief Default Constructor.
     *  
     *  \post Current size and maximum size set to 0, 
     *   and data set to NULL.
     *  \return None.
     */
    ArrayList(): m_size(0), m_max(0), m_data(nullptr) {};
  
    /*!
     *  \brief Destructor.
     *  
     *  \post Current size and maximum size set to 0, 
     *  data deallocated and set to NULL.
     *  \return None.
     */
    ~ArrayList();
  
    /*!
     *  \brief Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' ArrayList.
     *
     *  \param rhs The ArrayList object being copied.
     *  \post Current size, maximum size, and elements same as rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    ArrayList<T>& operator=(const ArrayList<T>& rhs);

    /*!
     *  \brief Move Assignment Operator, performs a deep copy of 'rhs'
     *  into 'this' ArrayList.
     *
     *  \param rhs The ArrayList object being moved.
     *  \post Current size, maximum size, and elements moved from rhs.
     *  \return This object, containing deep copies of the data in rhs.
     */
    ArrayList<T>& operator=(ArrayList<T>&& rhs) noexcept;
  
    /*!
     *  \brief Copy Constructor.
     *  
     *  \param cpy ArrayList to be copied.
     *  \post Current size, maximum size, and elements same as cpy.
     *  \return This object with deep copies of data of rhs.
     */
    ArrayList(const ArrayList<T>& cpy);

    /*!
     *  \brief Move Constructor.
     *
     *  \param src ArrayList to be moved.
     *  \post Current size, maximum size, and data moved from src to new object
     *  \return None.
     */
    ArrayList(ArrayList<T>&& src) noexcept : m_size(src.m_size),
                                             m_max(src.m_max),
                                             m_data(std::move(src.m_data))
    {}
     
    /*!
     *  \brief Accessor function for the number of elements in the list.
     *  
     *  \return Number of elements in the list.
     */
    int size() const;
  
    /*!
     *  \brief Accessor function for the max capacity of elements.
     *  
     *  \return The maximum capacity of this list.
     */
    int max() const { return m_max; };
  
    /*!
     *  \brief Accessor function for the first element of the list.
     *  
     *  \pre Array must have at least one element.
     *  \return The first element in the list.
     *  \throws numErr Thrown if the list is empty.
     */
    const T& first() const;
  
    /*!
     *  \brief Return a read-and-write reference to the element at the specified
     *  position.
     *  
     *  \param i Zero-Based index of the ArrayList.
     *  \pre Array must have at least one element and i must be non-negative.
     *  \return The element at position i in the ArrayList.
     *  \throws numErr Thrown if the index is invalid.
     */
    T& operator[](int i);
  
    /*!
     *  \brief Return a read-only reference to the element at the specified
     *  position.
     *  
     *  \param i Zero-Based index of the ArrayList.
     *  \pre Array must have at least one element and i must be non-negative.
     *  \return The element at position i in the ArrayList.
     *  \throws numErr Thrown if the index is invalid.
     */
    const T& operator[](int i) const;

    /*!
     *  \brief Compares an ArrayList with a separate ArrayList to determine if 
     *  their contents are identical.
     *  
     *  \param rhs ArrayList being compared to.
     *  \return True if the ArrayLists are identical, false otherwise.
     */
    bool operator==(ArrayList<T> rhs);

    /*!
     *  \brief Compares an ArrayList with a separate ArrayList to determine if 
     *  their contents are not identical.
     *  
     *  \param rhs ArrayList being compared to.
     *  \return False if the ArrayLists are identical, true otherwise.
     */
    bool operator!=(ArrayList<T> rhs);
  
    /*!
     *  \brief finds an element in the ArrayList.
     *  
     *  \param x Value to be found in the ArrayList
     *  \return The position of the first occurrence of x in the list, or -1 if 
     *  x is not found.
     */
    int find(const T& x) const;
  
    /*!
     *  \brief Clears the ArrayList
     *  
     *  \post current size and maximum size set to 0, elements are deallocated 
     *  and data is set to NULL.
     *  \return None.
     */
    void clear();

    /*!
     *  \brief Puts the value x at the end of an ArrayList.
     *  
     *  \param x Value to be added to ArrayList.
     *  \post current size is incremented by 1 if max size is reached, a new
     *   array of size max*2 is allocated and data is copied to it.
     *  \return None.
     */
    void insert_back(const T& x);
  
    /*!
     *  \brief Puts the value x at the position i in the  ArrayList.
     *  
     *  \param x Value to be added to ArrayList.
     *  \param i The position to insert x at.
     *  \pre i must be a non-negative value less than 
     *  the maximum size of the array.
     *  \post current size is incremented by 1; if max size is reached, a new
     *  array of size max*2 is allocated and data is copied to it.
     *  \return None.
     *  \throws numErr Thrown if the index is invalid.
     */
    void insert(const T& x, int i);
  
    /*!
     *  \brief Removes the element at index i in the array.
     *  
     *  \param i The index of the element to remove.
     *  \pre i must be a non-negative value less than 
     *  the maximum size of the array.
     *  \post If the size of the list is greater than 0, size is decremented by 
     *  one. If the size of the list less than 1/4 the max size, a new array of 
     *  size max/2 is allocated, and data is copied to it.
     *  \return None.
     *  \throws numErr Thrown if the index is invalid.
     */
    void remove(int i);
  
    /*!
     *  \brief Swaps two elements of the array.
     *  
     *  \param i A position in the array.
     *  \param k A position in the array.
     *  \pre i and k must be non-negative values less than 
     *  the maximum size of the array.
     *  \post The elements at positions i and k swap positions.
     *  \return None.
     */
    void swap(int i, int k);

    /*!
     *  \brief Appends two lists.
     *  
     *  \param alist A list to appended to the end of 'this' list.
     *  \pre Preconditions for append
     *  \post Current size is incremented by size of alist, and the elements of
     *  alist are appended to the elements of 'this.'
     *  \return None.
     */
    void append(const ArrayList<T>& alist);
  
    /*!
     *  \brief Removes duplicates from an Arraylist
     *  
     *  \post All duplicate elements are removed from the list.
     *  \return None.
     */
    virtual void purge();

#ifndef DOXYGEN
    //Comments for this exist above the class template
    friend std::ostream& operator<< <> (std::ostream& out, 
                                        const ArrayList<T>& alist);

    friend std::istream& operator>> <>(std::istream& is, ArrayList<T>& alist);
#endif

protected:
    /*! Number of assigned elements in the array */
    int m_size;
    
    /*! Maximum capacity of the array */
    int m_max;
    
    /*! Array containing all of the elements */
    std::unique_ptr<T[]> m_data;
};  

#include "arraylist.hpp"

#endif