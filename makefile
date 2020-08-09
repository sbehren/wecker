# CXX=clang++
CXX=g++
INO=arduino-builder
RMF=rm -rf
CXXFLAGS=-pedantic -Wall -Wextra -Wconversion
INO_FLAGS=-fqbn archlinux-arduino:avr:uno -hardware /usr/share/arduino/hardware -tools /usr/bin -warnings all -build-cache ./cache -build-path ./build -libraries libraries
SRCS_ALL=$(wildcard src/*/*.cpp)

# Could not avoid code duplication since make apparently ignored changes to SRCS
SRCS_PC=wecker.cpp $(SRCS_ALL)
OBJS_PC=$(subst .cpp,.o, $(SRCS_PC))
MACROS_PC=PC_ONLY

LDFLAGS_PC=-lncurses
LDFLAGS_INO=

pc: CXXFLAGS += -g -O0 -D$(MACROS_PC)

pc: $(OBJS_PC)
	$(CXX) $(CXXFLAGS) -o wecker $(OBJS_PC) $(LDFLAGS_PC) 

ino:
	$(INO) $(INO_FLAGS) wecker.ino

clean:
	$(RMF) $(OBJS_PC) $(OBJS_INO) build/* cache/* wecker

all:	pc
