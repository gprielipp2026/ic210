src=$(wildcard p*.cpp)
parts=$(src:p%.cpp=part%)

all: $(parts)

clean:
	$(RM) $(RF) $(parts)

part1: p1.cpp
	g++ board.cpp list.cpp p1.cpp easycurses.cpp Pos.cpp -l ncurses -g -o $@	
part2: p2.cpp
	g++ board.cpp list.cpp p2.cpp easycurses.cpp Pos.cpp -l ncurses -g -o $@	
part3: p3.cpp
	g++ board.cpp list.cpp p3.cpp easycurses.cpp Pos.cpp -l ncurses -g -o $@		
part4: p4.cpp
	g++ board.cpp list.cpp p4.cpp easycurses.cpp Pos.cpp -l ncurses -g -o $@	
part5: p5.cpp
	g++ board.cpp list.cpp p5.cpp easycurses.cpp Pos.cpp -l ncurses -g -o $@	
################## DON'T TOUCH BELOW ##################
run1: part1
	@./part1
run_%: %
	@test -f $* && echo "$*: Code compiled successfully" 

