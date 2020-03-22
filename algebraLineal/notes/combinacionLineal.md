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

#### Problema ?
${v_1} = \begin{bmatrix}1 \\ -1 \\ 3\end{bmatrix}, {v_2} = \begin{bmatrix}-1 \\ 5 \\ 1\end{bmatrix}, {v_3} = \begin{bmatrix}1 \\ -3 \\ 1\end{bmatrix}$

**Solución: Para saber si generan ${|R^3}$, cualquier vector de {R^3} se puede escribir como combinación lineal de ${v_1}, {v_2}, {v_3}$. Para eso, deben existir ${c_1}, {c_2}, {c_3}$ tales que $\begin{bmatrix}x\\y\\z\end{bmatrix}=w={c_1}{v_1}+{c_2}{v_2}+{c_3}{v_3}$**

<center>Matriz aumentada</center>

$$
\begin{bmatrix}
1 & -1 & 1 & | & x\\
-1 & 5 & -3 & | & y\\
3 & 1 & 1 & | & z
\end{bmatrix}
-rref->
\begin{bmatrix}
1 & 0 & \frac{1}{2} & | & \frac{1}{4}\left(5xty\right)\\
0 & 1 & \frac{-1}{2} & | & \frac{1}{4}\left(x+y\right)\\
0 & 0 & 0 & | & \left(x+y-z\right)
\end{bmatrix}
$$
**El SEL es inconsistente si 4x+y-z = 0**

#### Problemas: Determine si los vectores dados generan ${R^3}$. Si no lo generan, diga que espacio lineal sí generan geométricamente y analíticamente:
1. ${v_1} = \begin{bmatrix}2\\2\\2\end{bmatrix},{v_2} = \begin{bmatrix}0\\0\\3\end{bmatrix}, {v_3}=\begin{bmatrix}0\\1\\1\end{bmatrix}$
$$
\begin{bmatrix}
2 & 0 & 0 & | & x\\
2 & 0 & 1 & | & y\\
2 & 3 & 1 & | & z
\end{bmatrix}
-rref->
\begin{bmatrix}
1 & 0 & 0 & | & \frac{x}{2}\\
0 & 1 & 0 & | & \frac{1}{3}\left(y+x\right)\\
0 & 0 & 1 & | & -x+y
\end{bmatrix}
$$
Como el SEL es consistente entonces $Gen\left({v_1},{v_2},{v_3}=R^3=\begin{bmatrix}x\\y\\z\end{bmatrix}\epsilon R^3:4x+y-z=0\right)$

2. ${v_1} = \begin{bmatrix}2\\-1\\3\end{bmatrix},{v_2} = \begin{bmatrix}4\\1\\2\end{bmatrix}, {v_3}=\begin{bmatrix}8\\-1\\8\end{bmatrix}$
$$
\begin{bmatrix}
2 & 4 & 8 & | & x\\
-1 & -1 & -1 & | & y\\
3 & 2 & 8 & | & z
\end{bmatrix}
-rref->
\begin{bmatrix}
1 & 0 & 2 & | & \frac{x}{2}\\
0 & 1 & 0 & | & \frac{1}{6}\left(x+2y\right)\\
0 & 0 & 0 & | & \frac{1}{6}\left(-5x+8y+6z\right)
\end{bmatrix}
$$

4. Sean ${v_1},{v_2}...{v_z} \epsilon \R^n$ y $c \epsilon \R$. Si $u,v \epsilon Gen\left\{{v_1},{v_2}\right\}$ demuestre que:
    1. $u+x \epsilon Gen\left\{{v_1},{v_2}\right\}$
**$u+x \epsilon Gen\left\{{v_1},{v_2}\right\}$ si y sólo si es combinación lineal de ${v_1}, .., {v_k}$:**
