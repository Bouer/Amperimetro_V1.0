 float get_corriente()  {
      float voltaje;
      float corriente=0;
      long tiempo=millis();
      float Imax=0;
      float Imin=0;
    
      while(millis()-tiempo<500){ //realizamos mediciones durante 0.5 segundos
  
        voltaje = analogRead(A0) * (5.0 / 1023.0);//lectura del sensor
        corriente=0.9*corriente+0.1*((voltaje-2.4955)/Sensibilidadca); //Ecuación  para obtener la corriente
        if(corriente>Imax)Imax=corriente;
        if(corriente<Imin)Imin=corriente;
        }
     return((Imax-Imin)/2);
  }
