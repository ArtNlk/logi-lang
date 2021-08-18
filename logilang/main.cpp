#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "logilib.h"

int main()
{
    std::string inputFileName;
    std::string targetVariable;

    std::cout << "Enter input file name:\n";
    std::cin >> inputFileName;
    std::cout << "Enter variable to solve for:\n";
    std::cin >> targetVariable;

    std::ifstream inputFile;
    inputFile.open(inputFileName);

    LogiSolver solver;
    std::string tempString;
    while (std::getline(inputFile, tempString))
    {
        if(!solver.parseLine(tempString))
        {
            if(solver.getLastError() != LINE_IS_EMPTY && solver.getLastError() != LINE_IS_COMMENT)
            {
                std::cout << "Error parsing line: " << tempString << "\n";
            }
        }
    }

    bool result;
    try {
        result = solver.solveFor(targetVariable);
    }catch(std::logic_error &e)
    {
        std::cout << e.what() << "\n";
        std::exit(1);
    }

    std::cout << targetVariable << " == " << std::boolalpha << result << "\n";
}