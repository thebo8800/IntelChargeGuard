// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;
const int greenPin = 2;
const int redPin = 21;
const int yellowPin = 5;

// variable for storing the potentiometer value
int potValue = 0;

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);

  //2000 volts until things are damages
  int threshold = 1800;
  double constant = 5000/4095;


  if (potValue * constant > threshold) {
    Serial.print("\nRed - Extreme Caution Please Discharge: ");
    Serial.print(potValue * constant);
    Serial.println(" millivolts");

    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    
  }

  else if (potValue * constant > threshold * 2/3) {
    Serial.print("\nYellow - Moderate Caution Please Discharge: ");
    Serial.print(potValue * constant);
    Serial.println(" millivolts");  

    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);


  }

  else if (potValue * constant > threshold / 3) {
    Serial.print("\nGreen - Slight Caution: ");
    Serial.print(potValue * constant);
    Serial.println(" millivolts");

    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }

  else {
    Serial.print("\nNothing - No Caution: ");
    Serial.print(potValue * constant);
    Serial.println(" millivolts");

    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);


  }

  delay(50);
}