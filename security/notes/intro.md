Seguridad informática
====================

### Los 3 niveles de inseguridad en una infraestructura tecnológica
1. **Nivel de la infraestructura tecnológica** (hardware y nivel físico)
2. **Nivel lógico** (errores en diseño, redes, sistemas de información, almacenamiento)
3. **Nivel humano**

## Dominios de la seguridad informática

![topology]

### Seguridad de perímetro
Protección frente ataques del exterior.

1. **Firewalls**: controla la entrada y salida del tráfico de la red de acuerdo a
reglas de seguridad
2. **IPS (Intrusion Prevention System)**: monitorea la red buscando actividad
maldosa o violaciones de políticas.
3. **IDS (Intrusion Detection System)**: monitorea la red buscando actividad
maldosa o violaciones de políticas.
4. **Anti-sniffers**: Los sniffers son programas que registran la información que
envían los periféricos, así como la actividad realizada en un determinado
ordenador.

### Seguridad en el canal
Proteger los datos frente a escuchas mediante cifrado de información

1. Uso de [criptografía](www.google.com)
    * Criptografía simétrica (única clave).
    * Criptografía asimétrica (clave pública).
    * Criptografía cuántica.
2. Uso de protocolos seguros
    * PGP y S/mime para correos
    * HTTPS para envío de información por la web.
    * Secure shell
3. VPN

### Seguridad de acceso
Se contempla la identificiación del usuario, la autorización del acceso y la
auditoría de las operaciones.

1. RBAC
2. Técnicas de autenticación robustas
3. Autenticación biométrica
    * Universal
    * Único
    * Permanente
    * Colectable por un sensor
    * Confiable (NO falsos positivos)
4. Firmas digitales

#### Probabilidad de descifrar una contraseña
$$P=\frac{tiempoDeVida*númeroDeIntentosPorUnidadDeTiempo}{S}$$
Dónde:
$$S=numCaracteres^{longitud}$$

### Seguridad interna
Incluye la monitorización y seguridad de los servidores, aplicaciones y procesos.

1. Utilizar y actualizar los sistemas operativos seguros.
2. Contra código externo
    * Sólo ejecutar código firmado por una CA confiable
3. Tener antivirus
4. Capacitación de personal
5. Implementación de [políticas de seguridad](./politicas.md)


[topology]: ./media/intro_topology.png
