#define boton 4
int contador = 0;

void setup(){
pinMode(boton, INPUT);
Serial.begin(9600);
}

void loop(){
  int estado = digitalRead(boton);
  if (estado == HIGH){
    contador++;
    Serial.println(contador);
    delay(1000);
  }
}