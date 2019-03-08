#**************************************************
# Makefile for CST407 Lab 8
#
# Author: JinJie Xu
# Email:  jinjie.xu@oit.edu
# Date:   Feb. 26, 2019
#
CC = gcc
CFLAGS = -g -O0 -Wall -pthread -std=c99
CPPFLAGS = -g -O3 -Wall -std=c++11
LFLAGS = -pthread

OBJS = 

all: main

clean:
	rm -f threader
	rm -f main
	rm -f *.o

.c.o:
	gcc $(CFLAGS) -c $? -o $@

.cpp.o:
	g++ $(CPPFLAGS) -c $? -o $@

main: main.o $(OBJS)
	g++ main.o -o main $(OBJS) $(LFLAGS) 

tar: 
	tar -cvf lab8_jinjie_xu.tar *
