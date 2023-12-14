CC = g++
CFLAGS = -std=c++11

exe_file = program4 

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g -Wall
else
	CFLAGS += -DNDEBUG -O3
endif

SRCDIR = .
SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS = $(SOURCES:.cpp=.o)
DEP = $(OBJECTS:.o=.d)

$(exe_file): $(OBJECTS)
	$(CC) $^ -o $(exe_file)

-include $(DEP)

%.d: %.$(SRCEXT)
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.out *.o *.d $(exe_file)

run: 
	clear; ./program4 

valgrind:
	clear; valgrind --leak-check=full --track-origins=yes -s ./program4

operation: 
	make clean && clear && make && make run

.PHONY: clean