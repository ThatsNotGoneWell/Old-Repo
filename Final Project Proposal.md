This proposal layout all the details for our final prject. 

1. Leading Question:
With our flight and airport dataset, we want to find the shortest path between two airports. Then we want to project all the shortest flight paths onto a world map. Our two leading questions will be: "what is the shortest path (with each path being a flight route) between any two airports without considering distance (i.e. an unweighted graph)?", "How can we visualize these paths by projecting the routes onto a world map?", and "what is the shortest path between any two airports with distance as a consideration)". 
 
2. Dataset Acquisition and Processing:
The dataset we plan to use is OpenFlights, which is provided in the CS 225 Project Datasets. Specifically, we will be using the airports and routes datasets, which can be found here https://openflights.org/data.html. From there each team member will pull and get the datasets on their machine. We will use c++'s built in functions within <fstream> and <iostream>. This is because our data is in the .dat format. There are a handful of data points with some missing values or that are irregularly formatted. SInce these points represent a very small minority, we will simply ignore these points. We will find the distances between two airports using their longitutde and latitude. 

3. Graph Algorithms:
First we want to figure out what is the shortest path for any destination. To find the shortest path, we will represent our aiports as nodes in a graph and use a Breadth-first-search while keeping track of the length of each path until we find the destination airport. We believe the algorithm to be able to run with big-O O(g^d) where g is the number of adjacent nodes for any given node and d is the length of the shortest path between the two desired nodes. However, one downside of BFS is that it only returns the shortest path of an unweighted graph. Thus, for the second algorithm, we have picked Dijkstra's algorithm. This algorithm will find the shortest route in real life because it returns the shortest path of a weighted graph. Once we calculate all the cycles and find the shortest one, we can visualize it on any map PNG using the coordinates from the airport dataset and the PNG classes we've used all semester. For the visualization we will use an equirectangular projection to convert the longitude and latitude of each airport  into an x, y coordinate pair in 2d space. We will then use the PNG and HSLAPixel classes  we have used in class to draw the flight paths on an equirectangular projection png image.

4. Timeline:
There are multiple tasks to be done. We separated them into different parts. Tasks in the same part can be done concurrently. 
Part 1: Final Project Proposal
Part 2: Data Aquisition, understand the data
Part 3: Data Processing, individual algorithm (maybe)
Part 4: Debug and Testing
Part 5: Data Visualization
Part 6: Presentation Video

For the timeline, we hope to finish most of part 3, maybe get started on part 4 before the thankgiving break. It would be very ideal for us if we finish part 4 by the mid-project checkin. However, it should also be acceptable if we just finish part 3 by the mid-project checkin. By that time, we should still have about a week, which should be enough unless the debug process took an unreasonable amount of time (which usually happens ¯\_(ツ)_/¯ ). If we didn't even finish part 3 by mid-point checkin, we should be very nervous and spend extra amount of time on this project. 
