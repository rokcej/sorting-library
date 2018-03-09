CC=gcc
BUILDDIR=build
SOURCES=test.c heapsort.c insertion_sort.c selection_sort.c bubble_sort.c bogosort.c
OBJS=$(patsubst %.c,$(BUILDDIR)/%.o,$(SOURCES))
EXECUTABLE=$(BUILDDIR)/test

all: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJS)
	$(CC) $^ -o $@

$(BUILDDIR)/%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXECUTABLE)
