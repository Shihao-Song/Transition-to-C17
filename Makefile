SOURCE  := main.cc

CC      := g++
FLAGS   := -O3 -std=c++17 -w
TARGET  := main

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(FLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm $(TARGET)                                                                                   
