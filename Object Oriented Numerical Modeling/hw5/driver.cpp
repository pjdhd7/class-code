#include <fstream>
#include <iomanip>
#include <limits>
#include "Matrix.h"
#include "gaussian_elimination.h"

int main(int argc, char *argv[])
{
    Matrix<double> A;
    Dolan_Vector<double> V;
    Gaussian_Elimination<double> solver;
    std::ifstream input;
    int number_of_rows;

    try
    {
        if(argc > 1)
        {
            input.open(argv[1]);

            if(input.is_open() == true)
            {
                input >> number_of_rows;
                input.ignore();
                input.ignore();


                A.set_dimensions(number_of_rows, number_of_rows);

                input >> A;
                input.ignore();


                input >> V;
            }
            else
            {
                std::cerr << "Aborting Driver: File failed to open. make sure "
                          << argv[1] <<" exists in the directory." << std::endl;
                exit(1);
            }
        }
        else
        {
            //input.open("gaussian.dat");
            input.open("data6.dat");

            if(input.is_open() == true)
            {
                input >> number_of_rows;
                input.ignore();
                //input.ignore();


                A.set_dimensions(number_of_rows, number_of_rows);

                input >> A;
                input.ignore();

                input.ignore();
                input >> V;
            }
            else
            {
                std::cerr << "Aborting Driver: File failed to open. make sure "
                          << "gaussian.dat exists in the directory."
                          << std::endl;
                exit(1);
            }
        }
    }
    catch (streamErr e)
    {
        std::cerr << "Aborting Driver: " << e.errString() << std::endl;
        exit(2);
    }
    catch(inputErr e)
    {
        std::cerr << "Aborting Driver: " << e.errString() << std::endl;
        exit(3);

    }

    try
    {
        std::cout << std::setprecision(8) << std::fixed;

        //std::cout<< A * ~A << std::endl;
        std::cout<< A << std::endl;
        std::cout << std::endl << V << std::endl;

        Dolan_Vector<double> x = solver(A, V);

        std::cout << std::endl << x << std::endl;

        std::cout << std::endl << A * x << std::endl;
    }
    catch( numErr e)
    {
        cerr << e.errString() << endl;
    }

    return 0;
}