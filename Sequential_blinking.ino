// Mapping traffic lights to pins
const int red = 7;
const int yellow = 6;
const int green = 5;
const int buzzer = 8; // Buzzer pin

// Pedestrian button pin
const int button = 2;
volatile bool buttonPressed = false;  // Flag for button press, volatile to avoid optimization

// Configuation function
void setup() {
    pinMode(red, OUTPUT); // Establish pin modes using pinMode(pin, mode) function
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(button, INPUT_PULLUP);  // Internal pull-up resistor enabled

    // Attach interrupt to detect button presses
    // attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
    attachInterrupt(digitalPinToInterrupt(button), buttonPressISR, FALLING); // FALLING: activate interrupt when going from HI to LO (on button press)
}

// Looping function
void loop() { 
    buttonPressed = false;  // Reset button flag at the start of a full cycle

    // Green Light ON, rest OFF
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    noTone(buzzer); // Buzzer off until red

    unsigned long startTime = millis(); // Store time it took to begin in ms using millis() function; return type: unsigned long
    unsigned long greenDuration = 10000;  // Default 10s green phase

    // Check for button press DURING the green phase
    while (millis() - startTime < greenDuration) {
        if (buttonPressed) {
            greenDuration = 2000;  // Shorten to 2s
        }
    }

    // Yellow Light ON, green OFF (Always 2 seconds)
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(2000);

    // Red light ON, yellow light OFF (Always 5 seconds)
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);

    // Changing buzzer tone while red is ON
    for (int i = 0; i < 10; i++) {  
        tone(buzzer, 500 + (i * 100)); // tone(pin, frequency) -- increasing the frequency every 0.25s
        delay(250);
    }
    for (int i = 10; i >= 0; i--) {  
        tone(buzzer, 500 + (i * 100));  // Frequency decreases
        delay(250);
    }

    noTone(buzzer);
    delay(5000);

    // Return to green light after cycle completes
    digitalWrite(red, LOW);
}

// Interrupt service routine
void buttonPressISR() {
    buttonPressed = true;
}
