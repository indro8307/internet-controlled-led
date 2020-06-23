#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

//WiFi Config
const char ssid[] = "Your wifi name";
const char password[] = "your wifi password";

const unsigned long channel_id = 12345;  // your channel id goes here
const char read_api_key[] = "MNOPQRSTUV";  // your read api key goes here

WiFiClient client;
 
void setup() {
  // Initialize Serial
  Serial.begin(9600);
  delay(100);
 
  // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
 
  // Show that we are connected
  Serial.println("Connected!");
 
  // Print IP address
  Serial.println(WiFi.localIP());

 ThingSpeak.begin(client);

 // Setiing D7 as the output pin for this project
 pinMode(D7, OUTPUT);
 digitalWrite(D7, LOW);
}

void loop() {
  int my_num = ThingSpeak.readIntField(channel_id, 1, read_api_key);
  Serial.println(my_num);
  if(my_num == 1)
  {
    digitalWrite(D7, HIGH);
  }
  else if(my_num == 0)
  {
    digitalWrite(D7, LOW);      
  }
  delay(3000);
}
