template <typename T>
Matrix<T>::Matrix(int rows, int columns): m_columns(columns)
{
    m_rows = 0;
    for(int i = 0; i < rows; i++)
    {
        new_row();
    }
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
    if(&rhs != NULL && this != &rhs)
    {
        m_rows = rhs.m_rows;
        m_columns = rhs.m_columns;

        m_data = rhs.m_data;
    }

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& rhs) noexcept
{
    if(&rhs != NULL && this != &rhs)
    {
        m_data = rhs.m_data;

        m_rows = rhs.m_rows;
        m_columns = rhs.m_columns;
    }

    return *this;
}

template <typename T>
ArrayList<T>& Matrix<T>::operator[](int i)
{
    if(i >= m_rows) throw numErr("Matrix<T>::operator[]: index out of bounds!");

    return m_data[i];
}

template <typename T>
const ArrayList<T>& Matrix<T>::operator[](int i) const
{
    if(i >= m_rows) throw numErr("Matrix<T>::operator[]: index out of bounds!");

    return m_data[i];
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(T rhs)
{
    for(int i = 0; i < m_rows; i++)
    {
        m_data[i] *= rhs;
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T rhs)
{
    Matrix result(*this);

    return result *= rhs;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& rhs)
{
    if(m_rows != rhs.m_rows || m_columns != rhs.m_columns)
        throw numErr("Matrix<T>::operator+: Attempting to add matrices with"
                     " different dimensions!");

    Matrix<T> result(*this);

    return result += rhs;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(Matrix<T>& rhs)
{
    if(m_rows != rhs.m_rows || m_columns != rhs.m_columns)
        throw numErr("Matrix<T>::operator+=: Attempting to add matrices with"
                     " different dimensions!");

    for(int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_columns; j++)
        {
            m_data[i][j] += rhs[i][j];
        }
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& rhs)
{
    if(m_rows != rhs.m_rows || m_columns != rhs.m_columns)
        throw numErr("Matrix<T>::operator+: Attempting to add matrices with"
                     " different dimensions.");

    Matrix<T> result(*this);

    return result -= rhs;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(Matrix<T>& rhs)
{
    if(m_rows != rhs.m_rows || m_columns != rhs.m_columns)
        throw numErr("Matrix<T>::operator+=: Attempting to add matrices with"
                     " different dimensions.");

    for(int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_columns; j++)
        {
            m_data[i][j] -= rhs[i][j];
        }
    }

    return *this;
}

template <typename T>
Dolan_Vector<T> Matrix<T>::operator*(Dolan_Vector<T>& rhs)
{
    if(m_columns != rhs.size())
        throw numErr("Matrix<T>::operator*: Attempting to multiply a Matrix by "
                     "a vector with unequal dimensions. (Number of Matrix "
                     "columns must equal number of elements in the vector)");

    Dolan_Vector<T> result;
    T temp_sum = 0;
    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < m_columns; j++)
        {
            temp_sum += m_data[i][j] * rhs[j];
        }
        result.insert_back(temp_sum);
        temp_sum = 0;
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& rhs)
{
    if(m_columns != rhs.m_rows)
        throw numErr("Matrix<T>::operator*: Attempting to multiply a Matrix by "
                     "another Matrix with unequal dimensions. (For A*B, the "
                     "number of columns in A must equal the number of rows in B"
        );

    Matrix<T> result;
    T temp_sum = 0;

    for(int i = 0; i < m_rows; i++)
    {
        result.new_row();

        for(int j = 0; j < rhs.m_columns; j++)
        {
            for(int k = 0; k < m_columns; k++)
            {
                temp_sum += m_data[i][k] * rhs[k][j];
            }
            result.m_data[i].insert_back(temp_sum);

            temp_sum = 0;
        }
    }

    result.m_columns = rhs.m_columns;

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>&& rhs)
{
    return *this * rhs;
}

template <typename T>
void Matrix<T>::new_row()
{
    Dolan_Vector<T> tempVector;
    for(int i = 0; i < m_columns; i++)
    {
        tempVector.insert_back(0);
    }
    m_data.insert_back(tempVector);
    m_rows++;

    return;
}


template <typename T>
Matrix<T> Matrix<T>::operator~() const
{
    Matrix<T> result(m_columns, m_rows);

    for(int i = 0; i < m_columns; i++)
    {
        for(int j = 0; j < m_rows; j++)
        {
            result[i][j] = m_data[j][i];
        }
    }

    return result;
}

template <typename T>
void Matrix<T>::insert_data(T data, int row, int column)
{
    if(row >= m_rows || column >= m_columns)
        throw numErr("Matrix<T>::insert_data: Invalid index");

    m_data[row][column] = data;
    return;
}

template <typename T>
void Matrix<T>::swap_rows(int i, int j)
{
    if(i >= m_rows || j >= m_rows)
        throw numErr("Matrix<T>::swap_rows: Invalid index");

    if(i != j) m_data.swap(i,j);

    return;
}

template <typename T>
void Matrix<T>::swap_columns(int i, int j)
{
    if(i >= m_columns || j >= m_columns)
        throw numErr("Matrix<T>::swap_columns: Invalid index");

    for(int k = 0; k < m_rows; k++)
    {
        m_data[k].swap(i, j);
    }

    return;
}

template <typename T>
void Matrix<T>::set_dimensions(int rows, int columns)
{
    if(rows <= 0 || columns <= 0) throw numErr("Matrix<T>::set_dimensions: "
                                               "invalid dimensions.");
    m_data.clear();
    m_columns = columns;

    for(int i = 0; i < rows; i++)
        new_row();
    return;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m)
{
    if(m.m_rows != 0)
    {
        for (int i = 0; i < m.m_rows; i++)
        {
            for(int j = 0; j < m.m_columns; j++)
            {
                out << m.m_data[i][j] << " ";
            }

            if (i < m.m_rows - 1) out << std::endl;
        }
    }

    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& m)
{
    //Checks if the stream is usable and still has data
    if(in.good() == false || in.eof() == true)
        throw streamErr("Bad Input stream");

    //Creates a temp object, which is then pushed into the m_data for each row
    Dolan_Vector<T> vectorTemp;
    for(int i = 0; i < m.m_rows; i++)
    {
        if(in.eof() == true) throw inputErr("Matrix did not receive the "
                                            "specified number of rows from the"
                                            "input stream.");

        if(in.good() == false) throw streamErr("Bad Input stream");

        in >> vectorTemp;

        m.m_data[i] = vectorTemp;
    }

    //Ensures the rows are all equally long, assuming that the rest of the row
    //  is a string of zeroes.
    int longest_row = 0;
    for(int i = 0; i < m.m_rows; i++)
    {
        if(m.m_data[i].size() > longest_row)
            longest_row = m.m_data[i].size();
    }

    m.m_columns = longest_row;
    for(int i = 0; i < m.m_rows; i++)
    {
        for(int j = m.m_data[i].size(); j < longest_row; j++)
            m.m_data[i].insert_back(0);
    }

    return in;
}
