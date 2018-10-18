template <typename T>
Diagonal_Matrix<T>::Diagonal_Matrix(const Matrix_Base<T>& src)
{
    if(is_diagonal(src) == false)
        throw numErr("Diagonal Matrix<T>::Copy_Constructor: Source matrix is "
                     "not a diagonal Matrix.");

    this->m_columns = src.Matrix_columns();
    this->m_rows = 0;
    for(int i = 0; i < src.Matrix_rows(); i++)
    {
        new_row();
    }

    for(int i = 0; i < this->m_rows; i++)
    {
        this->m_data[i][i] = src.get_element(i, i);
    }
}

template <typename T>
Diagonal_Matrix<T>::Diagonal_Matrix(int rows, int columns)
{
    if(rows < 0 || columns < 0)
        throw numErr("Diagonal_Matrix<T>(rows, columns): Tried to build a "
                     "matrix with negative dimensions.");

    this->m_columns = columns;
    this->m_rows = 0;
    for(int i = 0; i < rows; i++)
    {
        new_row();
    }
}

template <typename T>
Diagonal_Matrix<T>& Diagonal_Matrix<T>::operator=(const Diagonal_Matrix<T>& rhs)
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
Diagonal_Matrix<T>& Diagonal_Matrix<T>::operator=(Diagonal_Matrix<T>&& rhs)
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
Diagonal_Matrix<T>& Diagonal_Matrix<T>::operator*=(T rhs)
{
    for(int i = 0; i < this->m_rows; i++)
    {
        m_data[i] *= rhs;
    }

    return *this;
}

template <typename T>
Diagonal_Matrix<T> operator*(const Diagonal_Matrix<T>& lhs, const T& rhs)
{
    Diagonal_Matrix<T> result(lhs);

    return result *= rhs;
}

template <typename T>
Diagonal_Matrix<T> operator+(const Diagonal_Matrix<T>& lhs,
                            const Diagonal_Matrix<T>& rhs)
{
    if(lhs.m_rows != rhs.m_rows || lhs.m_columns != rhs.m_columns)
        throw numErr("Diagonal_Matrix<T>::operator+: Attempting to add matrices "
                     "with different dimensions!");

    Diagonal_Matrix<T> result(lhs);

    return result += rhs;
}

template <typename T>
Diagonal_Matrix<T>& Diagonal_Matrix<T>::operator+=(const Diagonal_Matrix<T>& rhs)
{
    if(this->m_rows != rhs.m_rows
       || this->m_columns != rhs.m_columns)
        throw numErr("Diagonal_Matrix<T>::operator+=: Attempting to add matrices"
                     " with different dimensions!");

    for(int i = 0; i < this->m_rows; i++)
    {
        m_data[i] += rhs.get_element(i, i);
    }

    return *this;
}

template <typename T>
Diagonal_Matrix<T> operator-(Diagonal_Matrix<T>& lhs,
                            Diagonal_Matrix<T>& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Diagonal_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Diagonal_Matrix<T> result(lhs);

    return result -= rhs;
}

template <typename T>
Diagonal_Matrix<T> operator-(Diagonal_Matrix<T>& lhs,
                             Diagonal_Matrix<T>&& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Diagonal_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Diagonal_Matrix<T> result(lhs);
    const int rows = result.Matrix_rows();

    for(int i = 0; i < rows; i++)
    {
        result.m_data[i] -= rhs.get_element(i, i);
    }

    return result;
}

template <typename T>
Diagonal_Matrix<T> operator-(Diagonal_Matrix<T>&& lhs,
                             Diagonal_Matrix<T>&& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Diagonal_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Diagonal_Matrix<T> result(lhs);
    const int rows = result.Matrix_rows();

    for(int i = 0; i < rows; i++)
    {
        result.m_data[i] -= rhs.get_element(i, i);
    }

    return result;
}

template <typename T>
Diagonal_Matrix<T>& Diagonal_Matrix<T>::operator-=(Diagonal_Matrix<T>& rhs)
{
    if(this->m_rows != rhs.m_rows
       || this->m_columns != rhs.m_columns)
        throw numErr("Diagonal_Matrix<T>::operator-=: Attempting to subtract "
                     "matrices with different dimensions.");

    for(int i = 0; i < this->m_rows; i++)
    {
        m_data[i] -= rhs.get_element(i,i);
    }

    return *this;
}

template <typename T>
Vector<T> operator*(const Diagonal_Matrix<T>& lhs,
                          const Vector<T>& rhs)
{
    if(lhs.Matrix_columns() != rhs.size())
        throw numErr("Diagonal_Matrix<T>::operator*: Attempting to multiply a "
                     "Diagonal_Matrix by a vector with unequal dimensions. "
                     "(Number of Diagonal_Matrix columns must equal number of "
                     "elements in the vector)");

    Vector<T> result;
    for(int i = 0; i < lhs.Matrix_rows(); i++)
    {
        result.insert_back(lhs.m_data[i] * rhs[i]);
    }

    return result;
}

