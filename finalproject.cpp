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

// state class implementation

state::state()
{

}

state::~state()
{

}

void state::create(string filename)
{
    ifstream fin(filename);
    string name, name2, name3, greeting, changeToInt, direction;
    int time;

    // Get the number of cities
    getline(fin, changeToInt);
    numberOfCities = stoi(changeToInt);
    // Get state name
    getline(fin, name);
    stateName = name;
    // Get state greeting
    getline(fin, greeting);
    stateGreeting = greeting;
    // Get the cities names
    int i = 0;
    while (i < numberOfCities)
    {
        getline(fin, name);
        addCity(name);
        i++;
    }
    // Get the roads
    while (!fin.eof())
    {
	    getline(fin, direction, '-');
        getline(fin, name, '-');
        getline(fin, name2, '-');
        getline(fin, name3, '-');
        getline(fin, changeToInt);
        time = stoi(changeToInt);
        addRoad(name, direction, name2, name3, time);
    }

    fin.close();
}

void state::addCity(string city_name)
{
    bool found = false;
    for (int i = 0; i < cities.size(); i++)
    {
        if (cities[i].name == city_name)
        {
            found = true;
        }
    }
    if (found == false)
    {
        city new_city(city_name);
        new_city.distance = 0;
        new_city.visited = false;
        new_city.previous = nullptr;
        cities.push_back(new_city);
    }
}

void state::addRoad(string road_name, string direction, string city1_name, string city2_name, int weight)
{
    for (int i = 0; i < cities.size(); i++)
    {
        if (cities[i].name == city1_name)
        {
            for(int j = 0; j < cities.size(); j++)
            {
                if (cities[j].name == city2_name && i != j)
                {
                    road new_road(road_name, weight);
                    new_road.adjCity = &cities[j];
		            new_road.direction = direction;
                    cities[i].roads.push_back(new_road);
                }
            }
        }
    }
}

void state::fixFileAddCity(string name)
{
    vector<string> lines;
    string line;
    ifstream fin("map.txt");

    while (!fin.eof())
    {
        getline(fin, line);
        lines.push_back(line);
    }
    fin.close();

    ofstream fout("map.txt");

    numberOfCities++;
    for (int i = 0; i < lines.size(); i++)
    {
        if (i == 0)
        {
            fout << numberOfCities << endl;
        }
        else
        {
            if (i == 3 + (numberOfCities - 1))
            {
                fout << name << endl;
            }
            fout << lines[i] << endl;
        }
    }
    fout.close();
}

void state::fixFileAddRoad(string name, string direction, string city1, string city2, int weight)
{
    vector<string> lines;
    string line;
    ifstream fin("map.txt");

    while (!fin.eof())
    {
        getline(fin, line);
        lines.push_back(line);
    }
    lines.push_back(direction + "-" + name + "-" + city1 + "-" + city2 + "-" + static_cast<ostringstream*>( &(ostringstream() << weight) )->str());
    fin.close();

    ofstream fout("map.txt");

    for (int i = 0; i < lines.size(); i++)
    {
        fout << lines[i] << endl;
    }
}

string state::getStateName()
{
    return stateName;
}

string state::getStateGreeting()
{
    return stateGreeting;
}

void state::printCities()
{
    if (cities.size() == 0)
    {
        cout << "The graph is empty" << endl;
    }
    else
    {
        cout << "Below are the cities contained in the map" << endl;
        for (int i = 0; i < cities.size(); i++)
        {
    	cout << i + 1 << " : " << cities[i].name << endl;
        }
        cout << "Note: When prompted, please enter in the actual names of the cities, not the numbers. Thanks!" << endl;
    }
}

