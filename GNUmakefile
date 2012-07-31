.DELETE_ON_ERROR:

CXX ?= g++
AR ?= ar

CFLAGS += -I include -fstack-protector-all
CFLAGS += -O2 -Wall -W -Werror -ggdb -fPIC
INC := $(shell find include -type f -name \*.h -print)

OBJS := obj/ystring.o

all: lib/libb0n.a

lib/libb0n.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

obj/%.o: src/%.cpp $(INC)
	$(CXX) $(CFLAGS) -Wno-deprecated -c $< -o $@

clean:
	@rm -f obj/*
	@rm -f lib/*
