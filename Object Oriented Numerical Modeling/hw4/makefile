###############################################################################

### Programmer: Peter Dolan
### Class: CS5201 Spring 2018
### Instructor: Clayton Price
### Date: 02/18/2018
### File: makefile
### Description: Makefile for the Newton_Poly and Chebyshev driver

################################################################################

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

driver.o: numErr.h         \
          streamErr.h      \
          inputErr.h       \
          arraylist.h      \
          arraylist.hpp    \
          function_calc.h  \
          Cheby_nodes.h    \
          Cheby_nodes.hpp  \
          Newton_Poly.h    \
          Newton_Poly.hpp  \
          driver.h         \
          driver_funcs.hpp \
          driver.cpp
