void setup() {
  Serial.begin(115200);

pinMode(D3, OUTPUT);
pinMode(D5, OUTPUT);
pinMode(D6, OUTPUT);
}

void loop() {
int A = random(999);
int B = random(999);
int C = random(999);
int D = random(999);
digitalWrite(D3, LOW);
digitalWrite(D5, LOW);
digitalWrite(D6, LOW);

if(A>B&&A<C){
digitalWrite(D3, HIGH);
}

if(C>A&&A<B){
  digitalWrite(D5, HIGH);
}

if(B>C&&B>A&& C<A){
  digitalWrite(D6, HIGH);
}

if(D>A&&D>B&&D>C){
digitalWrite(D3, HIGH);
digitalWrite(D5, HIGH);
digitalWrite(D6, HIGH);
}
delay(350);
}
