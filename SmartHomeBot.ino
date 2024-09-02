
#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "YOUR_SSID_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Initialize Telegram BOT
#define BOTtoken "X2X4X0X5X:AXXXXXS1AXXXXXBN3QXXPrxVXXXXXXXXXXX"

// Use @chatIDrobot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "YOUR_CHAT_ID"

#ifdef ESP8266
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;
// Output pins
const int fan = 5;          // D1
const int Light1 = 4;       // D2
const int Light2 = 0;       // D3 
const int Light3 = 14;      // D5
const int Light4 = 12;      // D6
const int Light5 = 13;      // D7
const int Light6 = 15;      // D8
const int Light7 = 3;       // RX
const int Charging = 2;     // D4
bool ledState = LOW;        // Initial LED state

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    // Report the state of the outputs
if (text == "/start") {
      String welcome = "Welcome, " + from_name + " 🎉.\n";
      welcome += "👉 Use the following commands to control your outputs. 👈\n\n";
      welcome += "🔌 /Charging_on to turn Charging Point ON \n";
      welcome += "🔌 /Charging_off to turn Charging Point OFF \n";
      welcome += "🌬️ /fan_on to turn Fan ON \n";
      welcome += "🌬️ /fan_off to turn Fan OFF \n";
      welcome += "💡 /Light1_on to turn Light 1 ON \n";
      welcome += "💡 /Light1_off to turn Light 1 OFF \n";
      welcome += "💡 /Light2_on to turn Light 2 ON \n";
      welcome += "💡 /Light2_off to turn Light 2 OFF \n";
      welcome += "💡 /Light3_on to turn Light 3 ON \n";
      welcome += "💡 /Light3_off to turn Light 3 OFF \n";
      welcome += "💡 /Light4_on to turn Light 4 ON \n";
      welcome += "💡 /Light4_off to turn Light 4 OFF \n";
      welcome += "💡 /Light5_on to turn Light 5 ON \n";
      welcome += "💡 /Light5_off to turn Light 5 OFF \n";
      welcome += "💡 /Light6_on to turn Light 6 ON \n";
      welcome += "💡 /Light6_off to turn Light 6 OFF \n";
      welcome += "💡 /Light7_on to turn Light 7 ON \n";
      welcome += "💡 /Light7_off to turn Light 7 OFF \n";
      welcome += "🔍 /state to request current GPIO state \n";
      welcome += "/get_ip to Get IP \n";
      bot.sendMessage(chat_id, welcome, "");
    }

   // Control Charging Point
    if (text == "/Charging_on") {
      bot.sendMessage(chat_id, "Charging Point is now ON ✅", "");
      ledState = HIGH;
      digitalWrite(Charging, ledState);
    }
    
    if (text == "/Charging_off") {
      bot.sendMessage(chat_id, "Charging Point is now OFF ❌", "");
      ledState = LOW;
      digitalWrite(Charging, ledState);
    }

    // Control Fan
    if (text == "/fan_on") {
      bot.sendMessage(chat_id, "Fan is now ON ✅", "");
      digitalWrite(fan, HIGH);
    }
    
    if (text == "/fan_off") {
      bot.sendMessage(chat_id, "Fan is now OFF ❌", "");
      digitalWrite(fan, LOW);
    }

    // Control Light1
    if (text == "/Light1_on") {
      bot.sendMessage(chat_id, "Light 1 is now ON ✅", "");
      digitalWrite(Light1, HIGH);
    }

    if (text == "/Light1_off") {
      bot.sendMessage(chat_id, "Light 1 is now OFF ❌", "");
      digitalWrite(Light1, LOW);
    }

    // Control Light2
    if (text == "/Light2_on") {
      bot.sendMessage(chat_id, "Light 2 is now ON ✅", "");
      digitalWrite(Light2, HIGH);
    }

    if (text == "/Light2_off") {
      bot.sendMessage(chat_id, "Light 2 is now OFF ❌", "");
      digitalWrite(Light2, LOW);
    }

    // Control Light3
    if (text == "/Light3_on") {
      bot.sendMessage(chat_id, "Light 3 is now ON ✅", "");
      digitalWrite(Light3, HIGH);
    }

    if (text == "/Light3_off") {
      bot.sendMessage(chat_id, "Light 3 is now OFF ❌", "");
      digitalWrite(Light3, LOW);
    }

    // Control Light4
    if (text == "/Light4_on") {
      bot.sendMessage(chat_id, "Light 4 is now ON ✅", "");
      digitalWrite(Light4, HIGH);
    }

    if (text == "/Light4_off") {
      bot.sendMessage(chat_id, "Light 4 is now OFF ❌", "");
      digitalWrite(Light4, LOW);
    }

    // Control Light5
    if (text == "/Light5_on") {
      bot.sendMessage(chat_id, "Light 5 is now ON ✅", "");
      digitalWrite(Light5, HIGH);
    }

    if (text == "/Light5_off") {
      bot.sendMessage(chat_id, "Light 5 is now OFF ❌", "");
      digitalWrite(Light5, LOW);
    }

    // Control Light6
    if (text == "/Light6_on") {
      bot.sendMessage(chat_id, "Light 6 is now ON ✅", "");
      digitalWrite(Light6, HIGH);
    }

    if (text == "/Light6_off") {
      bot.sendMessage(chat_id, "Light 6 is now OFF ❌", "");
      digitalWrite(Light6, LOW);
    }

    // Control Light7
    if (text == "/Light7_on") {
      bot.sendMessage(chat_id, "Light 7 is now ON ✅", "");
      digitalWrite(Light7, HIGH);
    }

    if (text == "/Light7_off") {
      bot.sendMessage(chat_id, "Light 7 is now OFF ❌", "");
      digitalWrite(Light7, LOW);
    }
    if(text=="/get_ip"){
        // Send Ip Details on Telegram
      String message = "Device connected to Wi-Fi. IP address: " + WiFi.localIP().toString();
      bot.sendMessage(CHAT_ID, message, "");  
    }

    // Report the state of the outputs
    if (text == "/state") {
      String stateMessage = "Your Device Status Report\n";
      stateMessage += digitalRead(Charging) ? "Charging Point is ON ✅\n" : "Charging Point is OFF ❌\n";
      stateMessage += digitalRead(fan) ? "Fan is ON ✅\n" : "Fan is OFF ❌\n";
      stateMessage += digitalRead(Light1) ? "Light 1 is ON ✅\n" : "Light 1 is OFF ❌\n";
      stateMessage += digitalRead(Light2) ? "Light 2 is ON ✅\n" : "Light 2 is OFF ❌\n";
      stateMessage += digitalRead(Light3) ? "Light 3 is ON ✅\n" : "Light 3 is OFF ❌\n";
      stateMessage += digitalRead(Light4) ? "Light 4 is ON ✅\n" : "Light 4 is OFF ❌\n";
      stateMessage += digitalRead(Light5) ? "Light 5 is ON ✅\n" : "Light 5 is OFF ❌\n";
      stateMessage += digitalRead(Light6) ? "Light 6 is ON ✅\n" : "Light 6 is OFF ❌\n";
      stateMessage += digitalRead(Light7) ? "Light 7 is ON ✅\n" : "Light 7 is OFF ❌\n";
      bot.sendMessage(chat_id, stateMessage, "");
    }
    }
  }

