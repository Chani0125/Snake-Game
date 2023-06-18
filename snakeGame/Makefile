# CC = g++

# SRC_DIR = ./src

# TARGET = game

# $(TARGET) :
# 	$(CC) -o $(TARGET) $(wildcard $(SRC_DIR)/*.cpp) -lncurses

CC = g++

SRC_DIR = ./src
OBJ_DIR = ./obj

TARGET = game

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)

OBJDIRS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))

$(TARGET) : $(OBJDIRS)
	$(CC) -o $(TARGET) $(OBJDIRS) -lncurses

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) -c -o $@ $^

clean:
	rm -f $(OBJDIRS) $(TARGET)
