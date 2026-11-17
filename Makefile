CXX=g++
CXXFLAGS = -std=c++20 -Wall -O2 -I /usr/include/eigen3 -I libs

TARGET = build/qtie
TEST_TARGET = build/test_qtie

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=build/%.o)

TEST_SRCS = test.cpp
TEST_OBJS = $(TEST_SRCS:%.cpp=build/%.o)

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

build/%.o: %.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build
