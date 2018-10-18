template <typename T>
polarNum<T>& polarNum<T>::operator-() const
{
    setModulus(-1 * getModulus());
    return (*this);
}

template <typename T>
const polarNum<T> polarNum<T>::operator*(const polarNum<T>& p)
{
    polarNum<T> product;
    
    //p1*p2 = (r1*r2,θ1 + θ2)
    product.setModulus(getModulus() * p.getModulus());
    product.setArgument(getArgument() + p.getArgument());
    
    return product;
}

//THROWS: numErr
template <typename T>
const polarNum<T> polarNum<T>::operator/(const polarNum<T>& p)
{
    //Protects against division by zero
    if(p.getModulus() == static_cast<T>(0)) throw numErr("Divide by zero");
    
    polarNum<T> quotient;
    
    //p1/p2 = (r1/r2,θ1 - θ2)
    quotient.setModulus(getModulus() / p.getModulus());
    quotient.setArgument(getArgument() - p.getArgument());
    
    return quotient;
}

template <typename T>
const T polarNum<T>::operator~()
{
    return std::fabs(getModulus());
}

template <typename T>
const polarNum<T>& polarNum<T>::operator!()
{
    setArgument(-1 * getArgument());
    return (*this);
}

template <typename T>
const polarNum<T>& polarNum<T>::operator=(const polarNum<T>& p)
{
    setModulus(p.getModulus());
    setArgument(p.getArgument());
    return (*this);
}


//THROWS: numErr
template <typename T>
const T& polarNum<T>::operator[](const short i) const
{
    switch(i){
        case 0:
            return getModulus();
            break;
            
        case 1:
            return getArgument();
            break;
        
        //Range Exceptions
        default:
            throw numErr("Invalid Range operation");
            break;
    }
}

template <typename T>        
bool polarNum<T>::operator>(const polarNum<T>& p)
{
    return (std::fabs(getModulus()) > ~p);
}

template <typename T>        
bool polarNum<T>::operator<(const polarNum<T>& p)
{
    return (std::fabs(getModulus()) < ~p);
}

template <typename T>       
bool polarNum<T>::operator==(const polarNum<T>& p)
{
    return (std::fabs(getModulus()) == ~p);
}

template <typename T>       
bool polarNum<T>::operator!=(const polarNum<T>& p)
{
    return (std::fabs(getModulus()) != ~p);
}

//THROWS: streamErr, inputErr
template <typename T> 
istream& operator>>(istream& is, polarNum<T>& p)
{
    //Checks if the stream is usable
    if(is.good() == false) throw streamErr("Bad Input stream");
    
    //Sets up a temporary container the input
    //Then checks for empty input
    string inputTemp;
    getline(is, inputTemp);
    if(inputTemp.empty() == true) throw inputErr("Empty input string");
    
    try
    {
        //Attempts to convert the input
        string::size_type index;
        
        double modTemp = stod(inputTemp, &index);
        double argTemp = stod(inputTemp.substr(index), &index);
    
        p.setModulus(static_cast<T>(modTemp));
        p.setArgument(static_cast<T>(argTemp));
        
        return is;
    }
    //Exception thrown by stod() if the input can't be converted
    catch(invalid_argument e)
    {
        throw inputErr("Malformed input");
    }
}

template <typename T>
ostream& operator<<(ostream& os, const polarNum<T>& p)
{
    if(os.good())
    {
        os << std::setprecision(9) 
           << "(" << p.getModulus() << ", " << p.getArgument() << ")";
    }
    
    return os;
}

template <typename T>
void polarNum<T>::setModulus(const T& r)
{
    m_modulus = r;
    return;
}

template <typename T>
void polarNum<T>::setArgument(const T& theta)
{
    m_argument = theta;
    return;
}
