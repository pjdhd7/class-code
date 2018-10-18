#include <fstream>
#include <iomanip>
#include "Newton_Poly.h"

//Since we have to calculate points for 1 / (1 + 12x^2), might as well
//    wrap this in a function.
double function_calc(const double& x)
{
    double denom = 1 + 12 * pow(x, 2);
    return 1 / denom;
}

int main (int argc, char *argv[])
{
    Newton_Poly<double> poly;

    //Values calculated by the interpolant
    ArrayList<double> calc_values;
    //The actual values
    ArrayList<double> real_values;

    int numberOfPairs;
    std::ifstream polyInput;

    //Sets the input to be either a passed filename, or the default
    if(argc > 1)
    {
        polyInput.open(argv[1]);

        if(polyInput.is_open() == true)
        {
            //Gets the number of pairs in the input file
            polyInput >> numberOfPairs;
            polyInput.ignore();
        }
        else
        {
            std::cout << "Aborting Driver: File failed to open. Make sure "
                      << argv[1] << " exists in the directory." << std::endl;
            exit(1);
        }
    }
    else
    {
        //Use the first line for CLion development, the second for submission
        //polyInput.open("../repo/default_data.txt");
        polyInput.open("default_data.txt");

        if(polyInput.is_open() == true)
        {
            //Gets the number of pairs in the input file
            polyInput >> numberOfPairs;
            polyInput.ignore();
        }
        else
        {
            std::cout << "Aborting Driver: File failed to open. Make sure "
                      << "default_data.txt exists in the directory."
                      << std::endl;
            exit(1);
        }
    }

    //Iterates over the file to grab the data
    for(int i = 0; i < numberOfPairs; i++)
    {
        try
        {
            polyInput >> poly;
        }
        catch(inputErr e)
        {
            std::cerr << "Input Error: " << e.errString() << std::endl;
        }
        catch(streamErr e)
        {
            std::cerr << "Stream Error: " << e.errString() << std::endl;
            std::cerr << "Aborting Driver" << std::endl;
            exit(1);
        }
        catch(numErr e)
        {
            std::cerr << "Numerical Error: " << e.errString() << std::endl;
            std::cerr << "Aborting Driver" << std::endl;
            exit(1);
        }
    }


    //Output results of the input
    std::cout << "# Data Points and Coefficients" << std::endl;
    std::cout << std::setprecision(8) << poly << std::endl;

    std::cout << std::endl << "# Interpolant Values" << std::endl;
    for(short i = 0; i < 10; i++)
    {
        calc_values.insert_back(poly.compute(i / 10.0));
        std::cout << "(" << i /10. << ", "
                  << calc_values[i] << ")" << std::endl;
    }

    std::cout << std::endl << "# Function Values" << std::endl;
    for(short i = 0; i < 10; i++ )
    {
        real_values.insert_back(function_calc(i / 10.0));
        std::cout << "(" << i / 10. << ", "
                  << real_values[i] << ")" << std::endl;
    }

    std::cout << std::endl << "# Absolute Error" << std::endl;
    for(short i = 0; i < 10; i++)
    {
        std::cout << real_values[i] - calc_values[i] << std::endl;
    }

    std::cout << std::endl << "# Percent Relative Error" << std::endl;
    for(short i = 0; i < 10; i++)
    {
        std::cout << ((real_values[i] - calc_values[i]) / real_values[i]) * 100
                  << std::endl;
    }

    polyInput.close();

    return 0;
}
/*
Wolfram Alpha reference:
{{-1,0.0769230769},{-0.8,0.1152073733},{-0.6,0.1879699248},{-0.4,0.3424657534}}
 */
