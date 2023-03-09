#include <TM1637Display.h>

#define boton 4
int contador = 0;
const int CLK = 2;
const int DIO = 5;

TM1637Display display(CLK, DIO);

const uint8_t linea[] = {
  SEG_G, SEG_G, SEG_G, SEG_G
};

void setup(){
pinMode(boton, INPUT);
Serial.begin(115200);
display.setBrightness(5);
}

void loop(){
int estado = digitalRead(boton);
if (estado == HIGH){
  contador++;
Serial.println(contador);
display.setSegments(linea);
delay(1000);
}
}