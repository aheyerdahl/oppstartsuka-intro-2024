/* Eksempelprogram for robotbil i Oppstartsuka 2024. 
Lærer du deg først å forstå dette programmet, vil alt annet bli enklere.
Se hva du kan forandre i koden og deretter observer hvordan 
robotbilen oppfører seg annerledes. */

//Linje 7 og 8 henter biblioteker med kode vi trenger
#include <Wire.h>
#include <Zumo32U4.h>

//Linje 12 henter underbiblioteker fra Zumo-biblioteket
//Denne brukes til å kontrollere motorene
Zumo32U4Motors motors; //Underbibliotek kalt "Zumo32U4Motors", "motors" er så begrepet brukt i koden

//Funksjonen setup() og all kode inni kjøres KUN en gang ved oppstart
void setup() { 
  Serial.begin(9600); //Starter kommunikasjon med PC-en din (Serial Monitor)

  delay(5000); //Venter/stopper programmet i 5 sekunder

  motors.setLeftSpeed(400); //Setter maks hastighet på venstre motor
  motors.setRightSpeed(400); //Setter maks hastighet på høyre motor

  delay(2500);

  motors.setLeftSpeed(0); //Skrur av venstre motor
  motors.setRightSpeed(0); //Skrur av høyre motor
}

//Funksjonen loop() og all kode inni kjøres "hele tiden"
//Unntaket er når funksjonen delay() brukes, da venter programmet i antall millisekunder
void loop() {
  Serial.println("I am"); //Skriver beskjed til serial monitor (på PC-en)
  ledRed(false); //Skrur av rødt LED-lys på bilen
  delay(1000);

  Serial.println("Zumo");
  ledRed(true); //Skrur på rødt LED-lys på bilen
  delay(1000);
}