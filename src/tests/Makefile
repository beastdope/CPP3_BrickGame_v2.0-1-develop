CC = g++
CFLAGS = -Wall -Werror -Wextra -c -std=c++17 -pedantic -fsanitize=address -g
CFLAGS_GCOV = -Wall -Werror -Wextra -std=c++17
CHECK_FLAG = -lgtest -lgtest_main -lm -lsubunit 
VALGRIND_FLAGS  = 	--log-file="valgrind.txt" --tool=memcheck --leak-check=yes --track-origins=yes
GCOV_FLAGS = -ftest-coverage -fprofile-arcs -fno-elide-constructors 
TEST_FLAGS = -lgtest -lpthread
TEST = snake_tests.cpp 
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

# -fno-elide-constructors -fno-default-inline to cover the curly brackets {}
SRC_TESTS = $(wildcard *.cpp)
OBJ_TESTS = $(patsubst %.cpp, %.o, $(SRC_TESTS))

all: clean s21_snake.a

s21_snake.a: $(OBJ)
	ar cr snake_lib.a $(OBJ)
test: $(OBJ) $(OBJ_TESTS) 
	$(CC) $(OBJ) $(OBJ_TESTS) $(CHECK_FLAG) -o test
	./test
		
gcov_report : test
	$(CC) $(CFLAGS_GCOV) $(SRC) $(SRC_TESTS) $(CHECK_FLAG) $(GCOV_FLAGS) -o test_coverage
	./test_coverage
	lcov -c -d . --output-file test_coverage.info
	genhtml test_coverage.info --output-directory html_report
	xdg-open ./html_report/index.html
	
valgrind: clean test
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt

rebuild:
	make clean 
	make all

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf tests/*.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf html_report
	rm -rf valgrind.txt
	rm -rf test_coverage
	rm -rf test

