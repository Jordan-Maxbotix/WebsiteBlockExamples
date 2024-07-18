#define MaxSonarPin A0  //Which pin on the Arduino is the Analog voltage line from the MaxBotix sensor connected to? This needs to be an analog input.

int analogData = 0;               //Used to store the raw analog measurements
int rangeDataCM = 0;              //Used to convert the measurement into centimeters

void setup() {
  Serial.begin(115200);           //Setup a serial connection with the host computer.
  pinMode(MaxSonarPin, INPUT);    //Setup the analog pin so that it can measure values from the sensor

}

void loop() {
  // put your main code here, to run repeatedly:
  analogData = analogRead(MaxSonarPin);   //Return an analog measure. This is 10 Bit by default on Arduino boards

  rangeDataCM = analogData;       //The MB1200 has an output resolution of 10 Bits.
                                  //This means there is 1024 available values. The output is scaled such that 1 Bit equals 1 cm.
                                  //The Arduino also defaults to this same resolution, and as such the analog read is already in
                                  //units of centimeters. If you use a sensor with a different scale factor, or set the arduino
                                  //to a different resolution, you may need to multiple or divide this variable by that scale factor.

  Serial.print("Range data = ");  //Send a string to Arduino Serial Monitor
  Serial.println(rangeDataCM);    //Send the range data just after that string, and then start a new line.
}
