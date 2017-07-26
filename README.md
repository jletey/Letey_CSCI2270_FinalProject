# Letey_CSCI2270_FinalProject
John Letey's Final Project for CSCI 2270 Final Project

-----------------------------------------------------------------------------------------------------------

**Project Proposal**

One of the things that Google has mastered is being able to create services that use the data that they've gathered. One prominent example is using GPS data in Google Maps to give the most efficient route. The most efficient route from a starting location to a destination includes both the length of the road - you want to minimize distance - and the time spent on each road. For this project, I will be implementing a shortest-path algorithm, very similar to Google maps, except that I will be focusing on only the time variable. In other words, I will use a map (stored in a graph) where roads are weighted with the average time spent on that road. As expected, roads will be the edges and cities will be the vertices. 

In order to implement this algorithm, I will be using Dijkstra's algorithm on a weighted graph. The graph will be stored in a txt file, and then I will output the optimal route in another text file. I will convert this into the structure-combo shown below. As far as other data structures go, Dijkstra's algorithm will also use a queue to calculate the shortest path. 

![settings window](https://github.com/JohnLetey/Letey_CSCI2270_FinalProject/blob/master/datastruct.png?raw=true)

My graph will be implemented using a combination of two structures. One structure will store information for the vertices, which are the type 1 structures, or the red structures. Type-1 structures store the name of the cities and an array of type 2 structures. Type 2 structures (yellow) store the information for the edges, such as the name of the road, average time spent on that road, and which city (type 1 structure) the road connects to. 

-----------------------------------------------------------------------------------------------------------

**Summary**

As stated in my project proposal, I implemented an all-pairs-shortest-path (APSP) algorithm. The user will be able to input any start and end location, and my algorithm will calculate the path of least time. As expected, I stored my map in a graph with roads represented by edges and cities represented by vertices. I did not implement a traditional APSP algorithm, which would minimize distance; instead, the weights on the edges stored the average time spent on each road. My algorithm (a modification of Dijkstra's algorithm) then calculates the "fastest" path between the start and end locations.

To achieve the program interface I wanted, I used a mix of two structures to create my graph class.

![settings window](https://github.com/JohnLetey/Letey_CSCI2270_FinalProject/blob/master/datastruct.png?raw=true)

My graph will be implemented using a combination of two structures. One structure will store information for the vertices, which are the type 1 structures, or the red structures. Type-1 structures store the name of the cities and an array of type 2 structures. Type 2 structures (yellow) store the information for the edges, such as the name of the road, average time spent on that road, and which city (type 1 structure) the road connects to.

My implementation of Dijkstra's algorithm is quite standard and follows the implementation in Austin's slides. Dijkstra's algorithm is a dynamic programming algorithm, that calculates the shortest path from the start node to each node in the graph. The reason why it calculates the shortest path for each nodes is because the shortest path from the start (S) to finish (F) might include the shortest path from S to some other node N. My implementation of Dijkstra's algorithm uses a standard library vector to make these calculations.

For my other data structures, I implemented my own queue to read in the map from the text file it is stored in (see more info on this in the Interface Instructions section). I also used a two-dimensional array to illustrate the shortest path after it was calculated. 

-----------------------------------------------------------------------------------------------------------

**Interface Instructions**

My program reads in from a file called "map.txt". That file contains cities for one state, contained in one column. First comes information on the state (such as the state name), then comes the cities in the state. After that, the text file list the direction, name, connecting cities, and average time of each road I include in my map.

Wow. That's a bit to digest. Here's what my "built-in" txt file looks like:

![settings window](https://github.com/JohnLetey/Letey_CSCI2270_FinalProject/blob/master/map.png?raw=true)

I've included the built-in "map.txt" file for you to test with, but feel free to change up the map cities (just as long as you follow the formatting above).

In order to find the shortest path, run the file "map.cpp." You will be asked to enter your starting location and destination. If you want to change the map that is used, unfortunately, you will have to go into "map.txt" and manually edit the data that my program uses.

I implemented this project in a C++ editor called Sublime, but it's meant to be run on any C++ running terminal. I implemented everything I needed for this project, without third-party libraries or programs, so there are no dependencies you need to worry about.

-----------------------------------------------------------------------------------------------------------

**Improvements**

One of the things I would like to implement to expand my project is to allow for multiple states in the map, because so far, I've only set it up to include one state (Colorado, in the case of the built-in map). In addition to that, I would like my program to support intercity travel (such as going from Starbucks to Rio Grande Restaurant in Boulder), which is actually much more useful than what I've implemented (interstate travel). I would also like to have the user be able to add or remove cities and connections, and my program would automatically change "map.txt" and change the data to include that.
