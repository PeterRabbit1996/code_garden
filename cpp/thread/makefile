CC        = g++
CFLAGS    = $(CFLAG) -Wall -pthread -g -std=c++11

SOURCE_FILES  := $(wildcard ./*.cpp)
DSYM_FILES    := $(patsubst %.cpp, %.dSYM, $(SOURCE_FILES))
TARGETS       := $(patsubst %.cpp, %, $(SOURCE_FILES))

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

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(DSYM_FILES) $(TARGETS)
