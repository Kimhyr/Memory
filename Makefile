BIN=./Memory.exe
SRC=./Main.cpp

CC=clang++
FLGS=-std=c++20 -O3 -Wall -Wextra -Werror -I./

all:$(BIN)

run:$(BIN)
	$(BIN)

$(BIN):$(SRC)
	$(CC) $(SRC) -o $(BIN) $(FLGS)

clean:
	rm .\Memory.exe
