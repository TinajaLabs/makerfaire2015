

/*
 *  This sketch originally designed to sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 * It sends 
 */

#include <ESP8266WiFi.h>



const char* ssid     = "myssid";
const char* password = "password";

// node red service
const char* host = "192.168.84.243";
const char* streamId   = "882f39922be845f992f0";
const char* privateKey = "ddbe1f751efc43a5903e";
const int httpServicePort = 4766;

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // prepare GPIO2
  pinMode(2, INPUT);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int lastVal = 0;
int value = 0;
int pinVal = 0;
// ##############################################################
void loop() {
  delay(500);
  ++value;

  pinVal = digitalRead(2);

  if (pinVal != lastVal){

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = httpServicePort;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "tinaja.switch1.state ";
  url += pinVal;

  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  lastVal = pinVal;

  delay(10);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print("resp:" +line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  }
  delay(10);
}