void setup() {
  Serial.begin(115200);

  #ifdef ESP8266
    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  #endif

  // Set all pins as outputs
  pinMode(fan, OUTPUT);
  pinMode(Light1, OUTPUT);
  pinMode(Light2, OUTPUT);
  pinMode(Light3, OUTPUT);
  pinMode(Light4, OUTPUT);
  pinMode(Light5, OUTPUT);
  pinMode(Light6, OUTPUT);
  pinMode(Light7, OUTPUT);
  pinMode(Charging, OUTPUT);

  // Initialize all outputs to OFF
  digitalWrite(fan, LOW);
  digitalWrite(Light1, LOW);
  digitalWrite(Light2, LOW);
  digitalWrite(Light3, LOW);
  digitalWrite(Light4, LOW);
  digitalWrite(Light5, LOW);
  digitalWrite(Light6, LOW);
  digitalWrite(Light7, LOW);
  digitalWrite(Charging, LOW);
  
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  #endif

  // Wait for Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println("Connected to WiFi. IP Address: " + WiFi.localIP().toString());

  // Send confirmation message to Telegram
  String message = "Device connected to Wi-Fi. IP address: " + WiFi.localIP().toString();
  bot.sendMessage(CHAT_ID, message, "");

  // Optionally, you can also send a message confirming the successful setup
  bot.sendMessage(CHAT_ID, "Your Device is Now Online.", "");
  bot.sendMessage(CHAT_ID,"You can Start Control Device Just Click On /start ","");
}


void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
