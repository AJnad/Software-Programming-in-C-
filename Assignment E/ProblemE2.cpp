/**
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment E
    Problem E2
    This program is similar to D1 in which
    it will read in characteristics of the Cars
    and it will output to the console. However,
    we will keep the data in an array and modify
    it to the program's specifications. We will be
    pushing and popping certain objects.
*/

#include <iostream>
#include <fstream>   // for file I/O
#include <cstdlib>   // for exit()
#include <iomanip>
using namespace std;

class Car
{
protected:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;

public:

    Car()
    {
        setup(reportingMark = "", carNumber = 0, kind = "other", loaded = false, destination ="NONE");
    }

    Car (const Car &userCar)
    {
        setup(userCar.reportingMark, userCar.carNumber, userCar.kind, userCar.loaded, userCar.destination);
    }

    Car(string reportingMark, int carNumber, string kind, bool loaded, string destination)
    {
        setup(reportingMark, carNumber, kind, loaded, destination);
    }
    void setup(string, int, string, bool, string);

    virtual void setKind(string const_string);

    void output();
    friend bool operator== (const Car &c1, const Car &c2);
    Car &operator=(const Car & carB);

    virtual ~Car() {};

};

class FreightCar : public Car
{
public:
    FreightCar()
    {
        reportingMark = "";
        carNumber     = 0;
        kind          = "other";
        loaded        = false;
        destination   = "NONE";
    }
    FreightCar(const FreightCar &obj)
    {
        reportingMark = obj.reportingMark;
        carNumber     = obj.carNumber;
        kind          = obj.kind;
        loaded        = obj.loaded;
        destination   = obj.destination;
    }
    FreightCar(string reportingMark, int carNumber, string kind, bool loaded, string destination)
    {
        setup(reportingMark, carNumber, kind, loaded, destination);
    }
    ~FreightCar() {};

    void setKind(string const_string);
};

/** ******************** setKind ********************
    set the correct Kind to the FreightCar class
*/
void FreightCar::setKind(string const_string)
{
    if (const_string == "box")
        kind = "box";
    else if (const_string == "tank")
        kind = "tank";
    else if (const_string == "flat")
        kind = "flat";
    else
        kind = "otherFreight";
}

class PassengerCar : public Car
{
public:
    PassengerCar()
    {
        reportingMark = "";
        carNumber     = 0;
        kind          = "other";
        loaded        = false;
        destination   = "NONE";
    }
    PassengerCar(const PassengerCar &obj)
    {
        reportingMark = obj.reportingMark;
        carNumber      = obj.carNumber;
        kind            = obj.kind;
        loaded            = obj.loaded;
        destination     = obj.destination;
    }
    PassengerCar(string reportingMark, int carNumber, string kind, bool loaded, string destination)
    {
        setup(reportingMark, carNumber, kind, loaded, destination);
    }
    ~PassengerCar() {};

    void setKind(string const_string);
};

/** ******************** setKind ********************
 set the correct Kind to the PassengerCar class
 */
void PassengerCar::setKind(string const_string)
{
    if (const_string == "chair")
        kind = "chair";
    else if (const_string == "sleeper")
        kind = "sleeper";
    else
        kind = "otherPassenger";
}



class StringOfCars
{
private:
    Car **ptr;
    static const int ARRAY_SIZE = 10;
    int carCount;

public:

    StringOfCars()
    {
        ptr = new Car*[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            ptr[i] = NULL;
        }
        carCount = 0;
    }

    StringOfCars(const StringOfCars &userString)
    {
        ptr = new Car*[ARRAY_SIZE];
        for (int i = 0; i < userString.carCount; i++)
        {
            push(*userString.ptr[i]);
        }

    }
    ~StringOfCars()
    {
        for (int i = 0; i < ARRAY_SIZE; i++)
            delete ptr[i];
        delete []ptr;
    }

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
    if(carCount < ARRAY_SIZE)
    {
        Car *p = new Car;
        *p = obj;
        ptr[carCount++] = p;
    }
    else
        cerr << "The string of cars is full";
}

/************** pop ********************
Takes the data at the particular index and
assigns it to the position before its original
position
*/
void StringOfCars::pop (Car &obj)
{
    if(carCount > 0)
    {
        Car empty;
        obj = *ptr[--carCount];
        *ptr[carCount] = empty;
        ptr[carCount] = NULL;
    }
    else
        cout << "the array is empty\n";
}

/************** output ********************
prints out to console the position, values of
reportingMark, carNumber, kind, loaded or not,
and destination
*/
void StringOfCars::output()
{
    if (carCount <= 0)
        cout << "\nNO CAR!\n";
    else
    {
        for(int i = 0; i < carCount; i++)
        {
            cout << "\nposition: " << i + 1;
            (*ptr[i]).output();
        }
    }

}
/*************** setup ********************
takes in the user input and sets that data to
the class variables in Car
*/
void Car::setup (string rep, int cnum, string kd, bool load, string dest)
{
    reportingMark = rep;
    carNumber = cnum;
    (*this).setKind(kd);
    loaded = load;
    destination = dest;
}

/** ******************* setKind *******************
   set the correct Kind to the Car class
*/
void Car::setKind(string const_string)
{
    if (const_string == "business")
        kind = "business";
    else if (const_string == "maintenance")
        kind = "maintenance";
    else
        kind = "other";
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
    cout << "------------------------Car---------------------";
    Car car1("SLSF", 46871, "wrecker", "true", "Memphis");
    car1.output();

    cout << "\n------------------------Freight Car---------------------";
    FreightCar freightCar1("MP", 98765, "gondola", "true", "Saint Louis");
    freightCar1.output();


    cout << "\n------------------------Passenger Car---------------------";
    PassengerCar passengerCar1("PAPX", 145, "combine", true, "Tucson");
    passengerCar1.output();
    return 0;
}

/************* input ********************
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
    position: 1
    reportingMark       CN
    carNumber           819481
    kind                maintenance
    loaded              false
    destination         NONE

    position: 2
    reportingMark       SLSF
    carNumber           46871
    kind                business
    loaded              false
    destination         Memphis

    position: 3
    reportingMark       AOK
    carNumber           156
    kind                tender
    loaded              false
    destination         McAlester

    ------------------------TEST 3---------------------
    reportingMark       AOK
    carNumber           156
    kind                tender
    loaded              false
    destination         McAlester

    position: 1
    reportingMark       CN
    carNumber           819481
    kind                maintenance
    loaded              false
    destination         NONE

    position: 2
    reportingMark       SLSF
    carNumber           46871
    kind                business
    loaded              false
    destination         Memphis

    Process returned 0 (0x0)   execution time : 0.063 s
    Press any key to continue.
*/
