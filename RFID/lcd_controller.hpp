#pragma once

#include "Arduino.h"
#include "config.hpp"
#include <LiquidCrystal.h>


class LCD_controller{
    private:
        LiquidCrystal component;

    public:
        LCD_controller();
        void default_message();
        void welcome_message(String name);
};