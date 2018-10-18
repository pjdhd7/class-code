template <typename T>
Vector<T>::Vector()
{
    this->m_size = 0;
    this->m_max = 0;
    this->m_data = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
    //if(&rhs != NULL && this != &rhs)
    if(this != &rhs)
    {
        this->m_max = rhs.m_max;
        this->m_size = rhs.m_size;

        this->m_data.reset(new T[rhs.m_max]);
        for (int i = 0; i < rhs.m_size; i++)
        {
            this->m_data[i] = rhs[i];
        }
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs) noexcept
{
    //if(&rhs != NULL && this != &rhs)
    if(this != &rhs)
    {
        this->m_data.reset(rhs.m_data.release());

        this->m_size = rhs.m_size;
        this->m_max = rhs.m_max;
    }

    return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& src) noexcept
{
    this->m_size = src.m_size;
    this->m_max = src.m_max;
    this->m_data.reset(src.m_data.release());
}

template <typename T>
Vector<T> Vector<T>::operator+(Vector<T>& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator+: Vectors are not the same "
                     "length.");

    Vector<T> result(*this);

    return result += rhs;
}

template <typename T>
Vector<T> Vector<T>::operator+(Vector<T>&& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator+: Vectors are not the same "
                     "length.");

    Vector<T> result(*this);

    return result += rhs;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(Vector<T>& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator+=: Vectors are not the same "
                     "length.");

    for(int i = 0; i < this->m_size; i++)
    {
        this->m_data[i] += rhs[i];
    }

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator-: Vectors are not the same "
                     "length.");

    Vector<T> result(*this);

    return result -= rhs;
}

template <typename T>
Vector<T> Vector<T>::operator-(Vector<T>&& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator-: Vectors are not the same "
                     "length.");

    Vector<T> result(*this);

    return result -= rhs;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator-=: Vectors are not the same "
                     "length.");

    for(int i = 0; i < this->m_size; i++)
    {
        this->m_data[i] -= rhs[i];
    }

    return *this;
}

template <typename T>
T Vector<T>::operator*(Vector<T>& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator*=: Vectors are not the same "
                     "length.");

    T sum = 0;

    for(int i = 0; i < this->m_size; i++)
        sum += this->m_data[i] * rhs[i];

    return sum;
}

template <typename T>
T Vector<T>::operator*(Vector<T>&& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator*=: Vectors are not the same "
                     "length.");

    T sum = 0;

    for(int i = 0; i < this->m_size; i++)
        sum += this->m_data[i] * rhs[i];

    return sum;
}

template <typename T>
T Vector<T>::operator*=(Vector<T>& rhs)
{
    if(this->m_size != rhs.size())
        throw numErr("Vector<T>::operator*=: Vectors are not the same "
                     "length.");

    T sum = 0;

    for(int i = 0; i < this->m_size; i++)
        sum += this->m_data[i] * rhs[i];

    return sum;
}

template <typename T>
Vector<T> Vector<T>::operator*(T rhs)
{
    Vector<T> result(*this);
    return result *= rhs;
}

template <typename T>
Vector<T>& Vector<T>::operator*=(T rhs)
{
    for(int i = 0; i < this->m_size; i++)
    {
        this->m_data[i] *= rhs;
    }

    return *this;
}

template <typename T>
Vector<T> operator*(T lhs, Vector<T>& rhs)
{
    return rhs * lhs;
}

template <typename T>
T Vector<T>::oneNorm() const
{
    T sum = 0;
    for(int i = 0; i < this->m_size; i++)
    {
        sum += fabs(this->m_data[i]);
    }

    return sum;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
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
std::istream& operator>>(std::istream& in, Vector<T>& v)
{
    //Checks if the stream is usable and still has data
    if(in.good() == false || in.eof() == true)
        throw streamErr("Bad Input stream");

    std::string inputTemp;
    T elmTemp;
    Vector<T> tempVector;

    //Gets one line of input, then sets up a StringStream
    std::getline(in, inputTemp);
    std::stringstream streamTemp(inputTemp);

    //Grabs all of the individual elements from the StringStream
    while(streamTemp.eof() != true)
    {
        streamTemp >> elmTemp;
        tempVector.insert_back(elmTemp);
    }

    v = tempVector;

    return in;
}