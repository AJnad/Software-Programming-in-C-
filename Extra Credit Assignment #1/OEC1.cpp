/**
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment OEC1
    This program is similar to D1 in which
    it will read in characteristics of the Cars
    and it will output to the console. However,
    we will keep the data in an array and modify
    it to the program's specifications.
*/

#include <iostream>
#include <fstream>   // for file I/O
#include <cstdlib>   // for exit()
#include <iomanip>
#include <vector>
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
    Car &operator=(const Car & carB);


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

class StringOfCars
{
private:
    vector<Car>members;

public:

    StringOfCars()
    {}

    StringOfCars(const StringOfCars &userString)
    {
        members = userString.members;
    }
    ~StringOfCars() {};

    void push(const Car &obj);
    void pop (Car &obj);
    void output();

};

/************** push ********************
Takes the data at the particular index and
assigns it to the position after its original
position
*/
void StringOfCars::push(const Car &obj)
{
   members.push_back(obj);
}

/************** pop ********************
Takes the data at the particular index and
assigns it to the position before its original
position
*/
void StringOfCars::pop (Car &obj)
{
    obj = members.back();
    members.pop_back();
}

/************** output ********************
prints out to console the position, values of
reportingMark, carNumber, kind, loaded or not,
and destination
*/
void StringOfCars::output()
{
    if(members.size() == 0)
        cout << "NO CAR!\n";
    else
        for(int x = 0; x < members.size(); x++)
            members[x].output();
}
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

/** ******************** Car::operator= ********************
sets the values in the left hand object from the right hand object
*/
Car & Car::operator=(const Car & carB)
{
    setup(carB.reportingMark, carB.carNumber, carB.kind, carB.loaded, carB.destination);

    return * this;
}

bool operator== (const Car &c1, const Car &c2)
{
    if ((c1.reportingMark == c2.reportingMark) && (c1.carNumber == c2.carNumber))
        return true;
    else
        return false;
}

void input (StringOfCars &tempObj);


int main()
{
    cout << "------------------------TEST 1---------------------";
    Car car1("SP", 34567, "business", "true", "Salt Lake City");
    Car car2;
    car2 = car1;
    car2.output();

    cout << "\n------------------------TEST 2---------------------";
    StringOfCars string1;
    input(string1);
    string1.output();


    cout << "\n------------------------TEST 3---------------------";
    Car car3;
    string1.pop(car3);
    cout << "\n**************************Car 3**********************\n";
    car3.output();
    cout << "\n**************************Car 3**********************\n";
    string1.output();

    return 0;
}

/************** input ********************
reads in the data that was given to the
different types of carss
*/
void input (StringOfCars &tempObj)
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
            tempObj.push(temp);
        }
        else
            cout << "ERROR ALERT!!!" << endl;
    }

    inputFile.close();
    fout.close();
}
/*  Execution Results

    ------------------------TEST 1---------------------
    reportingMark       SP
    carNumber           34567
    kind                business
    loaded              true
    destination         Salt Lake City

    ------------------------TEST 2---------------------
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

    ------------------------TEST 3---------------------
    **************************Car 3**********************

    reportingMark       AOK
    carNumber           156
    kind                tender
    loaded              false
    destination         McAlester

    **************************Car 3**********************

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

    Process returned 0 (0x0)   execution time : 0.109 s
    Press any key to continue.

*/
