
CXX := g++
CXXFLAGS := -std=c++26 -Wall -Wextra -Wpedantic -O2 -Iinclude
DEPFLAGS := -MMD -MP

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp,cpp-out/obj/%.o,$(SRC))
DEP := $(OBJ:.o=.d)

TARGET := cpp-out/vak

ifeq ($(BUILD),debug)
    CXXFLAGS += -O0 -g3 -DDEBUG
else
    CXXFLAGS += -O2 -DNDEBUG
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

cpp-out/obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEP)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf cpp-out

.PHONY: all run clean

