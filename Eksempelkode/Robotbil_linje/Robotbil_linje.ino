#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;
Zumo32U4OLED display;
Zumo32U4LineSensors lineSensors;

const int NUM_SENSORS = 5;
unsigned int lineSensorValues[NUM_SENSORS];

void calibrateSensors() {
  display.clear(); //Fjerner gammel grafikk på OLED

  //Venter 1 sekund og begynner automaitsk sensor kallibrering
  delay(1000);
  for(int i = 0; i < 120; i++) { //Dette er en for-løkke, de har vi ikke fortalt om
    if (i > 30 && i <= 90) {
      motors.setSpeeds(-200, 200);
    }
    else {
      motors.setSpeeds(200, -200);
    }

    lineSensors.calibrate();
  }
  motors.setSpeeds(0, 0);
}

void setup() {
  lineSensors.initFiveSensors();

  buzzer.play(">g32>>c32");

  display.clear();
  display.print(F("Press A"));
  display.gotoXY(0, 1);
  display.print(F("to calib"));
  buttonA.waitForButton();

  calibrateSensors();

  display.clear();
  display.print(F("Ready!"));
  buzzer.play("L16 cdegreg4");
  while(buzzer.isPlaying());
}

void loop() {
  float position = lineSensors.readLine(lineSensorValues);
  display.clear();
  display.print(position);

  //Skriv kode med if-betingelser her
}
