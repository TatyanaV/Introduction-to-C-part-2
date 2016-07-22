#makefile for Lab1

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

SRCS = main.cpp f.cpp g.cpp
HEADERS = f.hpp g.hpp


LAB1: ${SRCS} ${HEADERS}
    ${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o lab1
