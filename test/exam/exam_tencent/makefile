CC        = g++
CPPFLAGS    = $(CFLAG) -Wall -std=c++11 -pthread -g

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
	$(CC) $(CPPFLAGS) $^ -o $@

clean:
	rm -rf $(DSYM_FILES) $(TARGETS)
