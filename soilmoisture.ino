const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */
int relaypin = D5;
int S, s;
void setup() 
{
  Serial.begin(9600); /* Define baud rate for serial communication */
  pinMode(relaypin, OUTPUT);
}

void loop() 
{
  s = analogRead(sensor_pin);
  S = 1023 - s;
  S = S * 0.0977;

  //Serial.print("Soil Moisture = ");
  //Serial.print(S);
  //Serial.println("%");

  if (S < 50)
  {
    digitalWrite(relaypin, LOW);
    //Serial.println("Motor is ON");
    delay(100);
  }
  if (S > 50)
  {
    digitalWrite(relaypin, HIGH);
    //Serial.println("Motor is OFF");
    delay(100);
  }

  delay(1000);
}
