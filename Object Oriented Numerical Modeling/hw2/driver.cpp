#include "polarNum.h"
#include "norm.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    vector<polarNum<double> > pairs;
    polarNum<double> polarTemp;
    int numberOfPairs;
    oneNorm<double> polarNorm;
    ifstream polarInput;
    
    //Sets the input to be either a passed filename, or the default
    if(argc > 1)
    {
        polarInput.open(argv[1]);
    }
    else
    {
        polarInput.open("input_dataset2.txt");
    }
    
    //Gets the number of pairs in the input file
    polarInput >> numberOfPairs;
    polarInput.ignore();
    
    //Iterates over the file to grab the data
    for(int i = 0; i < numberOfPairs; i++)
    {
        try
        {
            polarInput >> polarTemp;
            pairs.push_back(polarTemp);
        }
        catch(inputErr e)
        {
            cerr << "Input error: " << e.errString() << endl;
        }
        catch(streamErr e)
        {
            cerr << "Stream Error: " << e.errString() << endl;
            cerr << "Aborting Driver" << endl;
            exit(1);
        }
    }
    
    //Gets the total number of pairs that weren't errors
    numberOfPairs = pairs.size();
    
    //Prevents Seg Faults by checking if enough pairs exist before executing
    try
    {
        if(numberOfPairs > 1)
        {
            cout << "p1 / p2: "<< pairs[0] / pairs[1] << endl;
        }
    }
    catch(numErr e)
    {
        cerr << "Aborting Division operation: " << e.errString() << endl;
    }
    
    if(numberOfPairs > 3)
    {
        cout << "p3 * p4: " << pairs[2] * pairs[3] << endl;
    }
    
    if(numberOfPairs > 4)
    {
        cout << "~p5: " << ~pairs[4] << endl;
    }
    
    //Calculates the 1-norm of the polar pairs
    cout << "1-norm: " << polarNorm(pairs) << endl;
    
    polarInput.close();
    
    return 0;
}
