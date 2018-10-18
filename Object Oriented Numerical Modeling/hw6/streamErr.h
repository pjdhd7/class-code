/*!
 *  \file streamErr.h
 *  \brief Class description of streamErr
 */
#ifndef STREAMERR_H
#define STREAMERR_H

#include <string>
using namespace std;

/*! \brief A Stream Error class.
 *
 * A class used to represent stream errors in code
 *
 * \pre None.
 *
 */
class streamErr
{
    public:
        /*!
         *  \brief Constructor
         *  
         *  \param s String used to describe what kind of error occurred.
         *  \pre None.
         *  \post Creates a streamErr object.
         *  
         */
        streamErr(string s): err(move(s)) {}
        
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
