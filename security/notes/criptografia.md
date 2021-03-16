Criptografía
============

## Criptografía clásica
### Transposición
Consiste en cambiar las letras de lugar. Las operaciones se realizan mediantes
grupos, serias, columnas o filas.

### Sustitución
* **Monoalfabética**: Se usa sólo un alfabeto de cifrado. Se sustituye un elemento
del texto por un único elemento del alfabeto. Se puede utilizar el método **monográmico**
(sustitución de una letra) ó el método **poligrámico** (varias letras).
* **Polialfabética**: Se usa con varios alfabetos de crifrado.
    * **No Periódicos**: Usan una misma clave.
    * **Periódicos**: Usan diferentes claves.

#### Sustitución monoalfabeto monográmica
$$criptograma = \left(a*{letraTextoClaro}+b\right){mod}n$$
ecuación de descifrado
$${letraTextoClaro}=({criptograma}-b)*{a}^{-1}{mod}n$$

#### Sustición polialfabética
![polialfabetica]

[polialfabetica]: ./media/criptograma_polialfabetica.png
