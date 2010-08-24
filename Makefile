all : demo1

# My demo
CFLAGS += -Wall -W -Werror -g
demo1 : demo1.o testdata1.o testdata2.o
clean ::
	$(RM) demo1 demo1.o testdata1.o testdata2.o

# rules

# let's use .bin for the first way
%.o : %.bin
	$(LD) -r -b binary -o $@ $^

# let's use .dat for the second way
%.o : %.S %.dat
	$(CC) $(ASFLAGS) $(CPPFLAGS) $(TARGET_MACH) -c -o $@ $<
