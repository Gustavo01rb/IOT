#include "config.hpp"
#include "lcd_controller.hpp"
#include "rfid_controller.hpp"

LCD_controller lcd_component;
RFID_controller rfid_component;

void setup()
{
    Serial.begin(9600);
    lcd_component = LCD_controller();
    rfid_component = RFID_controller();
    rfid_component.init();
    pinMode(RELE_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
    if (rfid_component.check_new_card_presence())
        return;
    rfid_component.read_tag();
    String person = rfid_component.check_data();
    lcd_component.welcome_message(person);
    lcd_component.default_message();
}
