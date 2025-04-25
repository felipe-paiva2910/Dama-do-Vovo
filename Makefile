CC := gcc

BINARY := tp1

BINDIR := .
BUILDDIR := build
INCDIR := include
SRCDIR := src

CFLAGS := -Wall -I $(INCDIR)

NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.c)))
OBJECTS := $(patsubst %,$(BUILDDIR)/%.o,$(NAMES))

all: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)/$(BINARY) $+ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) -c $^ -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(BINDIR)/$(BINARY)
