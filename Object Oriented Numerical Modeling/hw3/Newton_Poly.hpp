//Add a row to the table for every new point
//THROWS: numErr
template <typename T>
void Newton_Poly<T>::add_data(const T& x, const T& y)
{
    ArrayList<T> temp_vector;
    m_dd_table.insert_back(temp_vector);
    const short table_size = static_cast<short>( m_dd_table.size() );
    m_x.insert_back(x);
    m_dd_table[table_size - 1].insert_back(y);

    //i = 1 to avoid the for loop for the first point added to the table
    T temp_number;
    for(short i = 1; i < table_size; i++)
    {
        //Prevents division by zero, also catches potential double entries
        if ( m_x[table_size - 1] == m_x[table_size - 1 - i] )
            throw numErr("Divide by zero. Same x-value is used twice in data");

        temp_number =
             ( m_dd_table[table_size - 1][i - 1]
              - m_dd_table[table_size - 2][i - 1] )
             / ( m_x[table_size - 1] - m_x[table_size - 1 - i] );

        m_dd_table[table_size - 1].insert_back(temp_number);
    }

    //Insert the first data point into our expanded polynomial
    if(table_size == 1) {
        m_expanded_poly.insert_back(y);

        //Creates the forward poly of x-x0
        m_forward_poly.insert_back(-x);
        m_forward_poly.insert_back(1);
    }
    //Add new elements to the expanded and forward polynomials
    else
    {
        //I'm pretty sure that temp_number retains the latest coeff value
        //But, we're doing this anyway
        const T new_coeff = m_dd_table[table_size - 1][table_size - 1];
        short expanded_poly_size = static_cast<short>(m_expanded_poly.size());

        for(short i = 0; i < expanded_poly_size; i++)
        {
            m_expanded_poly[i] = m_expanded_poly[i]+
                                 m_forward_poly[i] * new_coeff;
        }

        m_expanded_poly.insert_back(new_coeff);

        //Increment this value to reuse a variable we already have for the loop
        expanded_poly_size++;

        //Duplicate the forward poly vector
        //We'll use this for one half of the polynomial conversion
        ArrayList<T> copy_forward(m_forward_poly);

        //m_forward_poly * -xi
        for(short i = 0; i < expanded_poly_size; i++)
        {
            m_forward_poly[i] = m_forward_poly[i] * -x;
        }

        //Adding the result of m_forward_poly * x and m_forward_poly * -xi
        //The final vector contains the new m_forward_poly for the next data
        //   point added to the interpolation.
        for(short i = 1; i < expanded_poly_size; i++)
        {
            m_forward_poly[i] = m_forward_poly[i] + copy_forward[i-1];
        }

        m_forward_poly.insert_back(1);
    }

    return;
}

//Returns the value of the polynomial at x
template <typename T>
T Newton_Poly<T>::compute(const T& x)
{
    T x_term = 1;
    T y_term = m_dd_table[0][0];
    const short table_size = static_cast<short>( m_dd_table.size() );

    for(int i = 1; i < table_size; i++)
    {
        x_term = x_term * (x - m_x[i - 1]);
        y_term = y_term + m_dd_table[i][i] * x_term;
    }

    return y_term;
}

//THROWS: streamErr, inputErr
//If it ain't broke, don't fix it
template <typename T>
std::istream& operator>>(std::istream& is, Newton_Poly<T>& poly)
{
    //Checks if the stream is usable and still has data
    if(is.good() == false && is.eof() == false)
        throw streamErr("Bad Input stream");

    //Sets up a temporary container for the input
    //Then checks for empty input
    std::string inputTemp;
    std::getline(is, inputTemp);
    if(inputTemp.empty() == true) throw inputErr("Empty input string");

    try
    {
        //Attempts to convert the input
        std::string::size_type index;

        double x = std::stod(inputTemp, &index);
        double y = std::stod(inputTemp.substr(index), &index);

        poly.add_data(static_cast<T>(x), static_cast<T>(y));

        return is;
    }
    //Exception thrown by stod() if the input can't be converted
    catch(std::invalid_argument e)
    {
        throw inputErr("Malformed input");
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Newton_Poly<T>& poly)
{
    const short poly_size = static_cast<short>( poly.m_expanded_poly.size() );
    const short dataset_size = static_cast<short>( poly.m_x.size() );

    //Outputs the data points used for the interpolant
    for(short i = 0; i < dataset_size; i++)
    {
        os << "(" << poly.m_x[i] << ", " << poly.m_dd_table[i][0] << ")"
             << std::endl;
    }

    //Outputs the constant term of the power form
    os << std::endl << poly.m_expanded_poly[0] << " " << std::endl;

    //Outputs all remaining terms of the power form
    for(int i = 1; i < poly_size; i++)
    {
        if(poly.m_expanded_poly[i] > 0)
        {
            os << poly.m_expanded_poly[i] << "x^" << i << std::endl;
        }
        else if(poly.m_expanded_poly[i] < 0)
        {
            os << poly.m_expanded_poly[i]<< "x^" << i << std::endl;
        }
    }

    return os;
}
