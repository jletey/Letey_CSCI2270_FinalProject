// Name : John Letey
// Student I.D. : 107219241
// Instructor : Austin Holler
// Teaching Assistant : Abhijit Suresh

using namespace std; 

struct city;

struct road
{
    string name;
    int weight;
    string direction;
    city *adjCity;

    road(){};

    road(string in_name, int in_weight)
    {
        name = in_name;
        weight = in_weight;
    }
};

struct city
{
    string name;
    bool visited;
    int distance;
    city *previous;
    vector<road> roads;

    city(){};

    city(string in_name)
    {
        name = in_name;
    }
};

class state
{
public:
    state();
    ~state();
    void create(string filename);
    void addCity(string city_name);
    void addRoad(string road_name, string direction, string city1_name, string city2_name, int weight);
    void fixFileAddCity(string name);
    void fixFileAddRoad(string name, string direction, string city1, string city2, int weight);
    string getStateName();
    string getStateGreeting();
    void printCities();
    void shortestPath(string starting, string destination);
private:
    vector<city> cities;
    int numberOfCities;
    string stateName;
    string stateGreeting;
};

class Queue
{
public:
    Queue(int qs);
    void enqueue(string s);
    string dequeue();
    bool isFull();
    bool isEmpty();
private:
    int queueSize;
    string* arrayQueue;
    int queueHead;
    int queueTail;
    int queueCount;
};