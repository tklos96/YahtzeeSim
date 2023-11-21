BINARYNAME = YahtzeeSim

OBJS = Yahtzee.o main.o

CXXFLAGS = -std=c++20
LDFLAGS =

##### Commands
default: $(BINARYNAME) 
play: $(BINARYNAME)
	./$(BINARYNAME)


$(BINARYNAME): $(OBJS)
	g++ -o $(BINARYNAME) $(OBJS) $(CXXFLAGS) $(LDFFLAGS)

%.o: %.cpp
	g++ -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o
