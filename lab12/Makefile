SRCS := $(wildcard *.cpp)
SRCS := $(filter-out p*.cpp, $(SRCS))

psrc=$(wildcard p*.cpp)
PARTS=$(psrc:p%.cpp=part%)

all: $(PARTS)

part%: p%.cpp $(SRCS)
	g++ -g -Wall $^ -o $@

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py
