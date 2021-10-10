
# include "pitches.h";

int greenLEDPin = 2;
int redLEDPin = 3;
int speakerPin = 4;
int dial3LEDPin = 5;
int dial2LEDPin = 6;
int dial1LEDPin = 7;
int dial1Pin = A0;
int dial2Pin = A1;
int dial3Pin = A2;
int buttonPin = A3;

int dial1Reading;
int dial2Reading;
int dial3Reading;

int lastDial1Reading;
int lastDial2Reading;
int lastDial3Reading;

// notes in the melody:
  int melodyIncorrect[] = {
  NOTE_C4, NOTE_B2 , NOTE_B1};

  int melodyCorrect[] = {
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_G5};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurationsIncorrect[] = {8,8,4};
  int noteDurationsCorrect[] = {8,8,8,2};
  

void setup() {
  // put your setup code here, to run once;
  pinMode(dial1Pin, INPUT);
  pinMode(dial2Pin, INPUT);
  pinMode(dial2Pin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(dial1LEDPin, OUTPUT);
  pinMode(dial2LEDPin, OUTPUT);
  pinMode(dial3LEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dial1Reading = analogRead(dial1Pin)/171;
  dial2Reading = analogRead(dial2Pin)/171;
  dial3Reading = analogRead(dial3Pin)/171;

  Serial.println("---");
  Serial.println("Current combination:");
  Serial.println(dial1Reading);
  Serial.println(dial2Reading);
  Serial.println(dial3Reading);


 if (dial1Reading != lastDial1Reading) { 
  Serial.println("dial 1 changed");
    // DIAL 1: play different tones for different dial readings
    if (dial1Reading == 0) { tone(4, NOTE_C3, 200); };
    if (dial1Reading == 1) { tone(4, NOTE_D3, 200); };
    if (dial1Reading == 2) { tone(4, NOTE_E3, 200); };
    if (dial1Reading == 3) { tone(4, NOTE_F3, 200); };
    if (dial1Reading == 4) { tone(4, NOTE_G3, 200); };
    if (dial1Reading == 5) { tone(4, NOTE_A3, 200); };
    digitalWrite(dial1LEDPin, HIGH);
    digitalWrite(dial2LEDPin, LOW);
    digitalWrite(dial3LEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  lastDial1Reading = dial1Reading;
 };

  if (dial2Reading != lastDial2Reading) { 
  Serial.println("dial 2 changed");
    // DIAL 2: play different tones for different dial readings
    if (dial2Reading == 0) { tone(4, NOTE_C4, 200); };
    if (dial2Reading == 1) { tone(4, NOTE_D4, 200); };
    if (dial2Reading == 2) { tone(4, NOTE_E4, 200); };
    if (dial2Reading == 3) { tone(4, NOTE_F4, 200); };
    if (dial2Reading == 4) { tone(4, NOTE_G4, 200); };
    if (dial2Reading == 5) { tone(4, NOTE_A4, 200); };
    digitalWrite(dial1LEDPin, LOW);
    digitalWrite(dial2LEDPin, HIGH);
    digitalWrite(dial3LEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  lastDial2Reading = dial2Reading;
 };


   if (dial3Reading != lastDial3Reading) { 
  Serial.println("dial 3 changed");
    // DIAL 3: play different tones for different dial readings
    if (dial3Reading == 0) { tone(4, NOTE_C5, 200); };
    if (dial3Reading == 1) { tone(4, NOTE_D5, 200); };
    if (dial3Reading == 2) { tone(4, NOTE_E5, 200); };
    if (dial3Reading == 3) { tone(4, NOTE_F5, 200); };
    if (dial3Reading == 4) { tone(4, NOTE_G5, 200); };
    if (dial3Reading == 5) { tone(4, NOTE_A5, 200); };
    digitalWrite(dial1LEDPin, LOW);
    digitalWrite(dial2LEDPin, LOW);
    digitalWrite(dial3LEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  lastDial3Reading = dial3Reading;
 };


  int buttonState = digitalRead(buttonPin);

   if (buttonState  == HIGH) {
      digitalWrite(dial1LEDPin, LOW);
      digitalWrite(dial2LEDPin, LOW);
      digitalWrite(dial3LEDPin, LOW);
      // CHECK if correct: play different tones & light red or green to check if the code is correct
        if ((dial1Reading == 5) && (dial2Reading == 3) && (dial3Reading == 2)) {
          Serial.println("Correct combination!");
          digitalWrite(greenLEDPin, HIGH);
          digitalWrite(redLEDPin, LOW);
         // MELODY iterate over the notes of the melody:
          for (int thisNote = 0; thisNote < 4; thisNote++) {
          int noteDuration = 1000/noteDurationsCorrect[thisNote];
          tone(speakerPin, melodyCorrect[thisNote],noteDuration);
     
          //pause for the note's duration plus 30 ms:
          delay(noteDuration +30);
          //noTone(speakerPin);
           } 
          } else {
              digitalWrite(greenLEDPin, LOW);
              digitalWrite(redLEDPin, HIGH);
              Serial.println("Incorrect combination!");
              // MELODY iterate over the notes of the melody:
              for (int thisNote = 0; thisNote < 3; thisNote++) {
               int noteDuration = 1000/noteDurationsIncorrect[thisNote];
                tone(speakerPin, melodyIncorrect[thisNote],noteDuration);
           
              //pause for the note's duration plus 30 ms:
              delay(530);
              //noTone(speakerPin);
              };
          }; 
      } 
//      else if (buttonPressed == 0) { 
//        Serial.println("Press button to check!"); 
//        digitalWrite(greenLEDPin, LOW);
//        digitalWrite(redLEDPin, LOW);
      };
