Files
===
En un proceso recién aplicado. Si yo abro un archivo ¿Cuál es el valor numérico del file que me va regresa? 3. Porque ya tienen 3 files descriptors.

En un programa nuevo. Si hago:
<pre><code>char* s[] = "Hola Mundo";
fd = open(__,O_WRLONY__);
close(1); // Se cierra la salida estándar (stdout) y libero el file escrito
dup(fd); // Me regresa un file escrito en el mismo recurso. Osea dos files en el mismo recurso
close(fd); // 
write(fd, s, sizeof(s));
</code></pre>
¿Dónde imprime? Se imprime en la pantalla y en el archivo.
