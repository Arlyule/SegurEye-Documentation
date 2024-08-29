#include "pitches.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

// Configuración de la red WiFi
const char* ssid = "HUAWEI nova 3 A4E7";
const char* password = "hola12345";

// URL de la API para registrar los datos
const char* serverName = "https://segureye-server.onrender.com/register-event";

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_user = "";
const char* mqtt_password = "";

const char* client_id = "sistema_segureye";

// Tópicos MQTT para controlar el LED y el buzzer
const char* led_control_topic = "segureye/led/color";
const char* buzzer_control_topic = "segureye/buzzer/control";

WiFiClient espClient;
PubSubClient client(espClient);  // instancia del cliente MQTT

#define PIR_PIN 13
#define BUZZER_PIN 14
#define RED_PIN 2
#define GREEN_PIN 15
#define BLUE_PIN 4
#define LIGHT_SENSOR_PIN 34

// Definir canal PWM
#define LEDC_CHANNEL_0 0
#define LEDC_TIMER_13_BIT 13
#define LEDC_BASE_FREQ 5000

const unsigned long MOTION_THRESHOLD = 15000;
const unsigned long LED_BLINK_INTERVAL = 500;
const unsigned long BUZZER_INTERVAL = 500;

unsigned long lastMotionTime = 0;
unsigned long lastLEDBlinkTime = 0;
unsigned long lastBuzzerTime = 0;
unsigned long lastLEDBlinkTimeManual = 0;

bool ledState = LOW;
bool motionDetected = false;

int melody1[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };
int noteDurations1[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

int manualRedValue = 0;
int manualGreenValue = 0;
int manualBlueValue = 0;
bool manualLEDControlActive = false;

void reconnect() {
  while (!client.connected()) {
    Serial.println("Intentando conexión MQTT...");
    if (client.connect(client_id, mqtt_user, mqtt_password)) {
      Serial.println("Conectado al servidor MQTT");
      // Suscribirse a los tópicos de control del LED y buzzer al conectarse
      client.subscribe(led_control_topic);
      client.subscribe(buzzer_control_topic);
    } else {
      Serial.print("Error de conexión, rc=");
      Serial.print(client.state());
      Serial.println(" Intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

// Inicialización de pines y conexión WiFi
void setup() {
  initializePins();
  connectToWiFi();
  configurePWMChannels();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  int pirState = digitalRead(PIR_PIN);
  float lightState = analogRead(LIGHT_SENSOR_PIN) * (3.3 / 4095.0);
  unsigned long currentTime = millis();

  if (pirState == HIGH && !motionDetected) {
    lastMotionTime = currentTime;
    motionDetected = true;
    Serial.println("¡Movimiento detectado!");
    sendDataToServer(pirState, lightState);
  }

  if (pirState == HIGH) {
    handleMotionDetection(currentTime);
  }

  if (currentTime - lastMotionTime >= MOTION_THRESHOLD) {
    stopAlert();
  }

  if (manualLEDControlActive) {
    handleManualLEDBlink(currentTime);
  }
}

void initializePins() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  Serial.begin(115200);
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");
}

void configurePWMChannels() {
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL_0);
  ledcAttachPin(RED_PIN, 0);
  ledcAttachPin(GREEN_PIN, 1);
  ledcAttachPin(BLUE_PIN, 2);
}

void handleMotionDetection(unsigned long currentTime) {
  if (currentTime - lastBuzzerTime >= BUZZER_INTERVAL) {
    playMelody(melody1, noteDurations1, 8);
    lastBuzzerTime = currentTime;
  }

  if (currentTime - lastLEDBlinkTime >= LED_BLINK_INTERVAL) {
    lastLEDBlinkTime = currentTime;
    toggleLED();
  }
}

void toggleLED() {
  ledState = !ledState;
  ledcWrite(0, ledState ? 255 : 0);
}

void stopAlert() {
  ledcWriteTone(3, 0);
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  motionDetected = false;
}

void sendDataToServer(int pirState, float lightState) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("User-Agent", "ESP32");

    StaticJsonDocument<200> doc;
    doc["accion"] = 1;
    JsonObject data = doc.createNestedObject("data");
    data["pirState"] = pirState;
    data["lightState"] = lightState;

    String jsonString;
    serializeJson(doc, jsonString);

    int httpResponseCode = http.POST(jsonString);
    Serial.println(jsonString);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error en la solicitud HTTP: ");
      Serial.println(httpResponseCode);
    }

    http.end();

    if (client.connected()) {
      String lightMessage = String(lightState);
      client.publish("segureye/sensor_data/light", lightMessage.c_str());
      Serial.println("lightState publicado en MQTT:");
      Serial.println(lightMessage);

      String pirMessage = "¡Movimiento detectado!";
      client.publish("segureye/sensor_data/pir", pirMessage.c_str());
      Serial.println("pirMessage publicado en MQTT:");
      Serial.println(pirMessage);
    } else {
      Serial.println("No conectado a MQTT");
    }

  } else {
    Serial.println("Error: No conectado a WiFi");
  }
}

void playMelody(int melody[], int noteDurations[], int size) {
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    ledcWriteTone(LEDC_CHANNEL_0, melody[thisNote]);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    ledcWriteTone(LEDC_CHANNEL_0, 0);
  }
}

// Función callback para manejar los mensajes recibidos
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el tópico: ");
  Serial.println(topic);

  String msg = "";
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  Serial.println("Mensaje: " + msg);

  if (String(topic) == led_control_topic) {
    controlLED(msg);
  } else if (String(topic) == buzzer_control_topic) {
    controlBuzzer(msg);
  }
}

// Función para controlar el LED a través de MQTT
void controlLED(String msg) {
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, msg);

  if (!error) {
    manualRedValue = doc["red"];
    manualGreenValue = doc["green"];
    manualBlueValue = doc["blue"];
    manualLEDControlActive = true;

    Serial.print("Iniciando parpadeo con color: R=");
    Serial.print(manualRedValue);
    Serial.print(" G=");
    Serial.print(manualGreenValue);
    Serial.print(" B=");
    Serial.println(manualBlueValue);
  } else {
    Serial.println("Error al analizar JSON");
  }
}

// Función para manejar el parpadeo del LED manualmente
void handleManualLEDBlink(unsigned long currentTime) {
  if (currentTime - lastLEDBlinkTimeManual >= LED_BLINK_INTERVAL) {
    lastLEDBlinkTimeManual = currentTime;
    ledState = !ledState;
    ledcWrite(0, ledState ? manualRedValue : 0);
    ledcWrite(1, ledState ? manualGreenValue : 0);
    ledcWrite(2, ledState ? manualBlueValue : 0);
  }
}

// Función para controlar el buzzer a través de MQTT
void controlBuzzer(String msg) {
  if (msg == "on") {
    playMelody(melody1, noteDurations1, 8);
    Serial.println("Buzzer activado");
  } else if (msg == "off") {
    ledcWriteTone(LEDC_CHANNEL_0, 0);
    Serial.println("Buzzer desactivado");
  } else {
    Serial.println("Comando de buzzer no reconocido");
  }
}
