# draadloze communicatie proof of concept
minimale hard- en software waarmee aangetoond wordt dat duplex kan gecommuniceerd worden tussen de microcontroller en een [laptop|smartphone] (schappen wat niet past), gebruik makend van [programma] (in te vullen)
<br />
### configuratie
#include "BluetoothSerial.h"

BluetoothSerial serialBT;
char cmd;

void setup() {
  // put your setup code here, to run once:
  serialBT.begin("Esp32-BT");
  pinMode(2, OUTPUT);
  
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(serialBT.available()){
    cmd = serialBT.read();
  }
  if (cmd == '1'){
    digitalWrite(2, HIGH);

  }
  if (cmd == '0'){
    digitalWrite(2, LOW);
  }
  delay(50);
}
### opmerkingen

### gebruiksaanwijzing
- Sluit de ESP32 aan op de PC
- Selecteer de jusite ESP device en COM-poort
- Upload de bovenstaande Code

- Nu kan je de ESP aansluiten op de externe powersource.
- Ga op de PC naar Bluetooth apparaten en voeg een nieuw apparaat toe "ESP32"
- Eenmaal verbonden ga je terug naar de Arduino IDE
- Selecteer je de COM-poort die verbonden is met de Bleutooth device
- En nu kan je 1 of 0 invoeren in de seriële monitor en zal de interne led branden
  -  Zorg dat de baudrate op de correcte waarde staan (9600) 
