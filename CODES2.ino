#include <SoftwareSerial.h>
SoftwareSerial MyBlue(0, 1); // RX | TX

// Déclaration des variables
int led = 8; //pin 8 pour la led

String value; // Valeur venant du module Blueetooth

void setup() {
  // Initialisation des valeurs
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Si dans la voie(canal ou port) série il y a quelque chose
  
  if (Serial.available()) {
    
    value = Serial.read(); // Exécuter ce canal en affectant sa valeur à la variable "value"
    digitalWrite(led, HIGH);

    // Si la valeur est "ON", alors que la led s'allume
    if (value == "78" || value == "79") {
      digitalWrite(led, LOW); // On met le pin 8 sous état haut
      Serial.println(value);
    }
    // Si la valeur est "OFF", alors que la led s'éteigne.
    if (value == "70") {
      digitalWrite(led, HIGH); // On met la led sous état bas
      Serial.println(value);
    }
  }
  //digitalWrite(led, HIGH);
}
