template <typename T>
Dolan_Vector<T>::Dolan_Vector()
{
    ArrayList<T>::m_size = 0;
    ArrayList<T>::m_max = 0;
    ArrayList<T>::m_data = nullptr;
}

template <typename T>
Dolan_Vector<T>& Dolan_Vector<T>::operator=(const Dolan_Vector<T>& rhs)
{
    if(&rhs != NULL && this != &rhs)
    {
        ArrayList<T>::m_max = rhs.m_max;
        ArrayList<T>::m_size = rhs.m_size;

        ArrayList<T>::m_data.reset(new T[rhs.m_max]);
        for (int i = 0; i < rhs.m_size; i++)
        {
            ArrayList<T>::m_data[i] = rhs[i];
        }
    }

    return *this;
}

template <typename T>
Dolan_Vector<T>& Dolan_Vector<T>::operator=(Dolan_Vector<T>&& rhs) noexcept
{
    if(&rhs != NULL && this != &rhs)
    {
        ArrayList<T>::m_data.reset(rhs.m_data.release());

        ArrayList<T>::m_size = rhs.m_size;
        ArrayList<T>::m_max = rhs.m_max;
    }

    return *this;
}

template <typename T>
Dolan_Vector<T>::Dolan_Vector(Dolan_Vector<T>&& src) noexcept
{
    ArrayList<T>::m_size = src.m_size;
    ArrayList<T>::m_max = src.m_max;
    ArrayList<T>::m_data.reset(src.m_data.release());
}


template <typename T>
Dolan_Vector<T> Dolan_Vector<T>::operator*(T rhs)
{
    Dolan_Vector<T> result(*this);
    return result *= rhs;
}

template <typename T>
Dolan_Vector<T>& Dolan_Vector<T>::operator*=(T rhs)
{
    for(int i = 0; i < ArrayList<T>::m_size; i++)
    {
        ArrayList<T>::m_data[i] *= rhs;
    }

    return *this;
}

template <typename T>
Dolan_Vector<T> operator*(T lhs, Dolan_Vector<T>& rhs)
{
    return rhs * lhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Dolan_Vector<T>& v)
{
    if(v.m_size != 0)
    {
        out << v.m_data[0] << std::endl;
        for (int i = 1; i < v.m_size; i++)
        {
            out << v.m_data[i];
            if (i < v.m_size - 1) out << std::endl;
        }
    }

    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Dolan_Vector<T>& v)
{
    //Checks if the stream is usable and still has data
    if(in.good() == false || in.eof() == true)
        throw streamErr("Bad Input stream");

    std::string inputTemp;
    T elmTemp;
    Dolan_Vector<T> tempVector;

    //Gets one line of input, then sets up a StringStream
    std::getline(in, inputTemp);
    std::stringstream streamTemp(inputTemp);

    //Grabs all of the individual elements from the StringStream
    while(streamTemp.eof() != true)
    {
        streamTemp >> elmTemp;
        tempVector.insert_back(elmTemp);
    }

    cout << tempVector<<endl<<endl;
    v = tempVector;

    return in;
}