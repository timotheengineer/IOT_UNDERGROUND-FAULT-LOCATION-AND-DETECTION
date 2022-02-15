
/*LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 7
   LCD D5 pin to digital pin 6
   LCD D6 pin to digital pin 5
   LCD D7 pin to digital pin 4
*/
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
SoftwareSerial mySerial(0,1);//Initialises the serial port

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Contrast = 75;
float voltage=0;


int sensorPin   = A0; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {

  pinMode(8, OUTPUT);//initialize as output for red phase
  digitalWrite(8, LOW);//turn off the relay
  analogWrite(6, Contrast);

  Serial.begin(9600); //sets serial port for communication
  mySerial.begin(115200);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("UNDERGROUND CABLE");
  lcd.setCursor(0, 1);
  lcd.print("FAULT LOCATOR");
  delay(2000);

}
void loop()//start of the execution process
{
  lcd.clear();
  digitalWrite(8, HIGH);
  delay(3000);

  sensorValue = analogRead(sensorPin); // read the value from the sensor
 // Serial.println(sensorValue);
  voltage=sensorValue*(5.0/1023.0);
  //dtostrf(val, 4, 6, buff);      //convert float to a string 
  Serial.println(voltage); //prints the line voltage from the sensor.
  
  if ( (sensorValue >= 1000) ) //5.0V
  {
    lcd.setCursor(0, 0);
    lcd.print("R -  NF,        ") ;
    Serial.println("R -  NF   ") ;

  }

  else if ( (sensorValue >= 890) && (sensorValue <= 920)  ) //4.44V
  {
    Serial.println("R - 2KM,") ;
    lcd.setCursor(0, 0);
    lcd.print("R - 2KM      ") ;
  }
  else if ( (sensorValue >= 870) && (sensorValue <= 880)  ) //4.29V
  {
    Serial.print("R - 4KM,") ;
    lcd.setCursor(0, 0);
    lcd.print("R - 4KM       ") ;
  }
  else if ( (sensorValue >= 800) && (sensorValue <= 825)  ) //4.0V
  {
    Serial.println("R - 6KM,") ;
    lcd.setCursor(0, 0);
    lcd.print("R - 6KM      ") ;
  }
  else if ( (sensorValue >= 670) && (sensorValue <= 688)  ) //3.33V
  {
    Serial.println("R - 8KM,") ;
    lcd.setCursor(0, 0);
    lcd.print("R - 8KM      ") ;
  }
  delay(2000);
  digitalWrite(8, LOW);
  delay(1000);
  lcd.clear();
  delay(1000);
  
}
