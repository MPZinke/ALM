# Directories
# Directories::Source
ALU_CPP_DIR=$(CPP_DIR)/ALU
BASIC_COMPONENTS_CPP_DIR=$(CPP_DIR)/BasicComponents


ALU.o:
	@$(MAKE) ALU.o -C $(ALU_CPP_DIR) \
	  -e CXX=$(CXX) \
	  -e FLAGS=$(FLAGS) \
	  -e CPP_DIR=$(CPP_DIR) \
	  -e INCLUDES="$(INCLUDES)" \
	  -e OBJECTS_DIR=$(OBJECTS_DIR)


BasicComponents.o:
	@$(MAKE) -C $(BASIC_COMPONENTS_CPP_DIR) \
	  -e CXX=$(CXX) \
	  -e FLAGS=$(FLAGS) \
	  -e CPP_DIR=$(CPP_DIR) \
	  -e INCLUDES="$(INCLUDES)" \
	  -e OBJECTS_DIR=$(OBJECTS_DIR)


Controller.o: ALU.o BasicComponents.o
	@$(eval CONTROLLER_OBJ:=$(OBJECTS_DIR)/Controller.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Controller.cpp -o $(CONTROLLER_OBJ)


CPU.o: ALU.o BasicComponents.o Controller.o
	@$(eval CPU_OBJ:=$(OBJECTS_DIR)/CPU.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c CPU.cpp -o $(CPU_OBJ)


Main.o: CPU.o
	@$(eval MAIN_OBJ:=$(OBJECTS_DIR)/Main.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Main.cpp -o $(MAIN_OBJ)
