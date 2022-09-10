//Declare the pins for the buttons
const int doorButton=2;
const int bootButton=3;
const int beltButton=4;

//Declare the LED buttons
const int doorRedLed=8;
const int doorGreenLed=9;
const int beltRedLed=10;
const int beltGreenLed=11;

//Set the states of the buttons to be low 
int beltState=0;
int doorState=0;
int bootState=0;

void setup() {
  //The buttons are declared as inputs
  pinMode(doorButton,INPUT);
  pinMode (bootButton, INPUT);
  pinMode (beltButton, INPUT);

  //The LEDs are declared as outputs
  pinMode (doorRedLed, OUTPUT);
  pinMode (doorGreenLed, OUTPUT);
  pinMode (beltRedLed, OUTPUT);
  pinMode (beltGreenLed, OUTPUT);
}

void loop() {
  //Read the states of the buttons
  doorState=digitalRead (doorButton);
  bootState=digitalRead (bootButton);
  beltState=digitalRead (beltButton);


  //check state of the door and boot
  if (doorState && bootState == HIGH){
    digitalWrite (doorGreenLed, HIGH); 
    digitalWrite (doorRedLed, LOW);         
  } else {
    digitalWrite (doorRedLed, HIGH);
    digitalWrite (doorGreenLed, LOW);
  }

  //check state of the belts
  if (beltState == HIGH){
    digitalWrite (beltGreenLed, HIGH);
    digitalWrite (beltRedLed, LOW);
  } else{
    digitalWrite (beltRedLed, HIGH);
    digitalWrite (beltGreenLed, LOW);
  }
}
