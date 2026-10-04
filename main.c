/*
 * Project 5 - UART Based PC Communication using PIC18F4580
 * Hardware: PIC18F4580 + USB-to-TTL/Serial interface + 16x2 CLCD + LED
 * UART: RC6/TX and RC7/RX, 9600 baud
 *
 * Commands from PC:
 *   ON  -> LED ON
 *   OFF -> LED OFF
 *   Any other text -> shown as invalid command
 *
 * CLCD: PORTD data, RC0=RW, RC1=RS, RC2=EN
 * LED : RB0
 */


#include <xc.h>
#include "clcd.h"
#include "uart.h"

static void init_config(void)
{
    ADCON1 = 0x0F;

    TRISB0 = 0;
    RB0 = 0;

    init_clcd();
    init_uart();

    clcd_print("UART PC CONTROL", LINE1(0));
    clcd_print("CMD: ON / OFF", LINE2(0));

    puts("\r\nPIC18F4580 UART Control\r\n");
    puts("Type ON or OFF and press Enter.\r\n");
}

/*
 * Read a command until Enter.
 * Maximum 15 characters because CLCD is 16 columns.
 */
static unsigned char read_command(char *cmd)
{
    unsigned char index = 0;
    unsigned char ch;

    while (1)
    {
        ch = getch();

        if (ch == '\r' || ch == '\n')
        {
            cmd[index] = '\0';
            return index;
        }

        // Backspace
        if (ch == 8)
        {
            if (index > 0)
                index--;
            continue;
        }

        if (index < 15)
        {
            cmd[index++] = ch;
        }

        putch(ch);     // Echo received character to PC
    }
}

static unsigned char string_equal(const char *a, const char *b)
{
    while (*a && *b)
    {
        if (*a != *b)
            return 0;

        a++;
        b++;
    }

    return (*a == '\0' && *b == '\0');
}

void main(void)
{
    char command[16];

    init_config();

    while (1)
    {
        clcd_print("                ", LINE1(0));
        clcd_print("                ", LINE2(0));
        clcd_print("CMD:", LINE1(0));

        read_command(command);

        if (string_equal(command, "ON"))
        {
            RB0 = 1;
            clcd_print("LED ON           ", LINE2(0));
            puts("\r\nLED is ON\r\n");
        }
        else if (string_equal(command, "OFF"))
        {
            RB0 = 0;
            clcd_print("LED OFF          ", LINE2(0));
            puts("\r\nLED is OFF\r\n");
        }
        else
        {
            clcd_print("INVALID CMD      ", LINE2(0));
            puts("\r\nUse ON or OFF\r\n");
        }
    }
}
