source = socket.cc address.cc packet.cc int64.cc timestamp.cc \
	datagrump-sender.cc datagrump-receiver.cc \
	util.cc controller.cc

objects = socket.o address.o packet.o int64.o timestamp.o util.o controller.o

executables = datagrump-sender datagrump-receiver

CXX = g++
CXXFLAGS = -g -O3 -std=c++0x -ffast-math -pedantic -Werror -Wall -Wextra \
	-Weffc++ -fno-default-inline -pipe
LIBS = -lm -lrt

all: $(executables)

datagrump-sender: datagrump-sender.o $(objects)
	$(CXX) $(CXXFLAGS) -o $@ $+ $(LIBS)

datagrump-receiver: datagrump-receiver.o $(objects)
	$(CXX) $(CXXFLAGS) -o $@ $+ $(LIBS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

-include depend

depend: $(source)
	$(CXX) $(INCLUDES) -MM $(source) > depend

.PHONY: clean
clean:
	-rm -f $(executables) depend *.o *.rpo
