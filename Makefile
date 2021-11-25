EXENAME = main
OBJS = main.o graph.o donaldson_algo.o strong_connected_components.o

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

main.o : main.cpp graph.h JohnsonAlgo/donaldson_algo.h JohnsonAlgo/strong_connected_components.h
	$(CXX) $(CXXFLAGS) main.cpp

graph.o : graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp

donaldson_algo.o : JohnsonAlgo/donaldson_algo.cpp JohnsonAlgo/donaldson_algo.h
	$(CXX) $(CXXFLAGS) JohnsonAlgo/donaldson_algo.cpp

strong_connected_components.o : JohnsonAlgo/strong_connected_components.cpp JohnsonAlgo/strong_connected_components.h
	$(CXX) $(CXXFLAGS) JohnsonAlgo/strong_connected_components.cpp

clean :
	-rm -f *.o $(EXENAME) test