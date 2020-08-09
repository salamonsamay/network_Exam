
all:main.o  prefix_table.o prefix_table_opt.o
	clang++  main.o prefix_table.o prefix_table_opt.o -o all
main.o:main.cpp  prefix_table.cpp prefix_table_opt.cpp
	clang++ -c main.cpp 
prefix_table.o: prefix_table.cpp 	
	clang++ -c prefix_table.cpp
prefix_table_opt.o: prefix_table_opt.cpp
	clang++ -c prefix_table_opt.cpp
clean:
	rm *.o all

