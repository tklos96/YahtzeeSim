BINARYNAME = YahtzeeTest

OBJS = Yahtzee.o Logfile.o main.o

CXXFLAGS = -std=c++11 -I../source
LDFLAGS = -I../source

vpath %.cpp ../source

##### Commands
default: $(BINARYNAME) 
test: $(BINARYNAME)
	./$(BINARYNAME)


$(BINARYNAME): $(OBJS)
	g++ -o $(BINARYNAME) $(OBJS) $(CXXFLAGS) $(LDFFLAGS)

%.o: %.cpp
	g++ -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f $(BINARYNAME)
