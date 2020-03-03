Combinación lineal
===
### Juegos lineales finitos
#### Problema 1
Una hilera de cinco luces se controla mediante cinco interruptores. Cada interruptor cambia el estado (encendido/apagado) de la luz directamente arriba de él y los estados de las luces inmediatamente adyacentes a izquierda y derecha.
1. ¿Puede oprimir los interruptores en algún orden de modo que sólo la primera, la tercera y quinta luces estén encendidas?
2. ¿Importa el orden en que haga dicha operación?
3. ¿Se podrán oprimir los interruptores de algún modo que sólo la primera luz esté encendida?
  
**Si consideramos los estados 0 - apagado, 1 - encendido:**
$$ 
a = \begin{bmatrix}1 \\ 1 \\ 0 \\ 0 \\ 0\end{bmatrix}, 
b = \begin{bmatrix}1 \\ 1 \\ 1 \\ 0 \\ 0\end{bmatrix},
c = \begin{bmatrix}0 \\ 1 \\ 1 \\ 1 \\ 0\end{bmatrix},
d = \begin{bmatrix}0 \\ 0 \\ 1 \\ 1 \\ 1\end{bmatrix},
e = \begin{bmatrix}0 \\ 0 \\ 0 \\ 1 \\ 1\end{bmatrix}
$$
$$
s+a = \begin{bmatrix}0 \\ 0 \\ 0 \\ 0 \\ 0\end{bmatrix}+ 
\begin{bmatrix}1 \\ 1 \\ 0 \\ 0 \\ 0\end{bmatrix}=
\begin{bmatrix}1 \\ 1 \\ 0 \\ 0 \\ 0\end{bmatrix} \\
$$
**Del estado inicial se oprime:**
$$
{s^*}+a = \begin{bmatrix}0 \\ 1 \\ 1 \\ 1 \\ 0\end{bmatrix}+ 
\begin{bmatrix}1 \\ 1 \\ 0 \\ 0 \\ 0\end{bmatrix}=
\begin{bmatrix}1 \\ 0 \\ 1 \\ 1\\ 0\end{bmatrix}
$$
**Por lo que se llega  la ec. vectorial:**
$$
{s^*}+a+c+d+a+c+b = {s^*}+2a+2c+d+b = {s^*}+d+b = t \\
t = {c_1}a + {c_2}b +{c_3}c+{c_4}d{c_5}e
$$

$$
\begin{bmatrix}
1 & 1 & 0 & 0 & 0 & | & 1\\
1 & 1 & 1 & 0 & 0 & | & 0\\
0 & 1 & 1 & 1 & 0 & | & 1\\
0 & 0 & 1 & 1 & 1 & | & 0\\
0 & 0 & 0 & 1 & 1 & | & 1
\end{bmatrix}
$$
$${c_1} = {c_5} \\ {c_2} = {c_5} + 1 \\ {c_3} = -1 \\ {c_4} = {c_5} + 1 \\ {c_5} = {c_5}$$
**C5 es una variable libre. Por lo que hay una infinidad de soluciones. Ejemplo:**
$${c_1} = 0 \\ {c_2} = 1 \\ {c_3} = -1 \\ {c_4} = 1 \\ {c_5} = 0$$
**Ó**
$${c_1} = 1 \\ {c_2} = 0 \\ {c_3} = 1 \\ {c_4} = 0 \\ {c_5} = 1$$

#### Problema 2 
Escriba un sistem de ecuaciones que sea equivalente a la ecuación vectorial:
$$
{x_1} \begin{bmatrix}6 & -1 & 5\end{bmatrix}+
{x_2} \begin{bmatrix}-3 & 4 & 0\end{bmatrix}=
\begin{bmatrix}1 & -7 & -5\end{bmatrix}
$$

$$
\begin{bmatrix}
6 & -1 & 5 & | & {x_1}\\
-3 & 4 & 0 & | & {x_2}
\end{bmatrix}
=
\begin{bmatrix}1 \\ -7 \\ -5\end{bmatrix}
$$

#### Problema 3
Escriba una ecuación vectorial que sea equivalente al SEL:
$$
4{x_1} + {x_2} + {x_3} = 9 \\
{x_1} - 7{x_2} - 2{x_3} = 2 \\
8{x_1} + 6{x_2} - 5{x_3} = 15
$$
