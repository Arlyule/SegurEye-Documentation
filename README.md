# Proyecto de Sistema de Seguridad con Cámara en la Puerta

# Equipo de Desarrollo

## Scrum Master
- Carlos Edurado Mata Rojas

## Product Owner
- Julio Samuel Torres Reyes

## Equipo Scrum
1. Carlos Mata (Scrum Master) 
2. Julio Torres (Product Owner)
3. Joel Morales

# Visión
Ser una organización de desarrollo de software basada en el compromiso con la innovación, la seguridad y la facilidad de uso, 
ofreciendo soluciones tecnológicas avanzadas que mejoren la calidad de vida de nuestros usuarios mediante sistemas de seguridad inteligentes y accesibles.

# Descripción del Proyecto
El proyecto consiste en desarrollar un sistema de seguridad inteligente que utilice una cámara instalada en la puerta principal para detectar y reconocer a los visitantes, proporcionando un control de acceso seguro y conveniente para los residentes del hogar. El sistema estará equipado con tecnologías avanzadas como reconocimiento facial y detección de objetos inteligente, ofreciendo una experiencia de seguridad innovadora y fácil de usar.

# Software Empleados

| Nombre | Licencia | 
|--------|----------|
| Arduino IDE | GNU General Public License (GPL) | 
| Node Red | Apache License 2.0 | 
| Flutter | BSD 3-Clause License | 
| ESP32 S3 LVGL | MIT |
| ESP32 Camera | MIT |
| Servo FS90R |	LGPL-2.1 |
| Arduino-PIR |	MIT |

# Hardware empleado
| Nombre | Imagen | Descripción | Cantidad |
|--------|--------|-------------|----------|
| ESP32 CAM | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/308890b1-333b-4517-ba16-6d12565bce9b" alt="ESP32 CAM" width="150"/>| El módulo ESP32 CAM integra un microcontrolador ESP32 y una cámara OV2640. El ESP32 proporciona conectividad Wi-Fi y Bluetooth, mientras que la cámara OV2640 captura imágenes con resolución de hasta 2 megapíxeles. Este módulo es ideal para proyectos de visión artificial, como detección de movimiento, reconocimiento facial y transmisión de video en tiempo real. | 1 |
| EL sensor de movimiento PIR | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/b048c046-b468-4325-9cb8-d7613bba292a" alt="EL sensor de movimiento PIR" width="150"/>| El sensor de movimiento PIR (Passive Infrared) detecta cambios en la radiación infrarroja emitida por objetos en su campo de visión. Cuando se detecta movimiento, el sensor activa una señal eléctrica, que puede ser utilizada para activar dispositivos de seguridad, luces automáticas u otros sistemas de automatización. | 1 |
| Sensor de Luz | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/7567182c-dbce-4fee-80bb-8abad6df72be" alt="Sensor de Luz" width="150"/>| Este sensor mide la intensidad de la luz incidente en su entorno. Utiliza un fotoresistor o un fotodiodo para convertir la luz en una señal eléctrica. La salida del sensor puede ser utilizada para ajustar automáticamente la iluminación en función de las condiciones de luz ambiental. | 1 |
| Buzzer | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/eec6b1ad-77c3-49b5-9331-36960f156517" alt="Bocina" width="150"/>| Un buzzer es un transductor electromecánico que convierte una señal eléctrica en sonido audible. Puede generar tonos simples o patrones de sonido más complejos. Se utiliza comúnmente para proporcionar retroalimentación audible en sistemas electrónicos, como alarmas, notificaciones o señales de advertencia. | 1 |
| Jumper Macho-Macho | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/0dc09801-833e-4635-9293-84b0f8350037" alt="Jumper Macho-Macho" width="150"/>| Estos cables están diseñados para conectar componentes electrónicos entre sí. Tienen un conector macho en cada extremo, lo que les permite establecer conexiones temporales en una protoboard o en un circuito impreso. | 40 |
| Jumper Macho-Hembra | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/6449b658-7fdb-4a4b-8c57-8e37dee4059c" alt="Jumper Macho-Hembra" width="150"/>| Estos cables tienen un conector macho en un extremo y un conector hembra en el otro. Son útiles para conectar componentes electrónicos con diferentes tipos de pines, como microcontroladores y sensores, a una protoboard. | 40 |
| Protoboard | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/2b68b33c-ef44-4fb1-a582-9407515812d2" width="150"/>| Una protoboard es una placa de pruebas que permite la conexión temporal de componentes electrónicos. Tiene una matriz de agujeros y líneas conductoras que facilitan la creación de circuitos y prototipos. Es una herramienta fundamental en el desarrollo y la depuración de proyectos electrónicos. | 1 |
| Servo FS90R | <img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/783bff7a-2f3e-4497-8bb1-ed898a5c9d5c" width="150"/>| Un servo es un dispositivo que combina un motor, un sensor de posición y un circuito de control. Se utiliza para controlar el movimiento angular de manera precisa y es común en aplicaciones robóticas, sistemas de control de aeronaves, y dispositivos de automatización. | 1 |


# Historias de usuario épicas

| Épica | Historia de Usuario | Prioridad | Puntos de Historia |
|-------|---------------------|-----------|--------------------|
| 1     | Reconocimiento de Visitantes | Alta | 8 |
| 2     | Control de Acceso | Alta | 5 |
| 3     | Interfaz de Usuario Intuitiva | Media | 3 |

# Épicas del Proyecto Wearable

## 1. Reconocimiento de Visitantes
**Descripción:** Implementar la capacidad de reconocer a los visitantes autorizados y no autorizados que se acerquen a la puerta.

**Historias de Usuario:**
- Como residente, quiero que el sistema reconozca automáticamente a los visitantes autorizados para evitar activar algún sistema de alertas.
- Como residente, quiero recibir una notificación cuando el sistema detecte a un visitante no autorizado para poder tomar medidas adicionales de seguridad.

## 2. Interfaz de Usuario Intuitiva
**Descripción:** Crear una interfaz de usuario fácil de usar para controlar y monitorear el sistema de seguridad.

**Historias de Usuario:**
- Como residente, quiero poder ver imágenes en tiempo real de la cámara de la puerta desde mi dispositivo móvil para verificar quién está afuera.
- Como residente, quiero poder ver toda la información registrada por el sistema de seguridad por medio de reportes, gráficas y tablas.

## 3. Integración de Dispositivos IoT
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

<img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/9fac58bd-3943-41b1-8664-4b3c161cd41a" width="1000" >

# Captura de pantalla del tablero Kanban

<img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/ce28cba9-c5c4-4000-8ed5-8c3197386682" width="1000" >

# Circuito diseñado para el proyecto completo 

<img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/1939a96f-9b2e-4764-af6d-adb9d5e10132" width="1000" >
<img src="https://github.com/Arlyule/SegurEye-Documentation/assets/105952154/70accff0-6133-4922-b106-7951473b91a9" width="1000" >

# Resultados
Aquí se listaran los resultados
