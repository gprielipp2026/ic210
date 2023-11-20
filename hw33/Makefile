hw: hw.cpp ll.cpp
	g++ hw.cpp ll.cpp -g -Wall -o hw
	

############### DON'T TOUCH BELOW #######################
run: hw
	@valgrind ./hw 2> out; python3 val.py

