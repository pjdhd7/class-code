template <typename T>
void compare_error(Newton_Poly<T> uniform_poly,
                   const Newton_Poly<T> cheby_poly,
                   function_calc<T> the_func)
{
    //Values calculated by the Chebyshev interpolant
    ArrayList<double> cheby_values;
    //Values calculated by the uniform interpolant
    ArrayList<double> uniform_values;
    //The actual values
    ArrayList<double> real_values;

    //Output results of the input
    std::cout << "# Data Points and Coefficients" << std::endl;
    std::cout << std::setprecision(8) << std::fixed << cheby_poly << std::endl;

    std::cout << std::endl << "# Interpolant Values" << std::endl;
    for(short i = 0; i < 5; i++)
    {
        cheby_values.insert_back(cheby_poly.compute((2*i+1) / 10.0));
        uniform_values.insert_back(uniform_poly.compute((2*i+1) / 10.0));
        std::cout << "(" << (2*i+1) /10. << ", "
                  << cheby_values[i] << ")" << std::endl;
    }

    std::cout << std::endl << "# Function Values" << std::endl;
    for(short i = 0; i < 5; i++)
    {
        real_values.insert_back(the_func((2*i+1) / 10.0));
        std::cout << "(" << (2*i+1) /10. << ", "
                  << real_values[i] << ")" << std::endl;
    }

    std::cout << std::endl << "# Absolute Error" << std::endl;
    for(short i = 0; i < 5; i++)
    {
        std::cout << fabs(real_values[i] - cheby_values[i]) << std::endl;
    }

    std::cout << std::endl << "# Percent Relative Error" << std::endl;
    for(short i = 0; i < 5; i++)
    {
        std::cout << fabs(((real_values[i] - cheby_values[i]) / real_values[i])
                          * 100)
                  << std::endl;
    }

    std::cout << std::endl << "# Percent Relative Change" << std::endl;
    for(short i = 0; i < 5; i++)
    {
        std::cout << fabs(((uniform_values[i] - cheby_values[i])
                           / uniform_values[i]) * 100)
                  << std::endl;
    }
}

