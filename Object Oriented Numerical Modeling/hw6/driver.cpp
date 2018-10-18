#include <fstream>
#include <iomanip>
#include <limits>
#include "Generic_Matrix.h"
#include "Diagonal_Matrix.h"
#include "Banded_Matrix.h"
#include "Symmetric_Matrix.h"
#include "Steepest_Descent.h"
#include "Gauss_Seidel.h"

int main(int argc, char *argv[])
{
    Generic_Matrix<double> A;
    Vector<double> V;
    //Gauss_Seidel<double> solver(0.000001);
    Steepest_Descent<double> solver(0.000001);
    std::ifstream input;
    int number_of_rows;

    try
    {
        if(argc > 1)
        {
            input.open(argv[1]);

            if(input.is_open() == true && input.eof() == false)
            {
                input >> number_of_rows;
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                A.set_dimensions(number_of_rows, number_of_rows);

                input >> A;
                input.ignore();
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
            input.open("data6.dat");

            if(input.is_open() == true && input.eof() == false)
            {
                input >> number_of_rows;
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                A.set_dimensions(number_of_rows, number_of_rows);

                input >> A;
                input.ignore();
                input.ignore();


                input >> V;
            }
            else
            {
                std::cerr << "Aborting Driver: File failed to open. make sure "
                          << "data6.dat exists in the directory."
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
        Symmetric_Matrix<double> B(A);
        std::cout << std::setprecision(8) << std::fixed;

        std::cout << A << std::endl;
        std::cout << std::endl << V << std::endl;
        std::cout << std::endl << B + A << std::endl;
        A+=B;

        std::cout << std::endl << B - A << std::endl;
        std::cout << std::endl << B * A << std::endl;
        std::cout << std::endl << B - A  + (2.0 * B) << std::endl;


        Vector<double> x = solver(A, V);

        std::cout << std::endl << x << std::endl;

        std::cout << std::endl << A * x << std::endl;

        std::cout << std::endl << solver.get_time() << std::endl;

        std::cout << std::endl << solver.get_iterations() << std::endl;
    }
    catch( numErr e)
    {
        cerr << e.errString() << endl;
    }

    return 0;
}
