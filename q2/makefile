
all:main.o   bd.o edf.o
	clang++  main.o  -o all
main.o:main.cpp   bd.hpp edf.hpp
	clang++ -c main.cpp 
bd.o: bd.hpp
	clang++ -c bd.hpp
edf.o: edf.hpp
	clang++ -c edf.hpp	
clean:
	rm *.o all

