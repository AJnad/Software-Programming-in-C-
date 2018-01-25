
/**
    Ajay Nadhavajhala
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
\

void Cone::setUp (double h, double r)
{
    radius = r;
    height = h;
}


double Cone::getVolume()
{
    const double PI = 3.14159265358979323846;
    return ((PI * (radius * radius) * height) / 3);
}

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



