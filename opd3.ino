const int LDR_PIN = A0;
const int LED_D3 = 3;
const int LED_D5 = 5;
const int LED_D6 = 6;

int ldrValue = 0;
int ldrMin = 1023;
int ldrMax = 0;

void setup() {
  pinMode(LED_D3, OUTPUT);
  pinMode(LED_D5, OUTPUT);
  pinMode(LED_D6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(LDR_PIN);
  updateLDRMinMax(ldrValue);

  digitalWrite(LED_D3, isLowLight(ldrValue) ? HIGH : LOW);
  controlLEDs(ldrValue);

  Serial.println(createJSON(ldrValue, ldrMin, ldrMax));
  delay(1000);
}

bool isLowLight(int value) {
  return value < 500;
}

void controlLEDs(int value) {
  digitalWrite(LED_D5, (value >= 500 && value < 700) ? HIGH : LOW);
  digitalWrite(LED_D6, (value >= 700) ? HIGH : LOW);
}

void updateLDRMinMax(int value) {
  if (value < ldrMin) ldrMin = value;
  if (value > ldrMax) ldrMax = value;
}

String createJSON(int current, int min, int max) {
  return "{\"Huidige waarde van de LDR\": " + String(current) + 
         ", \"Laagst gemeten waarde van de LDR\": " + String(min) + 
         ", \"Hoogst gemeten waarde van de LDR\": " + String(max) + "}";
}
