# IOT_UNDERGROUND-FAULT-LOCATION-AND-DETECTION
//Created by TIMOTHY KIPCHUMBA
//Final year project

#include <WiFi.h>
#include <ThingSpeak.h>
#include <String.h>

#define TXD2 17 //definition of tx and rx
#define RXD2 16

//defining the ThingSpeak channel id and api key
#define channel_id 1643775
#define channel_key "3OLXKS1TOARDTV7C"
const int Field_Number_1 = 1;

WiFiClient client;//initializing wifi client

//Initializing network credentials (STATION)
//const char* ssid = "FesTech-0790550708";
//const char* password = "Vikings001*";

const char* ssid = "Timotheengineer";
const char* password = "babayao12";
float volt_1;
String volt;
void initWiFi()  //function to initialise wifi
{      
  WiFi.mode(WIFI_STA); //setting wifi to station mode
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print('.');
    delay(1000);
  }
  Serial.println("Connected");
  Serial.println(WiFi.localIP());
}

void setup() 
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2); //initialise the serial port
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
  ThingSpeak.begin(client);
}

void loop() 
{
  Serial.println("Fault received ");
  //delay(4000);
  //Serial.println(Serial2.readString());
  volt=Serial2.readString();
  Serial.println(volt);
   upload();
}
void upload()
{
  ThingSpeak.writeField(channel_id,1,volt,channel_key);
   delay(15000);
  }
