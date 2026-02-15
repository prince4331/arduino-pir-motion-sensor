//const int motionpin=A0;
//const int ledpin=13;
//const int buzzpin=12; // ledpin,motionpin and buzpin are not changed throughout the process
//int motionsensvalue=0;
//void setup() {
//// put your setup code here, to run once:
//Serial.begin(9600);
//pinMode(ledpin, OUTPUT);
//pinMode(motionpin,INPUT);
//pinMode(buzzpin,OUTPUT);
//}
//void loop() {
//// put your main code here, to run repeatedly:
//motionsensvalue=analogRead(motionpin); // reads analog data from motion sensor
//if (motionsensvalue>=200){
//digitalWrite(ledpin,HIGH);
//tone(buzzpin,100); //turns on led and buzzer
//}
//else {
//digitalWrite(ledpin,LOW); //turns led off led and buzzer
//noTone(buzzpin);
//}
//}



int led = 13;
int pin = 04;
int buzz=05;

int value = 0;
int pirState = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop() {

  value = digitalRead(pin);

  if (value == HIGH) {
    digitalWrite(led, HIGH);
    digitalWrite(buzz, HIGH);

    if (pirState == LOW) {
      Serial.println("Motion Detected!");
      pirState = HIGH;
    }
  }else{
    digitalWrite(led, LOW);
    digitalWrite(buzz, LOW);

    if(pirState == HIGH){
      Serial.println("Motion Ended!");
      pirState = LOW;
      }
    }
}
