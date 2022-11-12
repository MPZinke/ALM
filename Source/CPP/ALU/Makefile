CXX=g++
FLAGS=-std=c++17


HEADER_DIR=$(HEADERS_DIR)/$(subst $(CPP_DIR),,$(CURDIR))


Adder.o:
	@$(eval ADDER_OBJ:=$(OBJECT_DIR)/Adder.o)
	@$(CXX) $(FLAGS) -I$(HEADER_DIR) -I$(BASIC_COMPONENT_HEADER_DIR) -c Adder.cpp -o $(ADDER_OBJ)


ALU.o:
	@$(eval ALU_OBJ:=$(OBJECT_DIR)/ALU.o)
	@$(CXX) $(FLAGS) -I$(HEADER_DIR) -I$(BASIC_COMPONENT_HEADER_DIR) -c ALU.cpp -o $(ALU_OBJ)


Not.o:
	@$(eval NOT_OBJ:=$(OBJECT_DIR)/Not.o)
	@$(CXX) $(FLAGS) -I$(HEADER_DIR) -I$(BASIC_COMPONENT_HEADER_DIR) -c Not.cpp -o $(NOT_OBJ)
