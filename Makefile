CXX=g++
CXXFLAGS= -std=c++20 -Wall -O2
INCLUDE= -I /usr/include/eigen3 -I libs

TARGET= build/qtie

SRCS=main.cpp
OBJS=$(SRCS:%.cpp=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(OBJS)

build/%.o: %.cpp libs/dirac.h | build
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build
