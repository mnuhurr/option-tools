
CXX = g++
CXX_FLAGS = -Wall -Wextra -std=c++17

TARGET = otool
SRCS = main.cpp bs.cpp cvec.cpp fft.cpp heston.cpp utils.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXX_FLAGS) -c $<  -o $@

clean:
	$(RM) $(TARGET) *.o

depend: $(SRCS)
	makedepend $^

