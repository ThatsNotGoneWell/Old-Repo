This proposal layout all the details for our final prject. 

1. Leading Question:
With our flight and airport dataset, we want to find the shortest path between two airports. Then we want to project all the shortest flight paths onto a world map. Our two leading questions will be: "what is the shortest path (with each path being a flight route) between any two airports?" and "How can we visualize the longest cyclic path of current flight routes on a world map?". To find  the shortest path, we will organize the data into a graph and use a BFS while keeping track of the length of each path until we find the destination airport. To find the longest cyclic path, we will be using the algorithm described in this paper by Dondald Johnson https://www.cs.tufts.edu/comp/150GA/homeworks/hw1/Johnson%2075.PDF. This algorithm finds all the cyclic paths, but we can then simply find the longest path from the outputted set of paths. 

2. Dataset Acquisition and Processing:
The dataset we plan to use is OpenFlights, which is provided in the CS 225 Project Datasets. Specifically, we will be using the airports and routes datasets. From there each team member will pull and get the datasets on their machine. We will use c++'s built in functions within <fstream> and <iostream>. This is because our data is in the .dat format. Our data looks to be good, no missing or corrupted items. For shortest flight path, we will find the shortest two distances two airports using their longitutde and latitude positions. For other datasets wtih similar formats, if we encounter corrupted or poorly fomratted data entries, we will simply ignore that entry. From here we can graph these flights drawing a straight line between points. 

3. Graph Algorithms:
First we want to figure out what is the shortest path for any destination? We will represent our aiports as nodes in a graph and use a Breadth-first-search. We believe the algorithm to be able to run with big-O O(g^d) where g is the number of adjacent nodes for any given node and d is the length of the shortest path between the two desired nodes. Then, how can we create a visualization of our flights on a world map? The algorithm proposed by Donaldson has big-O of O((n + e)(c + 1)) where n is the total number of nodes, e is the total number of edges, and c is the number of cycles in the graph. Once we calculate all the cycles and find the longest one, we can visualize it on any map  PNG using the coordinates from the airport dataset and the PNG classes we've used all semester.

4. Timeline:
There are multiple tasks to be done. We separated them into different parts. Tasks in the same part can be done concurrently. 
Part 1: Final Project Proposal
Part 2: Data Aquisition, understand the data
Part 3: Data Processing, individual algorithm (maybe)
Part 4: Debug and Testing
Part 5: Data Visualization
Part 6: Presentation Video

For the timeline, we hope to finish most of part 3, maybe get started on part 4 before the thankgiving break. It would be very ideal for us if we finish part 4 by the mid-project checkin. However, it should also be acceptable if we just finish part 3 by the mid-project checkin. By that time, we should still have about a week, which should be enough unless the debug process took an unreasonable amount of time (which usually happens ¯\_(ツ)_/¯ ). If we didn't even finish part 3 by mid-point checkin, we should be very nervous and spend extra amount of time on this project. 
