
# Compiles
CXX=g++
FLAGS=-std=c++17

# Directories
SOURCE_DIR=$(PWD)
# Directories::Objects
OBJECTS_DIR=$(SOURCE_DIR)/../Objects
# Directories::Source
CPP_DIR=$(SOURCE_DIR)/CPP
# Directories::Headers
HEADERS_DIR=$(SOURCE_DIR)/Headers


INCLUDES:=$(addprefix -I,$(shell find $(HEADERS_DIR) -type d -print))

# Outputs
BINARY=CPU
OBJECTS=$(OBJECTS_DIR)/*.o


all:
	@$(MAKE) Main.o -C $(CPP_DIR) \
	  -e CXX=$(CXX) \
	  -e FLAGS=$(FLAGS) \
	  -e CPP_DIR=$(CPP_DIR) \
	  -e INCLUDES="$(INCLUDES)" \
	  -e OBJECTS_DIR=$(OBJECTS_DIR)

	$(CXX) $(FLAGS) $(OBJECTS) -o $(BINARY)
