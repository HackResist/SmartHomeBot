# SmartHomeBot

SmartHomeBot is a versatile IoT project that leverages the ESP32 or ESP8266 microcontroller and the Telegram Bot API to control various devices and monitor their status via Telegram messages. This project allows you to manage your home automation devices, including lights, fan, and charging point, from anywhere using a Telegram bot.

***If You Like This Project Don't Forget to give a Star⭐.***

## Features

- **Control Devices Remotely**: Turn devices on/off through simple Telegram commands.
- **Status Reporting**: Get real-time status updates of your devices.
- **Wi-Fi Connectivity**: Connects to Wi-Fi and reports the IP address.
- **Secure Communication**: Uses HTTPS for secure communication with the Telegram API.

## Hardware Required

- ESP32 or ESP8266 microcontroller
- Relay modules or transistors for controlling high voltage devices (e.g., lights, fan, charging point)
- External power supply as required
- Wires and connectors

## Software Required

- Arduino IDE
- Libraries: `WiFi`, `WiFiClientSecure`, `UniversalTelegramBot`, `ArduinoJson`

## Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/HackResist/SmartHomeBot.git

2. **Install Required Libraries**
    Open Arduino IDE, go to `Sketch` > `Include Library` > `Manage Libraries...` and install the following libraries:
   
      - `WiFi`
      - `WiFiClientSecure`
      - `UniversalTelegramBot`
      - `ArduinoJson`
3. **Configure the Code**
   - Open `SmartHomeBot.ino` in Arduino IDE.
   - Replace the placeholder values for `ssid`, `password`, and `BOTtoken` with your <strong>Wi-Fi</strong> credentials and Telegram Bot Token.
   - Replace `CHAT_ID` with your Telegram chat ID.
     
4. **Upload the Code**
   - Connect your ESP32 or ESP8266 to your computer.
   - Select the correct board and port in Arduino IDE.
   - Upload the sketch to your board.
     
5. **Configure Bot**
      - Open Telegram
   
      - Search for BotFather in the search box or [Go to BotFather](https://web.telegram.org/k/#@BotFather).
         
      - Create a bot and obtain your bot token (e.g., `XXXXXXXXX:xxxxxxxxxDxxxxxxxSxxxxxxxxx2xxxxxxxxx`)
         
      - After Create Bot Search get Chat ID or [Go To Chat Id](https://web.telegram.org/k/#@chatIDrobot).
         
      - Tap `START` and Get chat ID.
          
      - Go to your Bot and Tap To `START`.

## Commands

> Here is a list of commands that you can use with the Telegram bot:
  - `/start`: Displays a welcome message and a list of available commands.
  - `/Charging_on`: Turns the charging point ON.
  - `/Charging_off`: Turns the charging point OFF.
  - `/fan_on`: Turns the fan ON.
  - `/fan_off`: Turns the fan OFF.
  - `/Light1_on` to `/Light7_on`: Turns corresponding lights ON.
  - `/Light1_off` to `/Light7_off`: Turns corresponding lights OFF.
  - `/state`: Reports the current status of all devices.
  - `/get_ip`: Provides the current IP address of the device.

## Troubleshooting
  - Wi-Fi Connection Issues: Ensure that the ESP32/ESP8266 is within range of the Wi-Fi network and that credentials are correct.
  - Bot Not Responding: Make sure that the bot token and chat ID are correctly configured and that the bot has started in your Telegram chat.

## Contributing
> If you have suggestions or improvements, feel free to create a pull request or open an issue on GitHub.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details.
