const int buttonPin = 2;
int shama = 9; // we need analog output for the Shamas
int nerot[] = {13,12,11,10,8,7,6,5};

int numberOfNer = 0;

int brightness = 200;    // how bright the Shamas will start
int fadeAmount = 5;    // how many points to fade the Shamas by

int buttonState = 0;         // variable for reading the pushbutton status
int buttonOldState = 0;
boolean buttonOn = false;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  for (int i=0; i < 8;i++) {
    pinMode(nerot[i], OUTPUT);
  }
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && buttonOldState != buttonState) {
    // turn LED on:
      numberOfNer++;
      if (numberOfNer == 9) {
        numberOfNer = 1;
      }
      for (int i=0; i < 8;i++) {
        if (i+1 <= numberOfNer) { 
          digitalWrite(nerot[i],HIGH);
        } else {
          digitalWrite(nerot[i],LOW);
        }
    }
  } 
  buttonOldState = buttonState;
  
  // set the brightness of Shamas:
  analogWrite(shama, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 50 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
