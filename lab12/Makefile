SRCS := $(wildcard *.cpp)
SRCS := $(filter-out p%.cpp, $(SRCS))
INCS := $(wildcard *.h)
psrc=$(wildcard p*.cpp)
PARTS=$(psrc:p%.cpp=part%)

all: $(PARTS) *.h

part%: p%.cpp $(SRCS)
	g++ -g -Wall $^ -o $@

clean:
	$(RM) $(RF) $(PARTS)

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py
