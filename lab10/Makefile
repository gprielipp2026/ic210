partscpp=$(wildcard p*.cpp)
parts=$(partscpp:p%.cpp=p%)

all: $(parts)

clean:
	$(RM) $(RF) $(parts)

p1: p1.cpp
	g++ p1.cpp easycurses.cpp -l ncurses -o p1

p2: p2.cpp
	g++ p2.cpp easycurses.cpp -l ncurses -o p2

p3: p3.cpp
	g++ p3.cpp easycurses.cpp -l ncurses -o p3

p4: p4.cpp
	g++ p4.cpp easycurses.cpp -l ncurses -o p4

p5: p5.cpp
	g++ p5.cpp easycurses.cpp -l ncurses -o p5

p6: p6.cpp
	g++ p6.cpp easycurses.cpp -l ncurses -o p6
