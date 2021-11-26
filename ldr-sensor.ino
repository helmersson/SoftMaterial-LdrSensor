// constants won't change. They're used here to set pin numbers:
int ledPin[] =  {2, 3, 4, 5, 6, 7}; // array with LED pins

// an array for how the leds will behave
int ledConf[] = { 1, 1, 1, 1, 1, 1,
                  0, 1, 1, 1, 1, 1,
                  0, 0, 1, 1, 1, 1,
                  0, 0, 0, 1, 1, 1,
                  0, 0, 0, 0, 1, 1,
                  0, 0, 0, 0, 0, 1,
                  0, 0, 0, 0, 0, 0
                };

#define LDR_PIN A0
int sensorValue;


void setup() {
  pinMode(LDR_PIN, INPUT);
  Serial.begin(9600);

// Declare the LED as an output
  for (int i = 0; i < sizeof(ledPin); i++) {
    pinMode(ledPin[i], OUTPUT); 

  }
}

void loop() {
  sensorValue = analogRead(LDR_PIN);

  //constrains the sensorValue from its original values to 0-7 instead
  int mapVal = map(sensorValue, 530, 950, 0, 7);

  //Tells the LEDS when to turn on and off
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPin[i], ledConf[6*mapVal + i]);
  }

  Serial.println(sensorValue);

}
