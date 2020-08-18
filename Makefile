
CXX = g++
CXX_FLAGS = -Wall -Wextra -std=c++17

OBJ_DIR = obj

_OBJ = main.o bs.o cvec.o fft.o heston.o utils.o numalg.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

TARGET = otool

.PHONY: clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJ_DIR)/*.o core

$(OBJ_DIR)/%.o: %.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $< 

$(TARGET): $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $@ $^ 
