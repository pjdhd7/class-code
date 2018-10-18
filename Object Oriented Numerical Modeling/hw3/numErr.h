/**
 *  \file numErr.h
 *  \brief Contains the class definition for numErr objects
 */
#ifndef NUMERR_H
#define NUMERR_H

#include <string>
using namespace std;

/*! A Number Error class.
 *
 * A class used to represent numerical errors in code
 *
 * \pre None.
 *
 */
class numErr
{
    public:
        /*!
         *  \brief Constructor
         *  
         *  \param s String used to describe what kind of error occurred.
         *  \pre None.
         *  \post Creates a numErr object.
         *  
         */
        numErr(string s): err(s) {}
        
        /*!
         *  \brief Returns the error string.
         *  
         *  \pre None.
         *  \post Returns the error string
         *  \return Returns a string object
         */
        string errString(){ return err; }
        
    private:
        /*! String object that contains the literal error string */
        string err;
};

#endif
