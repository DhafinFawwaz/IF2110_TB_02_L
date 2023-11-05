CC = gcc
CFLAGS = -Wall -Werror -std=c11

OUTPUT_DIR = Bin

MAIN = main
SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

SRC_FITUR = Fitur
SRC_ADT = ADT

SRC = $(wildcard $(SRC_FITUR)/*/*.c) $(wildcard $(SRC_ADT)/*/*.c)
OBJS = $(patsubst %,$(OUTPUT_DIR)/%,$(SRC:.c=.o))

.PHONY: all clean run test debug

all: build run

build: $(OUTPUT_DIR)/$(OBJ_MAIN) $(OBJS)
	$(info [Build Program])
	@echo -n ">> "
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(MAIN) $^

$(OUTPUT_DIR)/%.o: %.c
	@echo -n ">> "
	mkdir -p $(@D)
	@echo -n ">> "
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(info [Clean Program])
	@echo -n ">> "
	rm -f $(OUTPUT_DIR)/$(OBJ_MAIN) $(OUTPUT_DIR)/$(MAIN) $(OBJS)

run:
	$(info [Run Program])
	@echo -n ">> "
	./$(OUTPUT_DIR)/$(MAIN)
	


# UNIT TESTS
TESTS_DIR = $(word 2, $(MAKECMDGOALS))/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

SRC_FILE = $(wildcard $(word 2, $(MAKECMDGOALS))/*.c)
SRC_MTEST = $(wildcard $(word 2, $(MAKECMDGOALS))/tests/*.c)
OBJ_FILE = $(OUTPUT_DIR)/$(SRC_FILE:.c=.o)
OBJ_MTEST = $(OUTPUT_DIR)/$(SRC_MTEST:.c=.o)
EXE_MTEST = $(OBJ_MTEST:.o=)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out $(EXE_MTEST)
	@if $(EXE_MTEST) < $(TESTS_DIR)/$*.in | diff --strip-trailing-cr - $(word 2,$^) > /dev/null; then \
		echo "- $< $(word 2,$^): $(GREEN)PASS$(RESET)"; \
	else \
		echo "- $< $(word 2,$^): $(RED)FAIL$(RESET)"; \
		if [ "$(word 3, $(MAKECMDGOALS))" = "debug" ]; then \
			echo "Expected:"; \
			cat $(word 2,$^); \
			echo "Actual:"; \
			$(EXE_MTEST) < $<; \
		fi; \
	fi > $@

	
$(EXE_MTEST): $(SRC_MTEST) $(SRC)
	$(info [Compiling Dependencies...])
	@mkdir -p $(@D)
	@echo -n ">> "
	$(CC) $(CFLAGS) -o $(EXE_MTEST) $(SRC_MTEST) $(SRC)

ifeq ($(word 2, $(MAKECMDGOALS)),)
DIRS = $(wildcard ADT/*) $(wildcard Bin/*)
test:
	$(info [Test All Programs])
	@for dir in $(DIRS); do \
		if [ -n "$$(ls $$dir/tests/*.c 2>/dev/null)" ]; then \
			$(MAKE) -s test $$dir; \
		fi \
	done
	
else

test: $(EXE_MTEST) $(TEST_RESULTS)
	@mkdir -p $(@D)
	$(info [Test $(word 2, $(MAKECMDGOALS))])
	@cat $(TEST_RESULTS)
endif








