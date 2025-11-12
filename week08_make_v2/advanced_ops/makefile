SRC_DIR=src
OBJ_DIR=obj
INC_DIR=../include
LIB_DIR=../lib

ADV_LIB=$(LIB_DIR)/libmyadvanced.a
CFLAGS=-I$(INC_DIR) -lm
ADV_SRCS=$(wildcard $(SRC_DIR)/*.c)
ADV_OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(ADV_SRCS:.c=.o))
CC=gcc
AR=ar

.PHONY: clean

$(ADV_LIB): $(ADV_OBJS)
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)/* $(ADV_LIB)


