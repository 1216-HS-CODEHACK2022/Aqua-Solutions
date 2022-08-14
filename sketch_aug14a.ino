const int drySoil = 270;

const int pump = 7;
const int Sensor = A0;

void setup() {
  pinMode(pump, OUTPUT);
  pinMode(Sensor, INPUT);
  Serial.begin(9600);
  digitalWrite(pump, HIGH);
  delay(5000);
}

void loop() {
  int moisture = analogRead(Sensor);
  Serial.println(moisture);
  delay(5000);
  
   if (moisture >= drySoil) {
    Serial.println("Watering starts now..moisture is " + String(moisture));
    digitalWrite(pump, LOW);
    delay(100);
    digitalWrite(pump, HIGH);
    Serial.println("Done watering.");
   }
   else {
    Serial.println("Moisture is adequate. No watering needed " + String(moisture));
   }
}
