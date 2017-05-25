#!/opt/local/bin/fish
dfu-programmer atmega32u4 erase
dfu-programmer atmega32u4 flash fc660c.hex
dfu-programmer atmega32u4 reset
