/*
    Ajay Nadhavajhala
    CIS 22B
    Winter 2017
    Assignment A
    Problem A2
    Description of problem:
    A program that carries out string members and exercises
    as given by the instructor.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string1, string2, string3, string4, string5, string6;

    cout << "Please enter a phrase: " << string1;
    getline(cin, string1);
    cout << "\nExercise 1" << endl;
    cout << string1 << endl;

    string2 += string1;
    string2 += " sleepy heads";
    cout << "\nExercise 2" << endl;
    cout << string2 << endl;

    string3 = "bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow";
    cout << "\nExercise 3" << endl;
    cout << string3.find('h') << endl;

    string4.empty();
    string4 += string3;
    cout << "\nExercise 4" << endl;
    cout << string4.replace(string3.find('h'), 1, "J") << endl;

    string5 = string3;
    cout << "\nExercise 5" << endl;
    cout << string5.find_last_of('l') << endl;

    string6 += string3;
    cout << "\nExercise 6" << endl;
    cout << string6.erase(string5.find_last_of('l') + 1, string5.length()-string5.find_last_of('l')) << endl;

    return 0;
}

/*  Execution Results

    Please enter a phrase: Good morning

    Exercise 1
    Good morning

    Exercise 2
    Good morning sleepy heads

    Exercise 3
    20

    Exercise 4
    bellow cello fellow Jello mellow Novello Othello pillow Rollo solo yellow

    Exercise 5
    70

    Exercise 6
    bellow cello fellow hello mellow Novello Othello pillow Rollo solo yell

*/


