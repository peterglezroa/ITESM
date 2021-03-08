Procesos e hilos
===
## Definiciones
### Semáforo
Para controlar el acceso para un recurso compartido no exclusivo.
* Leer un archivo no es exclusividad.
* Leer y escribir sí es exclusividad.
* Dos operaciones:
  * B -> Bloquear:
    * Se saca del procesador
  * P -> 
### Monitor
Evolución de un semáforo con una lista de espera.
* Se bloquean y se sacan
### Variables de condición
* Spin locks
* Pueden acceder varios hilos al mismo hilo
  * Si no pueden acceder al recurso y siguen en el quantum de tiempo, se mantienen en estado de 'ready'
  * Si no pueden acceder al recurso y se les acaba su quantum de tiempo se saca.
### Atomicidad
Cuando se empieza una tarea, ya no se puede cancelar hasta que acabe.
## Hilo
* Lleva su counter.
* Si los hilos pertenecen al mismo proceso, no hay cambio de proceso.
* Puedo montar en hilos (físicos. 'cores') diferentes hilos (tareas) de procesos.  
  * Con quantums
## Proceso
{ Definir proceso }  
{ Estructura de memoria de un proceso (stack, heap, etc) }  
{ Estados de un proceso }  
#### Repaso Sistemas Operativos
* Para hacer que un proceso no dañe otros procesos o el sistema operativo: lo aislamo porque todo proceso cuando corre sólo pueder correr en 2 modos (kernel y usuario). Para acceder al kernel se necesitan llamadas al sistema.
## Deadlocks (Interbloqueos)
