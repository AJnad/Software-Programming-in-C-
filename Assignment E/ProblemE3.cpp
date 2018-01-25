/**
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment E
    Problem E3
    This program is similar to E2 in which
    it will read in characteristics of the Cars
    and it will output to the console. However,
    we will keep the data in an array and modify
    it to the program's specifications.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
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

    virtual void setKind(string const_string);
};


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

    virtual void setKind(string const_string);
};

//StringOfCars declaration for the Node class
class StringOfCars;

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
        carCount = 0;
        for (int i = 0; i < userString.carCount; i++)
        {
            push(*userString.ptr[i]);
        }
        for (int x = carCount; x < ARRAY_SIZE; x++)
            ptr[x] = NULL;

    }
    ~StringOfCars()
    {
        for (int i = 0; i < ARRAY_SIZE; i++)
            delete ptr[i];
        delete []ptr;
    }

    void push(const Car &obj);
    void push (const FreightCar &obj);
    void push (const PassengerCar &obj);
    void pop (Car &obj);
    void output();

};

//Function Prototypes
void input(StringOfCars & carArray);

int main()
{
    StringOfCars stringOfCars1;
    input(stringOfCars1);

    StringOfCars stringOfCars2(stringOfCars1);
    stringOfCars2.output();

}

// **********************************************************
// Car Member Functions
// **********************************************************

/*************************** Car::output *****************************
Outputs the member data in a neat format
Output is a member function of the Car class
*/
void Car::output()
{
    cout << "Reporting Mark: " << reportingMark << endl;
    cout << "Car Number : " << carNumber << endl;
    cout << "Kind : " << kind << endl;

//Converts the loaded boolean into a string for output
    string temp;
    if (loaded == true)
        temp = "true";
    else
        temp = "false";

    cout << "Loaded : " << temp << endl;
    cout << "Destination : " << destination << endl;
    cout << endl;

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

/** ******************** Car::operator= ********************
sets the values in the left hand object from the right hand object
*/
Car & Car::operator=(const Car & carB)
{
    setup(carB.reportingMark, carB.carNumber, carB.kind, carB.loaded, carB.destination);

    return * this;
}

/***************************** operator== **************************************
Compares two Car objects to check equivalence (same reportingMark and carNumber
operator== is a overloaded friend function from the Car class
*/
bool operator==(const Car &carA, const Car &carB)
{
    bool temp;
    if (carA.reportingMark == carB.reportingMark && carA.carNumber == carB.carNumber)
        temp = true;
    else
        temp = false;
    return temp;
}

// **********************************************************
// FreightCar Member Functions
// **********************************************************
void FreightCar::setKind(const string stringKind)
{
    if (stringKind == "box")
        kind = "box";
    else if (stringKind == "tank")
        kind = "tank";
    else if (stringKind == "flat")
        kind = "flat";
    else kind = "otherFreight";
}
// **********************************************************
// PassengerCar Member Functions
// **********************************************************
void PassengerCar::setKind(const string stringKind)
{
    if (stringKind == "chair")
        kind = "chair";
    else if (stringKind == "sleeper")
        kind = "sleeper";
    else kind = "otherPassenger";
}

// **********************************************************
// StringOfCars Member Functions
// **********************************************************


/*********************** StringOfCars::output ***************************
Outputs the data from the linked list of pointers to car objects
Prints the data saved in each car object
*/
void StringOfCars::output()
{
    if (carCount <= 0)
        cout << "No car!\n";
    else
        for (int i = 0;i < carCount; i++)
    {
        cout << "position: " << i + 1 << endl;
        ( *ptr[i]).output();
    }
}

/*********************** StringOfCars::push ***************************
Adds a car pointer to the list of pointers to cars
Car object accessed through constant refrence from calling function
*/
void StringOfCars::push(const Car & tempCar)
{
    if (carCount < ARRAY_SIZE)
    {
        Car *p = new Car;
        *p = tempCar;
        ptr[carCount++] = p;
    }
    else
    {
        cerr << "The string of car class is full!\n";
        exit(1);
    }
}

/*********************** FreightCar::push ***************************
Adds a car pointer to the list of pointers to cars
Car object accessed through constant refrence from calling function
*/
void StringOfCars::push(const FreightCar & tempCar)
{
    if (carCount < ARRAY_SIZE)
    {
        FreightCar *p = new FreightCar;
        *p = tempCar;
        ptr[carCount++] = p;
    }
    else
    {
        cerr << "The string of car class is full!\n";
        exit(1);
    }
}

/*********************** FreightCar::push ***************************
Adds a car pointer to the list of pointers to cars
Car object accessed through constant refrence from calling function
*/
void StringOfCars::push(const PassengerCar & tempCar)
{
    if (carCount < ARRAY_SIZE)
    {
        PassengerCar *p = new PassengerCar;
        *p = tempCar;
        ptr[carCount++] = p;
    }
    else
    {
        cerr << "The string of car class is full!\n";
        exit(1);
    }
}



/****************************** input ********************************
Reads in information on the train car from a file
Information saved in temporary car object in function
*/
void input(StringOfCars & carArray)
{
    string type;
    string order;
    string rMark;
    int carNum;
    string carKind;
    bool isLoaded;
    string dest;
    ifstream inputFile;

    inputFile.open("data.txt");

    if (!inputFile)
    {
        cerr << "Error while opening the file. Exiting with code 1" << endl;
        exit(1);

    }

    while (inputFile.peek() != EOF)
    {
        inputFile >> type;
        inputFile >> order;
        inputFile >> rMark;
        inputFile >> carNum;
        inputFile >> carKind;


        //Converts the user inputted true/false string to a boolean value
        string temp;
        inputFile >> temp;
        if (temp == "true")
            isLoaded = true;
        else if (temp == "false")
            isLoaded = false;

        while (inputFile.peek() == ' ')
            inputFile.get();

        getline(inputFile, dest);


        if (type == "Car")
        {
            Car obj = Car(rMark, carNum, carKind, isLoaded, dest);
            carArray.push(obj);
        }
        else if (type == "FreightCar")
        {
            FreightCar obj = FreightCar(rMark, carNum, carKind, isLoaded, dest);
            carArray.push(obj);
        }
        else if (type == "PassengerCar")
        {
            PassengerCar obj = PassengerCar(rMark, carNum, carKind, isLoaded, dest);
            carArray.push(obj);
        }
    }

    inputFile.close();
}
/*  Execution Results

    Car Number 1
    Reporting Mark: CN
    Car Number : 819481
    Kind : maintenance
    Loaded : false
    Destination : NONE

    Car Number 2
    Reporting Mark: SLSF
    Car Number : 46871
    Kind : business
    Loaded : true
    Destination : Memphis

    Car Number 3
    Reporting Mark: AOK
    Car Number : 156
    Kind : other
    Loaded : true
    Destination : McAlester

    Car Number 4
    Reporting Mark: MKT
    Car Number : 123456
    Kind : tank
    Loaded : false
    Destination : Fort Worth

    Car Number 5
    Reporting Mark: MP
    Car Number : 98765
    Kind : box
    Loaded : true
    Destination : Saint Louis

    Car Number 6
    Reporting Mark: SP
    Car Number : 567890
    Kind : flat
    Loaded : true
    Destination : Chicago

    Car Number 7
    Reporting Mark: GMO
    Car Number : 7878
    Kind : otherFreight
    Loaded : true
    Destination : Mobile

    Car Number 8
    Reporting Mark: KCS
    Car Number : 7893
    Kind : chair
    Loaded : true
    Destination : Kansas City

    Car Number 9
    Reporting Mark: PAPX
    Car Number : 145
    Kind : sleeper
    Loaded : true
    Destination : Tucson

    Car Number 10
    Reporting Mark: GN
    Car Number : 744
    Kind : otherPassenger
    Loaded : false
    Destination : NONE


    Process returned 0 (0x0)   execution time : 0.066 s
    Press any key to continue.
*/
