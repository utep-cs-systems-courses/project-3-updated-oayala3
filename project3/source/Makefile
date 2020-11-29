# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as -mmcu=${CPU} -c
AR		=msp430-eld-ar
all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} led.o lcd.o switches.o buzzer.o main.o stateMachines.o wdInterruptHandler.o  ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lTimer

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf
