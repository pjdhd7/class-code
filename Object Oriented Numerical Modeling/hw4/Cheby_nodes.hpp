template <typename T>
ArrayList<T> Cheby_nodes<T>::operator()(const int& degree)
{
    ArrayList<T> ret_vals;
    //double pi = 3.14159265358979323846;

    //Calculate the zeroes for every Chebyshev polynomial up to 'degree,'
    //then push each one to the back of 'ret_vals'
    for(short i = 0; i <= degree; i++)
    {
        ret_vals.insert_back(cos(((2*degree + 1 - 2*i) * M_PI)
                                 / (2*degree + 2)));
    }

    return ret_vals;
}