/**/
class UARTConfig{

public:
//Common Baud Rates in UART communication available to the user
    enum class BAUD_RATE{
        B4800 = 4600,
        B9600 = 9600,
        B19200 = 19200,
        B38400 = 38400,
        B57600 = 57600,
        B115200 = 115200
    };
    int askForBoudRate();
    void setBaudRate(int choice, BAUD_RATE baudRate);

private:
    BAUD_RATE baudRate;
    int dataBits;
    int stopBits;
    bool parityEnabled;
};