CC=g++
CPPFLAGS=-g

manage: main.o client.o user.o interface.o customer.o merchant.o
	g++ main.o client.o user.o interface.o customer.o merchant.o -g -o manage -lm

clean:
	del *.o *.log *.exe

run: main.o client.o user.o interface.o customer.o merchant.o
	g++ main.o client.o user.o interface.o customer.o merchant.o -g -o manage -lm
	manage.exe