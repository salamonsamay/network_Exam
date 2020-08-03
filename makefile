
all:main.o a.o  prefix_table.o
	clang++  main.o a.o prefix_table.o -o all
main.o:main.cpp a.hpp prefix_table.cpp
	clang++ -c main.cpp 
a.o:a.cpp a.hpp
	clang++ -c a.cpp

prefix_table.o: prefix_table.cpp 	
	clang++ -c prefix_table.cpp
clean:
	rm *.o all

