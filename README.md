# Proyecto de Sistema de Seguridad con Cámara en la Puerta

# Equipo de Desarrollo

## Scrum Master
- Carlos Edurado Mata Rojas

## Product Owner
- Julio Samuel Torres Reyes

## Equipo Scrum
1. Carlos Mata (Scrum Master) 
2. Julio Torres (Product Owner)

# Visión
El proyecto busca revolucionar la seguridad del hogar mediante la implementación de un sistema inteligente y autónomo que utiliza tecnología avanzada para detectar, reconocer la entrada de visitantes en la puerta principal. Este sistema proporcionará a los residentes una solución de seguridad integral que combina comodidad, eficiencia y protección, asegurando un entorno más seguro y controlado.

# Descripción del Proyecto
El proyecto consiste en desarrollar un sistema de seguridad inteligente que utilice una cámara instalada en la puerta principal para detectar y reconocer a los visitantes, proporcionando un control de acceso seguro y conveniente para los residentes del hogar. El sistema estará equipado con tecnologías avanzadas como reconocimiento facial y detección de objetos inteligente, ofreciendo una experiencia de seguridad innovadora y fácil de usar.

# Software Empleados

| Nombre | Licencia | 
|--------|----------|
| Arduino IDE | GNU General Public License (GPL) | 
| Flutter | BSD 3-Clause License | 
| ESP32 | MIT |
| ESP32 Camera | MIT |
| Servo FS90R |	LGPL-2.1 |
| Arduino-PIR |	MIT |

# Hardware empleado
| Nombre | Imagen | Descripción | Cantidad |
|--------|--------|-------------|----------|
| ESP32 CAM | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/308890b1-333b-4517-ba16-6d12565bce9b" alt="ESP32 CAM" width="150"/>| El módulo ESP32 CAM integra un microcontrolador ESP32 y una cámara OV2640. El ESP32 proporciona conectividad Wi-Fi y Bluetooth, mientras que la cámara OV2640 captura imágenes con resolución de hasta 2 megapíxeles. Este módulo es ideal para proyectos de visión artificial, como detección de movimiento, reconocimiento facial y transmisión de video en tiempo real. | 1 |
| ESP32  | <img src="https://github.com/user-attachments/assets/7f4dbfb2-fcd0-4f6e-8c22-caef05b9f779" alt="ESP32 CAM" width="150"/>| La ESP32 es un microcontrolador con Wi-Fi y Bluetooth integrado, desarrollado por Espressif Systems. Es ideal para proyectos de IoT por su conectividad, potencia y bajo consumo de energía, además de contar con múltiples GPIO y soporte para varios protocolos de comunicación. | 1 |
| EL sensor de movimiento PIR | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/b048c046-b468-4325-9cb8-d7613bba292a" alt="EL sensor de movimiento PIR" width="150"/>| El sensor de movimiento PIR (Passive Infrared) detecta cambios en la radiación infrarroja emitida por objetos en su campo de visión. Cuando se detecta movimiento, el sensor activa una señal eléctrica, que puede ser utilizada para activar dispositivos de seguridad, luces automáticas u otros sistemas de automatización. | 1 |
| Sensor de Luz | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/7567182c-dbce-4fee-80bb-8abad6df72be" alt="Sensor de Luz" width="150"/>| Este sensor mide la intensidad de la luz incidente en su entorno. Utiliza un fotoresistor o un fotodiodo para convertir la luz en una señal eléctrica. La salida del sensor puede ser utilizada para ajustar automáticamente la iluminación en función de las condiciones de luz ambiental. | 1 |
| Buzzer | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/eec6b1ad-77c3-49b5-9331-36960f156517" alt="Bocina" width="150"/>| Un buzzer es un transductor electromecánico que convierte una señal eléctrica en sonido audible. Puede generar tonos simples o patrones de sonido más complejos. Se utiliza comúnmente para proporcionar retroalimentación audible en sistemas electrónicos, como alarmas, notificaciones o señales de advertencia. | 1 |
| Jumper Macho-Macho | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/0dc09801-833e-4635-9293-84b0f8350037" alt="Jumper Macho-Macho" width="150"/>| Estos cables están diseñados para conectar componentes electrónicos entre sí. Tienen un conector macho en cada extremo, lo que les permite establecer conexiones temporales en una protoboard o en un circuito impreso. | 40 |
| Jumper Macho-Hembra | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/6449b658-7fdb-4a4b-8c57-8e37dee4059c" alt="Jumper Macho-Hembra" width="150"/>| Estos cables tienen un conector macho en un extremo y un conector hembra en el otro. Son útiles para conectar componentes electrónicos con diferentes tipos de pines, como microcontroladores y sensores, a una protoboard. | 40 |
| Protoboard | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/2b68b33c-ef44-4fb1-a582-9407515812d2" width="150"/>| Una protoboard es una placa de pruebas que permite la conexión temporal de componentes electrónicos. Tiene una matriz de agujeros y líneas conductoras que facilitan la creación de circuitos y prototipos. Es una herramienta fundamental en el desarrollo y la depuración de proyectos electrónicos. | 1 |
| Servo FS90R | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/783bff7a-2f3e-4497-8bb1-ed898a5c9d5c" width="150"/>| Un servo es un dispositivo que combina un motor, un sensor de posición y un circuito de control. Se utiliza para controlar el movimiento angular de manera precisa y es común en aplicaciones robóticas, sistemas de control de aeronaves, y dispositivos de automatización. | 1 |
| ISD1820 | <img src="https://github.com/user-attachments/assets/35768bda-4bdf-4327-99bc-5caf6a3418db" width="150"/>| Es un módulo de grabación y reproducción de voz que utiliza el chip ISD1820. Permite grabar y reproducir audio de hasta 20 segundos de duración. Este módulo es popular en proyectos de electrónica y robótica debido a su facilidad de uso y a su capacidad de ser controlado a través de microcontroladores como Arduino. Incluye botones integrados para grabar, reproducir y manejar otras funciones básicas de audio. | 2 |
| escudo de bateria de litio esp32 dual 18650 | <img src="https://github.com/user-attachments/assets/fe2f0e52-b40e-4ca5-b167-58ae1c7ffac6" width="150"/>| El escudo de batería de litio ESP32 dual 18650 es un accesorio que permite alimentar una placa ESP32 con dos baterías 18650. Proporciona un regulador de voltaje y un sistema de carga, facilitando el uso de baterías recargables en proyectos portátiles de IoT. | 2 |


