# Letey_CSCI2270_FinalProject
John Letey's Final Project for CSCI 2270 Final Project

-----------------------------------------------------------------------------------------------------------

**Project Proposal**

One of the things that Google has mastered is being able to create services that use the data that they've gathered. One prominent example is using GPS data in Google Maps to give the most efficient route. The most efficient route from a starting location to a destination includes both the length of the road - you want to minimize distance - and the time spent on each road. For this project, I will be implementing a shortest-path algorithm, very similar to Google maps, except that I will be focusing on only the time variable. In other words, I will use a map (stored in a graph) where roads are weighted with the average time spent on that road. As expected, roads will be the edges and cities will be the vertices. 

In order to implement this algorithm, I will be using Dijkstra's algorithm on a weighted graph. The graph will be stored in a txt file, and then I will output the optimal route in another text file. I will convert this into the structure-combo shown below. As far as other data structures go, Dijkstra's algorithm will also use a queue to calculate the shortest path. 

![settings window](https://github.com/JohnLetey/Letey_CSCI2270_FinalProject/blob/master/datastruct.png?raw=true)

My graph will be implemented using a combination of two structures. One structure will store information for the vertices, which are the type 1 structures, or the red structures. Type-1 structures store the name of the cities and an array of type 2 structures. Type 2 structures (yellow) store the information for the edges, such as the name of the road, average time spent on that road, and which city (type 1 structure) the road connects to. 
