CC = g++
CFLAGS = -std=c++11 -Wall -g -O0
INCLUDE = -I ./include
SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.cpp)

TARGET_DIR = ./bin

all: stm test_bin compiler

run: stm test_bin
	$(TARGET_DIR)/stm < $(TARGET_DIR)/stmbin.o

stm: $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET_DIR)/stm $(SRC_DIR)/slstm.cpp

test_bin: $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET_DIR)/test_bin_gen $(SRC_DIR)/test_bin_gen.cpp
	rm -f $(TARGET_DIR)/stmbin.o
	$(TARGET_DIR)/test_bin_gen $(TARGET_DIR)/stmbin.o

compiler: $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(TARGET_DIR)/compiler $(SRC_DIR)/compiler.cpp

clean:
	rm -rf $(TARGET_DIR)
