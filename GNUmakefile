.DELETE_ON_ERROR:

CXX ?= g++
AR ?= ar

CFLAGS += -I include -fstack-protector-all
CFLAGS += -O2 -Wall -W -Werror -ggdb -fPIC

INC := $(shell find include -type f -name \*.h -print)


OBJS := obj/ystring.o

all: lib/libb0n.a \
     test

test: test/ut_ystring
	./test/ut_ystring


lib/libb0n.a: $(OBJS)
	$(AR) rcs $@ $^

obj/%.o: src/%.cpp $(INC)
	$(CXX) $(CFLAGS) -Wno-deprecated -c $< -o $@

test/ut_ystring: $(OBJS) src/ut_ystring.cpp
	$(CXX) $(CFLAGS)  src/ut_ystring.cpp -lcppunit $< -o $@

clean:
	@rm -f obj/*
	@rm -f lib/*
	@rm -f test/*
