# lcd-screen-library
QAPASS 1602A LCD Screen Module driver library, for Atmega328P ( Arduino UNO R3's micro processor )
I followed Patrick Hood Daniel's great videos on the LCD Module, and changed it to fit my own needs.
Link to his channel:
https://www.youtube.com/channel/UCC7ifdmN7ebFo-eXBUZkeiw

## Wire Configuration

The library supports only 8bit data configuration. as such, it must be wired accordingly.
Please connect the following terminals for succesful use:\
LCD Module | Arduino Terminal\
\-----------------------------\
VSS        | LOW\
VDD        | HIGH\
V0         | VARIABLE_VOLTAGE  <-- Connect through a 10kOhm Potentiometer\
RS         | 10\
RW         | 11\
E          | 12\
D0-D7      | 2-9\
A          | HIGH\
K          | LOW\

For further information refer to the datasheet or the Patrick Hood Daniel's youtube videos on the LCD Module


## How to compile and run
You can follow this guide in order to set up AVRdude programmer with your Atmel Studio 7 IDE:
https://www.asensar.com/guide/arduino_atemlstudio/integrate-avrdude-with-atmel-studio.html

After setting up, click tools-> AVRDUDE programmer ( or whichever name you chose ) to program your MCU.

## Notes
I also added an example driver program, you can find how to set up your module and get it ready to display characters
Cheers!
## IDE
Atmel Studio 7

## License
[MIT](https://choosealicense.com/licenses/mit/)
