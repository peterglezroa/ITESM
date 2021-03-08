# UNIX
### Kernel
* Servicios básicos sobre el cual se monta un sistema operativo
* Sobre esto se agregan micro servicios (la mayoría de lo que usamos normalmente en la computadora)
* Unidad mínima de procesación
### Sistema de archivos
* Estructura jerárguica
* Realizar un tratamiento consistente de los datos de los archivos.
* A diferencia de Windows, el crecimiento es dinámico
	* Windows -> bloques continuos
	* Ventajas
		* Nunca se tiene que fragmentar. Windows deja huecos pero por cómo se guarda te va a decir que no hay espacio en memoria.
		* Cómo se almacena como linked list (o algo parecido. Usando apuntadores) se puede llenar los huecos.
	* Desventaja
		* Mayor tiempo para abrir los archivos.
* TODO LO MANEJA COMO ARCHIVOS (Hasta dispositivos externos como el teclado)
* Se pueden usar varios discos duros pero el sistema operativo lo considera como uno
