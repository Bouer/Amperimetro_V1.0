void leerEncoder( ) { //Funcion de funcionamiento del encoder
  //Rutina del encoder
  int asterisco=0;
        clkEstado = digitalRead(clk);
  if ((clkAnterior == LOW) && (clkEstado == HIGH)) { //MOVIENDO ENCODER ROTATIVO
        Serial.print("Posicion del Encoder: ");
     if (digitalRead(dt) == HIGH) {
         valEncoder = valEncoder - 1;
     if ( valEncoder < 0 ) {
        valEncoder = 1;
        asterisco= 1;
        Serial.print("Encoder hacia la izquierda");
      }
    }
    else {
      valEncoder++;
      if ( valEncoder > 2 ) {
       valEncoder = 2;
       asterisco= 2;
       Serial.print("Encoder hacia la derecha");
      }
    }
    Serial.println(valEncoder);
    delay(300);
  }
  clkAnterior = clkEstado;

  //CICLO DE PULSADOR
  swEstado = digitalRead(sw);
  if (swEstado == LOW && swAnterior == HIGH) {
    Serial.println("Encoder Pulsado");
    pulsw ++;
    delay(300);// REBOOTEO
  }
  swAnterior = swEstado;

if (asterisco< 2) {lcd.setCursor(0,0);lcd.print("*");}
if (asterisco>= 2) {lcd.setCursor(0,1);lcd.print("*");}

  if(pulsw !=0){
      if (valEncoder == 1  ){contador++;pulsw =0;}
      if (valEncoder == 2 ){contador++;pulsw =0;}
  }
}
