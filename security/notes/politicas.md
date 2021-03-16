Políticas de seguridad
======================
## ¿Qué son?
* Expresadas en un idioma y establecida en términos de **sujetos** y **objetos**.
* Deben estar basadas en estándares internacionales y apegadas a la legislación
del país donde se encuentra la compañía.

### Marcos de referencia
* COSO (Committe of Sponsoring Organizations of the Treadway Commission)
* COBIT (Control objectives for information and related technology)
* CRAMM (CCTA Risk Analysis and Management Method)
* FRAP (facilitated risk analysis process)

## Conceptos

### Vulnerabilidad
Es una falta/debilidad/falla de seguridad. Indica que el activo es susceptible a
recibir un daño através de un ataque.

### Exploit
Es el aprovechamiento automático de una vulnerabilidad.

### Riesgo
Es la probabilidad de que un evento desfavorable ocurra. Este tiene un impacto
negativo cuando se materializa.

### Amenaza
Cosa o persona que constituye una posiible causa de riesgo o perjuicio para alguien
o algo.

![amenazas]

## Mitigación de un riesgo
1. Identificar que es lo que se quiere proteger o lo más valioso de la empresa
2. Identificar las amenzas, vulnerabilidades o riesgos a los que está expuesto
este activo. Por ejemplo:
    ![ejemplotabla]
3. Valuar las propiedades (cuánto cuestan las propiedades o recursos):
    * **Evaluación cualitativa**: no se asignan en dólares a cada activo, sino
    solo se determina los niveles de riesgo en base a una política. (No da reporte
    preciso)
    * **Evaluación cuantitativa**:
        1. Estimar el valor SLE(Single Loss Expectancy): $SLE={assetValue} * {exposureFactor}$
        2. Estimar el ARO(Annual rate of occurrence)
        3. Determinar ALE(Annual Loss Expectancy): $ALE = ARO*SLE$
4. Definir una política para reducir el riesgo ó transferir el riesgo a un tercero.

## Escritura de Políticas de seguridad
* Basado en riesgos detectados. Por cada riesgo debe haber al menos 1 política.
* Propósito claro del enunciado
* Nivel de detalle consistente
* Neutralidad tecnológica
* Descubrir el qué, no el cómo

> Todas las conexiones con los servidores de la empresa deberán establecerse mediante
canales seguros.


## Mecanismos de seguridad
Para cada política debe haber 1 o más mecanismos de seguridad que lo implementen.

> Se instalarán certificados digitales y TLS para poder ofrecer conexiones seguras
a todos los servidores web de la compañía.

## Evaluación de un sistema
### Auditoría de seguridad
Proceso formal utilizado para medir aspectos de alto nivel de la infraestructura
de seguridadd desde la perspectiva organizacional. Se lleva acabo por directivos.

### Evaluación de la seguridad
Orientada a establecer mayores detalles técnicos de la seguridad de la infraestructura
de una organización. Son menos formales que las auditorías. se lleva a cabo por
un equipo de expertos en tecnología.

### Pruebas de penetración
Pretenden demostrar que una infraestructura es vulnerable, penetrando en ella
a través de ataques controlados desde dentro o fuera de la organización.

[amenazas]: ./media/politicas_amenazas.png
[ejemplotabla]: ./media/politicas_ejemplotabla.png
