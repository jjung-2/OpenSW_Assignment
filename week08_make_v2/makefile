PROJ_DIR=$(PWD)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib

STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
LDFLAGS=-L$(LIB_DIR) -lmybasic -lmyadvanced
CFLAGS=-I$(INC_DIR) -lm
CC=gcc

.PHONY: all basic_ops advanced_ops clean

all: basic_ops advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(STATIC_LIBS)
	$(CC) -o $@ $< $(LDFLAGS) $(CFLAGS)

basic_ops:
	$(MAKE) -C basic_ops
advanced_ops:
	$(MAKE) -C advanced_ops
clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean


