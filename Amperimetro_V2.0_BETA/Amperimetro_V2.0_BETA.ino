#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);

int pulsacion= 0 ;       // almacena la tecla pulsada MOD PROFE GARCIA
int  contador = 1; 

float Sensibilidadcc = 0.5; // Modelo 30A [A/A] - 0.063
float Sensibilidadca = 0.055; // Modelo 30A [A/A]
int NumMuestras = 100; //muestras del conversorADC
const int PulsadorPin = 0;
int pulsador = 0;


const int clk  = 3;  //PARAMETROS DEL ENCODER
const int dt  = 4;
const int sw  = 2;
const int ledVERDE= 10;
const int ledROJO= 11;

int valEncoder  = 0; // VARIABLES PARA EL ENCODER
bool clkEstado  = LOW;
bool clkAnterior  = HIGH;
bool swEstado  = HIGH;
bool swAnterior  = HIGH;
volatile bool pulsw = LOW;

void setup(){
   Serial.begin(9600); //Config velocidad comunicacion serie
   Serial.println(F("Initialize System"));
        
  pinMode(clk,INPUT); //INICIALIZAMOS LAS VARIABLES
  pinMode(dt,INPUT);
  pinMode(sw,INPUT);
  pinMode(ledVERDE,OUTPUT);
  pinMode(ledROJO,OUTPUT); 
   lcd.init();                  //INICIALIZAMOS LAS VARIABLES DEL LCD
   lcd.backlight();
 //pinMode(PulsadorPin, INPUT);
  
  presentacion(); //EJECUTAMOS LA PRESENTACION POR LCD
}

void loop(){
  
   /*ACA VA LO NUEVO*/
     
 if (pulsacion != 0) {      
    lcd.clear();
    delay(100);
    pulsador = 1;
    pulsw ++;
 } 
 if(contador == 2){ menu_2();accion_2();}
 if(contador == 1){ menu_1();accion_1();}
 ///////// Fin del void loop(), inician las Funciones/////////////// MOD PROFE GARCIA
   //leerEncoder();  // LEEMOS ENCODER
    
    if (pulsador!=0){
    
    digitalWrite(HIGH,ledROJO);
    float voltaje;
    float corrienteSuma = 0;
    for (int i = 0; i < NumMuestras; i++){
      voltaje = analogRead(A0) * 5.0 / 1023.0;
      corrienteSuma += (voltaje - 2.4900) / Sensibilidadcc;
    }
   float corriente = (corrienteSuma / NumMuestras);
   
   MostrarMedicion("Intensidad: ", corriente, " A ,");
   MostrarMedicion("SalidaSensor: ", voltaje, " V");

   if ( (corriente < 0.05) && (corriente > -0.05) ) {
          lcd.clear();
          lcd.setCursor(4,0);
          lcd.print("MEDICION CC");
          lcd.setCursor(0,2);
          lcd.print("I= ");
          lcd.setCursor(3,2);
          lcd.print("SIN LECTURA");
          delay(1000);
        }
    else{  //MEDICION CC
          lcd.clear();
          lcd.setCursor(4,0);
          lcd.print("MEDICION CC");
           
          lcd.setCursor(0,2);
          lcd.print("I= ");
          lcd.setCursor(5,2);
          lcd.print(corriente,3);
          lcd.setCursor(12,2);
          lcd.print(" Amp");
          delay(100);
          lcd.setCursor(0,1);
          lcd.print("V= ");
          lcd.setCursor(6,1);
          lcd.print("4.960");
          lcd.setCursor(12,1);
          lcd.print("Volt");
          delay(1000);
         }
    }
    if (pulsador == 100) { //Pulsador en HIGH - MEDICION CA
  
       float voltaje;
        float get_corriente();
        float corriente=get_corriente();//obtenemos la corriente pico
        float corrienteRMS=corriente*0.707; //Intensidad RMS = Ipico/(2^1/2)
        float potencia=corrienteRMS*223.2; // P=IV watts
   
         MostrarMedicion("Intensidad: ", corriente, "A ,");
         MostrarMedicion("Irms: ", corrienteRMS, "A ,");
         MostrarMedicion("Potencia: ", potencia, "W");
   
         if ( (corriente < 0.100) && (corriente > -0.100) ) {
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("Sin lectura");
          lcd.setCursor(6,1);
          lcd.print("CA");
          delay(1000);
        }
        else {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Irms= ");
          lcd.print(corrienteRMS,3);
          lcd.print(" A");
          lcd.setCursor(14,0);
          lcd.print("CA");
           
          lcd.setCursor(0,1);
          lcd.print("Prms= ");
          lcd.print(potencia,3);
          lcd.print(" W");
          delay(1000);
        }
    }
} 
