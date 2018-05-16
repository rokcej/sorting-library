CC=gcc
CFLAGS=
LDLIBS=-lm
SOURCEDIR=src
BUILDDIR=build
SOURCES=main.c tester.c quicksort.c merge_sort.c heapsort.c shellsort.c insertion_sort.c selection_sort.c gnome_sort.c cocktail_shaker_sort.c bubble_sort.c bogosort.c
OBJS=$(patsubst %.c,$(BUILDDIR)/%.o,$(SOURCES))
EXECUTABLE=$(BUILDDIR)/main

all: $(EXECUTABLE)
	@true

# Link .o files into an executable file
$(EXECUTABLE) : $(OBJS)
	@mkdir -p $(BUILDDIR)
	@echo "Linking..."
	@$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

# Compile .c files into .o files
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	@mkdir -p $(BUILDDIR)
	@echo "Compiling $^"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

# Delete created files
clean:
	@rm -f $(OBJS) $(EXECUTABLE)
