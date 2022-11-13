

Adder.o:
	@$(eval ADDER_OBJ:=$(OBJECTS_DIR)/Adder.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Adder.cpp -o $(ADDER_OBJ)


ALU.o: Adder.o Not.o
	@$(eval ALU_OBJ:=$(OBJECTS_DIR)/ALU.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c ALU.cpp -o $(ALU_OBJ)


Not.o:
	@$(eval NOT_OBJ:=$(OBJECTS_DIR)/Not.o)
	$(CXX) $(FLAGS) $(INCLUDES) -c Not.cpp -o $(NOT_OBJ)
