# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Target and Source
TARGET = cleaningData
SRC = cleaningData.c

# Build the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up build artifacts and output
clean:
	rm -f $(TARGET) players.txt

jsonClean:
	rm -f $(TARGET) json.txt