/*
 *  The circuit:
 * ESC lead attached to 11 and ground
 * pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground
 * 
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define OUTPIN 11
#define BUTTON 2
int buttonState;
int looptime = 2500;
int lastButtonState = LOW;

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

volatile int pulseDelay = 1000;

void setup()
{
    pinMode(OUTPIN, OUTPUT);
    pinMode(BUTTON, INPUT);
    Serial.begin(115200);
 
    // initialize Timer1
    cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
 
    // set compare match register to desired timer count:
    OCR1A = looptime*16;
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    // Set CS10 bit so timer runs at clock speed:
    TCCR1B |= (1 << CS10);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    // enable global interrupts:
    sei();
    Serial.println("Setup Complete");
    Serial.println("Waiting for Test Sequence Start");
}
 
void loop(){
  int reading = digitalRead(BUTTON);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        testSequence();
      }
    }
  }
  lastButtonState = reading;
}

void testSequence() {
    Serial.println("Test Sequence Start");
    
    Serial.println("Ramp Up Throttle");
    for (int i = 1080; i < 2000; i++) {
      pulseDelay = i;
      delay(5);
    }
    delay(1000);
    Serial.println("Ramp Down Throttle");
    for (int i = 2000; i > 1080; i--) {
      pulseDelay = i;
      delay(5);
    }
   
    delay(3000);
    
    pulseDelay = 1080;  // 
    Serial.println("Idle Throttle");
    delay(3000);
    
    pulseDelay = 1500;  // 
    Serial.println("50% throttle");
    delay(3000);
    
    pulseDelay = 1750;  // 
    Serial.println("75% throttle");
    delay(2000); 
    
    pulseDelay = 2000;  // 
    Serial.println("100% throttle");
    delay(2000); 
    
    pulseDelay = 1500;  // 
    Serial.println("50% throttle");
    delay(2000);
    
    pulseDelay = 2000;  // 
    Serial.println("100% throttle");
    delay(2000); 
    
    pulseDelay = 1250;  // 
    Serial.println("25% throttle");
    delay(2000);
    
    pulseDelay = 2000;  // 
    Serial.println("100% throttle");
    delay(2000); 
    
    pulseDelay = 1080;  // 
    Serial.println("Idle Throttle");
    delay(3000);
    
    pulseDelay = 1000;  // 
    Serial.println("Stop");
    Serial.println("Test Sequence End");
}
ISR(TIMER1_COMPA_vect)
{
    digitalWrite(OUTPIN, HIGH);
    cli();          // disable global interrupts
    delayMicroseconds(pulseDelay);
    sei(); // enable global interrupts:
    digitalWrite(OUTPIN, LOW);
}
