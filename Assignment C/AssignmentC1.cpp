/**
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment C
    Problem C1
    This program creates a Car class based off of user input
    for its characteristics of the vehicle. Some of the
    characteristics include reporting mark, car number, kind,
    loaded, and the location of where the car is going.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Car
{
private:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;

public:
    void setup(string, int, string, bool, string);
    void output();

};

/*************** setup ********************
takes in the user input and sets that data to
the class variables in Car
*/
void Car::setup (string rep, int cnum, string kd, bool load, string dest)
{
    reportingMark = rep;
    carNumber = cnum;
    kind = kd;
    loaded = load;
    destination = dest;
}

/************** output ********************
prints out to console the values of reportingMark,
carNumber, kind, loaded or not, and destination
*/
void Car::output()
{
    cout << endl;
    cout << left << setw(20)  << "reportingMark "  << reportingMark << endl;
    cout << setw(20) <<"carNumber " <<  carNumber << endl;
    cout << setw(20) <<"kind " <<  kind << endl;
    cout << setw(20) << "loaded " << boolalpha << loaded << endl;
    cout << setw(20) << "destination " <<  destination << endl;
}
void input (string&, int&, string&, bool&, string&);

int main()
{
    Car *ptr = new Car;
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;

    input(reportingMark, carNumber, kind, loaded, destination);
    ptr->setup(reportingMark, carNumber, kind, loaded, destination);
    ptr->output();

    delete ptr;

    return 0;
}
/************** input ********************
asks the user to enter the various characteristics
of the car
*/
void input (string& reportingMark, int& carNumber, string& kind, bool& loaded, string& destination)
{
    cout << "Please enter the reporting mark: ";
    cin >> reportingMark;
    cout << "Please enter the car number: ";
    cin >> carNumber;
    cout << "Please enter what kind of car it is: ";
    cin >> kind;
    cout << "Please type the number 1 if the car is loaded, 0 otherwise: ";
    cin >> loaded;

    if(loaded == false)
    {
        destination = "NONE";
    }
    else
    {
        cin.ignore(80, '\n');
        cout << "Please enter your destination: ";
        getline(cin, destination);
    }
}

/*  Execution Results

    Please enter the reporting mark: SP
    Please enter the car number: 34567
    Please enter what kind of car it is: business
    Please type the number 1 if the car is loaded, 0 otherwise: 1
    Please enter your destination: Salt Lake City

    reportingMark       SP
    carNumber           34567
    kind                business
    loaded              true
    destination         Salt

    Process returned 0 (0x0)   execution time : 18.761 s
    Press any key to continue.

*/
