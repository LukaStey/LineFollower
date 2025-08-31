# Gebruiksaanwijzing

### opladen / vervangen batterijen
uitleg over het opladen of vervangen van de batterijen

### draadloze communicatie
#### verbinding maken
De ESP32 heeft ingebouwde Wi-Fi en Bluetooth, dus je kunt je robot draadloos verbinden met een laptop of smartphone.

Verbinden via Bluetooth (Serial):

Schakel de robot aan.

Open op je laptop/smartphone een Bluetooth-terminal-app (bijv. Serial Bluetooth Terminal).

Zoek naar het apparaat met naam zoals "ESP32_Robot".

Maak verbinding.

Je kunt nu commando’s typen en de robot zal reageren.

#### commando's
set kp [0..]  (Stel P-waarde van PID-regelaar in.)
set ki [0..]  (Stel I-waarde van PID-regelaar in.)
set kd [0..]  (Stel D-waarde van PID-regelaar in.)
 

### kalibratie
uitleg kalibratie  

### settings
De robot rijdt stabiel met volgende parameters:  
Op basis van tests rijdt de robot stabiel met deze parameters:

baseSpeed ≈ 150

maxSpeed ≈ 255

Kp ≈ 0.05

Ki = 0

Kd = 0

Afhankelijk van vloer en snelheid kunnen deze waarden iets aangepast worden via de draadloze commando’s.

### start/stop button
De schakelaar hangt aan het frame, De middelste positie is de neutrale positie. naar links schakelen is het startsignaal. 
