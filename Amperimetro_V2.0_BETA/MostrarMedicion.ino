  void MostrarMedicion(String magnitud, float valor, String unidad){
   Serial.print(magnitud);
   Serial.print(valor, 3);
   Serial.println(unidad);
}
