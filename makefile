
all:main.o a.o  prefix_table.o prefix_table_opt.o
	clang++  main.o a.o prefix_table.o prefix_table_opt.o -o all
main.o:main.cpp a.hpp prefix_table.cpp prefix_table_opt.cpp
	clang++ -c main.cpp 
a.o:a.cpp a.hpp
	clang++ -c a.cpp
prefix_table.o: prefix_table.cpp 	
	clang++ -c prefix_table.cpp
prefix_table_opt.o: prefix_table_opt.cpp
	clang++ -c prefix_table_opt.cpp
clean:
	rm *.o all

