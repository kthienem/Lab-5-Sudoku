CMP = g++
MAIN = mainSudoku
FUNC1 = Puzzle
EXEC = $(MAIN)

$(EXEC): $(MAIN).o
	$(CMP) -o $(EXEC) $(MAIN).o 

$(MAIN).o: $(MAIN).cpp 
	$(CMP) -c $(MAIN).cpp

$(FUNC1).o: $(FUNC1).cpp $(FUNC1).h
	$(CMP) -c $(FUNC1).cpp

clean:
	rm $(EXEC) *.o
