void setup() {
// put your setup code here, to run once:
pinMode(13, OUTPUT);
Serial.begin(9600);
digitalWrite(13, LOW); // Start with LED turned OFF
Serial.println("Please send 1 to turn LED ON or 0 to turn LED OFF");
} 

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available() > 0) {
    int val = Serial.read();     // read the incoming byte:

    if (val == '1'){ // When 1 sent, turn ON LED
      digitalWrite(13, HIGH);
    } else if (val == '0'){ // When 0 sent, turn OFF LED
      digitalWrite(13, LOW); 
    }
  }
}
