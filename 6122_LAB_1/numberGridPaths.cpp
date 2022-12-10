/*
Author: Jiahao Sun
Class: ECE6122 QSZ
Last Date Modified: 09/26/2022
Description:
Mouse in a Grid Maze
Put a mouse in the top left position on a m x n grid maze. The mouse can move one position left or down at a time to reach the lower right corner of the grid.

Use Fibonnaci function to calculate the number of unique paths possible.
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

uint64_t numberGridPaths(unsigned int nRows, unsigned int nCols)
{
    // this function is used to calculate the number of grid path
    
    vector<long long> Path;
    long long uniquePath;

    if (nRows > 0)
    {
        // this functin is to prevent the situation of 0 row
        
        Path.resize(nRows + 1);
        Path[0] = 1;

        for (int i = 0; i < nCols; i++)
        {
            for (int j = 1; j < nRows; j++)
            {
                // Calculate all unique path by adding result in vector
                Path[j] = Path[j] + Path[j - 1];
            }
        }
        uniquePath = Path[nRows - 1];
        return Path[nRows - 1];
    }
    else
    {
        // this functin is to prevent the situation of 0 row
        
        Path.resize(nCols + 1);
        Path[0] = 1;

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 1; j < nCols; j++)
            {
                // Calculate all unique path by adding result in vector
                Path[j] = Path[j] + Path[j - 1];
            }
        }
        uniquePath = Path[nCols - 1];
        return Path[nCols - 1];
    }

    return uniquePath;
}
