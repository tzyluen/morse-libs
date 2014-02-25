CXX=gcc
CXXFLAGS=-O2 -g -Wall

all: morse handler tcp_morse_server tcp_morse_client

morse:
	$(CXX) $(CXXFLAGS) morse.c -c

handler:
	$(CXX) $(CXXFLAGS) handler.c -c

tcp_morse_server:
	$(CXX) $(CXXFLAGS) morse.o handler.o tcp_morse_server.c -o morsed

tcp_morse_client:
	$(CXX) $(CXXFLAGS) morse.o handler.o tcp_morse_client.c -o morse

clean:
	rm -f *o a.out morsed morse
