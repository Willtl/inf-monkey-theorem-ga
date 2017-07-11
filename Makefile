CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		InfinityMonkeyTheorem.o GeneticAlgorithm/GeneticAlgorithm.o GeneticAlgorithm/Individual.o GeneticAlgorithm/Population.o 

LIBS =		

TARGET =	InfinityMonkeyTheorem

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
