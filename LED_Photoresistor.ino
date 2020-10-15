const int pinLED = 8; // LED connected to digital pin 8
const int pinPhotoRes = A5; // Photoresistor connected to analog pin A5
int value; // Variable to store the read value

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED,OUTPUT);
  pinMode(pinPhotoRes, INPUT);
}

void loop() {
  value = analogRead(pinPhotoRes);
  
  if (value <=60){
    digitalWrite(pinLED,HIGH);
  } else if (value > 60){
    digitalWrite(pinLED,LOW);
  }
}
