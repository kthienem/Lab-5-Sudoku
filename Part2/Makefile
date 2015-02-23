CMP = g++
MAIN = mainPart2
FUNC1 = Puzzle
EXEC = $(MAIN)

$(EXEC): $(MAIN).o
	$(CMP) -o $(EXEC) $(MAIN).o 

$(MAIN).o: $(MAIN).cpp 
	$(CMP) -c $(MAIN).cpp

clean:
	rm $(EXEC) *.o
