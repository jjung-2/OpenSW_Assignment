CC=gcc
AR=ar
LN=ln
PROJ=$(shell pwd)
BIN_DIR=$(PROJ)/bin
LIB_DIR=$(PROJ)/lib
OBJ_DIR=$(PROJ)/obj
SRC_DIR=$(PROJ)/src
INC_DIR=$(PROJ)/include

.PHONY: all clean

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp : $(SRC_DIR)/myapp.c $(LIB_DIR)/libmyops.so
	$(CC) $< -L$(LIB_DIR) -lmyops -lm -o $@ -I$(INC_DIR)

$(LIB_DIR)/libmyops.so: $(LIB_DIR)/libmyops.so.1
	$(LN) -s $< $@

$(LIB_DIR)/libmyops.so.1: $(LIB_DIR)/libmyops.so.1.0
	$(LN) -s $< $@

$(LIB_DIR)/libmyops.so.1.0 : $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mypow.o $(OBJ_DIR)/mymod.o
	$(CC) -fPIC -shared -Wl,-soname=libmyops.so.1 -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/*