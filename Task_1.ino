// DEFINE THE PINS for LED'S, RGB's, Buzzers and Push to make Switches 
int red = 9;
int yellow = 8;
int green = 7;
int buttonPin = 2;
int rgbRed = 3;
int rgbBlue = 4;
int rgbGreen = 5;
int buzzer = 6;

// Initial Setup- Input's and Outputs defined 
void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(rgbRed, OUTPUT);
  pinMode(rgbGreen, OUTPUT);
  pinMode(rgbBlue, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

// Main System Loop 
void loop() {

  // "ON-STATE" Green only... wait for traffic flow- Traffic flows normally until the pedestrian button is pressed. 
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(rgbRed, HIGH);   
  digitalWrite(rgbGreen, LOW);  
  digitalWrite(rgbBlue, LOW);


  // WAIT FOR A PEDESTRIAN TO PRESS BUTTON TO CROSS,
  // COMPLETE TRAFFIC LIGHT CYCLE.
  if (digitalRead(buttonPin) == HIGH) {
    delay(2000); // Delay between each LED.
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);// Yellow light for cars. 
    delay(2000);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH); // Red light for cars.
    delay(500);
    digitalWrite(rgbRed, LOW);   
    digitalWrite(rgbGreen, HIGH); // Pedestrian light green. 
    digitalWrite(buzzer, HIGH); // BUZZER On 
    delay(5000);
    digitalWrite(buzzer, LOW); // Buzzer off. 
    digitalWrite(rgbGreen, LOW);
    digitalWrite(rgbRed, HIGH);// Pedestrian Light Red.
    delay(500);
    digitalWrite(yellow, HIGH);
    delay(3000);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW); // Green traffic returns, loop continues. 

    // Bounce on button- Debounces(resets).
    while (digitalRead(buttonPin) == HIGH) {
      delay(10); 
      // loops 
    }
  }
} 
