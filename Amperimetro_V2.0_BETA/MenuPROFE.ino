void menu_1(){ 
   lcd.setCursor(0,0);
   lcd.print("  MENU PRINCIPAL");
   lcd.setCursor(2,1);
   lcd.print("DC");
   lcd.setCursor(2,2);
   lcd.print("AC");   
}
/////////////////////Accion 1 //////////////////////////////
void accion_1(){ 
  leerEncoder();
  Serial.print("MENU 1");
  
}
/////////////////////Menu_2  //////////////////////////////////
void menu_2(){ 
  lcd.setCursor(0,0);
   lcd.print("MENU DE MODO DC");
  lcd.setCursor(2,1);
   lcd.print("ON");
   lcd.setCursor(2,2);
   lcd.print("OFF");  
}
/////////////////////accion_2  //////////////////////////////////
void accion_2(){ 
  leerEncoder();
  Serial.print("MENU 2");
  if (contador == 3){pulsacion++; contador=0; digitalWrite(HIGH,ledROJO);}
}
