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
    if     (name == UNDEFINED   ) this->component.print(" Acesso negado!");
    else if(name == KEYCHAIN_TAG) this->component.print("    ALARME! ");
    else {
        this->component.print("   Bem vindo");
        this->component.setCursor(0,1);
        this->component.print(name);
    }
    delay(ONE_SECOND * 3);
}
