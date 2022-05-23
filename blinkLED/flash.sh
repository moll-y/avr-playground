#!/usr/bin/bash

avrdude \
  -v \
  -V \
  -p atmega328p \
  -c arduino \
  -P /dev/ttyACM0 \
  -b 115200 \
  -D \
  -U flash:w:pololu.hex:i
