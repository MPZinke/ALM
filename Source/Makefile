
# Compiles
CXX=g++
FLAGS=-std=c++17
# Outputs
BINARY=CPU
OBJECTS=Adder.o ALU.o Controller.o CPU.o Main.o Memory.o Not.o Port.o Register.o

# Paths
SOURCE_DIR=$(PWD)
OBJECT_DIR=$(SOURCE_DIR)/../Objects

HEADERS_DIR=$(SOURCE_DIR)/Headers
CPP_DIR=$(SOURCE_DIR)/CPP

ALU_CPP_DIR=$(CPP_DIR)/ALU
ALU_HEADER_DIR=$(HEADERS_DIR)/ALU

BASIC_COMPONENT_CPP_DIR=$(CPP_DIR)/BasicComponents
BASIC_COMPONENT_HEADER_DIR=$(HEADERS_DIR)/BasicComponents


all: Main.o
	$(CXX) $(FLAGS) ../Objects/Adder.o ../Objects/ALU.o ../Objects/Controller.o ../Objects/CPU.o ../Objects/Memory.o \
	  ../Objects/Not.o ../Objects/Port.o ../Objects/Register.o ../Objects/Main.o -o $(BINARY)


Main.o: CPU.o
	@$(eval MAIN_OBJ:=$(OBJECT_DIR)/Main.o)
	$(CXX) $(FLAGS) -I$(CPP_DIR) -I$(ALU_HEADER_DIR) -I$(BASIC_COMPONENT_HEADER_DIR) -c Main.cpp -o $(MAIN_OBJ)


Adder.o: Port.o
	@$(MAKE) Adder.o -C $(ALU_CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR) \
	  -e BASIC_COMPONENT_HEADER_DIR=$(BASIC_COMPONENT_HEADER_DIR)


ALU.o: Adder.o Not.o Port.o
	@$(MAKE) ALU.o -C $(ALU_CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR) \
	  -e BASIC_COMPONENT_HEADER_DIR=$(BASIC_COMPONENT_HEADER_DIR)


Controller.o: Port.o
	@$(MAKE) Controller.o -C $(CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR) \
	  -e ALU_HEADER_DIR=$(ALU_HEADER_DIR) \
	  -e BASIC_COMPONENT_HEADER_DIR=$(BASIC_COMPONENT_HEADER_DIR)


CPU.o: Adder.o ALU.o Controller.o Memory.o Not.o Port.o Register.o
	@$(MAKE) CPU.o -C $(CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR) \
	  -e ALU_HEADER_DIR=$(ALU_HEADER_DIR) \
	  -e BASIC_COMPONENT_HEADER_DIR=$(BASIC_COMPONENT_HEADER_DIR)


Memory.o:
	@$(MAKE) Memory.o -C $(BASIC_COMPONENT_CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR)


Not.o: Port.o
	@$(MAKE) Not.o -C $(ALU_CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR) \
	  -e BASIC_COMPONENT_HEADER_DIR=$(BASIC_COMPONENT_HEADER_DIR)


Port.o:
	@$(MAKE) Port.o -C $(BASIC_COMPONENT_CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR)


Register.o: Port.o
	@$(MAKE) Register.o -C $(BASIC_COMPONENT_CPP_DIR) \
	  -e SOURCE_DIR=$(SOURCE_DIR) \
	  -e ALU_HEADER_DIR=$(ALU_HEADER_DIR)
