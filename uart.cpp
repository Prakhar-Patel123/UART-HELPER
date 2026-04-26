#include "uart.h"

/*
 * Definition of UART2 object.
 * This ensures only one instance exists across the program.
 */
HardwareSerial MySerial(2);

/*
 * Initializes UART2 hardware.
 * Must be called inside setup() before any UART communication.
 */
void UART_Init(uint32_t baudRate, uint32_t config) {
    MySerial.begin(baudRate, config, 16, 17);
}

/*
 * Reads incoming UART data (generic receiver).
 * Checks if data is available to avoid blocking.
 */
String ComToESP() {
    if (MySerial.available()) {
        // Read incoming data until newline character
        return MySerial.readStringUntil('\n');
    }

    // Return empty string if no data received
    return "";
}

/*
 * Sends a message over UART.
 * println() ensures newline termination for proper parsing on receiver side.
 */
void ESPtoESP_Sender(const String& message) {
    MySerial.println(message);
}

/*
 * Dedicated receiver function (mirrors ComToESP).
 * Can be refactored if redundancy is not desired.
 */
String ESPtoESP_Receiver() {
    if (MySerial.available()) {
        return MySerial.readStringUntil('\n');
    }

    return "";
}
