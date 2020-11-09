CC        = gcc
CFLAGS    = $(CFLAG) -Wall -std=c99 -pthread -g

SOURCE_FILES  := $(wildcard ./*.c)
DSYM_FILES    := $(patsubst %.c, %.dSYM, $(SOURCE_FILES))
TARGETS       := $(patsubst %.c, %, $(SOURCE_FILES))

.PHONY: all start end config compile clean

all: start config compile end

start:
	@echo "compile start."

end:
	@echo "compile over."

config:
	@echo $(SOURCE_FILES)
	@echo $(TARGETS)

compile: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(DSYM_FILES) $(TARGETS)
