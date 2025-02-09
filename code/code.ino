#define BLYNK_TEMPLATE_NAME "template_name"
#define BLYNK_TEMPLATE_ID "template_id"
#define BLYNK_AUTH_TOKEN "Authorization token"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "wifi";  
char pass[] = "";        


int gasSensor = A0;       
int buzzer = D5;          
int greenLed = D6;        
int redLed = D3;          

// Default Threshold (will be updated from Blynk)
int sensorThreshold = 150;

LiquidCrystal_PCF8574 lcd(0x27);

// Timer for Blynk
BlynkTimer timer;

// Function to Read Sensor and Update Display
void sendSensorData() {
    int gasLevel = analogRead(gasSensor);
    Blynk.virtualWrite(V0, gasLevel);  // Send data to Blynk app

    Serial.print("Gas Level: ");
    Serial.println(gasLevel);
    Serial.print("Threshold: ");
    Serial.println(sensorThreshold);

    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gas Level: ");
    lcd.print(gasLevel);

    if (gasLevel > sensorThreshold) {
        
        Blynk.logEvent("gas_alert", "Gas Leakage Detected!");
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
        digitalWrite(buzzer, HIGH);
        
        lcd.setCursor(0, 1);
        lcd.print("ALERT! Leakage!");
    } else {
        
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        digitalWrite(buzzer, LOW);
        
        lcd.setCursor(0, 1);
        lcd.print("Status: Safe");
    }
}

//  Function to Update Threshold from Blynk
BLYNK_WRITE(V1) {
    sensorThreshold = param.asInt();  // Get the new threshold from the Blynk slider
    Serial.print("New Threshold Set: ");
    Serial.println(sensorThreshold);
}

void setup() {
    Serial.begin(115200);
    
    
    pinMode(gasSensor, INPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);

    
    lcd.begin(16, 2);
    lcd.setBacklight(255);
    lcd.setCursor(0, 0);
    lcd.print("Initializing...");

    
    Blynk.begin(auth, ssid, pass);

    
    timer.setInterval(500L, sendSensorData);
}

void loop() {
    Blynk.run();
    timer.run();
}
