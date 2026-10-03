// wifi communication example sending through json to all connected devices on the network
// hours wasted 3h
// #DIEYOUNG - wasting life on coding and having fun which i enjoy :)

#include <WiFi.h>
#include <WebServer.h>

const char* wifiName = " ";      // your wifi name here USSID like the name you see on your phone while trying to connect
const char* wifiPassword = " ";  // your wifi password here, same password when you're trying to connect to your wifi

WebServer webServer(80);

void handleData() {
    // feeding fake info because i didn't have sensors or anything to try :D
    float temp = 30;
    float humidity = 50;
    int light = 400;

    String jsonData = "{";
    jsonData += "\"temp\":" + String(temp) + ",";
    jsonData += "\"humidity\":" + String(humidity) + ",";
    jsonData += "\"light\":" + String(light);
    jsonData += "}";

    webServer.send(200, "application/json", jsonData);
}

void setup() {
    Serial.begin(115200);

    WiFi.begin(wifiName, wifiPassword);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected");
    Serial.println(WiFi.localIP());

    webServer.on("/get", handleData);

    webServer.begin();
}

void loop() {

    webServer.handleClient();
    
}
