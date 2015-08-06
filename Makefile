ROOT_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

ifdef ComSpec
    PATHSEP2 := \\
		MKDIR := mkdir
		RMDIR := del
else
    PATHSEP2 := /
		MKDIR := mkdir -p
		RMDIR := rm -rf
endif
PATHSEP := $(strip $(PATHSEP2))

BIN_DIR := $(ROOT_DIR)$(PATHSEP)bin
DEBUG_DIR := $(ROOT_DIR)$(PATHSEP)debug
SRC_DIR := $(ROOT_DIR)$(PATHSEP)src
INCLUDE_DIR := $(SRC_DIR)

CC := clang++

STD := c++1y
WARNING_FLAGS := -Wall -Wextra -pedantic -Wno-variadic-macros -Wno-gnu-zero-variadic-macro-arguments
DEBUG_FLAGS := -g -DDEBUG
NODEBUG_FLAGS := -DNDEBUG -s
OPTIMIZATION_FLAGS := -O3
STD_FLAGS := -std=$(STD)
INCLUDE_FLAGS := -I$(INCLUDE_DIR)
BUILD_FLAGS := -static

DEBUGGING_BUILD := $(WARNING_FLAGS) $(STD_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS) $(INCLUDE_FLAGS) $(BUILD_FLAGS)
OPTIMIZED_BUILD := $(WARNING_FLAGS) $(STD_FLAGS) $(OPTIMIZATION_FLAGS) $(INCLUDE_FLAGS) $(BUILD_FLAGS)

DEBUG ?= 0
ifeq (DEBUG, 1)
  CFLAGS := $(DEBUGGING_BUILD)
else
  CFLAGS := $(OPTIMIZED_BUILD)
endif

SRCS := primes.cpp random_access_queue.cpp

default: $(SRCS)

%.cpp:
	$(CC) $(CFLAGS) $(shell find $(SRC_DIR) -type f -name $@) \
		-o $(BIN_DIR)$(PATHSEP)$(subst .cpp,.exe,$@)

folders:
	$(MKDIR) $(INCLUDE_DIR)
	$(MKDIR) $(BIN_DIR)$(PATHSEP)
	$(MKDIR) $(DEBUG_DIR)$(PATHSEP)

clean:
	$(RMDIR) $(BIN_DIR) $(DEBUG_DIR)
