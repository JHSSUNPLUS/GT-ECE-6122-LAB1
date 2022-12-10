/*
Author: Jiahao Sun
Class: ECE6122 QSZ
Last Date Modified: 09/26/2022
Description:
Mouse in a Grid Maze
Put a mouse in the top left position on a m x n grid maze. The mouse can move one position left or down at a time to reach the lower right corner of the grid.

We need to know how many unique paths possible.
Use command line argument, user can set the number of rows and the number of column. Output unique paths to a text file.
The first command line argument is the number of rows and the second argument is the number of columns. The output file is overwritten each time the program is executed.
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

#include "numberGridPaths.cpp"

bool checkInput(string s)
{
    // Check input type
    for (int i = 0; i < s.length(); i++)
    {
        // Check all bit in the string
        if (isdigit(s[i]) == false)
        {
            // Check every bit if is not a digit
            return false;
        }
        else if (s.length() > 1)
        {
            // If the length of string is larger than one
            if (s[0] == '0')
            {
                // The first bit should not be zero
                return false;
            }
        }
        else if (s.length() == 0)
        {
            // The string cannot be empty
            return false;
        }
    }
 
    return true;
}

int main(int argc, char *argv[])
{
    //Initialize variables
    FILE * pathFile; // file of NumberPaths.txt
    int nRows = 0; // number of rows
    int nCols = 0; // number of columns
    
    if (argc == 3 && checkInput(argv[1]) && checkInput(argv[2]))
    {
        // If input command line argument is valid
        // Convert input to integer, and calculate number of grid paths
        // Print the result in the file
        
        //Convert string to integer
        nRows = stoi(argv[1]);
        nCols = stoi(argv[2]);
        
        // Open file, write and close
        pathFile = fopen ("NumberPaths.txt", "w");
        fprintf (pathFile, "Total Number Paths: %llu", numberGridPaths(nRows, nCols));
        fclose (pathFile);
    }
    else
    {
        // If input command line argument is invalid
        // Print invalid message in the file
        
        // Open file, write and close
        pathFile = fopen ("NumberPaths.txt", "w");
        fprintf (pathFile, "Invalid Input!");
        fclose (pathFile);
    }
    
    return 0;
}
