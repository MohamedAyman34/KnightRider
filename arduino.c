/*
 * Knight Rider LED Effect
 * For Arduino Mega 2560
 * 
 * Connects 6 LEDs to digital pins 2-7
 * Creates a back-and-forth scanning pattern every 200ms
 */

const int ledPins[6] = {2, 3, 4, 5, 6, 7}; // Digital pins on Arduino Mega
int currentIndex = 0;                      // Current LED position
int direction = 1;                         // Direction of movement (+1 or -1)
unsigned long previousMillis = 0;          // Time tracking
const long interval = 200;                 // 200ms interval

void setup() {
  // Initialize Serial for debugging (optional)
  Serial.begin(9600);
  Serial.println("Knight Rider effect starting on Arduino Mega");
  
  // Initialize each pin as output
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
    // Flash each LED briefly during setup to verify connections
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if 200ms has elapsed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Reset timer
    
    // Turn off all LEDs
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    
    // Turn on the current LED
    digitalWrite(ledPins[currentIndex], HIGH);
    
    // Debug output (optional)
    Serial.print("LED at pin ");
    Serial.print(ledPins[currentIndex]);
    Serial.println(" is ON");
    
    // Update position
    currentIndex += direction;
    
    // Reverse direction when reaching either end
    if (currentIndex == 5 || currentIndex == 0) {
      direction = -direction;
    }
  }
}