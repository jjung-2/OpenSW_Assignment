PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib

CC=gcc
AR=ar

OPS_SRCS=$(wildcard $(SRC_DIR)/???.c)
MYAPP_SRC=$(SRC_DIR)/myapp.c
OPS_OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(OPS_SRCS:.c=.o))
MYAPP_OBJ=$(subst $(SRC_DIR), $(OBJ_DIR), $(MYAPP_SRC:.c=.o))
BASIC_LIB=$(LIB_DIR)/libmybasic.a

.PHONY: all basic clean

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(BASIC_LIB) $(MYAPP_OBJ)
	$(CC) -o $@ $(MYAPP_OBJ) -lmybasic -L$(LIB_DIR)

basic: $(BASIC_LIB)

$(BASIC_LIB): $(OPS_OBJS)
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	@echo "Cleaning up..."
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/*


