void setup() {
  // put your setup code here, to run once:
   pinMode(25,OUTPUT);
   Serial.begin(115200);
}

bool ledState = false;  

void hysteresis(float a){   //this function avoids the led flickering by creating deadband
  if(ledState == true && a <= 0.1) //lower band 
  ledState = false;
  else if(ledState == false && a >= 2)  //upper band
  ledState = true;

  if(ledState == true)
    digitalWrite(25,HIGH);
  else digitalWrite(25,LOW);

}

void serialmonitor(){  //this function allows me to observe voltage values in the specific pins
  float degers = analogRead(34);
  float voltages = (degers*3.3)/4095;
  Serial.println(voltages);
}

void loop() {
  // put your main code here, to run repeatedly:
   int total = 0,pinno[50];
   for(int i=0;i<50;i++){
    pinno[i]=analogRead(34);
    total = total + pinno[i];
   }
   float average = total/50.0;  //the reason I've chose 50.0 instead of 50 is about converting it into float
   float vvalue = average * (3.3/4095.0);
   hysteresis(vvalue);
   //for debugging (how many volts are provided in the pin).you can add the function serialmonitor() by printing it here
}