template <typename T>
Diagonal_Matrix<T> operator*(const Diagonal_Matrix<T>& lhs,
                            const Diagonal_Matrix<T>& rhs)
{
    if(lhs.Matrix_columns() != rhs.Matrix_rows())
        throw numErr("Diagonal_Matrix<T>::operator*: Attempting to multiply a "
                     "Diagonal_Matrix by another Diagonal_Matrix with unequal "
                     "dimensions. (For A*B, the number of columns in A must "
                     "equal the number of rows in B");

    int rows = lhs.Matrix_rows();
    int columns = rhs.Matrix_columns();
    int diag; // used to represent how long the main diagonal is
    Diagonal_Matrix<T> result(rows, columns);

    if(rows <= columns) diag = rows;
    else diag = columns;

    for(int i = 0; i < diag; i++)
    {
        result.m_data[i] = lhs.m_data[i] * rhs.m_data[i];
    }

    return result;
}

template <typename T>
Diagonal_Matrix<T> operator*(const Diagonal_Matrix<T>&& lhs,
                            const Diagonal_Matrix<T>&& rhs)
{
    if(lhs.Matrix_columns() != rhs.Matrix_rows())
        throw numErr("Diagonal_Matrix<T>::operator*: Attempting to multiply a "
                     "Diagonal_Matrix by another Diagonal_Matrix with unequal "
                     "dimensions. (For A*B, the number of columns in A must "
                     "equal the number of rows in B");

    int rows = lhs.Matrix_rows();
    int columns = rhs.Matrix_columns();
    int diag; // used to represent how long the main diagonal is
    Diagonal_Matrix<T> result(rows, columns);

    if(rows <= columns) diag = rows;
    else diag = columns;

    for(int i = 0; i < diag; i++)
    {
        result.m_data[i] = lhs.m_data[i] * rhs.m_data[i];
    }

    return result;
}

template <typename T>
void Diagonal_Matrix<T>::new_row()
{
    m_data.insert_back(0);
    this->m_rows++;

    return;
}

template <typename T>
void Diagonal_Matrix<T>::set_columns(int columns)
{
    if(columns < 0)
        throw numErr("Diagonal_Matrix<T>::set_columns: Negative column value.");

    this->m_columns = columns;
    return;
}

template <typename T>
void Diagonal_Matrix<T>::set_rows(int rows)
{
    if(rows < 0)
        throw numErr("Diagonal_Matrix<T>::set_rows: Negative row value.");

    this->m_rows = rows;
    return;
}

template <typename T>
Diagonal_Matrix<T> operator~(const Diagonal_Matrix<T>& src)
{
    Diagonal_Matrix<T> result(src);

    return result;
}

template <typename T>
void Diagonal_Matrix<T>::insert_data(T data, int row, int column)
{
    if(row >= this->m_rows || row < 0
       || column >= this->m_columns || column < 0)
        throw numErr("Diagonal_Matrix<T>::insert_data: Invalid index");

    if(row == column) m_data[row] = data;
    return;
}

template <typename T>
void Diagonal_Matrix<T>::set_dimensions(int rows, int columns)
{
    if(rows <= 0 || columns <= 0)
        throw numErr("Diagonal_Matrix<T>::set_dimensions: Invalid dimensions.");
    m_data.clear();
    this->m_columns = columns;
    this->m_rows = 0;

    for(int i = 0; i < rows; i++)
        new_row();
    return;
}

template <typename T>
const T Diagonal_Matrix<T>::get_element(int row, int column) const
{
    if(row  < 0 || column  < 0 || row >= this->m_rows
       || column >= this->m_columns)
        throw numErr("Diagonal_Matrix<T>::get_element: Invalid Index.");

    if(row == column) return this->m_data[row];
    else return 0;
}

template <typename T>
bool Diagonal_Matrix<T>::is_diagonal(const Matrix_Base<T>& A)
{
    const int rows = A.Matrix_rows();
    const int columns = A. Matrix_columns();
    const T zero = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(i != j)
            {
                if(A.get_element(i, j) != zero)
                    return false;
            }
        }
    }

    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Diagonal_Matrix<T>& m)
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
std::istream& operator>>(std::istream& in, Diagonal_Matrix<T>& m)
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
                throw inputErr("Symmetric_Matrix did not receive the specified number"
                               " of rows from the input stream.");

            if(in.good() == false) throw streamErr("Bad Input stream");

            in >> Temp;
            m.insert_data(Temp, i, j);
        }
    }

    return in;
}