# Historias de usuario épicas

| Épica | Historia de Usuario | Prioridad | Puntos de Historia |
|-------|---------------------|-----------|--------------------|
| 1    | Control de Acceso | Alta | 5 |
| 2     | Interfaz de Usuario Intuitiva | Media | 3 |

# Épicas del Proyecto Wearable

## 1. Interfaz de Usuario Intuitiva
**Descripción:** Crear una interfaz de usuario fácil de usar para controlar y monitorear el sistema de seguridad.

**Historias de Usuario:**
- Como residente, quiero poder ver imágenes en tiempo real de la cámara de la puerta desde mi dispositivo móvil para verificar quién está afuera.
- Como residente, quiero poder ver toda la información registrada por el sistema de seguridad por medio de reportes, gráficas y tablas.

## 2. Integración de Dispositivos IoT
**Descripción:** Integrar el sistema de seguridad con otros dispositivos IoT del hogar para una mayor automatización y control.

**Historias de Usuario:**
- Como usuario, quiero que el sistema se integre con las luces inteligentes para que se enciendan automáticamente cuando se detecte movimiento en la puerta principal.
- Como usuario, quiero que el sistema se integre con un sistema de alarmas para que se enciendan automáticamente cuando se detecte movimiento en la puerta principal.
- Como usuario, quiero poder tomar medidas de seguridad en caso de sentirme en peligro como disparar gas pimienta para alejar a un intruso.

## 4. Registro de Visitantes y Alertas Personalizadas
**Descripción:** Desarrollar una función para registrar a los visitantes autorizados y enviar alertas personalizadas a los residentes.

**Historias de Usuario:**
- Como usuario, quiero poder registrar a los visitantes autorizados en el sistema para saber cuándo se acercan visitantes/familiares.
- Como usuario, quiero recibir una alerta personalizada cuando llegue un visitante específico, como un paquete de entrega, para poder atenderlo rápidamente.


# Fotografía del prototipo propuesto por el equipo

<img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/9ef0944d-dd46-4e1e-a016-2a45b0736386" width="1000" >

# Arquitectura del proyecto

<img src="https://github.com/user-attachments/assets/d5f77eef-5543-41f7-94ff-0550d5bbf5ce" width="1000" >

# Captura de pantalla del tablero Kanban

<a href="https://trello.com/invite/b/gu8ObnVK/ATTIe3733723cdf267f55ab372aa59358de68D40B681/segureye-desarrollo-dispositivos-inteligentes-2024">
    <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/ce28cba9-c5c4-4000-8ed5-8c3197386682" width="1000" alt="SegurEye Documentation">
</a>

# Circuito diseñado para el proyecto completo 

<img src="https://github.com/user-attachments/assets/18089642-508a-4992-826f-6c3b656587c7" width="1000" >

# Video Demostrativo
[Video Demostrativo](https://www.youtube.com/watch?v=J-cqAHvEt4Q)


# Resultados
<img src="https://github.com/user-attachments/assets/c9cabf60-787d-4477-86bb-67d1c3c4348e" width="1000" >
<img src="https://github.com/user-attachments/assets/65f47a3c-3fca-46be-880c-b2dba62205a6" width="1000" >
<img src="https://github.com/user-attachments/assets/ba63419a-205d-497a-bd3d-078af4f50014" width="1000" >

# Planos de caja
<img src="https://github.com/user-attachments/assets/12023bbc-e406-4731-b760-120d172463d0" width="1000" >

# Dashboard

<img src="https://github.com/user-attachments/assets/2265d1d7-4dab-464c-ae0e-9c55bd511dac" width="1000" >

[Dashboard](https://github.com/Arlyule/dashboard-SecureEyes.git)
# Carta
<img src="https://github.com/user-attachments/assets/10705554-f9c8-4783-9622-572ca10a0596" width="1000" >

# Video de agradecimiento

[Video de agradecimiento](https://youtu.be/6E4rt0JwYfY)
