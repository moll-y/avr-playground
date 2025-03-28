## Compile
```sh
avr-gcc -mmcu=atmega328p -DF_CPU=8000000UL -Os -c main.c -o main.o
avr-gcc -mmcu=atmega328p main.o -o main.elf
avr-objcopy -O ihex main.elf main.hex
```

## Upload code
```sh
avrdude \
  -v -V \
  -p atmega328p \
  -c stk500v1 \
  -P /dev/ttyACM0 \
  -b19200 \
  -U flash:w:./main.hex:i
```

## Set fuse lf=0xE2, hf=0xD9 ef=0xFF
```sh
avrdude \
  -p atmega328p \
  -c stk500v1 \
  -P /dev/ttyACM0 \
  -b 19200 \
  -U lfuse:w:0xE2:m \
  -U hfuse:w:0xD9:m \
  -U efuse:w:0xFF:m
```
