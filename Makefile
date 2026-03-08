CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -Iinclude
DEBUGFLAGS = -Wall -Wextra -O0 -g -fsanitize=address -fno-omit-frame-pointer -Iinclude
# LDFLAGS
DEBUGLDFLAGS = -fsanitize=address

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEBUG_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/debug_%.o,$(SRCS))

TARGET = $(BIN_DIR)/exec-main
DEBUG_TARGET = $(BIN_DIR)/exec-main-debug

all: $(TARGET)

debug: $(DEBUG_TARGET)

# Release build
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Debug build
$(DEBUG_TARGET): $(DEBUG_OBJS) | $(BIN_DIR)
	$(CXX) $(DEBUG_OBJS) -o $@ $(DEBUGLDFLAGS)

# Release object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug object files
$(OBJ_DIR)/debug_%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(DEBUGFLAGS) -c $< -o $@

# Ensure directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

.PHONY: all debug clean
