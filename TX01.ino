#include "RCSwitch.h"
// Instantiate an RC-Switch object
RCSwitch mySwitch = RCSwitch();
// Use ATtiny85 physical pin 5 to transmit (Arduino Pin 0)
#define TX_PIN      3
// LED will be connected to physical pin 3 (Arduino Pin 4)
#define LED_PIN     13

int c;
void setup() {
  // put your setup code here, to run once:
 
  
    Serial.begin (9600);
    pinMode(LED_PIN, OUTPUT);
    // Make sure led pin is low  
    digitalWrite(LED_PIN, LOW);


    // Enable transmission on defined pin
    mySwitch.enableTransmit(TX_PIN);
    // Set the desired pulse length in microseconds (Similar to baud rate)
    mySwitch.setPulseLength(500);
    // Set the amount of times to re-transmit each data packet
    mySwitch.setRepeatTransmit(4);

    
}

void loop() {
  // put your main code here, to run repeatedly:
  
   
  //c = Serial.read();
  //Serial.println ( Serial.available());
  //delay (300);

  if (Serial.available() > 0 ) {
    
    c = Serial.read();
    if ( c == '1') {

       digitalWrite(LED_PIN, HIGH);
    
    // This is the data packet that will be transmitted
    unsigned long code = 1373281;

    // Only the first 'length' bits of 'code' will be transmitted
    unsigned int length = 24;
    // Send the data packet
    mySwitch.send(code, length);
    
    // Turn off led when transmission is complete
    digitalWrite(LED_PIN, LOW);
    delay(300); 
      
    }


    if ( c == '2') {

       digitalWrite(LED_PIN, HIGH);
    
    // This is the data packet that will be transmitted
    unsigned long code = 1373282;

    // Only the first 'length' bits of 'code' will be transmitted
    unsigned int length = 24;
    // Send the data packet
    mySwitch.send(code, length);
    
    // Turn off led when transmission is complete
    digitalWrite(LED_PIN, LOW);
    delay(300); 
      
    }
    
  }

}
