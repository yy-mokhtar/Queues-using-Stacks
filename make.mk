# Compiler
compiler = g++
com_flags = -Wall -g

# Executable names
att_1 = Queue_attempt_1
att_2 = Queue_attempt_2

# Source files
SRC1 = Queue_attempt_1.cpp
SRC2 = Queue_attempt_2.cpp

#both
all: $(att_1) $(att_2)

#Queue_attempt_1
$(att_1): $(SRC1)
	$(compiler) $(com_flags) -o $(att_1) $(SRC1)

# Queue_attempt_2
$(att_2): $(SRC2)
	$(compiler) $(com_flags) -o $(att_2) $(SRC2)

# Remove executables
clean:
	rm -f $(att_1) $(att_2)
