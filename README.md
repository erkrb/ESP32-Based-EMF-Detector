# ESP32-Based-EMF-Detector
This mini project is based on the simple EMF detector circuit. The basic circuit ampllifies the electric field. However, the led in the circuit flickers while doing it. So,I've develop this project so that no more noise occurs. 

To avoid noise, ADC averaging and hysteresis were used. To observe voltage value, serialmonitor function was used.

I needed three bc547 model transistors,three resistors to protect components,led,9 v battery and ESP32-WROOM-2S.T

I connected three transistors to each other and left one base pin (first one, furthest one to the esp32) so that it can detect EMF around. Subsequently,I connected third transistor's emittor pin to 34th adc pin of ESP32. Since 34th pin collects inputs from the circuit. Upon the completion of connection, 25th (output) pin was connected to GND.

