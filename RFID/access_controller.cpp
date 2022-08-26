#include "access_controller.hpp"

Access_controller::Access_controller(){
    pinMode(RELE_PIN  , OUTPUT);
    pinMode(LED_PIN   , OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(RELE_PIN, LOW);
}

void Access_controller::check_access(String key){
    if(key == UNDEFINED){
        digitalWrite(RELE_PIN, LOW);
        for(int i = 0; i < 3; i++){
            digitalWrite(LED_PIN, HIGH);
            delay(ONE_SECOND/2);
            digitalWrite(LED_PIN, LOW);
        }
        return;
    }
    if(key == KEYCHAIN_TAG){
        tone(BUZZER_PIN,440,ONE_SECOND*3);
        return;
    }
    digitalWrite(RELE_PIN, HIGH);
}

void Access_controller::close(){digitalWrite(RELE_PIN, LOW);}