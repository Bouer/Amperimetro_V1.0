void presentacion(){
lcd.clear();
lcd.setCursor(1,0);
lcd.print("FISICA ELECTRONICA");
lcd.setCursor(2,1);
lcd.print("2R4 - 2do AÑO");
lcd.setCursor(1,2);
lcd.print(" CABRERA MATIAS");
lcd.setCursor(3,3);
lcd.print("LEG: 84261");
delay(2000);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("  AMPERIMETRO");
lcd.setCursor(5,1);
lcd.print("INVASIVO");
lcd.setCursor(0,2);
lcd.print("  POR EFECTO HALL");
lcd.setCursor(7,3);
lcd.print("2021");
delay(2000);
lcd.clear();
}
