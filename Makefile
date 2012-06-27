# MakeFile
ab : main.o Address_Manager.o Address.o
	g++ -o ab main.o Address_Manager.o Address.o
main.o : main.cpp Address_Manager.h
	g++ -c main.cpp
Address_Manager.o : Address_Manager.cpp Address_Manager.h Address.h
	g++ -c Address_Manager.cpp
Address.o : Address.cpp Address.h
	g++ -c Address.cpp
clean:
	rm *.o
