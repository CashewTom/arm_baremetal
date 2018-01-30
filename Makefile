.SUFFIXES: .c .o .s

OBJECTS= \
	startup.o \
	hw.o \
	test.o

PROG= prog

CPU_FLAG= -mcpu=arm926ej-s

.s.o:
	arm-none-eabi-as $(CPU_FLAG) -o $@ $< 

.c.o:
	arm-none-eabi-gcc $(CPU_FLAG) -c -o $@ $< 

.PHONY: all
all: $(PROG)


$(PROG): $(OBJECTS)
	arm-none-eabi-ld -T linker.x -o $(PROG).elf $(OBJECTS) 
	arm-none-eabi-objcopy -O binary $(PROG).elf $(PROG)

.PHONY: sim
sim: $(PROG)
	qemu-system-arm -M versatilepb -nographic -kernel $(PROG)

.PHONY: clean
clean:
	-rm $(OBJECTS) $(PROG) $(PROG).elf
