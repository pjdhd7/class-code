template <typename T>
ArrayList<T>::~ArrayList()
{
    m_data.reset();
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
    m_max = rhs.m_max;
    m_size = rhs.m_size;

    m_data.reset( new T[rhs.m_max] );
    for(int i = 0; i < rhs.m_size; i++)
    {
        m_data[i] = rhs[i];
    }

    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList<T>&& rhs) noexcept
{
    if(this != &rhs)
    {
        m_data.reset(rhs.m_data.release());

        m_size = rhs.m_size;
        m_max = rhs.m_max;
    }

    return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
    *this = cpy; //Kick it off to operator=
}

template <typename T>
int ArrayList<T>::size() const
{
    return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
    if(m_size == 0)
        throw numErr("ArrayList<T>.first(): Empty List");
      
    return m_data[0];
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
    if(i >= m_size)
        throw numErr("ArrayList<T>.[]: Empty List");
    
    return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
    if(i >= m_size)
        throw numErr("ArrayList<T>.[]: Empty List");
    
    return m_data[i];
}

template <typename T>
int ArrayList<T>::find(const T& x) const
{
    int found = -1;
    
    for(int i = 0; i < m_size && found < 0; i++)
    {
        if(x == m_data[i])
        {
            found = i;
        }
    }
    
    return found;
}

template <typename T>
void ArrayList<T>::clear()
{
    m_data.reset();
    m_max = m_size = 0;
    return;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
    if(m_max == 0)
    {
        m_data.reset(new T[1]);
        m_max = 1;
    }
    
    if(m_size >= m_max)
    {
        std::unique_ptr<T[]> temp( new T[m_max * 2] );
        for(int i = 0; i < m_size; i++)
        {
            temp[i] = m_data[i];
        }

        m_data.reset(temp.release());
        m_max = m_max * 2;
    }
    
    m_data[m_size] = x;
    m_size++;
    return;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
    if(i > m_size)
        throw numErr("ArrayList<T>.insert(): index out of bounds");
    else 
    {
        if(m_size == m_max)
        {
            std::unique_ptr<T[]> temp( new T[m_max * 2] );
            for(int k = 0; k < m_size; k++)
            {
                temp[k] = m_data[k];
            }

            m_data.reset( temp.release() );
            m_max  = m_max * 2 + 1;
        }
  
        for(int k = m_size; k >= i; k--)
        {
            m_data[k] = m_data[k - 1];
        }
  
        m_data[i] = x;
        m_size++;
    }
    
    return;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
    if(i > m_size)
        throw numErr("ArrayList<T>.remove(): index out of bounds");
    else 
    {
        if(m_size == m_max / 4)
        {
            std::unique_ptr<T[]> temp( new T[m_max / 2] );
            for(int k = 0; k < m_size; k++)
            {
                temp[k] = m_data[k];
            }

            m_data.reset( temp.release() );
            m_max /= 2;
        }
  
        for(int k = i; k < m_size; k++)
        {
           m_data[k] = m_data[k+1];
        }
        
        m_size--;
    }
    
    return;
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
    if(i > m_size || k > m_size)
        throw numErr("ArrayList<T>.swap(): index out of bounds");
    else
    {
        T temp = m_data[i];
        m_data[i] = m_data[k];
        m_data[k] = temp;
    }
    
    return;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
    //added 1 to give a little extra space and prevent seg faults
    std::unique_ptr<T[]> temp(new T[m_max + alist.max() + 1]);

    for (int i = 0; i < m_size; i++)
    {
        temp[i] = m_data[i];
    }
    
    for(int i = m_size; i < (m_size + alist.size()); i++)
    {
        temp[i] = alist[i - m_size];
    }

    m_data.reset( temp.release() );
    m_max += alist.max();
    m_size += alist.size();
  
    return;
}

template <typename T>
void ArrayList<T>::purge()
{
    for(int i = 0; i < m_size; i++)
    {
        for(int k = i + 1; k < m_size; k++)
        {
            if(m_data[i] == m_data[k])
            {
                remove(k);
            }
        }
    }
        
    return;
}

// Purpose: prints an ArrayList
template <typename T>                 
std::ostream& operator<< (std::ostream& out, const ArrayList<T>& alist)
{
    out << "[ ";
    for (int i=0; i < alist.m_size; i++)
    {
        out << alist.m_data[i] << ", ";
    } 
    out << "]";
    
    return out;
}