CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = project2sampletests
SRCS = project2sampletests.cc dynamicarray.cc
OBJS = $(SRCS:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc dynamicarray.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	.\$(TARGET)

clean:
	del /Q $(TARGET).exe 2>nul || true
	del /Q *.o 2>nul || true
