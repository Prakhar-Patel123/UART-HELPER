#ifndef UART_H
#define UART_H

#include <Arduino.h>
#include <HardwareSerial.h>

/*
 * External declaration of UART2 interface.
 * Defined in uart.cpp to avoid multiple definition errors.
 * UART2 is typically mapped to GPIO16 (RX) and GPIO17 (TX) on ESP32.
 */
extern HardwareSerial MySerial;

/*
 * Initializes UART2 with:
 * - Baud rate: As You Want
 * - Frame:     As You Want
 * - RX pin:    GPIO16
 * - TX pin:    GPIO17
 */
void UART_Init(uint32_t baudRate, uint32_t config);

/*
 * Reads a message from UART (ESP-to-ESP communication).
 * - Non-blocking check using available()
 * - Reads until newline '\n'
 * Returns:
 *   Received string if available, otherwise empty string
 */
String ComToESP();

/*
 * Sends a message over UART.
 * - Uses println() to append newline delimiter
 * - Accepts const reference to avoid unnecessary copying
 */
void ESPtoESP_Sender(const String& message);

/*
 * Receives a message from UART.
 * - Same behavior as ComToESP (can be merged conceptually)
 * - Returns empty string if no data is available
 */
String ESPtoESP_Receiver();

#endif
