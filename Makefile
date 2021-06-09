CC=g++
CPPFLAGS=-g

manage: main.o client.o interface.o user.o commodity.o
	g++ main.o client.o interface.o user.o commodity.o -g -o manage -lm

clean:
	del *.o *.log *.exe

run: main.o client.o interface.o user.o commodity.o
	g++ main.o client.o interface.o user.o commodity.o -g -o manage -lm
	manage.exe