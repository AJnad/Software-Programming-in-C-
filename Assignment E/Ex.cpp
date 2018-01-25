/**
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment E
    Problem E3
    This program is similar to D1 in which
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

    void setUp(string rMark, int carNum, string carKind, bool isLoaded, string dest);
    virtual void setKind(const string & tempKind);
    void output();
    Car& operator=(const Car & carB);
    friend bool operator==(const Car &carA, const Car &carB);

    Car()
    {
        setUp("", 0, "other", false, "NONE");
    }
    Car(const Car &oldCar)
    {
        setUp(oldCar.reportingMark, oldCar.carNumber, oldCar.kind, oldCar.loaded, oldCar.destination);
        kind = oldCar.kind;
    }
    Car(const string &reportingMark, const int &carNumber, const string &kind, const bool &loaded, const string &destination)
    {
        setUp(reportingMark, carNumber, kind, loaded, destination);
    }
    int getCarNum()
    {
        return carNumber;
    }
    string getRepMark()
    {
        return reportingMark;
    }

    virtual ~Car() {};

};

class FreightCar : public Car
{
public:
    FreightCar()
    {
        setUp("", 0, "other", false, "NONE");
    }
    FreightCar(const FreightCar &oldFreight)
    {
        setUp(oldFreight.reportingMark, oldFreight.carNumber, oldFreight.kind, oldFreight.loaded, oldFreight.destination);
    }
    FreightCar(const string &reportingMark, const int &carNumber, const string &kind, const bool &loaded, const string &destination)
    {
        setUp(reportingMark, carNumber, kind, loaded, destination);
    }
    void setKind(const string & stringKind);
};


class PassengerCar : public Car
{
public:
    PassengerCar()
    {
        setUp("", 0, "other", false, "NONE");
    }
    PassengerCar(const PassengerCar &oldPassenger)
    {
        setUp(oldPassenger.reportingMark, oldPassenger.carNumber, oldPassenger.kind, oldPassenger.loaded, oldPassenger.destination);
    }
    PassengerCar(const string &reportingMark, const int &carNumber, const string &kind, const bool &loaded, const string &destination)
    {
        setUp(reportingMark, carNumber, kind, loaded, destination);
    }
    void setKind(const string & stringKind);

};

//StringOfCars declaration for the Node class
class StringOfCars;

class Node
{
private:
    Node * next;
    Car * data;
    Node()
    {
        next = nullptr;
        data = nullptr;
    }
public:
    friend class StringOfCars;

};

class StringOfCars
{
private:
    Node * head;
    Node * tail;

public:
    StringOfCars()
    {
        head = nullptr;
        tail = nullptr;
    }

    StringOfCars(const StringOfCars & oldStringOfCars)
    {
        Node * currentNodePtr = oldStringOfCars.head;
        head = nullptr;
        tail = nullptr;

        if (oldStringOfCars.head != nullptr)
        {
            while (currentNodePtr != nullptr)
            {
                push(*currentNodePtr->data);
                currentNodePtr = (*currentNodePtr).next;
            }
        }
    }

    ~StringOfCars() {}

    void push(const Car & tempCar);
    void output();
};

//Function Prototypes
void input(StringOfCars & carArray);
void buildCar(string rMark, int carNum, string carKind, bool isLoaded, string dest, StringOfCars & carArray);
void buildFreightCar(string rMark, int carNum, string carKind, bool isLoaded, string dest, StringOfCars & carArray);
void buildPassengerCar(string rMark, int carNum, string carKind, bool isLoaded, string dest, StringOfCars & carArray);

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

/*************************** Car::setUp *****************************
Assigns the data to the member data in an object from the Car class
setUp is a member function of the Car class
*/
void Car::setUp(string rMark, int carNum, string carKind, bool isLoaded, string dest)
{
    reportingMark = rMark;
    carNumber = carNum;
    setKind(carKind);
    loaded = isLoaded;
    destination = dest;
}

/*********************** Kind Car::setKind ***************************
Sets the kind variable for the setUp function
*/
void Car::setKind(const string & stringKind)
{
    if (stringKind == "business")
        kind = "business";
    else if (stringKind == "maintenance")
        kind = "maintenance";
    else kind = "other";
}

/************************* Car::operator= *****************************
Returns the left hand operator by refrence
operator= is an overloaded member function from the Car class
*/
Car & Car::operator=(const Car & carB)
{
    setUp(carB.reportingMark, carB.carNumber, carB.kind, carB.loaded, carB.destination);

    return *this;
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
void FreightCar::setKind(const string & stringKind)
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
void PassengerCar::setKind(const string & stringKind)
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
    Node * currentNodePtr;
    if (head == nullptr)
    {
        cout << "No cars\n";
    }
    else
    {
        currentNodePtr = head;
        int currentCarNumber = 0;
        while (currentNodePtr != nullptr)
        {
            cout << "Car Number " << ++currentCarNumber << endl;
            (*currentNodePtr->data).output();
            currentNodePtr = (*currentNodePtr).next;
        }
    }
}

/*********************** StringOfCars::push ***************************
Adds a car pointer to the list of pointers to cars
Car object accessed through constant refrence from calling function
*/
void StringOfCars::push(const Car & tempCar)
{
    Car* currentCarPtr = new Car(tempCar);
    Node* currentNodePtr = new Node;

    (*currentNodePtr).data = currentCarPtr;

    if (head == nullptr)
    {
        head = currentNodePtr;
        tail = currentNodePtr;
    }
    else
    {
        (*tail).next = currentNodePtr;
        tail = currentNodePtr;
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