void state::shortestPath(string starting, string destination)
{
    city * start = nullptr;
    city * ending = nullptr;
    Queue directions(500);
    ofstream fin("directions.txt");
    //search routine to find starting and destination
    for (int i = 0; i < cities.size(); i++) 
    {
        cities[i].visited = false;
        cities[i].distance = INT_MAX;
        cities[i].previous = nullptr;
        if (cities[i].name == starting) 
        {
            start = &cities[i];
        }
        if (cities[i].name == destination)
        {
            ending = &cities[i];
        }
    }
    if (start != nullptr && ending != nullptr && starting == destination)
    {
        cout << "You're at your destination!" << endl;
        cout << "Estimated travel time is 0 minutes" << endl;
	    directions.enqueue("You're at your destination!");
	    directions.enqueue("Estimated travel time is 0 minutes");
    }
    if (start != nullptr && ending != nullptr && starting != destination)
    {
        start->visited = true;
        start->distance = 0;
        vector<city *> solved;
        vector<city *> path;
        solved.push_back(start);
        road * av;
        city * u;
        city * minCity;
        city * prev;
        while (ending->visited == false) 
        {
            int minDistance = INT_MAX;
            for (int i = 0; i < solved.size(); i++) 
            {
                u = solved[i];
                for (int j = 0; j < u->roads.size(); j++) 
                {
                    av = &solved[i]->roads[j];
                    if (av->adjCity->visited == false) 
                    {
                        int dist = u->distance + av->weight;
                        if (dist < minDistance) 
                        {
                            minDistance = dist;
                            minCity = av->adjCity;
                            prev = u;
                        }
                    }
                }
            }
            solved.push_back(minCity);
            minCity->distance = minDistance;
            minCity->previous = prev;
            minCity->visited = true;
        }

        cout << "Directions from " << starting << " to " << destination << endl;
	    directions.enqueue("Directions from " + starting + " to " + destination);
        city * vert = ending;
        while (vert != nullptr) 
        {
            path.push_back(vert);
            vert = vert->previous;
        }
        for (int i = path.size() - 1; i > 0; i--)
        {
	        for (int j = 0; j < path[i]->roads.size(); j++)
	        {
		        if (path[i]->roads[j].adjCity->name == path[i - 1]->name)
		        {
		            if (path[i]->roads[j].direction == "")
		            {
			            cout << "Go on " << path[i]->roads[j].name << " from " << path[i]->name << " to arrive at " << path[i - 1]->name << endl;
	    		        directions.enqueue("Go on " + path[i]->roads[j].name + " from " + path[i]->name + " to arrive at " + path[i - 1]->name);
		            }
		            else
		            {
			            cout << "Go " << path[i]->roads[j].direction << " on " << path[i]->roads[j].name << " from " << path[i]->name << " to arrive at " << path[i - 1]->name << endl;
	    		        directions.enqueue("Go " + path[i]->roads[j].direction + " on " + path[i]->roads[j].name + " from " + path[i]->name + " to arrive at " + path[i - 1]->name);
		            }
	            }
	        }
        }
        cout << "Estimated travel time is " << solved[solved.size() - 1]->distance << " minute(s)" << endl;
    	directions.enqueue("Estimated travel time is " + static_cast<ostringstream*>( &(ostringstream() << solved[solved.size() - 1]->distance) )->str() + " minute(s)");
        cout << "Note that the directions are also in 'directions.txt'" << endl;
    }
    if (start == nullptr && ending == nullptr)
    {
        cout << starting << " and " << destination << " are not in the map!" << endl;
    }
    else
    {
        if (start == nullptr)
        {
            cout << starting << " is not in the map!" << endl;
        }
        if (ending == nullptr)
        {
            cout << destination << " is not in the map!" << endl;
        }
    }

    if (!directions.isEmpty())
    {
        while (!directions.isEmpty())
	    {
	       fin << directions.dequeue() << endl;
	    }
    }
}

// queue class implementation

Queue::Queue(int qs) 
{
    queueSize = qs;
    arrayQueue = new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}

void Queue::enqueue(string s)
{
    arrayQueue[queueTail] = s;
    queueTail++;
    queueCount++;
}

string Queue::dequeue()
{
    queueCount--;
    string word = arrayQueue[queueHead];
    queueHead++;
    return word;
}

bool Queue::isFull()
{
    if (queueCount == queueSize)
    {
        return true;
    }
    return false;
}

bool Queue::isEmpty()
{
    if (queueCount == 0)
    {
        return true;
    }
    return false;
}