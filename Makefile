EXE := cli

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude
CFLAGS   := -g
LDFLAGS  :=
LDLIBS   := 

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	    $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
		mkdir -p $(BIN_DIR)
		mv $(EXE) $(BIN_DIR)/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	    $(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	    mkdir $@

clean:
	    $(RM) $(OBJ)
	    $(RM) -rf $(BIN_DIR)
