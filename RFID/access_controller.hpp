#include "config.hpp"
#include "Arduino.h"

class Access_controller{
    public:
        Access_controller();
    
    public:
        void check_access(String key);
        void close();
};