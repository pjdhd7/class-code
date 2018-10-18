template <typename T>
Symmetric_Matrix<T>::Symmetric_Matrix(const Matrix_Base<T>& src)
{
    if(is_symmetric(src) == false)
        throw numErr("Symmetric_Matrix<T>::Copy_Constructor: Passed matrix is "
                     "not symmetric.");

    this->m_columns = src.Matrix_columns();
    this->m_rows = 0;
    for(int i = 0; i < src.Matrix_rows(); i++)
    {
        new_row();
    }

    for(int i = 0; i < this->m_rows; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            this->m_data[i][j] = src.get_element(i, j);
        }
    }
}

template <typename T>
Symmetric_Matrix<T>::Symmetric_Matrix(int rows, int columns)
{
    if(rows < 0 || columns < 0)
        throw numErr("Symmetric_Matrix<T>(rows, columns): Tried to build a "
                     "matrix with negative dimensions.");

    this->m_columns = columns;
    this->m_rows = 0;
    for(int i = 0; i < rows; i++)
    {
        new_row();
    }
}

template <typename T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator=(
        const Symmetric_Matrix<T>& rhs
)
{
    if(&rhs != NULL && this != &rhs)
    {
        this->m_rows = rhs.m_rows;
        this->m_columns = rhs.m_columns;

        m_data = rhs.m_data;
    }

    return *this;
}

template <typename T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator=(Symmetric_Matrix<T>&& rhs)
noexcept
{
    if(&rhs != NULL && this != &rhs)
    {
        m_data = rhs.m_data;

        this->m_rows = rhs.m_rows;
        this->m_columns = rhs.m_columns;
    }

    return *this;
}

template <typename T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator*=(T rhs)
{
    for(int i = 0; i < this->m_rows; i++)
    {
        m_data[i] *= rhs;
    }

    return *this;
}

template <typename T>
Symmetric_Matrix<T> operator*(const Symmetric_Matrix<T>& lhs, const T& rhs)
{
    Symmetric_Matrix<T> result(lhs);

    return result *= rhs;
}

template <typename T>
Generic_Matrix<T> operator+(const Symmetric_Matrix<T>& lhs,
                              const Matrix_Base<T>& rhs)
{
    if(lhs.m_rows != rhs.Matrix_rows() || lhs.m_columns != rhs.Matrix_columns())
        throw numErr("Symmetric_Matrix<T>::operator+: Attempting to add "
                     "matrices with different dimensions.");

    Generic_Matrix<T> result(lhs);

    return result += rhs;
}

template <typename T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator+=(
        const Symmetric_Matrix<T>& rhs
)
{
    if(this->m_rows != rhs.m_rows
       || this->m_columns != rhs.m_columns)
        throw numErr("Symmetric_Matrix<T>::operator+=: Attempting to add "
                     "matrices with different dimensions.");

    for(int i = 0; i < this->m_rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            m_data[i][j] += rhs.get_element(i, j);
        }
    }

    return *this;
}

template <typename T>
Generic_Matrix<T> operator-(Symmetric_Matrix<T>& lhs,
                              Matrix_Base<T>& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Symmetric_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Generic_Matrix<T> result(lhs);

    return result -= rhs;
}

template <typename T>
Generic_Matrix<T> operator-(Symmetric_Matrix<T>& lhs,
                            Matrix_Base<T>&& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Symmetric_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Generic_Matrix<T> result(lhs);

    return result - rhs;
}

template <typename T>
Generic_Matrix<T> operator-(Symmetric_Matrix<T>&& lhs,
                            Matrix_Base<T>& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Symmetric_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Generic_Matrix<T> result(lhs);

    return result - rhs;
}

template <typename T>
Generic_Matrix<T> operator-(Symmetric_Matrix<T>&& lhs,
                              Matrix_Base<T>&& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Symmetric_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Generic_Matrix<T> result(lhs);

    return result - rhs;
}

template <typename T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator-=(Symmetric_Matrix<T>& rhs)
{
    if(this->m_rows != rhs.m_rows
       || this->m_columns != rhs.m_columns)
        throw numErr("Symmetric_Matrix<T>::operator-=: Attempting to subtract "
                     "matrices with different dimensions.");

    for(int i = 0; i < this->m_rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            m_data[i][j] -= rhs.get_element(i, j);
        }
    }

    return *this;
}

template <typename T>
Vector<T> operator*(const Symmetric_Matrix<T>& lhs, const Vector<T>& rhs)
{
    if(lhs.Matrix_columns() != rhs.size())
        throw numErr("Symmetric_Matrix<T>::operator*: Attempting to multiply a "
                     "Symmetric_Matrix by a vector with unequal dimensions. "
                     "(Number of Symmetric_Matrix columns must equal number of "
                     "elements in the vector)");

    Vector<T> result;
    T temp_sum = 0;
    for(int i = 0; i < lhs.Matrix_rows(); i++)
    {
        for(int j = 0; j < lhs.Matrix_rows(); j++)
        {
            temp_sum += lhs.get_element(i, j)* rhs[j];
        }
        result.insert_back(temp_sum);
        temp_sum = 0;
    }

    return result;
}

