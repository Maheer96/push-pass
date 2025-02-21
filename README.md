# 🚦 Push&Pass: Traffic Light System  

Push & Pass is an Arduino-powered traffic light system integrating a pedestrian crossing button to mimic realistic and interactive signal control. The system follows a standard green-yellow-red traffic sequence but automatically adjusts the timing when a pedestrian presses the button. A summary of these operations can be found below: 

 * If the button is pressed during the green phase, the system shortens the green light and transitions to the yellow and red frequency within 2 seconds of the press. This allows pedestrians to cross safely. 
* If no button is pressed, the traffic light follows a normalized cycle of green (10s), yellow (2s), and red (5s), before restarting. A buzzer will make a noise indicating that the pedestrian can safely cross.
* The button press is handled as an interrupt, meaning an immediate response without disrupting the system’s timing.

This project is a fun way to introduce students to microcontrollers, embedded systems, and real-world traffic logic while making pedestrian crossings more interactive.  

![IMG_1642](https://github.com/user-attachments/assets/dbb8cc1d-176f-416d-af86-efa24c25f33c)
