CXX        := g++
OUTPUT     := sfmlgame

SFML_DIR   := .

# Default to release mode if no mode is specified
MODE       ?= release

# Flags for release and debug
CXX_FLAGS_RELEASE := -O3 -std=c++17
CXX_FLAGS_DEBUG   := -g -O0 -std=c++17

LDFLAGS    := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -L$(SFML_DIR)/lib
INCLUDES   := -I./src -I$(SFML_DIR)/include

SRC_FILES  := $(wildcard *.cpp)
OBJ_FILES  := $(SRC_FILES:.cpp=.o)

# Set the appropriate flags based on the mode
ifeq ($(MODE),debug)
	CXX_FLAGS := $(CXX_FLAGS_DEBUG)
	OUTPUT := $(OUTPUT)_debug
else
	CXX_FLAGS := $(CXX_FLAGS_RELEASE)
endif

all: $(OUTPUT)

$(OUTPUT): $(OBJ_FILES) Makefile
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./bin/$@

%.o: %.cpp
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) $< -o $@

clean:
	@rm -f $(OBJ_FILES) ./bin/$(OUTPUT)

run: $(OUTPUT)
	@rm *.o
	@cd bin && ./$(OUTPUT) && cd ..
