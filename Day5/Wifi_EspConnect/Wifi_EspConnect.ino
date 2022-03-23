#include <WiFi.h>
void setup() {
  // put your setup code here, to run once:
  // Wifi Creds
#define WIFI_SSID "------"
#define WIFI_PASSWORD "*****"

Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();


}

void loop() {
  // put your main code here, to run repeatedly:

}
