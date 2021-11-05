This proposal layout all the details for our final prject. 

1. Leading Question:
With our flight and airport dataset, we want to find the shortest path between two airports. Then we want to project all the shortest flight paths onto a world map. Our two leading questions will be: "what is the shortest path for any destination?" and "How can we visualize the longest path starting and ending at the same airport using current flight routes on a world map?"

2. Dataset Acquisition and Processing:
The dataset we plan to use is OpenFlights, which is provided in the CS 225 Project Datasets. We simply download this file and push it to our respository. From there each team member will pull and get the datasets on their machine. We will use c++'s built in functions within <fstream> and <iostream>. This is because our data is in the .dat format. Our data looks to be good, no missing or corrupted items. For shortest flight path, we will find the shortest two distances two airports using their longitutde and latitude positions. From here we can graph these flights drawing a straight line between points. 

3. Graph Algorithms:
First we want to figure out what is the shortest path for any destination? We will represent our aiports as nodes in a KD-tree. We will sort them by their physical distances to each other. We will find the shortest path between two points and find that distance. Then, how can we create a visualization of our flights on a world map? For this, we will find an image of a world map. Then we will use a directed graph to visualize the longest path on a different world map.

4. Timeline:
There are multiple tasks to be done. We separated them into different parts. Tasks in the same part can be done concurrently. 
Part 1: Final Project Proposal
Part 2: Data Aquisition, understand the data
Part 3: Data Processing, individual algorithm (maybe)
Part 4: Debug and Testing
Part 5: Data Visualization
Part 6: Presentation Video

For the timeline, we hope to finish most of part 3, maybe get started on part 4 before the thankgiving break. It would be very ideal for us if we finish part 4 by the mid-project checkin. However, it should also be acceptable if we just finish part 3 by the mid-project checkin. By that time, we should still have about a week, which should be enough unless the debug process took an unreasonable amount of time (which usually happens ¯\_(ツ)_/¯ ). If we didn't even finish part 3 by mid-point checkin, we should be very nervous and spend extra amount of time on this project. 
