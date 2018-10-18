template <typename T>
Banded_Matrix<T>::Banded_Matrix(const Matrix_Base<T>& src)
{
    if(is_banded(src) == false)
        throw numErr("Diagonal Matrix<T>::Copy_Constructor: Source matrix is "
                     "not a Banded Matrix.");

    this->m_columns = src.Matrix_columns();
    this->m_rows = 0;
    for(int i = 0; i < src.Matrix_rows(); i++)
    {
        new_row();
    }

    for(int i = 0; i < this->m_rows; i++)
    {
        if(i != 0)
            this->m_data[i][0] = src.get_element(i, i - 1);

        this->m_data[i][1] = src.get_element(i, i);

        if(i != this->m_rows - 1)
            this->m_data[i][2] = src.get_element(i, i + 1);

    }
}

template <typename T>
Banded_Matrix<T>::Banded_Matrix(int rows, int columns)
{
    if(rows < 0 || columns < 0)
        throw numErr("Banded_Matrix<T>(rows, columns): Tried to build a "
                     "matrix with negative dimensions.");

    this->m_columns = columns;
    this->m_rows = 0;
    for(int i = 0; i < rows; i++)
    {
        new_row();
    }
}

template <typename T>
Banded_Matrix<T>& Banded_Matrix<T>::operator=(const Banded_Matrix<T>& rhs)
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
Banded_Matrix<T>& Banded_Matrix<T>::operator=(Banded_Matrix<T>&& rhs)
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
Banded_Matrix<T>& Banded_Matrix<T>::operator*=(T rhs)
{
    for(int i = 0; i < this->m_rows; i++)
    {
        m_data[i][0] *= rhs;
        m_data[i][1] *= rhs;
        m_data[i][2] *= rhs;
    }

    return *this;
}

template <typename T>
Banded_Matrix<T> operator*(const Banded_Matrix<T>& lhs, const T& rhs)
{
    Banded_Matrix<T> result(lhs);

    return result *= rhs;
}

template <typename T>
Banded_Matrix<T> operator+(const Banded_Matrix<T>& lhs,
                           const Banded_Matrix<T>& rhs)
{
    if(lhs.m_rows != rhs.m_rows || lhs.m_columns != rhs.m_columns)
        throw numErr("Banded_Matrix<T>::operator+: Attempting to add matrices "
                     "with different dimensions!");

    Banded_Matrix<T> result(lhs);

    return result += rhs;
}

template <typename T>
Banded_Matrix<T>& Banded_Matrix<T>::operator+=(const Banded_Matrix<T>& rhs)
{
    if(this->m_rows != rhs.m_rows
       || this->m_columns != rhs.m_columns)
        throw numErr("Banded_Matrix<T>::operator+=: Attempting to add matrices"
                     " with different dimensions!");

    for(int i = 0; i < this->m_rows; i++)
    {
        m_data[i][0] += rhs.m_data[i][0];
        m_data[i][1] += rhs.m_data[i][0];
        m_data[i][2] += rhs.m_data[i][0];
    }

    return *this;
}

template <typename T>
Banded_Matrix<T> operator-(Banded_Matrix<T>& lhs,
                           Banded_Matrix<T>& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Banded_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Banded_Matrix<T> result(lhs);

    return result -= rhs;
}

template <typename T>
Banded_Matrix<T> operator-(Banded_Matrix<T>& lhs,
                             Banded_Matrix<T>&& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Banded_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Banded_Matrix<T> result(lhs);
    const int rows = result.Matrix_rows();

    for(int i = 0; i < rows; i++)
    {
        lhs.m_data[i][0] += rhs.m_data[i][0];
        lhs.m_data[i][1] += rhs.m_data[i][0];
        lhs.m_data[i][2] += rhs.m_data[i][0];
    }

    return result;
}

template <typename T>
Banded_Matrix<T> operator-(Banded_Matrix<T>&& lhs,
                             Banded_Matrix<T>&& rhs)
{
    if(lhs.Matrix_rows() != rhs.Matrix_rows()
       || lhs.Matrix_columns() != rhs.Matrix_columns())
        throw numErr("Banded_Matrix<T>::operator-: Attempting to subtract "
                     "matrices with different dimensions.");

    Banded_Matrix<T> result(lhs);
    const int rows = result.Matrix_rows();

    for(int i = 0; i < rows; i++)
    {
        lhs.m_data[i][0] += rhs.m_data[i][0];
        lhs.m_data[i][1] += rhs.m_data[i][0];
        lhs.m_data[i][2] += rhs.m_data[i][0];
    }

    return result;
}

template <typename T>
Banded_Matrix<T>& Banded_Matrix<T>::operator-=(Banded_Matrix<T>& rhs)
{
    if(this->m_rows != rhs.m_rows
       || this->m_columns != rhs.m_columns)
        throw numErr("Banded_Matrix<T>::operator-=: Attempting to subtract "
                     "matrices with different dimensions.");

    for(int i = 0; i < this->m_rows; i++)
    {
        m_data[i][0] += rhs.m_data[i][0];
        m_data[i][1] += rhs.m_data[i][0];
        m_data[i][2] += rhs.m_data[i][0];
    }

    return *this;
}

template <typename T>
Vector<T> operator*(const Banded_Matrix<T>& lhs,
                          const Vector<T>& rhs)
{
    if(lhs.Matrix_columns() != rhs.size())
        throw numErr("Banded_Matrix<T>::operator*: Attempting to multiply a "
                     "Banded_Matrix by a vector with unequal dimensions. "
                     "(Number of Banded_Matrix columns must equal number of "
                     "elements in the vector)");

    Vector<T> result;
    T temp_sum = 0;
    int rows = lhs.Matrix_rows();
    for(int i = 0; i < rows; i++)
    {
        for(int j = i-1; j < i+2; j++)
        {
            if(j >= 0 && j < rows)
                temp_sum += lhs.get_element(i,j) * rhs[j];
        }
        result.insert_back(temp_sum);
        temp_sum = 0;
    }

    return result;
}

