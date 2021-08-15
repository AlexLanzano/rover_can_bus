#include <FlexCAN_T4.h>

FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
CAN_message_t msg;

void setup(void) {
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    Serial.print("CAN bus blink example");
    can1.begin();
    can1.setBaudRate(250000);
}

void loop() {

    if ( can1.read(msg) ) {
        Serial.print("CAN1 ");
        Serial.print("MB: "); Serial.print(msg.mb);
        Serial.print("  ID: 0x"); Serial.print(msg.id, HEX );
        Serial.print("  EXT: "); Serial.print(msg.flags.extended );
        Serial.print("  LEN: "); Serial.print(msg.len);
        Serial.print(" DATA: ");
        for ( uint8_t i = 0; i < msg.len; i++ ) {
            Serial.print(msg.buf[i]); Serial.print(" ");
        }
        Serial.print("  TS: "); Serial.println(msg.timestamp);

        if (msg.id == 0 && msg.len == 1) {
            if (msg.buf[0] == 0) {
                Serial.print(msg.buf[0], HEX);
                digitalWrite(13, LOW);
            } else {
                digitalWrite(13, HIGH);
            }
        }
    }

}
