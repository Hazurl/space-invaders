SRC_DIR := src

SRC := $(foreach d,$(SRC_DIR),$(wildcard $(d)/*.cpp))

BUILD_DIR := $(addprefix build/,$(SRC_DIR))
DEST := build/spaceinvaders

OBJ := $(patsubst %.cpp,build/%.o,$(SRC))

OPTIM := -O2
FLAGS := -std=c++17 -g3 -Wall -Wextra -Wno-pmf-conversions
LIBS := -lsfml-graphics -lsfml-window -lsfml-system
MAKEFLAGS += --jobs=$(shell nproc)

#.PHONY: test

all: build/spaceinvaders

# Main build task
build/spaceinvaders: $(BUILD_DIR) $(OBJ)
	g++ $(FLAGS) -o $(DEST) $(OBJ) $(LIBS)
	@echo "---------------"
	@echo "Build finished!"
	@echo "---------------"

build/%.o: %.cpp
	g++ -c $(OPTIM) $(FLAGS) -o "$@" "$<"

$(BUILD_DIR):
	@mkdir -p $@

# Clean every build files by destroying the build/ folder.
clean:
	rm -rf build
	@echo "----------------"
	@echo "Project cleaned."
	@echo "----------------"


run:
	@echo "----------------"
	@echo "      Run"
	@echo "----------------"
	@$(DEST)
	@echo "----------------"
	@echo "      Stop"
	@echo "----------------"

again: clean build/spaceinvaders
