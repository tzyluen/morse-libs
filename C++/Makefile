CXX=g++
CXXFLAGS=-O2 -g -Wall -std=c++11 -fmessage-length=0

all: morse.o
	$(CXX) $(CXXFLAGS) morse.o -o main main.cpp

morse.o:
	$(CXX) $(CXXFLAGS) -c morse.cpp

clean:
	rm -f *o main
