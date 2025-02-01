#include <WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <MFRC522.h>


#define SS_PIN  10

//#define MOSI_PIN 11
//#define SCK_PIN 12
//#define MISO_PIN 13

#define RST_PIN 5

const char * topic = "rfid";
const char* ssid = "SK_WiFiGIGA0C2F";
const char* password = "1705002607";
const char* mqttServer = "broker.emqx.io";
int port = 1883;


String stMac;
char mac[50];
char clientId[50];


WiFiClient espClient;
PubSubClient client(espClient);

//MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522 rfid(10, 5);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  wifiConnect();

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
  stMac = WiFi.macAddress();
  stMac.replace(":", "_");
  Serial.println(stMac);

  client.setServer(mqttServer, port);
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522
}


void wifiConnect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void mqttReconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    long r = random(1000);
    sprintf(clientId, "clientId-%ld", r);
    if (client.connect(clientId)) {
      Serial.print(clientId);
      Serial.println(" connected");
      client.subscribe(topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}



void loop() {
  delay(10);
  if (!client.connected()) {
    mqttReconnect();
  }
  client.loop();
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      String value = "";
      String uid = "";
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
        value += String(rfid.uid.uidByte[i], HEX);
      }
      client.publish(topic, (char*) value.c_str());
      Serial.println();

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
