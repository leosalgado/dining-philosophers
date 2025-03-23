CXX = g++
CXXFLAGS = -std=c++11 -pthread
SRC = main.cpp
OUT = build/main

all: $(OUT)

$(OUT): $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

run: $(OUT)
	@./$(OUT)
