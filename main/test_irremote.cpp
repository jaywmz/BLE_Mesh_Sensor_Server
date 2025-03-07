#include <Arduino.h>
#include <IRremote.h>

// Choose a GPIO for IR receive (make sure it is valid for your ESP32-C3 board)
#define IR_RECEIVE_PIN 9  

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

extern "C" void app_main(void); // We'll call our IR test from inside app_main or setup()

void setupIRTest() {
    Serial.begin(115200);
    while (!Serial) {
        delay(10); // Wait for Serial to initialize
    }
    Serial.println("IRremote test code started");

    // Initialize the IR receiver
    irrecv.enableIRIn();
}

void loopIRTest() {
    if (irrecv.decode(&results)) {
        Serial.print("Received IR code: 0x");
        Serial.println(results.value, HEX);
        // Resume for the next code
        irrecv.resume();
    }
    // Add some dummy data output for demonstration
    Serial.println("Dummy IR test message - waiting for IR signal...");
    delay(1000);
}
