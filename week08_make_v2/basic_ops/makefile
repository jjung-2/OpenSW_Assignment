SRC_DIR=src
OBJ_DIR=obj
INC_DIR=../include
LIB_DIR=../lib

BASIC_LIB=$(LIB_DIR)/libmybasic.a
CFLAGS=-I$(INC_DIR) -lm
BASIC_SRCS=$(wildcard $(SRC_DIR)/*.c)
BASIC_OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(BASIC_SRCS:.c=.o))
CC=gcc
AR=ar

.PHONY: clean

$(BASIC_LIB): $(BASIC_OBJS)
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/* $(BASIC_LIB)


