int ledpin=2;                   // Set led pin at Arduino pin 11
int shocksensor=4;               // Set sensor pin at Arduino pin 8
int sensorvalue;                 // initialize variable to store sensor data
void setup()
{
 pinMode(ledpin,OUTPUT);       // LED pin set to output
 pinMode(shocksensor,INPUT);  //shock sensor pin set to input
 Serial.begin(9600);        // set baud rate for Serial communication
}
void loop() 
{
 sensorvalue = digitalRead(shocksensor); // read values from sensor pin and store in variable
 if (sensorvalue==HIGH)      // if shake detected
 // if (sensorvalue==LOW)  // for pull-up configuration
 {
  digitalWrite(ledpin,HIGH);   // turn LED on
  Serial.println("vibration detected system awake"); // Print message 
 }
 else{
  digitalWrite(ledpin,LOW);   // turn LED off
  Serial.println("Sleep mode");  // Print message
 }
 delay(20);                   // delay 
}