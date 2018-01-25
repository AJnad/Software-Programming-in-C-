/*
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment A
    Problem A1
    Description of problem:
    A program that prompts the user to enter a certain
    number of strings and print them out.
*/

#include <iostream>
#include <string>

using namespace std;
void getSize(int&);
void getSpace(int, string*&);
void inputData(int, string*);
void printData(string*, int);
void destroy(string*);

int main()
{
    int sizeOfString;
    string* ptrSpace;

    getSize(sizeOfString);
    getSpace(sizeOfString, ptrSpace);
    inputData(sizeOfString, ptrSpace);
    printData(ptrSpace, sizeOfString);
    destroy(ptrSpace);

}

/*********** getSize ************
Ask user to input how many strings they want.
*/

void getSize(int &sizeOfString)
{
    cout << "Enter the number of strings you want: ";
    cin >> sizeOfString;
}

/*********** getSpace ************
gets an array in heap of the size requested by the user
*/
void getSpace(int sizeOfString, string*& str)
{
    str = new string[sizeOfString];
}

/*********** inputData ************
Allow users to input string values and store them in the array
*/

void inputData(int sizeOfString, string *space)
{
    for (int i = 0; i < sizeOfString; i++)
    {
        cout << "Enter string number " << i+1 << ":  ";
        cin >> space[i];
    }
}

/*********** printData ************
Print out all the strings One string per line
*/

void printData(string *space, int sizeOfString)
{
    cout << "\n";
    for (int i = 0; i < sizeOfString; i ++)
    {
        cout << space[i] << endl;
    }
}

/*********** Destroy ************
Retrun all the space to the heap
*/

void destroy(string *space)
{
    delete [] space;
}

/*  Execution results

Enter the number of strings you want: 3
Enter string number 1: Hello
Enter string number 2: Sunny
Enter string number 3: World

Hello
Sunny
World

*/
