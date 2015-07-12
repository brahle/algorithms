ROOT_DIR = $(CURDIR)\..\..\..\..

RAQ = random_access_queue
BIN_DIR = $(ROOT_DIR)\bin
TEST_DIR = $(ROOT_DIR)\test
INCLUDE_DIR = $(ROOT_DIR)\src

RAQ_debug = $(RAQ)_debug
RAQ_opt = $(RAQ)_opt

CC = clang++
STD = c++1y
WARNING_FLAGS = -Wall -Wextra -pedantic -Wno-variadic-macros -Wno-gnu-zero-variadic-macro-arguments
DEBUG_FLAGS = -g -DDEBUG
NODEBUG_FLAGS = -DNDEBUG -s
OPTIMIZATION_FLAGS = -O3
STD_FLAGS = -std=$(STD)
INCLUDE_FLAGS = -I$(INCLUDE_DIR)

DEBUGGING_BUILD = $(WARNING_FLAGS) $(STD_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS) $(INCLUDE_FLAGS)
OPTIMIZED_BUILD = $(WARNING_FLAGS) $(STD_FLAGS) $(OPTIMIZATION_FLAGS) $(INCLUDE_FLAGS)

.PHONY: $(RAQ_debug) $(RAQ_opt) random_access_queue_opt

RAQ_CPP = $(RAQ).cpp
RAQ_EXE = $(BIN_DIR)\$(RAQ).exe
RAQ_TARGET = -o $(RAQ_EXE) $(RAQ_CPP)
RAQ_DEBUG = $(TEST_DIR)\$(RAQ).exe
RAQ_DEBUG_TARGET = -o $(RAQ_DEBUG) $(RAQ_CPP)

default: $(RAQ)

$(RAQ_debug): $(RAQ_CPP)
	$(CC) $(DEBUGGING_BUILD) $(RAQ_DEBUG_TARGET)
	$(RAQ_DEBUG)

$(RAQ_opt): $(RAQ_CPP)
	$(CC) $(OPTIMIZED_BUILD) $(RAQ_TARGET)
	$(RAQ_EXE)

$(RAQ): $(RAQ_opt)
	@echo Success
