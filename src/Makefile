OS=$(shell uname)
CC = g++

# Flags
MAIN_FLAGS = -std=c++17
DEBUG_FLAGS = -Wall -Wextra -Werror
VALG_FLAGS = -g
POSIX_FLAG = -D_POSIX_C_SOURCE=201706L
COVLAGS =-fprofile-arcs -ftest-coverage
GTEST_FLAGS = -L/usr/lib/ -lgtest -lgtest_main -pthread #-Wl,--no-warn-search-mismatch
LIBFLAGS= $(GTEST_FLAGS)
ifeq ($(OS), Linux)
#	 GTEST_FLAGS += -lsubunit
endif

# Checkers
VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(VALG_FILE) ./
CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem  --force --check-level=exhaustive --checkers-report=$(CPPCHECK_FILE) 
CLANG = clang-format --style=Google

# directories 
BUILD_DIR = ../build
SRC_DIR=src
TEST_DIR=tests
OBJ_DIR = $(BUILD_DIR)/service_files
COV_DIR = $(BUILD_DIR)/coverage
VALG_FILE = $(BUILD_DIR)/RESULT_VALGRIND.txt
CPPCHECK_FILE = $(BUILD_DIR)/RESULT_CPPCHECK.txt

PROJECT_NAME=s21_containers

# continer files 
MAIN_HEADER=$(SRC_DIR)/$(PROJECT_NAME:=.hpp)
HEAD_FILES_stack = $(shell find $(SRC_DIR)/stack -type f -name '*.hpp')
HEAD_FILES_AVLtree = $(shell find $(SRC_DIR)/AVLtree -type f -name '*.hpp')
HEAD_FILES = $(shell find $(SRC_DIR)/*/ -type f -name '*.hpp')
TPP_FILES = $(shell find $(SRC_DIR)/*/ -type f -name '*.tpp')

# test files
TEST_SRC_FILES_stack= $(TEST_DIR)/stack_tests.cc $(TEST_DIR)/stack_tests_outsource.cc
TEST_SRC_FILES_AVLtree= $(TEST_DIR)/AVLtree_tests.cc
TEST_SRC_FILES = $(shell find $(TEST_DIR)/ -type f -name '*.cc')
TEST_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRC_FILES:.cc=.o)))
TEST_EXEC = $(addprefix $(BUILD_DIR)/, tests) 
TEST_EXEC_stack=$(addprefix $(BUILD_DIR)/, stack_tests)
TEST_EXEC_AVLtree=$(addprefix $(BUILD_DIR)/, AVLtree_tests)


# target specific variables
$(TEST_EXEC_stack):MAIN_FLAGS:= $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG)
$(TEST_EXEC_AVLtree):MAIN_FLAGS:= $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG)
$(TEST_EXEC): MAIN_FLAGS:= $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG) #$(VALG_FLAGS)


.PHONY: test test_stack clean all

# targets
all: test

# tests
$(TEST_EXEC): clear_o $(TEST_OBJ_FILES)
	$(CC) $(MAIN_FLAGS) $(TEST_OBJ_FILES) -o $@ $(LIBFLAGS)
	make -s clear_o

test: $(TEST_EXEC)
	@./$(TEST_EXEC)

# object files
$(OBJ_DIR)/%.o: %.cc
	@$(CC) $(MAIN_FLAGS) -c $< -o $@

$(TEST_EXEC_stack): $(BUILD_DIR)
	$(CC) $(MAIN_FLAGS) $(TEST_SRC_FILES_stack) -o $@ $(LIBFLAGS)

test_stack: $(TEST_EXEC_stack)
	@./$(TEST_EXEC_stack)

$(TEST_EXEC_AVLtree): $(BUILD_DIR)
	$(CC) $(MAIN_FLAGS) $(TEST_SRC_FILES_AVLtree) -o $@ $(LIBFLAGS)

test_AVLtree: $(TEST_EXEC_AVLtree)
	@./$(TEST_EXEC_AVLtree)
# coverage & report



# deployment



#checkers 
clang_all:
	$(CLANG) -i $(HEAD_FILES) $(TEST_SRC_FILES) $(MAIN_HEADER) $(TPP_FILES) 

clang_check:
	@$(CLANG) -n $(HEAD_FILES) $(TEST_SRC_FILES) $(MAIN_HEADER) $(TPP_FILES) 
	$(CLANG) -n $(shell find ../ -type f -name '*.cc' -o -name '*.hpp' -o -name '*.cc' -o -name '*.h')

valgrind_all: $(TEST_EXEC)
	$(VALG)$(TEST_EXEC)

valgrind_stack: $(TEST_EXEC_stack)
	$(VALG)$(TEST_EXEC_stack)

valgrind_AVLtree: $(TEST_EXEC_AVLtree)
	$(VALG)$(TEST_EXEC_AVLtree)

cpp_check:
	$(CPPCHECK) $(shell find $(TEST_DIR) $(SRC_DIR) -type f \( -name '*.cc' -o -name '*.hpp' -o -name '*.cpp' -o -name '*.h'\))

# service
$(OBJ_DIR) $(BUILD_DIR) $(COV_DIR):
	@mkdir -p $@

clear_o: 
	@rm -fr $(OBJ_DIR)

clear:  clear_o
	rm -fr $(BUILD_DIR) 

clean: clear

rebuild_test_stack: clear test_stack
rebuild_test_AVLtree: clear test_AVLtree


