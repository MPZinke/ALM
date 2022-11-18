# Directories
# Directories::Source
ALU_CPP_DIR=$(CPP_DIR)/ALU


ALU.o:
	@$(MAKE) ALU.o -C $(ALU_CPP_DIR) \
	  -e CXX=$(CXX) \
	  -e FLAGS=$(FLAGS) \
	  -e CPP_DIR=$(CPP_DIR) \
	  -e INCLUDES="$(INCLUDES)" \
	  -e OBJECTS_DIR=$(OBJECTS_DIR)


Controller.o: ALU.o
	@$(eval CONTROLLER_OBJ:=$(OBJECTS_DIR)/Controller.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Controller.cpp -o $(CONTROLLER_OBJ)


CPU.o: ALU.o Controller.o Memory.o Port.o Register.o
	@$(eval CPU_OBJ:=$(OBJECTS_DIR)/CPU.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c CPU.cpp -o $(CPU_OBJ)


Main.o: CPU.o
	@$(eval MAIN_OBJ:=$(OBJECTS_DIR)/Main.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Main.cpp -o $(MAIN_OBJ)


Memory.o: Port.o
	@$(eval MEMORY_OBJ:=$(OBJECTS_DIR)/Memory.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Memory.cpp -o $(MEMORY_OBJ)


Port.o:
	@$(eval PORT_OBJ:=$(OBJECTS_DIR)/Port.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Port.cpp -o $(PORT_OBJ)


Register.o: Port.o
	@$(eval REGISTER_OBJ:=$(OBJECTS_DIR)/Register.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Register.cpp -o $(REGISTER_OBJ)
