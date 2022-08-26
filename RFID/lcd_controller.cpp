#include "lcd_controller.hpp"

LCD_controller::LCD_controller():component(LiquidCrystal(RS, EN, D4, D5, D6, D7)){
    this->component.begin(16,2);
    this->default_message();
}

void LCD_controller::default_message(){
    this->component.clear();
    this->component.setCursor(2,0);
    this->component.print("Aproxime seu");
    this->component.setCursor(5,1);
    this->component.print("cartao");
}

void LCD_controller::welcome_message(String name){
    this->component.clear();
    this->component.setCursor(0,0);
    if(name == UNDEFINED){
        this->component.print(" Acesso negado!");
        digitalWrite(RELE_PIN, LOW);
        digitalWrite(LED_PIN, HIGH);
        delay(ONE_SECOND/2);
        digitalWrite(LED_PIN, LOW);
        delay(ONE_SECOND/2);
        digitalWrite(LED_PIN, HIGH);
        delay(ONE_SECOND/2);
        digitalWrite(LED_PIN, LOW);
        return;
    } 
    if(name == KEYCHAIN_TAG){
      this->component.print("    ALARME! ");
      delay(ONE_SECOND*3);
      tone(BUZZER_PIN,440,ONE_SECOND*5);
      return;
    }
    this->component.print("   Bem vindo");
    this->component.setCursor(0,1);
    this->component.print(name);
    digitalWrite(RELE_PIN, HIGH);
    delay(ONE_SECOND * 3);
    digitalWrite(RELE_PIN, LOW);
}
