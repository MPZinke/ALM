CXX=g++
FLAGS=-std=c++17


# all: Memory.o Port.o Register.o


Controller.o:
	@$(eval CONTROLLER_OBJ:=$(OBJECT_DIR)/Controller.o)
	@$(CXX) $(FLAGS) -I$(HEADERS_DIR) -I$(BASIC_COMPONENT_HEADER_DIR) -I$(ALU_HEADER_DIR) -c Controller.cpp -o $(CONTROLLER_OBJ)


CPU.o:
	@$(eval CPU_OBJ:=$(OBJECT_DIR)/CPU.o)
	@$(CXX) $(FLAGS) -I$(HEADERS_DIR) -I$(BASIC_COMPONENT_HEADER_DIR) -I$(ALU_HEADER_DIR) -c CPU.cpp -o $(CPU_OBJ)
