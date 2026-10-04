# UART-Based PC Control using PIC18F4580

## 📌 Project Overview

This project demonstrates **serial communication between a PC and the PIC18F4580 microcontroller using UART/EUSART**.

Commands are entered from a PC terminal and transmitted to the PIC18F4580 through a USB-to-TTL serial interface.

The microcontroller receives the command and performs the corresponding operation.

### Commands

```text
ON  → LED ON
OFF → LED OFF
```

The command/status is also displayed on a **16x2 Character LCD (CLCD)**.

This project demonstrates practical implementation of **UART communication, GPIO control, CLCD interfacing, and command processing**.

---

## 🎯 Objective

The main objective is to establish communication between a PC and PIC18F4580 using UART and control an output device using serial commands.

The project helps in understanding:

* UART/EUSART
* Serial communication
* TX and RX
* Baud rate
* UART frame
* PC-to-microcontroller communication
* Command parsing
* GPIO control
* CLCD interfacing

---

## 🛠️ Hardware Requirements

* PIC18F4580 Microcontroller
* USB-to-TTL / USB-UART converter
* 16x2 Character LCD
* LED
* Resistor
* 20 MHz crystal oscillator
* Breadboard / development board
* Power supply

---

## 💻 Software Requirements

* MPLAB X IDE
* XC8 Compiler
* PIC18F4580 Device Family Pack
* Serial terminal application
* Embedded C

---

## 🔌 Pin Connections

### UART

| PIC18F4580 | Connection   |
| ---------- | ------------ |
| RC6/TX     | USB-UART RX  |
| RC7/RX     | USB-UART TX  |
| GND        | USB-UART GND |

> TX of the PIC is connected to RX of the USB-UART converter, and RX of the PIC is connected to TX of the converter.

### LED

| Component | PIC18F4580 |
| --------- | ---------- |
| LED       | RB0        |

### CLCD

| CLCD Signal | PIC18F4580 |
| ----------- | ---------- |
| Data D0-D7  | PORTD      |
| RW          | RC0        |
| RS          | RC1        |
| EN          | RC2        |

---

## ⚙️ UART Configuration

The UART is configured with:

```text
Baud Rate : 9600
Data Bits : 8
Parity    : None
Stop Bits : 1
```

Therefore, the communication format is:

```text
9600 8N1
```

---

## 🔄 Working Principle

### 1. Initialization

The PIC initializes:

* GPIO
* CLCD
* UART/EUSART

The UART is configured for serial communication.

The CLCD displays:

```text
UART PC CONTROL
CMD: ON / OFF
```

---

### 2. PC Sends Command

A serial terminal is opened on the PC.

The user enters:

```text
ON
```

and presses Enter.

The command is transmitted serially through the USB-UART converter.

---

### 3. PIC Receives Data

The PIC receives each character through the UART RX pin.

For example:

```text
O
N
```

The characters are stored in a command buffer.

When Enter is received, the command is completed.

---

### 4. Command Processing

The received command is compared with predefined commands.

If:

```text
ON
```

is received:

```c
RB0 = 1;
```

The LED turns ON.

If:

```text
OFF
```

is received:

```c
RB0 = 0;
```

The LED turns OFF.

---

### 5. CLCD Display

The result is displayed on the CLCD.

For example:

```text
CMD:
LED ON
```

or:

```text
CMD:
LED OFF
```

For an unknown command:

```text
INVALID CMD
```

is displayed.

---

## 🔄 Communication Flow

```text
        PC / Serial Terminal
                 |
                 |
          USB-to-UART
                 |
        +--------+--------+
        |                 |
       TX                RX
        |                 |
        v                 v
      PIC18F4580 EUSART
                 |
                 v
          Command Buffer
                 |
                 v
         Command Checking
           /           \
          /             \
        ON              OFF
        |                |
        v                v
     LED ON           LED OFF
        \                /
         \              /
          v            v
              CLCD
```

---

## 🧠 Important Concepts

### UART

UART stands for **Universal Asynchronous Receiver/Transmitter**.

It is used for asynchronous serial communication between two devices.

In PIC18F4580, the **EUSART module** is used for UART communication.

### TX

TX means **Transmit**.

It is used to send serial data from the PIC to another device.

### RX

RX means **Receive**.

It is used to receive serial data from another device.

### Baud Rate

Baud rate represents the number of signal symbols transmitted per second.

In this project:

```text
Baud Rate = 9600
```

Both the PC and PIC must use the same baud rate for reliable communication.

### Command Parsing

The received characters are stored in a buffer and compared with predefined strings.

For example:

```text
Received → "ON"
Expected → "ON"
Result   → LED ON
```

---

## 📂 Project Files

```text
main.c
    |
    ├── GPIO configuration
    ├── UART initialization
    ├── Command reception
    ├── Command comparison
    └── LED control

uart.c
    |
    └── UART driver implementation

uart.h
    |
    └── UART function declarations

clcd.c
    |
    └── CLCD driver implementation

clcd.h
    |
    └── CLCD function declarations
```

---

## 🚀 Applications

The same concept can be extended to:

* PC-controlled embedded systems
* Home automation
* Device configuration
* Debugging embedded systems
* Sensor data monitoring
* Industrial control systems
* Serial command interfaces

---

## 📚 Learning Outcome

Through this project, I gained practical understanding of:

* PIC18F4580 EUSART module
* UART communication
* TX/RX operation
* Baud rate configuration
* Serial terminal communication
* Command parsing
* GPIO control
* CLCD interfacing
* Embedded C programming

---


