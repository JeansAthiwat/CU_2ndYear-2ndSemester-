# Esp32-Esp8266_Send_DHT11_Data_To_FireStore 

This Arduino code allows you to read data from a DHT11 sensor (temperature and humidity) and send it to Firebase Firestore using an ESP8266 or ESP32 microcontroller. The data is stored in Firebase Firestore, a NoSQL database, and can be accessed and visualized remotely.

## Prerequisites

- Arduino IDE
- ESP8266 or ESP32 board
- DHT11 sensor
- Firebase account
- Firebase Realtime Database and Firestore setup
- Libraries: [Firebase ESP Client Library]( https://github.com/mobizt/Firebase-ESP-Client ) and [DHT Sensor Library]( https://github.com/adafruit/DHT-sensor-library )

## Circuit Connections

- Connect the DHT11 sensor to your ESP8266/ESP32 board as follows:
  - DHT11 VCC pin to 3.3V
  - DHT11 GND pin to GND
  - DHT11 DATA pin to D4 (you can change the pin in the code if needed)

## Firebase Setup

1. Create a Firebase account if you don't have one: [Firebase](https://firebase.google.com/).

2. Set up a Firebase project and enable Realtime Database and Firestore.

3. Obtain your Firebase project's API Key, Project ID, and user credentials (email and password).

4. Update the following variables in your code with your Firebase information:

   - `API_KEY`: Your Firebase project's API Key.
   - `FIREBASE_PROJECT_ID`: Your Firebase Project ID.
   - `USER_EMAIL`: Your Firebase user's email.
   - `USER_PASSWORD`: Your Firebase user's password.

## Firestore Structure

The code is designed to send data to Firebase Firestore with the following structure:

- **Collection Name**: `EspData`
  - **Document Name**: `DHT11`
    - **Field Names**:
      - `Temperature`: Temperature reading in degrees Celsius.
      - `Humidity`: Humidity reading in percentage.

These names are used in the code to specify the Firestore collection, document, and field to store the sensor data.

## Uploading the Code

1. Open the Arduino IDE and make sure you have the required libraries installed.

2. Copy and paste the code into the Arduino IDE.

3. Select the appropriate board (ESP8266 or ESP32) and port.

4. Upload the code to your ESP8266/ESP32 board.

## Running the Code

1. Open the Serial Monitor to see the output from your ESP8266/ESP32.

2. The code will read temperature and humidity data from the DHT11 sensor and send it to Firebase Firestore every 10 seconds.

3. If successful, the Serial Monitor will display "ok" and the updated data.

4. You can access and visualize the data from your Firebase Firestore database.

## Troubleshooting

- If you encounter issues, double-check your Firebase setup and the circuit connections.
- Ensure you have a stable internet connection.

## Additional Notes

- This code is for educational purposes and can be extended for more sensors or advanced features.

That's it! You've set up a system to read DHT11 sensor data and store it in Firebase Firestore for remote access.
