# Gebruiksaanwijzing

### opladen / vervangen batterijen
Er word gebruik gemaakt van 18650 Li-Ion batterijen. Deze zijn ook oplaadbaar via microUSB.

### draadloze communicatie
#### verbinding maken
De ESP32 heeft ingebouwde Wi-Fi en Bluetooth, dus je kunt je robot draadloos verbinden met een laptop of smartphone.

Verbinden via Bluetooth (Serial):

Schakel de robot aan.

Open op je laptop/smartphone een Bluetooth-terminal-app (bijv. Serial Bluetooth Terminal).

Zoek naar het apparaat met naam zoals "ESP32-BT".

Maak verbinding via een seriële communicatie, COM4 met een baudrate van 115200.

Je kunt nu commando’s typen en de robot zal reageren.

#### commando's
set kp [0..]  (Stel P-waarde van PID-regelaar in.)
set ki [0..]  (Stel I-waarde van PID-regelaar in.)
set kd [0..]  (Stel D-waarde van PID-regelaar in.)

set power [0..]  (Stel de snelheid in.)
set Cycle time [0..] (Stel de tijd in waarin één cyclus overlopen wordt.)

Calibrate black (laat de sensoren weten welke waarde's zwart zijn)
Calibrate white (laat de sensoren weten welke waarde's wit zijn)

### kalibratie
Typ in de seriële communicatie "Calibrate black" of "Calibrate white" om de sensoren te kalibreren om te detecteren wat het verschil tussen zwart en wit is.   

### settings
De robot rijdt stabiel met volgende parameters:  
Op basis van tests rijdt de robot stabiel met deze parameters:

baseSpeed ≈ 150
maxSpeed ≈ 255

Cycle time = 1000 (µs)

Kp ≈ 0.05
Kd 
Ki = 0
Diff = 0.5


Kd = 0

Afhankelijk van vloer en snelheid kunnen deze waarden iets aangepast worden via de draadloze commando’s.

### start/stop button
De schakelaar hangt aan het frame, De middelste positie is de neutrale positie. naar links schakelen is het startsignaal. 
