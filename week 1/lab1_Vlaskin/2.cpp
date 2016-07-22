/**************************************************************
Tatyana Vlaskin
Lab#1
Problem 2
06.29.2014
name: 2.cpp
Description:
Takes 2 5x5 arrays and display the product of the arrays
in the 3rd array. 1st array is filled from 0-24 and
2nd array is filled with numbers 24-0.
**************************************************************/
#include <iostream>
#include <iomanip>
//used information on http://stackoverflow.com/questions/18840877/multiplying-two-2d-arrays
//also used information on http://stackoverflow.com/questions/8767166/passing-2d-array-to-function
/************************************************
** Function: populateArray1
** Description: populates 5x5 array with numbers 0-24
*************************************************/
void populateArray1(int (&array)[5][5]);

/************************************************
** Function: populateArray2
** Description: populates 5x5 array with numbers 24-0
*************************************************/
void populateArray2(int (&array)[5][5]);

/************************************************
** Function: populateArray3
** Description: Initializes elements in the 3rd array to 0.
*************************************************/
void populateArray3(int (&array)[5][5]);

/************************************************
** Function: multiplyArrays
** Description: multiplies the first two arrays,
** and populates the 3rd array with products
*************************************************/
void multiplyArrays(int (&array1)[5][5], int (&array2)[5][5], int (&array3)[5][5]);

/************************************************
** Function: displayResultsArray3
** Description: Displays the product of the array1 and array2
*************************************************/
void displayResultsArray3(int (&array)[5][5]);
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int array1[5][5];
  int array2[5][5];
  int array3[5][5];
  populateArray1(array1);
  populateArray2(array2);
  populateArray3(array3);
  multiplyArrays(array1, array2, array3);
  return 0;
}

/************************************************
** Function: populateArray1
** Description: populates 5x5 array with numbers 0-24
*************************************************/
void populateArray1(int (&array)[5][5])
{
    cout <<endl<< "ARRAY #1:" <<endl;
    int i, n;
    int l = 0;
    for (i = 0; i<5; i++)
    {
        for (n = 0; n<5; n++)
        {
            array[i][n] = l;
            l++;
            //used information from http://stackoverflow.com/questions/8750853/how-to-conveniently-align-numbers-centrally-in-c-cout
            //to align numbers
            cout <<std::left << std::setw(5) << array[i][n];
        }
        cout <<endl;
    }
}

/************************************************
** Function: populateArray2
** Description: populates 5x5 array with numbers 24-0
*************************************************/
void populateArray2(int (&array)[5][5])
{
    cout << endl << "ARRAY #2:" <<endl;
    int i, n;
    int l = 24;
    for (i = 0; i<5; i++)
    {
        for (n = 0; n<5; n++)
        {
            array[i][n] = l;
            l--;
            cout <<std::left << std::setw(5) << array[i][n];
        }
        cout <<endl;
  }
}

/************************************************
** Function: populateArray3
** Description: Initializes elements in the 3rd array to 0.
*************************************************/
void populateArray3(int (&array)[5][5])
{
    int i, n;
    for (i = 0; i<5; i++)
    {
        for (n = 0; n<5; n++)
        {
            array[i][n] = 0;
        }
    }
}
/************************************************
** Function: displayResultsArray3
** Description: Displays the product of the array1 and array2
*************************************************/
void displayResultsArray3(int (&array)[5][5]){
    cout << endl <<"PRODUCT OF THE ARRAY#1 AND ARRAY#2:" <<endl;
    int i, n;
    for (i = 0; i<5; i++)
    {
        for (n = 0; n<5; n++)
        {
        cout <<std::left << std::setw(5) << array[i][n];
        }
        cout << endl;
    }
}

/************************************************
** Function: multiplyArrays
** Description: multiplies the first two arrays,
** and populates the 3rd array with products
*************************************************/

void multiplyArrays(int (&array1)[5][5], int (&array2)[5][5], int (&array3)[5][5])
{
    int i, j;
    for (i = 0; i<5; i++)
    {
        for (j = 0; j<5; j++)
        {
            array3[i][j] = array1[i][j]*array2[i][j];
        }
    }
    displayResultsArray3(array3);// call function to display results
}
