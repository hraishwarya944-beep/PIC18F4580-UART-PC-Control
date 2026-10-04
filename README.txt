PROJECT 5 - UART PC CONTROL

PIC18F4580, 20 MHz, 16x2 CLCD, EUSART/UART.

Connections:
RC6/TX -> USB-to-TTL RX
RC7/RX -> USB-to-TTL TX
GND -> GND
RB0 -> LED
PORTD -> CLCD data D0-D7
RC0 -> CLCD RW
RC1 -> CLCD RS
RC2 -> CLCD EN

UART settings:
9600 baud, 8 data bits, no parity, 1 stop bit (8N1).

Commands:
ON  -> LED ON
OFF -> LED OFF

Concepts:
EUSART/UART, serial communication, baud rate, TX/RX, command parsing, CLCD, GPIO.
