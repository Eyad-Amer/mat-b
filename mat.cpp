/**
 * mat function
 *
 * Author: Eyad Amer
 * Since : 2022-03
 */

#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// mat function
string ariel::mat(int num1, int num2, char c1, char c2)
{

    // const numbers to check if the inputs of the characters are legal(between 33 and 126 in the ascii table)
    const int min_ascii = 33;
    const int max_ascii = 126;

    /* check the inputs */

    // Bad inputs - even numbers
    if (num1 % 2 == 0 || num2 % 2 == 0)
    {
        throw invalid_argument("illegal inputs - please enter odd numbers!");
    }

    // Bad inputs - Negetave number
    if (num1 < 1 || num2 < 1)
    {
        throw invalid_argument("illegal inputs - please enter positive numbers!");
    }

    // Bad inputs - illegal characters
    if ((c1 < min_ascii || c1 > max_ascii) || (c2 < min_ascii || c2 > max_ascii))
    {
        throw invalid_argument("illegal inputs - please enter a charcters are between 33 and 126 in the ascii table!");
    }
    

    /* defining variables */

    vector<vector<char>> mat(num2, vector<char>(num1)); // vector of vectors
    string results;                                     // the result matrix

    // Defining the boundaries of the matrix.
    int top = 0;
    int bottom = num2 - 1;
    int left = 0;
    int right = num1 - 1;
    int turn = 0; // to switch the symbol

    /* Implementation of functions */
    for(; top < bottom+1 && left < right+1; top++,right--,bottom--,left++,turn++) 
    {
        // This part make the top row of the matrix
        for (int i = left; i < right+1; i++)
        {
            if (turn % 2 == 0)
            {
                mat[top][i] = c1;
            }
            else
            {
                mat[top][i] = c2;
            }
        }  

        // This part make the right side of the matrix
        for (int i = top+1; i < bottom+1; i++)
        {
            if (turn % 2 == 0)
            {
                mat[i][right] = c1;
            }
            else
            {
                mat[i][right] = c2;
            }
        }
        
        // This part make the bottom of the matrix
        for (int i = right-1; i > left-1; i--)
        {
            if (turn % 2 == 0)
            {
                mat[bottom][i] = c1;
            }
            else
            {
                mat[bottom][i] = c2;
            }
        }

        // This part make the lift side of the matrix
        for (int i = bottom-1; i > top-1; i--)
        {
            if (turn % 2 == 0)
            {
                mat[i][left] = c1;
            }
            else
            {
                mat[i][left] = c2;
            }
        }
    }

    // Copy the matrix to a String
    for (int i = 0; i < num2; i++)
    {
        for (int j = 0; j < num1; j++)
        {
            results.push_back(mat[i][j]);
        }
        results.push_back('\n');
    }

    return results;
}
