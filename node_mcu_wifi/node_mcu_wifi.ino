#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char ssid[] = "BMwifi";
const char password[] = "4849876290";
char packetBuffer[UDP_TX_PACKET_MAX_SIZE + 1];

WiFiUDP client;
const int PORT = 8888;

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n\n");
  Serial.println("SSID:");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  client.begin(PORT);
}

void loop() {
  int packetSize = client.parsePacket();
  if(packetSize){
    Serial.print("Recieved packet:\n\t");
    int n = Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    packetBuffer[n] = '\0';
    Serial.println(packetBuffer);
  }
  
}
