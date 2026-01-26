# SMART-PARKING-SYSTEM
<H1>🌟INTRODUCTION</H1>
<BR>
<pre>
Automated Car Parking System (ACPS) uses modern technologies such as sensors,
controllers, and automation mechanisms to park vehicles efficiently without human intervention.
By intelligently detecting available parking slots and maneuvering vehicles into them,
this system optimizes parking space usage, enhances safety, and reduces the time 
and effort required from drivers.
</pre>
<BR>
<HR>
<BR>
<H1>🌟INTRODUCTION</H1>
<pre>Automatic Vehicle Detection (IR Sensors)
1.IR sensors are used at the entry and inside the parking area to detect the presence of vehicles.
  When a car approaches the gate, the IR sensor sends a signal to the Arduino, 
  enabling the system to recognize vehicle entry or exit automatically without human involvement.

2.Central Control and Decision Making (Arduino Uno)
  The Arduino Uno acts as the brain of the system. It continuously reads data from the IR sensors,
  decides whether a parking slot is available or occupied, controls the servo motor gate,
  and updates the display and IoT status in real time.

3.Automated Entry Gate Control (Servo Motor)
  The servo motor functions as the parking gate or barrier. Based on commands from the Arduino,
  it opens the gate when a slot is available and closes it after the vehicle enters,
  ensuring controlled and secure access to the parking area.

4.Real-Time Parking Status Display (LCD with I2C Module)
  A 16×2 LCD displays real-time messages such as “Slot Available,” “Parking Full,” or “Welcome.”
  The I2C module reduces wiring complexity while allowing the Arduino to clearly communicate
  parking status to users at the entrance.

5.IoT-Based Remote Monitoring
  The IoT module sends parking slot data to a cloud platform, allowing users to check parking
  availability through a mobile app or web interface. This feature helps drivers plan parking
  in advance and reduces  unnecessary traffic congestion.

6.Efficient and Secure System Integration (Jumper Wires & Power Management)
  Jumper wires ensure reliable connections between all components, enabling smooth data and 
  power transfer. Proper integration ensures accurate sensor readings, stable motor operation,
  and overall system reliability and safety. 
</pre>
<br>
<hr>
<br>
<H1>🌟CIRCUIT DIAGRAM</H1>
<img width="819" height="565" alt="Screenshot 2026-01-26 104544" src="https://github.com/user-attachments/assets/98ebfaf2-9b28-4af0-9b71-16aafef150da" />
<br>
<hr>
<br>
<H1>🌟PROJECT IMAGE</H1>
<img width="610" height="899" alt="Screenshot 2026-01-26 112132" src="https://github.com/user-attachments/assets/7ceb6c89-6e25-4ec7-b231-b69508b84f3f" />

<br>
<hr>
<br>
<H1>🌟BLOCK DIAGRAM</H1>
<img width="823" height="779" alt="Screenshot 2026-01-26 104638" src="https://github.com/user-attachments/assets/16ba8784-dbcb-49f9-9225-ed16fadca291" />
<br>



