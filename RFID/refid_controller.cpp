#include "rfid_controller.hpp"

RFID_controller::RFID_controller():component(MFRC522(SS_PIN, RST_PIN)){}

void RFID_controller::init(){
    SPI.begin(); 
    this->component.PCD_Init();
}

bool RFID_controller::check_new_card_presence(){
     return (!this->component.PICC_IsNewCardPresent() || !this->component.PICC_ReadCardSerial());
}

void RFID_controller::read_tag(){
    this->last_tag = "";
    for (byte i = 0; i < component.uid.size; i++) 
        this->last_tag += 
            (component.uid.uidByte[i] < 0x10 ? "0" : "") +
                String(component.uid.uidByte[i], HEX) + 
                    (i!=3 ? ":" : "");

  this->last_tag.toUpperCase();
  delay(ONE_SECOND);
}

String RFID_controller::check_data(){
    if(this->last_tag == GUSTAVO_TAG) return GUSTAVO_NAME;

    return UNDEFINED;
}