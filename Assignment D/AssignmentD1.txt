/**
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment D
    Problem D1
    This program reads in a file that contains
    data about a car. There are three different
    cars that have unique characteristics in which
    this program will output to the console.
*/

#include <iostream>
#include <fstream>   // for file I/O
#include <cstdlib>   // for exit()
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
    friend bool operator== (const Car &c1, const Car &c2);

    Car()
    {
        setup(reportingMark = "", carNumber = 0, kind = "other", loaded = false, destination ="NONE");
    }

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

bool operator== (const Car &c1, const Car &c2)
{
    if ((c1.reportingMark == c2.reportingMark) && (c1.carNumber == c2.carNumber))
        return true;
    else
        return false;
}

void input ();


int main()
{
    input();
    return 0;
}

/************** input ********************
reads in the text file that contains the data
about the different types of cars
*/
void input ()
{
    string carType;

    string load;
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;

    ofstream fout;
    std::ifstream inputFile("D1.txt");


    if (inputFile.fail())
    {
        cout << "Input file failed to open.\n";
        exit(-1);
    }

    fout.open("outfile.txt");
    if (fout.fail())
    {
        cout << "Output file failed to open.\n";
        exit(-1);
    }

    while(inputFile.peek() != EOF)
    {
        inputFile >> carType;
        inputFile >> reportingMark;
        inputFile >> carNumber;
        inputFile >> kind;
        inputFile >> destination;

        if (load == "true")
            loaded = true;
        else
            loaded = false;

        while(inputFile.peek() == ' ')
            inputFile.get();
        getline(inputFile, destination);

        if (carType == "Car")
        {
            Car temp(reportingMark, carNumber, kind, loaded, destination);
            temp.output();
        }
        else
            cout << "ERROR ALERT!!!" << endl;

    }

    inputFile.close();
    fout.close();
}
/*  Execution Results

    reportingMark       CN
    carNumber           819481
    kind                maintenance
    loaded              false
    destination         NONE

    reportingMark       SLSF
    carNumber           46871
    kind                business
    loaded              false
    destination         Memphis

    reportingMark       AOK
    carNumber           156
    kind                tender
    loaded              false
    destination         McAlester

    Process returned 0 (0x0)   execution time : 0.024 s
    Press any key to continue.
*/
