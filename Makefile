# CSE30FA22 PA1B makefile
#
# Instructions: Fix this Makefile by filling in the values for HEAD and OBJ
#

# if you type 'make' without arguments, this is the default
PROG        = printhash
all:        $(PROG)

# header files and the associated object files
HEAD        =  # FILL THIS IN
OBJ         =  # FILL THIS IN

# special libraries
LIB         =
LIBFLAGS    = -L ./ $(LIB)

# select the compiler and flags yopu can over-ride on command line e.g. make DEBUG= 
CC	        = gcc
DEBUG       = -ggdb
CSTD        =
WARN        = -Wall -Wextra -Werror
CDEFS       =
CFLAGS      = -I. $(DEBUG) $(WARN) $(CSTD) $(CDEFS)

# some flags to use with assembler tools
ASLIST	    = -Wa,-adhln
ASFLAGS     =

$(OBJ):     $(HEAD)

# specify how to assemble a .S file
%.o : %.S
	$(CC) $(CFLAGS) $(ASFLAGS)  -c -o $@ $<

# specify how to compile/assemble the target
$(PROG):    $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

# remove binaries
.PHONY: clean clobber
clean:
	rm -f $(OBJ) $(PROG)
