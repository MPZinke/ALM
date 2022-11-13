

all: Memory.o Port.o Register.o


Memory.o: Port.o
	@$(eval MEMORY_OBJ:=$(OBJECTS_DIR)/Memory.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Memory.cpp -o $(MEMORY_OBJ)


Port.o:
	@$(eval PORT_OBJ:=$(OBJECTS_DIR)/Port.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Port.cpp -o $(PORT_OBJ)


Register.o: Port.o
	@$(eval REGISTER_OBJ:=$(OBJECTS_DIR)/Register.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Register.cpp -o $(REGISTER_OBJ)
