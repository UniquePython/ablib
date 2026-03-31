CC     = gcc
CFLAGS = -nostdlib -nostartfiles -Wall -Wextra -g -MMD -MP -I include

SRC_DIR  = src
RT_DIR   = rt
TEST_DIR = test
OBJ_DIR  = obj
BIN_DIR  = bin

LIB_SRCS  = $(wildcard $(SRC_DIR)/*.c)
RT_SRCS   = $(wildcard $(RT_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

LIB_OBJS  = $(LIB_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
RT_OBJS   = $(RT_SRCS:$(RT_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_BINS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(BIN_DIR)/%)

DEPS = $(LIB_OBJS:.o=.d) $(RT_OBJS:.o=.d)

.PHONY: all run test clean

all: $(TEST_BINS)

run: all
	@for bin in $(TEST_BINS); do \
		echo "==> $$bin"; \
		$$bin; \
		echo "exit: $$?"; \
		echo; \
	done

test: all
	@PASS=0; FAIL=0; \
	for bin in $(TEST_BINS); do \
		$$bin > /dev/null 2>&1; \
		if [ $$? -eq 0 ]; then \
			echo "PASS  $$bin"; \
			PASS=$$((PASS+1)); \
		else \
			echo "FAIL  $$bin"; \
			FAIL=$$((FAIL+1)); \
		fi; \
	done; \
	echo; \
	echo "$$PASS passed, $$FAIL failed"

$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(RT_OBJS) $(LIB_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(RT_OBJS) $< $(LIB_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(RT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

-include $(DEPS)