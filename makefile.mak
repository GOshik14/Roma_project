compiler = g++

all: ini_parcer

ini_parcer: config_read.o config_write.o main.o my_string.o print_structure.o
	$(compiler) -o ini_parcer.exe config_read.o config_write.o main.o my_string.o print_structure.o
	
config_read.o: config_read.cpp interfaces.hpp
	$(compiler) -c config_read.cpp
	
config_write.o: config_write.cpp interfaces.hpp my_string.o my_string.hpp
	$(compiler) -c config_write.cpp

main.o: main.cpp interfaces.hpp
	$(compiler) -c main.cpp
	
my_string.o: my_string.cpp  my_string.hpp
	$(compiler) -c my_string.cpp
	
print_structure.o: print_structure.cpp interfaces.hpp
	$(compiler) -c print_structure.cpp