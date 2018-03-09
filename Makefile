CC=gcc
BUILDDIR=build
SOURCES=test.c heapsort.c insertion_sort.c selection_sort.c bubble_sort.c bogosort.c
OBJS=$(patsubst %.c,$(BUILDDIR)/%.o,$(SOURCES))
EXECUTABLE=$(BUILDDIR)/test

all: directories $(EXECUTABLE)

# Create required directories if they don't exist
directories:
	mkdir -p $(BUILDDIR)

# Link .o files into an executable file
$(EXECUTABLE) : $(OBJS)
	$(CC) $^ -o $@

# Compile .c files into .o files
$(BUILDDIR)/%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean

# Delete created files
clean:
	rm -f $(OBJS) $(EXECUTABLE)
