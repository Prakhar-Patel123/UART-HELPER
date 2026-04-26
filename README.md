# UART Communication Library for ESP32

## Overview

In the quiet rhythm of embedded systems, where bytes whisper across wires and timing is everything, this library was born as a tool of clarity.
It is a lightweight UART abstraction layer for ESP32, designed to simplify serial communication between devices while maintaining discipline in firmware architecture.

---

## Features

* Simple and clean UART initialization
* Configurable baud rate and communication mode
* Line-based communication (`\n` terminated messages)
* Minimal and readable API surface
* Designed with modular firmware principles
* Avoids unnecessary complexity while staying extensible

---

## How to Use

### 1. Include the library

```cpp
#include "uart.h"
```

### 2. Initialize UART in `setup()`

```cpp
void setup() {
    Serial.begin(115200);  // Debugging

    UART_Init(9600, SERIAL_8N1);
}
```

### 3. Send data

```cpp
UART_Send("Hello from ESP32");
```

### 4. Receive data

```cpp
void loop() {
    String message = UART_Read();

    if (message != "") {
        Serial.println("Received: " + message);
    }
}
```

---

## API Reference

### `UART_Init(uint32_t baudRate, uint32_t config)`

Initializes UART2 with the specified baud rate and configuration.

### `UART_Send(const String& message)`

Sends a message over UART with newline termination.

### `UART_Read()`

Reads incoming UART data (non-blocking). Returns empty string if no data is available.

---

## Who Should Use This

* Students learning embedded systems
* Beginners working with ESP32 UART communication
* Developers who want a clean abstraction over raw `HardwareSerial`
* Anyone building ESP-to-ESP communication projects

---

## Limitations

* Uses `String` (heap allocation; not ideal for high-performance systems)
* Blocking read (`readStringUntil`) may introduce latency
* No packet validation (CRC, framing, etc.)
* Not interrupt-driven (polling-based design)

---

## Future Improvements

* Replace `String` with buffer-based communication
* Implement ring buffer for non-blocking reads
* Add packet framing and checksum validation
* Support interrupt-driven UART
* Expand into a full communication protocol layer

---

## The Story Behind This

There is a peculiar struggle every builder faces—not with complexity, but with memory.
The syntax, the parameters, the silent expectations of APIs… they slip through the mind like sand through fingers.

This library was forged from that very friction.

It began as a simple need:
*"Why must I keep looking up the same UART syntax again and again?"*

So instead of revisiting documentation endlessly, I chose to distill it—
to shape it into something reusable, readable, and reliable.

What you see here is not just code.
It is a small rebellion against forgetting.

---

## About the Author

**Name:** Prakhar Patel
**Age (2026):** 13
**Academic Status:** Student, Class 9 (2026–27 Batch)

An embedded systems learner driven by curiosity, discipline, and the quiet joy of building things from first principles.

---

## Contact

If you want to collaborate or suggest improvements, you can contact me.
You can also contact me if you just want to connect.

Email: [**prakharpatel343@gmail.com**](mailto:prakharpatel343@gmail.com)

---

## License

This project is fully open source.
Use it, modify it, improve it, and build upon it freely.

---

## Closing Note

Every abstraction is a step toward mastery—
not by hiding complexity, but by organizing it.

Keep building. Keep refining. 
