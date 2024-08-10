/* Eksempelprogram for robotbil i Oppstartsuka 2024. 
Lærer du deg først å forstå dette programmet, vil alt annet bli enklere.
Se hva du kan forandre i koden og deretter observer hvordan 
robotbilen oppfører seg annerledes. */

//Linje 7 og 8 henter biblioteker med kode vi trenger
#include <Wire.h>
#include <Zumo32U4.h>

//Linje 12 til 15 henter underbiblioteker fra Zumo-biblioteket
//Disse brukes f.eks. til å kontrollere motorene
Zumo32U4Motors motors; //Underbibliotek kalt "Zumo32U4Motors", "motors" er så begrepet brukt i koden
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;
Zumo32U4OLED display;

//Egenlaget funksjon for å kjøre bilen fremover
void fremover() {
  motors.setLeftSpeed(400); //Setter maks hastighet på venstre motor
  motors.setRightSpeed(400); //Setter maks hastighet på høyre motor
}

//Egenlaget funksjon for å kjøre bilen bakover
void bakover() {
  motors.setLeftSpeed(-400); //Kjører bakover (minus tegn)
  motors.setRightSpeed(-400); //Kjører bakover (minus tegn)
}

//Egenlaget funksjon for å stoppe bilen
void stopp() {
  motors.setLeftSpeed(0); //Skrur av venstre motor
  motors.setRightSpeed(0); //Skrur av høyre motor
}

//Funksjonen setup() og all kode inni kjøres KUN en gang ved oppstart
void setup() { 
  Serial.begin(9600); //Starter kommunikasjon med PC-en din (Serial Monitor)

  buzzer.play(">g32>>c32"); //Spiller av en fin lyd på robotbilens buzzer

  display.clear(); //Fjerner all tekst fra OLED-skjermen
  display.print(F("Trykk A")); //Skriver tekst til OLED-skjermen
  display.gotoXY(0, 1); //Flytter hvor tekst plasseres på OLED-skjermen
  display.print(F("for demo"));

  buttonA.waitForButton(); //Stopper hele programmet til A-knappen er trykket på
  buzzer.play("L16 cdegreg4");
  delay(1500); //Venter/stopper programmet i 1,5 sekund

  fremover(); //Kjører fremover med egenlaget funksjon
  delay(2500); //Venter
  bakover(); //Kjører bakover
  delay(2500); //Venter
  stopp(); //Stopper
}

//Funksjonen loop() og all kode inni kjøres "hele tiden"
//Unntaket er når funksjonen delay() brukes, da venter programmet i antall millisekunder
void loop() {
  display.clear();
  display.print(F("I am"));
  Serial.println("I am"); //Skriver beskjed til serial monitor (på PC-en)
  ledRed(false); //Skrur av rødt LED-lys på bilen
  delay(1000);

  display.clear();
  display.print(F("Zumo"));
  Serial.println("Zumo");
  ledRed(true); //Skrur på rødt LED-lys på bilen
  delay(1000);
}