template <typename T>
Banded_Matrix<T> operator*(const Banded_Matrix<T>& lhs,
                           const Banded_Matrix<T>& rhs)
{
    if(lhs.Matrix_columns() != rhs.Matrix_rows())
        throw numErr("Banded_Matrix<T>::operator*: Attempting to multiply a "
                     "Banded_Matrix by another Banded_Matrix with unequal "
                     "dimensions. (For A*B, the number of columns in A must "
                     "equal the number of rows in B");

    int rows = lhs.Matrix_rows();
    int columns = rhs.Matrix_columns();
    Banded_Matrix<T> result(rows, columns);
    T temp_sum = 0;

    for(int i = 0; i < rows; i++)
    {

        for(int j = 0; j < columns; j++)
        {
            for(int k = i-1; k < i+2; k++)
            {
                if(k >= 0 && k < rows)
                    temp_sum += lhs.get_element(i,k) * rhs.get_element(k,j);
            }
            result.insert_data(temp_sum, i, j);

            temp_sum = 0;
        }
    }

    return result;
}

template <typename T>
Banded_Matrix<T> operator*(const Banded_Matrix<T>&& lhs,
                           const Banded_Matrix<T>&& rhs)
{
    if(lhs.Matrix_columns() != rhs.Matrix_rows())
        throw numErr("Banded_Matrix<T>::operator*: Attempting to multiply a "
                     "Banded_Matrix by another Banded_Matrix with unequal "
                     "dimensions. (For A*B, the number of columns in A must "
                     "equal the number of rows in B");

    int rows = lhs.Matrix_rows();
    int columns = rhs.Matrix_columns();
    Banded_Matrix<T> result(rows, columns);
    T temp_sum = 0;

    for(int i = 0; i < rows; i++)
    {

        for(int j = 0; j < columns; j++)
        {
            for(int k = i-1; k < i+2; k++)
            {
                temp_sum += lhs.get_element(i,k) * rhs.get_element(k,j);
            }
            result.insert_data(temp_sum, i, j);

            temp_sum = 0;
        }
    }

    return result;
}

template <typename T>
void Banded_Matrix<T>::new_row()
{
    ArrayList<T> temp;
    T zero = 0;
    temp.insert_back(zero);
    temp.insert_back(zero);
    temp.insert_back(zero);
    m_data.insert_back(temp);
    this->m_rows++;

    return;
}

template <typename T>
void Banded_Matrix<T>::set_columns(int columns)
{
    if(columns < 0)
        throw numErr("Banded_Matrix<T>::set_columns: Negative column value.");

    this->m_columns = columns;
    return;
}

template <typename T>
void Banded_Matrix<T>::set_rows(int rows)
{
    if(rows < 0)
        throw numErr("Banded_Matrix<T>::set_rows: Negative row value.");

    this->m_rows = rows;
    return;
}

template <typename T>
Banded_Matrix<T> operator~(const Banded_Matrix<T>& src)
{
    Banded_Matrix<T> result(src);

    result.m_data.swap(0,2);

    int temp = result.m_rows;
    result.m_rows = result.m_columns;
    result.m_columns = temp;

    return result;
}

template <typename T>
void Banded_Matrix<T>::insert_data(T data, int row, int column)
{
    if(row >= this->m_rows || row < 0
       || column >= this->m_columns || column < 0)
        throw numErr("Banded_Matrix<T>::insert_data: Invalid index");

    //Element is on the main diagonal
    if(row == column)
        m_data[row][1] = data;

    //Element is on the immediate left of the main diagonal
    else if(column == row - 1 && row != 0)
        m_data[row][0] = data;

    //Element is on the immediate right of the main diagonal
    else if(column == row + 1 && row != this->m_rows)
        m_data[row][2] = data;

    return;
}

template <typename T>
void Banded_Matrix<T>::set_dimensions(int rows, int columns)
{
    if(rows <= 0 || columns <= 0)
        throw numErr("Banded_Matrix<T>::set_dimensions: Invalid dimensions.");
    m_data.clear();
    this->m_columns = columns;
    this->m_rows = 0;

    for(int i = 0; i < rows; i++)
        new_row();
    return;
}

template <typename T>
const T Banded_Matrix<T>::get_element(int row, int column) const
{
    if(row  < 0 || column  < 0 || row >= this->m_rows
       || column >= this->m_columns)
        throw numErr("Banded_Matrix<T>::get_element: Invalid Index.");

    //Element is on the main diagonal
    if(row == column)
        return m_data[row][1];

    //Element is on the immediate left of the main diagonal
    else if(column == row - 1 && row != 0)
        return m_data[row][0];

    //Element is on the immediate right of the main diagonal
    else if(column == row + 1 && row != this->m_rows)
        return m_data[row][2];

    //Element is not in the band
    else
        return 0;
}

template <typename T>
bool Banded_Matrix<T>::is_banded(const Matrix_Base<T> &A)
{
    const int rows = A.Matrix_rows();
    const int columns = A. Matrix_columns();
    const T zero = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(i > j + 1 || j > i + 1)
            {
                if(A.get_element(i, j) != zero)
                    return false;
            }
        }
    }

    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Banded_Matrix<T>& m)
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
std::istream& operator>>(std::istream& in, Banded_Matrix<T>& m)
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
