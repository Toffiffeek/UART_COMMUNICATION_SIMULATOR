/**/
#pragma once

#include<vector>
#include<string>

class UARTFrame{  
    
    public:
    UARTFrame(std::string message);
    std::string message;
    std::vector<bool> frame;

    std::string get_message();
    std::vector<bool> reverse_bits(std::vector<bool> bits);
    std::vector<bool> add_start_stop_bits(std::vector<bool> bits);
    std::vector<bool> add_parity_bit(std::vector<bool> bits);
};