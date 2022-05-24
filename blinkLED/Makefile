MCU   := atmega328p
F_CPU := 16000000L  
BAUD  := 9600UL


# Project's name
TARGET := $(lastword $(subst /, ,$(CURDIR)))
BUILD_DIR := ./build

# String substitution for every C/C++ file. As an example, hello.cpp turns into
# ./build/hello.cpp.
SOURCES := $(shell find . -name '*.c')
OBJECTS := $(SOURCES:%=$(BUILD_DIR)/%.o)
HEADERS := $(SOURCES:%=$(BUILD_DIR)/%.h)

CC      := avr-gcc
OBJCOPY := avr-objcopy
OBJDUMP := avr-objdump
AVRSIZE := avr-size
AVRDUDE := avrdude

CFLAGS := -Os -g -std=gnu99 -Wall
# Use short (8-bit) data types 
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 
# Splits up object files per function
CFLAGS += -ffunction-sections -fdata-sections 

#
CPPFLAGS := -DF_CPU=$(F_CPU) -DBAUD=$(BAUD) -I.

#
LDFLAGS := -Wl,-Map,$(BUILD_DIR)/$(TARGET).map 
# Optional, but often ends up with smaller code
LDFLAGS += -Wl,--gc-sections 

#
TARGET_ARCH := -mmcu=$(MCU)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<
	echo "build" $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ -o $@
	echo "target: " $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@
	echo $@


.PHONY: flash

PROGRAMMER_TYPE := arduino
# extra arguments to avrdude: baud rate, chip type, -F flag, etc.
PROGRAMMER_ARGS := -v -V -b 115200 -D -P /dev/ttyACM0

flash: $(BUILD_DIR)/$(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -U flash:w:$<:i
