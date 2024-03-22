CFLAGS = -c 
LDFLAGS = -std=c11 
SOURCE = $(wildcard s21_*.c)
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
UNAME_S := $(shell uname -s)
APP = build/SmartCalc.app
NEW_TEST_SRC=$(wildcard ./s21_tests/*.c)

ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB = -lcheck
endif

all: install

s21_calculator.a:
	@gcc $(CFLAGS) $(SOURCE)
	@ar rcs $@ $(OBJECTS)
	rm -rf *.o
	ranlib s21_calculator.a

test: s21_calculator.a
	@gcc $(LDFLAGS) ${NEW_TEST_SRC}  s21_calculator.a -o test $(ADD_LIB)
	./test

clean:
	-rm -rf build*
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./gcov_report
	-rm -fr report
	-rm -fr test
	-rm -rf *.txt

	

.PHONY:	s21_calculator.a test prov valgrind
