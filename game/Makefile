BINARYNAME = YahtzeeSim

OBJS = Yahtzee.o main.o

CXXFLAGS = -std=c++11 -I../source
LDFLAGS = -I../source

vpath %.cpp ../source

##### Commands
default: $(BINARYNAME) 
play: $(BINARYNAME)
	./$(BINARYNAME)


$(BINARYNAME): $(OBJS)
	g++ -o $(BINARYNAME) $(OBJS) $(LDFFLAGS)

%.o: %.cpp
	g++ -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f $(BINARYNAME)
