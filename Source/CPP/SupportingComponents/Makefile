CXX=g++
FLAGS=-std=c++17


HEADER_DIR=$(HEADERS_DIR)$(subst $(CPP_DIR),,$(CURDIR))


all: Memory.o Port.o Register.o


Memory.o: Port.o
	@$(eval MEMORY_OBJ:=$(OBJECT_DIR)/Memory.o)
	@$(CXX) $(FLAGS) -I$(HEADER_DIR) -c Memory.cpp -o $(MEMORY_OBJ)


Port.o:
	@$(eval PORT_OBJ:=$(OBJECT_DIR)/Port.o)
	@$(CXX) $(FLAGS) -I$(HEADER_DIR) -c Port.cpp -o $(PORT_OBJ)


Register.o: Port.o
	@$(eval REGISTER_OBJ:=$(OBJECT_DIR)/Register.o)
	@$(CXX) $(FLAGS) -I$(HEADER_DIR) -I$(ALU_HEADER_DIR) -c Register.cpp -o $(REGISTER_OBJ)
