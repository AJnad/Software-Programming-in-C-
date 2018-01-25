/**
    Ajay Nadhavajhala
    Youssouf Soro
    CIS 22B
    Winter 2017
    Assignment B
    Problem B2
    This program asks the user to enter a height and radius and
    it will calculate the volume of the cone based on user input.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Cone
{
private:
    double radius;
    double height;
public:
    void setUp(double, double);
    double getVolume();
    void output();
};

/**************** setUp ***************
takes in the user input and sets that data to
the class variables in Cone
*/
void Cone::setUp (double h, double r)
{
    radius = r;
    height = h;
}

/**************** getVolume ***************
calculates the volume of the cone based off user
input
*/
double Cone::getVolume()
{
    const double PI = 3.14159265358979323846;
    return ((PI * (radius * radius) * height) / 3);
}

/**************** output ***************
prints out to console the values for height, radius,
and volume
*/
void Cone::output()
{
    cout << fixed << showpoint << setprecision(2);
    cout << "\nHeight: " << setw(6) << height << endl;
    cout << "Radius: " << setw(6) << radius << endl;
    cout << "Volume: " << setw(6) << getVolume() << endl;
}

void input (double&, double&);

int main()
{
    Cone myCone;
    double coneRadius;
    double coneHeight;
    input(coneHeight, coneRadius);
    myCone.setUp(coneHeight, coneRadius);
    myCone.getVolume();
    myCone.output();
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

/*  Execution Results

    Please enter the height of the cone: 4
    Please enter the radius of the cone: 3

    Height:   4.00
    Radius:   3.00
    Volume:  37.70

    Process returned 0 (0x0)   execution time : 4.523 s
    Press any key to continue.
*/


