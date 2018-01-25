/**
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment C
    Problem C2
    This program is based off of the Car program
    from problem C1. However, we make use of
    copy and default constructors based off of
    the user input.
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
    // default constructor
    Car()
    {
        setup(reportingMark = "", carNumber = 0, kind = "other", loaded = false, destination ="NONE");
    }

    // copy constructor
    Car (const Car &userCar)
    {
        setup(userCar.reportingMark, userCar.carNumber, userCar.kind, userCar.loaded, userCar.destination);
    }

    Car(std::string reportingMark, int carNumber, std::string kind, bool loaded, std::string destination)
    {
        setup(reportingMark, carNumber, kind, loaded, destination);
    }
    ~Car() {};


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
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;

    input(reportingMark, carNumber, kind, loaded, destination);
    Car *car1 = new Car(reportingMark, carNumber, kind, loaded, destination);
    Car *car2 = new Car(*car1);
    Car *car3 = new Car;

    cout << "\nContents of car1:";
    car1->output();
    cout << "\nContents of car2: ";
    car2->output();
    cout << "\nContents of car3: ";
    car3->output();

    delete car1;
    delete car2;
    delete car3;

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

    Contents of car1:
    reportingMark       SP
    carNumber           34567
    kind                business
    loaded              true
    destination         Salt

    Contents of car2:
    reportingMark       SP
    carNumber           34567
    kind                business
    loaded              true
    destination         Salt

    Contents of car3:
    reportingMark
    carNumber           0
    kind                other
    loaded              false
    destination         NONE

    Process returned 0 (0x0)   execution time : 15.539 s
    Press any key to continue.
*/

