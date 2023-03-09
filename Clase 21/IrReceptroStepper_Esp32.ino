#include <Stepper.h>
#include <IRremote.h>

int RECV_PIN = 15;

IRrecv irrecv(RECV_PIN);
 
decode_results results;

int val;
double stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Pin inversion to make the library work

void setup() {
  irrecv.enableIRIn(); // Start the receiver
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead (Shock);
if (irrecv.decode(&results))
{
Serial.println("Detecta infrarojos");
  myStepper.step(stepsPerRevolution);
}else{
  Serial.println("No detecta infrarojos");
  myStepper.step(-stepsPerRevolution);
}  
}