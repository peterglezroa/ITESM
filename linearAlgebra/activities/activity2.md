Actividad 2
===
### Integrantes
* Pedro Luis González Roa A01651517
* Marcela Arcos Caballero A01703191
* Lisieux Serrano A01207648
### Ejercicio 1
**Respresente la ecuación vectorial dada en forma de un SEL y en forma matricial. Obtenga la forma _rref_ de la matriz aumentada y concluya sobre la(s) solución(ones) del SEL.**
$$
{x_1}\begin{bmatrix}4\\-1\\7\\-4\end{bmatrix}+
{x_2}\begin{bmatrix}-5\\3\\5\\1\end{bmatrix}+
{x_3}\begin{bmatrix}7\\-8\\0\\2\end{bmatrix}=
\begin{bmatrix}6\\-8\\0\\7\end{bmatrix}
$$
<br>
<center>Respuesta:</center>

$$
\begin{bmatrix}
4 & -5 & 7 & | & 6 \\
-1 & 3 & -8 & | & -8 \\
7 & 5 & 0 & | & 0 \\
-4 & 1 & 2 & | & 7 \\
\end{bmatrix}
->
\begin{bmatrix}
4 & \frac{-5}{4} & \frac{7}{4} & | & \frac{3}{2} \\
0 & 1 & \frac{-25}{7} & | & \frac{-26}{7} \\
0 & 0 & 1 & | & \frac{142}{129} \\
0 & 0 & 0 & | & \frac{-1295}{129} \\
\end{bmatrix}
$$
Conclusión: Es un sistema inconsistente porque hay un pivote en la última columna de la matriz aumentada.

### Ejercicio 2
Dados $u = \begin{bmatrix}3 \\ 4\end{bmatrix}, v = \begin{bmatrix}5 \\ -1\end{bmatrix}, w = \begin{bmatrix}7 \\ 1\end{bmatrix}$, calcule, si es posible, las siguientes expresiones:  
1. $||u*w||$
$$
u*w = (3*7)+4=25 \\ ||u*w||=\sqrt{25^2}=25
$$ 

2. $u*w+v$
<center>No se pude realizar la operación ya que no es posible sumar un escalar con un vector</center>

3. $u*(7v+w)$

$$7v+w=\begin{bmatrix}35\\-7\end{bmatrix}+\begin{bmatrix}7\\1\end{bmatrix}=\begin{bmatrix}42\\-6 \end{bmatrix}$$
$$u*(7v+w)=\begin{bmatrix}42\\-6\end{bmatrix}*\begin{bmatrix}3\\4\end{bmatrix}=(42*3)+(-6*4)=102$$

4. $||(u*v)w||$
$$u*v=\begin{bmatrix}3\\4\end{bmatrix}*\begin{bmatrix}5\\-1\end{bmatrix}=11\\$$
$$(u*v)w=11\begin{bmatrix}7\\1\end{bmatrix}=\begin{bmatrix}77\\11\end{bmatrix}\\$$
$$\left|\left|\begin{bmatrix}77\\11\end{bmatrix}\right|\right|=\sqrt{\left(77^2\right)+\left(11^2\right)}=77.817$$

5. ${c_1}$ y ${c_2}$ tal que ${c_1}u+{c_2}v=w$
$${c_1}\begin{bmatrix}3\\4\end{bmatrix}+{c_2}\begin{bmatrix}5\\-1\end{bmatrix}=\begin{bmatrix}7\\1\end{bmatrix}\\$$
$$\begin{bmatrix}3 & 5 & | & 7\\4 & -1 & | & 1 \end{bmatrix}->$$
$$\begin{bmatrix}1 & 0 & | & \frac{12}{23}\\0 & 1 & | & \frac{25}{23}\end{bmatrix}\\$$
$${c_1}=\frac{12}{23}, {c_2}=\frac{25}{23}$$


### Ejercicio 3
1. Si _P_ es invertible y $A=PXP^{-1}$
$$
PX{P}^{-1}=A\\
X{P}^{-1}={P}^{-1}A\\
X={P}^{-1}AP\\
$$

2. Si A,B y C son matrices reales invertibles de $nxn$ y $C^{-1}(A+X)B^{-1}=I$
$$
(A+X)B^{-1}=CI\\ 
(A+X)=CIB\\
X=CIB-A
$$


### Ejercicio 4
Efectué el producto matricial indicado, si es que existe:
$$A = \begin{bmatrix}1&0\\1&1\\1&2\\1&3\end{bmatrix}$$

$$A^t = \begin{bmatrix}1 & 1 & 1 & 1\\0 & 1 & 2 & 3\end{bmatrix}\\$$
1. $A^tA$
$$
[1,1]=1(1)+0(0)=1\\
[4,4]=1(1)+3(3)=10\\

A^tA= \begin{bmatrix}1 & 1 & 1 & 1\\1 & 2 & 3 & 4\\1 & 3 & 5 & 7\\1 & 4 & 7 & 10\end{bmatrix}
$$

2. $AA^t$
$$
[1,1] = 1(1) - 1(1) + 1(1) - 1(1) = 1\\
[2,2] = 0(0) + 1(1) + 2(2) + 3(3) = 14\\
AA^t\begin{bmatrix}1 & 6\\6 & 14\end{bmatrix}
$$

### Ejercicio 5
¿Qué restricciones debe imponer a _x_ y _y_ para que la matriz $A=\begin{bmatrix}x & y\\ y &x\end{bmatrix}$ sea invertible?
$$
(x*x)-(y*y) = x²-y²\\
A^{-1}=\frac{1}{x²-y²}\begin{bmatrix}x & -y\\-y & x\end{bmatrix}=
\begin{bmatrix}
x\frac{1}{x²-y²} & y\frac{1}{x²-y²}\\
-y\frac{1}{x²-y²} & x\frac{1}{x²-y²}
\end{bmatrix}
$$

### Ejercicio 6
Suponga que $A\varepsilon {M_{mxn}}(R)$ no es una matriz cuadrada. Suponga que x es un vector columna de tamaño _n_ y **y** es un vector columna de tamaño _m_. ¿Qué condición deve imponerse para que la ecuación $Ax=y$ tenga solución única para el vector x?

$${A_{mxn}}{x_{nx1}}={y_{mx1}}$$
$$A^tAx=A^ty$$
$$D=A^tA$$
$$Dx=A^ty$$
<center>Para que el sistema tenga una solución única es necesario que D sea invertible.</center>
