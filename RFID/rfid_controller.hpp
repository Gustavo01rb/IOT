#pragma once

#include "Arduino.h"
#include "config.hpp"
#include <SPI.h>
#include <MFRC522.h>

class RFID_controller{
    private:
        MFRC522 component;
        String last_tag;
    
    public:
        RFID_controller();
        void   init();
        bool   check_new_card_presence();
        void   read_tag();
        String check_data();
};