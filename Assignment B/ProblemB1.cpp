/**
    Ajay Nadhavajhala
    Youssouf Soro
    CIS 22B
    Winter 2017
    Assignment B
    Problem B1
    This program asks the user to enter a height and radius and
    it will calculate the volume of the cone based on user input.
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Cone
{
    double height;
    double radius;
};

void input (double&, double&);
void setUp (double, double, Cone *);
double getVolume (Cone *);
void output (Cone *);

int main()
{
    struct Cone *ptr;
    double height;
    double radius;
    Cone *myCone = new Cone();
    input(height, radius);
    setUp(height, radius, myCone);
    getVolume(myCone);
    output (myCone);
}

/**************** input ***************
asks the user to enter a height and radius for
the cone
*/
void input(double& height, double& radius)
{
    cout << "Please enter the height of the cone: ";
    cin >> height;
    cout << "Please enter the radius of the cone: ";
    cin >> radius;
}

/**************** setUp ***************
takes in the user input and sets that data to
the struct variables in Cone
*/
void setUp(double height, double radius, Cone *myCone)
{
    myCone->height = height;
    myCone->radius = radius;
}

/**************** getVolume ***************
calculates the volume of the cone based off user
input
*/
double getVolume (Cone *myCone)
{
    const double PI = 3.14159265358979323846;
    return ((PI * (myCone->radius * myCone->radius) * myCone->height) / 3);
}

/**************** output ***************
prints out to console the values for height, radius,
and volume
*/
void output (Cone *myCone)
{
    getVolume(myCone);
    cout << fixed << showpoint << setprecision(2);
    cout << "\nHeight: " << setw(6) << myCone->height << endl;
    cout << "Radius: " << setw(6) << myCone->radius << endl;
    cout << "Volume: " << setw(6) << getVolume(myCone) << endl;
}

/*  Execution Results

    Please enter the height of the cone: 6
    Please enter the radius of the cone: 2

    Height:   6.00
    Radius:   2.00
    Volume:  25.13

    Process returned 0 (0x0)   execution time : 1.282 s
    Press any key to continue.
*/

