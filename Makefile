EXENAME = main
OBJS = main.o graph.o PNG.o HSLAPixel.o lodepng.o BFS.o dijkstra.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -lc++abi -lm -lstdc++

# Custom Clang version enforcement logic:
# ccred=$(shell echo -e "\033[0;31m")
# ccyellow=$(shell echo -e "\033[0;33m")
# ccend=$(shell echo -e "\033[0m")

# IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
# IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
# ifneq ($(strip $(IS_EWS)),)
# ifeq ($(strip $(IS_CORRECT_CLANG)),)
# CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
# endif
# else
# ifneq ($(strip $(SKIP_EWS_CHECK)),True)
# CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
# endif
# endif

# .PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp graph.h cs225/PNG.h cs225/HSLAPixel.h BFS.h
	$(CXX) $(CXXFLAGS) main.cpp

graph.o : graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp

test: output_msg catchmain.o visualizer_tests.o PNG.o HSLAPixel.o lodepng.o graph.o BFS_test.o BFS.o dijkstra_test.o dijkstra.o
	$(LD) catchmain.o visualizer_tests.o PNG.o HSLAPixel.o lodepng.o graph.o BFS_test.o BFS.o dijkstra_test.o dijkstra.o $(LDFLAGS) -o test

catchmain.o : cs225/catch/catchmain.cpp cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

visualizer_tests.o : visualizer_tests.cpp cs225/catch/catch.hpp graph.cpp graph.h visualizer.h
	$(CXX) $(CXXFLAGS) visualizer_tests.cpp

PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

BFS_test.o : BFS_test.cpp cs225/catch/catch.hpp graph.cpp graph.h BFS.h BFS.cpp
	$(CXX) $(CXXFLAGS) BFS_test.cpp

BFS.o : BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

dijkstra.o : dijkstra.cpp dijkstra.h 
	$(CXX) $(CXXFLAGS) dijkstra.cpp 

dijkstra_test.o : dijkstra_test.cpp cs225/catch/catch.hpp graph.cpp graph.h dijkstra.h
	$(CXX) $(CXXFLAGS) dijkstra_test.cpp 

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

clean :
	-rm -f *.o $(EXENAME) test