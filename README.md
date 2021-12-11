This is the README file for this git (in progress).

(1) The location of all major code, data, and results:

The code is located on this github. The code consists of a `graph class` which is built using the `airport class` and `route class`; a `BFS class`
which uses a `graph object` to find the shortest path between two airports when the routes are unweighted; a `dijkstras class` which which uses a `graph object` to 
find the shortest path between two airports when the routes are weighted; and a `visualizer class` which uses a vector of `airport objects` to visualize
the path on a world map. The dataset we used is also stored on this github.  Normally datasets aren't stored on github with the code, but since the data is 
only around a single megabyte in size, we thought it would be fine. Some example visualizations are also here along with files containing the name of each 
airport in order of the path. Each visualization draws a line between each airport in order of path on a world map. The starting airport is orange, the 
intermediary airports are purple, and the final airport is pink. Some of the exampls are all the routes in a given country, fictitious paths of routes, and 
actual paths of routes.  

(2) Full instructions on how to build and run your executable, including how to define the input data and output location for each method.

To run each algorithm, you first need to build a graph object which takes in two files paths (one containg route data and another containing airport data)
as string inputs to the constructor. You then pass this object into the constructor for the BFS and Dijkstra's algorithms and call their respective
find path functions which returns a vector of Airport objects. This vector can then be passed into a static method in the visualizer class along with
the name of the png file of a world map, its dimensions, and the desired name of the outputted file. The visualizer method also outputs a text file containing
the names of the airports in order of path. It is also important to note that the input world map file must be an equirectangular projection, such a map can be 
found on NASA's website. The output files are outputted to the same directory as the source code. An example showing off the algorithms and visualization 
can be complied by calling `make main` in the command line followed by `main`. This complies and executes `main.cpp`. 

(3) Full instructions how to build and run your test suite, including a general description on what tests you have created

The test suite can be complied by calling `make test` in the command line followed by `test`. This compiles and executes the test files `.cpp`, `.cpp`, and `.cpp`.
The tests for the algorithms make sure that the outputted paths are indeed the shortest paths between two airports when the routes are weighted and unweighted. We
checked the route file and googled flights to verify that the paths are correct. We also made tests for when trying to find paths between airports that don't exist in 
the dataset and when there are no paths between two airports.
