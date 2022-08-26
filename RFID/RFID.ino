#include "config.hpp"
#include "lcd_controller.hpp"
#include "rfid_controller.hpp"
#include "access_controller.hpp"

LCD_controller   lcd_component;
RFID_controller  rfid_component;
Access_controller access_controller;

void setup()
{
    access_controller = Access_controller();
    lcd_component     = LCD_controller();
    rfid_component    = RFID_controller();
    rfid_component.init();
}

void loop()
{
    if (rfid_component.check_new_card_presence()) return;
    
    rfid_component.read_tag();
    String key = rfid_component.check_data();
    access_controller.check_access(key);
    lcd_component.welcome_message (key);
    lcd_component.default_message();
    access_controller.close();
}