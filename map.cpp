// Name : John Letey
// Student I.D. : 107219241
// Instructor : Austin Holler
// Teaching Assistant : Abhijit Suresh

#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <istream>
#include <unistd.h>
#include "finalproject.hpp"
using namespace std;

// main program
int main()
{
    state map;
    string choice;
    string start, end;
    string name;
    string roadName, direction, city1, city2;
    int time;
    int num;

    // Create map
    map.create("map.txt");
    // Print the state name
    cout << "Do you want to know the name of the state that you are in? (y/n) ";
    cin >> choice;
    for (int i = 0; i < choice.size(); i++)
    {
        if (choice[i] == 'y' || choice[i] == 'Y')
        {
            cout << "You're in the state of " << map.getStateName() << ". " << map.getStateGreeting() << endl;
            break;
        }
    }
    cin.ignore();

    do
    {
        cout << "==========Main Menu==========" << endl;
        cout << "1. Add a city" << endl;
        cout << "2. Add a connection" << endl;
        cout << "3. Print the cities" << endl;
        cout << "4. Calculate the shortest path" << endl;
        cout << "5. Quit" << endl;
        cin >> num;
        cin.ignore();
        switch (num)
        {
        case 1:
        {
            cout << "What is the name of your city? ";
            getline(cin, name);
            map.addCity(name);
            cout << "I would suggest adding a connection to this city" << endl;
            map.fixFileAddCity(name);
        }
            break;
        case 2:
        {
            cout << "What is the name of the road? ";
            getline(cin, roadName);
            cout << "What is the direction that you are going in? ";
            getline(cin, direction);
            cout << "What is the first city? ";
            getline(cin, city1);
            cout << "What is the second city? ";
            getline(cin, city2);
            cout << "What is the weight? ";
            cin >> time;
            map.addRoad(roadName, direction, city1, city2, time);
            map.fixFileAddRoad(roadName, direction, city1, city2, time);
        }
            break;
        case 3:
        {
            map.printCities();
        }
            break;
        case 4:
        {
            // Print cities
            map.printCities();
            // Get starting and ending point
            cout << "Please choose your starting location: ";
            getline(cin, start);
            cout << "Please choose your ending location: ";
            getline(cin, end);
            // Calculate shortest path
            map.shortestPath(start, end);
        }   
            break;
        case 5:
        {
            cout << "Goodbye!" << endl;
        } 
            break;
        }
    } while (num != 5);

    return 0;
}
