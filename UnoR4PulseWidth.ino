#define MaxSonarPin 7                   //Which pin on the Arduino is the Pulse Width from the MaxBotix sensor connected to? This can be any digital IO pin.

int pulseData = 0;                      //Used to store the raw pulse width measurements
int rangeDataCM = 0;                    //Used to convert the measurement into centimeters

void setup() {
  Serial.begin(115200);                 //Setup a serial connection with the host computer.
  pinMode(MaxSonarPin, INPUT);          //Setup the Pulse Width so that it can measure values from the sensor
}

void loop() {
  pulseData = pulseIn(MaxSonarPin);     //Return an pulse width measurement. This will be in microseconds.

  rangeDataCM = pulseData/58;           //Different sensor families will use different scale factors.
                                        //The MB1200 uses 58 Microseconds per centimeter. So we divide by 58 here to convert.

  Serial.print("Range data = ");        //Send a string to Arduino Serial Monitor
  Serial.println(rangeDataCM);          //Send the range data just after that string, and then start a new line.
}
