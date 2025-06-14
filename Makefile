CXX = g++
EXEC = game_of_life

SRC_DIR = src
OBJ_DIR = build
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

COMPILER_FLAG = -Wall -Werror -Iinclude
LINKER_FLAG = -Iinclude -Llib -lraylib -lwinmm -lgdi32

all: "$(EXEC)"
	cls

# Rule to compile the final executable
"$(EXEC)": $(OBJ)
	$(CXX) -o "$@" $^ $(COMPILER_FLAG) $(LINKER_FLAG)

# Rule to compile .cpp to .o in the build directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(CXX) -o $@ -c $< $(COMPILER_FLAG)

clean:
	rm -rf "$(OBJ_DIR)" "$(EXEC)"
