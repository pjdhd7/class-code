template <typename T>
T oneNorm<T>::operator()(vector<polarNum<T> > v)
{
    const int vec_size = v.size();
    T norm_sum = 0;
    if(vec_size > 0)
    {    
        for(int i = 0; i < vec_size; i++)
        {
            norm_sum = norm_sum + fabs(v[i].getModulus());
        }
    }
    
    return norm_sum;
}