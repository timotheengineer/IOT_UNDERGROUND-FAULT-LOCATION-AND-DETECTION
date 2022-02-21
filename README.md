# IOT_UNDERGROUND-FAULT-LOCATION-AND-DETECTION
<Final Year Project 2021>

<img src="Underground_fault _detection_system.jpg">

# Abstract
Fault in power systems is one of the greatest problems that cause power disruptions. It can occur from generation, distribution, and consumer systems. This project will focus mainly on the underground line fault.Underground cables are used more often in urban areas than overhead lines. It is difficult to locate a fault when it occurs, and the process may be time-consuming and costly. The proposed system will find the exact location of the fault and facilitate timely maintenance. The concept of a potential divider network connected across the underground line will be used.
IoT will allow the authority to check faults over the internet while in their respective stations. Therefore, they can alert the technicians who are near the particular location for repair.
A set of resistors represents the length of the cable in kilometres, and faults are created at predefined distances using switches. In case of a fault, there will be a change in current drops, which will be sent to the microcontroller. The ADC in the microcontroller interprets the data and conveys the information to the user in terms of distance in kilometres. This is then displayed over the LCD and shared online using the IoT platform.

# Acknowledgement
I wish to express my sincere gratitude to Kenyatta University for providing me with the training opportunity to fulfil my dream of becoming an Electrical Engineer. More so, providing the necessary infrastructure and services to develop my engineering skills and expertise. My special thanks to my supervisor Eng. Kore for his guidance, assistance, and effort to enable the success of this project. I would also want to acknowledge my classmates for their various assistance during various research and analysis, finally, to the Almighty God for offering His grace throughout this journey.

# System Overview

The system overview is shown below

<img src="system_overview.png">

# Flow Chart

It is shown below

<img src="flowchart.png">

# System Components

1. Arduino Uno [Arduino Rev3](https://store-usa.arduino.cc/products/arduino-uno-rev3/)
2. Current sensing circuit-Combination of resistors and switches
3. 1kilo ohm resistor
4. Push button[Component](https://components101.com/switches/push-button)
5. Esp32(Wemos Lolin32)[Component](https://artofcircuits.com/product/lolin32-esp32-dual-core-wifibluetooth-development-board-with-battery-charger)
6. Relays [Component](https://elearn.ellak.gr/mod/book/view.php?id=4568&chapterid=2440)

# Schematic Diagram

#Simulation
