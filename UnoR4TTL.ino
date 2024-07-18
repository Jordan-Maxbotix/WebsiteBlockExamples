//Note that different sensors can have a different amount of characters in their serial output. Some are 3 characters, some 4, and some 5.

char receiveBuffer[5];                                          //Buffer to contain the received serial data. Last character 
                                                                //will always be 0 because it's needed for ATOI to convert 
                                                                //it to an integer
char newData;                                                   //Temporary variable to store a single incoming character
int receiveIndex = 0;                                           //An index that contains the next spot in the buffer we should write to
int rangeData;                                                  //Used to store the range value after we receive and decode it
bool receiveStarted = false;                                    //A status flag used to remember if we have started receiving a frame
bool receiveComplete = false;                                   //A status flag used to remember if we have a complete transmission or not


void setup() {
  Serial.begin(115200);                                         //Setup a serial connection with the host computer.
  Serial1.begin(9600);                                          //Setup the serial interface on Pin 0 and 1 to receive data from the sensor.
}

void loop() {
  while (receiveComplete == false) {
    newData = Serial1.read();                                  //Read a new character

    if (newData == "R") {                                      //If we receive the start character, clear the RX buffer and
        receiveBuffer[0] = 0;                                  //set our status flags appropriately.
        receiveBuffer[1] = 0;
        receiveBuffer[2] = 0;
        receiveBuffer[3] = 0;
        receiveBuffer[4] = 0;
        receiveIndex = 0;
        receiveStarted = true;
        receiveComplete = false;
    } else if (newData == "\r" & receiveIndex = 4) {            //If we receive the end character
        receiveComplete = true;
    } else if (receiveStarted = true & receiveIndex <= 3) {     //If we receive a character this is neither "R" or "\r" and the buffer
        receiveBuffer[receiveIndex] = newData;                  //isn't full
        receiveIndex += 1;
    }
  }

  rangeData = atoi(receiveBuffer);                              //Take the receive buffer and convert it to an integer (Instead of
                                                                //an ASCII char array)

  Serial.print("Range data = ");                                //Send a string to Arduino Serial Monitor
  Serial.println(rangeData);                                    //Send the range data just after that string, and then start a new line.
}