template <typename T>
Generic_Matrix<T> operator*(const Symmetric_Matrix<T>& lhs,
                            const Matrix_Base<T>& rhs)
{
    if(lhs.Matrix_columns() != rhs.Matrix_rows())
        throw numErr("Symmetric_Matrix<T>::operator*: Attempting to multiply a "
                     "Symmetric_Matrix by another Symmetric_Matrix with unequal"
                     " dimensions. (For A*B, the number of columns in A must "
                     "equal the number of rows in B");

    Generic_Matrix<T> result(lhs);

    return result * rhs;
}

template <typename T>
Generic_Matrix<T> operator*(const Symmetric_Matrix<T>&& lhs,
                            const Matrix_Base<T>&& rhs)
{
    if(lhs.Matrix_columns() != rhs.Matrix_rows())
        throw numErr("Symmetric_Matrix<T>::operator*: Attempting to multiply a "
                     "Symmetric_Matrix by another Symmetric_Matrix with unequal"
                     " dimensions. (For A*B, the number of columns in A must "
                     "equal the number of rows in B");

    Generic_Matrix<T> result(lhs);

    return result * rhs;
}

template <typename T>
void Symmetric_Matrix<T>::new_row()
{
    Vector<T> tempVector;
    for(int i = 0; i < this->m_rows + 1; i++)
    {
        tempVector.insert_back(0);
    }
    m_data.insert_back(tempVector);
    this->m_rows++;

    return;
}

template <typename T>
void Symmetric_Matrix<T>::set_columns(int columns)
{
    if(columns < 0)
        throw numErr("Symmetric_Matrix<T>::set_columns: Negative column "
                     "value.");

    this->m_columns = columns;
    return;
}

template <typename T>
void Symmetric_Matrix<T>::set_rows(int rows)
{
    if(rows < 0)
        throw numErr("Symmetric_Matrix<T>::set_rows: Negative row value.");

    this->m_rows = rows;
    return;
}

template <typename T>
Symmetric_Matrix<T> operator~(const Symmetric_Matrix<T>& src)
{
    const int rows = src.Matrix_rows();
    const int columns = src.Matrix_columns();

    Symmetric_Matrix<T> result(columns, rows);

    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            result.insert_data(src.m_data[i][j], i, j);
        }
    }

    return result;
}

template <typename T>
void Symmetric_Matrix<T>::insert_data(T data, int row, int column)
{
    if(row >= this->m_rows
       || column >= this->m_columns)
        throw numErr("Symmetric_Matrix<T>::insert_data: Invalid index");


    if(column <= row)
        m_data[row][column] = data;
    else
        m_data[column][row] = data;
    return;
}

template <typename T>
void Symmetric_Matrix<T>::swap_rows(int i, int j)
{
    if(i >= this->m_rows
       || j >= this->m_rows)
        throw numErr("Symmetric_Matrix<T>::swap_rows: Invalid index");

    if(i != j) m_data.swap(i,j);

    return;
}

template <typename T>
void Symmetric_Matrix<T>::swap_columns(int i, int j)
{
    if(i >= this->m_columns
       || j >= this->m_columns)
        throw numErr("Symmetric_Matrix<T>::swap_columns: Invalid index");

    for(int k = 0; k < this->m_rows; k++)
    {
        m_data[k].swap(i, j);
    }

    return;
}

template <typename T>
void Symmetric_Matrix<T>::set_dimensions(int rows, int columns)
{
    if(rows <= 0 || columns <= 0)
        throw numErr("Symmetric_Matrix<T>::set_dimensions: Invalid "
                     "dimensions.");
    m_data.clear();
    this->m_columns = columns;
    this->m_rows = 0;

    for(int i = 0; i < rows; i++)
        new_row();
    return;
}

template <typename T>
const T Symmetric_Matrix<T>::get_element(int row, int column) const
{
    if(row  < 0 || column  < 0 || row >= this->m_rows
       || column >= this->m_columns)
        throw numErr("Symmetric_Matrix<T>::get_element: Invalid Index.");

    if(column <= row)
        return m_data[row][column];
    else
        return m_data[column][row];
}

template <typename T>
bool Symmetric_Matrix<T>::is_symmetric(const Matrix_Base<T>& A)
{
    const int rows = A.Matrix_rows();
    const int columns = A. Matrix_columns();

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(i != j)
            {
                if(A.get_element(i, j) != A.get_element(j, i))
                    return false;
            }
        }
    }

    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Symmetric_Matrix<T>& m)
{
    if(m.Matrix_rows() != 0 && m.Matrix_columns() != 0)
    {
        for (int i = 0; i < m.Matrix_rows(); i++)
        {
            for(int j = 0; j < m.Matrix_columns(); j++)
            {
                out << m.get_element(i, j) << " ";
            }

            if (i < m.Matrix_rows() - 1) out << std::endl;
        }
    }

    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Symmetric_Matrix<T>& m)
{
    //Checks if the stream is usable and still has data
    if(in.good() == false || in.eof() == true)
        throw streamErr("Bad Input stream");

    //Creates a temp object, which is then pushed into the m_data for each row
    T Temp;
    for(int i = 0; i < m.Matrix_rows(); i++)
    {
        for(int j = 0; j < m.Matrix_columns(); j++)
        {
            if(in.eof() == true)
                throw inputErr("Symmetric_Matrix did not receive the specified "
                               "number of rows from the input stream.");

            if(in.good() == false) throw streamErr("Bad Input stream");

            in >> Temp;
            m.insert_data(Temp, i, j);
        }
    }

    return in;
}
