#!/usr/bin/bash

avr-gcc -Os \
  -g \
  -std=gnu99 \
  -Wall \
  -funsigned-char \
  -funsigned-bitfields \
  -fpack-struct \
  -fshort-enums  \
  -ffunction-sections \
  -fdata-sections \
  -DF_CPU=16000000L \
  -DBAUD=9600UL \
  -I. -Ilib/ \
  -mmcu=atmega328p \
  -c -o main.o main.c

avr-gcc \
  -Wl,-Map,pololu.map  \
  -Wl,--gc-sections  \
  -mmcu=atmega328p main.o \
  -o pololu.elf

avr-objcopy \
  -j .text \
  -j .data \
  -O ihex pololu.elf pololu.hex
