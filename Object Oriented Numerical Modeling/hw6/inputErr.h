/*!
 *  \file inputErr.h
 *  \brief Class description of inputErr
 */
#ifndef INPUTERR_H
#define INPUTERR_H

#include <string>
using namespace std;

/*! \brief An Input Error class.
 *
 * A class used to represent input errors in code
 *
 * \pre None.
 *
 */
class inputErr
{
    public:
        /*!
         *  \brief Constructor
         *  
         *  \param s String used to describe what kind of error occurred.
         *  \pre None.
         *  \post Creates a inputErr object.
         *  
         */
        inputErr(string s): err(move(s)) {}
        
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
