###############################################################################

### Programmer: Peter Dolan
### Class: CS5201 Spring 2018
### Instructor: Clayton Price
### Date: 01/22/2018
### File: makefile
### Description: Makefile for the polarNum driver

###############################################################################

#Typical Compiler and Flag Macros
CXX = /usr/bin/g++
FLAGS = -std=c++17 -Wpedantic -Wall -Wextra -Wfloat-conversion -Werror

OBJECTS = driver.o  

.SUFFIXES: .cpp

.cpp.o: $<
	${CXX} -c ${FLAGS} $< -o $@

default: all

all: driver

driver: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

.PHONY: clean

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

#Dependency List for the object file

driver.o: polarNum.h   \
          polarNum.hpp \
          norm.h       \
          norm.hpp     \
          driver.cpp
