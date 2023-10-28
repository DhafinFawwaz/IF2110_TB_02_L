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

.PHONY: all clean run test

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

test:
	$(info [Test Program])
	@echo -n ">> "


# UNIT TESTS
SRC_FOO = ADT/Foo/foo.c
SRC_TEST = ADT/Foo/tests/mfoo.c
OBJ_FOO = $(OUTPUT_DIR)/$(SRC_FOO:.c=.o)
OBJ_TEST = $(OUTPUT_DIR)/$(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Foo/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mfoo: $(OBJ_FOO) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(TESTS_DIR)/$@ $^

test_%: m% $(TEST_RESULTS)
	$(info [Test])
	@cat $(TEST_RESULTS)

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m


$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mfoo
	@if $(OUTPUT_DIR)/$(TESTS_DIR)/mfoo < $(TESTS_DIR)/$*.in | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): $(GREEN)TRUE$(RESET)"; \
		echo "Expected:"; \
		# cat $(word 2,$^); \
		# echo ""; \
		# echo "Actual:"; \
		# $(OUTPUT_DIR)/$(TESTS_DIR)/mfoo < $(TESTS_DIR)/$*.in; \
		# echo ""; \
	else \
		echo "$< $(word 2,$^): $(RED)WRONG$(RESET)"; \
		echo "Expected:"; \
		cat $(word 2,$^); \
		echo ""; \
		echo "Actual:"; \
		$(OUTPUT_DIR)/$(TESTS_DIR)/mfoo < $(TESTS_DIR)/$*.in; \
		echo ""; \
	fi > $@