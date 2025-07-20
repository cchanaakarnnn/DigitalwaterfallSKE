int pin[] = {2,3,4,5,6,7,8,9,10,11,12,13,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,50,51,52,53,46,47,48,49};
int num = sizeof(pin) / sizeof(pin[0]);
int hz = 40;

void setup() {
  Serial.begin(250000);

  for (int i = 0; i < num; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], HIGH);
  }
  while (!Serial) {}  // Wait for serial connection
}

void loop() {
  // Check if there is data available in the serial buffer
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    // Ensure the message length matches the number of pins
    
      for (int i = 0; i < message.length(); i++) {
      digitalWrite(pin[i%40], message[message.length()-i-1] - '0');
      Serial.print(message[i]);
      if(i%40 == 39 && i - message.length() > 40){
        Serial.print('\n');
        delay(1000/hz);
      }
      
    }
    for(int i=0;i<num;i++){
      digitalWrite(pin[i], HIGH);
    }
    
    
    
    Serial.flush();
    Serial.println("q");
  }
}
