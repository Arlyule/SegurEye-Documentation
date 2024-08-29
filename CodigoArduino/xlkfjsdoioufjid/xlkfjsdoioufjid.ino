#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h>

// Configuración de la red WiFi
const char* ssid = "HUAWEI nova 3 A4E7";
const char* password = "hola12345";

// Configuración del servidor MQTT 
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_user = "";
const char* mqtt_password = "";

// ID único del cliente MQTT
const char* client_id = "sistema_segureye_esp2";

// Tópico MQTT para controlar el LED
const char* servo_control_topic = "segureye/servo";

const char* conta_topic = "casa/sala/conta";

const char* topic_grabar = "segureye/control/grabar";
const char* topic_reproducir = "segureye/control/reproducir";

WiFiClient espClient;
PubSubClient client(espClient); // instancia del cliente MQTT

Servo miServo;

// Pines del ISD1820
const int pinPL = 18;  // Pin para reproducción con bucle
const int pinPE = 19;  // Pin para reproducción con pulsación
const int pinRec = 21; // Pin para iniciar la grabación
const int pinLED = 35; // Pin del LED indicador

void setup_wifi() {
  delay(10);
  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Intentando conexión MQTT...");
    if (client.connect(client_id, mqtt_user, mqtt_password)) {
      Serial.println("Conectado al servidor MQTT");
      // Suscribirse al tópico de control del LED al conectarse
      client.subscribe(servo_control_topic);
      client.subscribe(topic_grabar);
      client.subscribe(topic_reproducir);
    } else {
      Serial.print("Error de conexión, rc=");
      Serial.print(client.state());
      Serial.println(" Intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Configuración de pines
  pinMode(pinPL, OUTPUT);
  pinMode(pinPE, OUTPUT);
  pinMode(pinRec, OUTPUT);
  pinMode(pinLED, OUTPUT);
  
  miServo.attach(15);  // Conecta el servo al pin 15 del ESP32

  // Inicializar pines en estado bajo
  digitalWrite(pinPL, LOW);
  digitalWrite(pinPE, LOW);
  digitalWrite(pinRec, LOW);
  digitalWrite(pinLED, LOW);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el tópico: ");
  Serial.println(topic);

  String msg="" ;
  for (int i = 0; i < length; i++) {
    //Serial.print((char)payload[i]);
    msg += (char)payload[i];
  }


  if (String(topic) == servo_control_topic) {
    int angle = msg.toInt();
    miServo.write(angle);
    Serial.print("Servo movido a: ");
    Serial.println(angle);
  } else if (String(topic) == topic_grabar) {
    if (msg == "start") {
      digitalWrite(pinLED, HIGH);
      digitalWrite(pinRec, HIGH);
      Serial.println("Grabando...");
    } else if (msg == "stop") {
      digitalWrite(pinRec, LOW);
      digitalWrite(pinLED, LOW);
      digitalWrite(pinPL, LOW);
      Serial.println("Grabación detenida.");
    }
  } else if (String(topic) == topic_reproducir) {
    if (msg == "start") {
      digitalWrite(pinPL, HIGH);
      Serial.println("Reproduciendo...");
    } else if (msg == "stop") {
      digitalWrite(pinPL, LOW);
      Serial.println("Reproducción detenida.");
    }
  }
}