Transformaciones lineales
=====
> Source: Presentaciones de Jorge Arturo Garza Venegas

Sean _V, W_ espacios vectoriales reales. Una **transformación lineal** de _V_ en _W_, es una función (denotada por _T_) de _V_ en _W_ que satisface dos condiciones:
* $\forall u,v \in V,$ se tiene que $T(u) + T(v)$ 
* $\forall u,v \in V y \forall \alpha \in \R$, se tiene que $T(\alpha u) = \alpha T (u)$

## Propiedades básicas
En Álgebra Lineal, las transformaciones lineales usualmente se puedes representar como:
$$y=Ax$$
que asemeja a la función lineal. Para crear _transformaciones_ más complejas podemos hacer algunas de ellas seguidas de otras. Si ${T_a}$ y ${T_b}$ son transformaciones lineales, se puede definir una transformación lineal como:
$$\left( {T_a}*{T_b}\right)(v) = {T_a}[{T_b}(v)]$$

### Ejemplo
**Considere una transformación lineal que consiste en las siguientes operaciones:**
1. **Una expansión en el eje $x$ de 5 unidades.**
2. **Una contracción en el eje $y$ en un factor de $\frac{1}{2}$.**
3. **Una reflexión sobre la recta $y=x$.**
4. **Un corte sobre el eje $x$ con $k=3$.**
**estrictamente en ese orden. Esto es, determine $T\left( \begin{bmatrix}x\\y\end{bmatrix} \right)$ y su representación matricial.**

Como las transformaciones lineales en _1._ - _2._ tienen representaciones matriciales dads por: 
$$
A = \begin{bmatrix}5 & 0 \\ 0 & 1\end{bmatrix},
B = \begin{bmatrix}1 & 0 \\ 0 & \frac{1}{2}\end{bmatrix},
C = \begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix},
D = \begin{bmatrix}1 & 3 \\ 0 & 1\end{bmatrix}
$$
Si tendríamos que el vector $v=\begin{bmatrix}x\\y\end{bmatrix}$ se transforma subsecuentemente:
1. Una expansión en el eje x de 5 unidades.
$$Av=\begin{bmatrix}5 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}=\begin{bmatrix}5x\\y\end{bmatrix}$$

2. Una contracción en el eje $y$ en un factor de $\frac{1}{2}$
$$B[Av]=\begin{bmatrix}1 & 0 \\ 0 & \frac{1}{2}\end{bmatrix}\left\{\begin{bmatrix}5 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}\right\} =\begin{bmatrix}5x \\ \frac{1}{2}y\end{bmatrix}$$

3. Una reflexión sobre la recta $y=x$.
$$C[BAv]=\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}\left\{\begin{bmatrix}1 & 0 \\ 0 & \frac{1}{2}\end{bmatrix}\begin{bmatrix}5 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}\right\} =\begin{bmatrix}\frac{1}{2}y \\ 5x\end{bmatrix}$$

4. Un corte sobre el eje $x$ con $k=3$
$$C[BAv]=\begin{bmatrix}1 & 3 \\ 0 & 1\end{bmatrix}\left\{\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}\begin{bmatrix}1 & 0 \\ 0 & \frac{1}{2}\end{bmatrix}\begin{bmatrix}5 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}\right\} =\begin{bmatrix}15x+\frac{1}{2}y \\ 5x\end{bmatrix}$$

De donde puede obtenerse la representación matricial de una de dos formas:
* Usando el hecho que:
$$T\left(\begin{bmatrix}x\\y\end{bmatrix}\right) = \begin{bmatrix}15x+\frac{1}{2}y\\5x\end{bmatrix} \implies {T_a} = \begin{bmatrix}15 & \frac{1}{2} \\ 5 & 0\end{bmatrix}$$
* Notando que la matrix de transformación es ${T_a} = DCBA$
$${T_a}=DCBA=\begin{bmatrix}1 & 3 \\ 0 & 1\end{bmatrix}\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}\begin{bmatrix}1 & 0 \\ 0 & \frac{1}{2}\end{bmatrix}\begin{bmatrix}5 & 0 \\ 0 & 1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix} =\begin{bmatrix}15x+\frac{1}{2}y \\ 5x\end{bmatrix}$$



## Expansiones y contracciones en el eje _x_, _y_ o ambos
![expansiones contraciones][expansiones]

### Ejemplo:
**Determine la matrix la matriz de transformación para una expansión/contracción sobre el eje $x$ en ${c_x}$ unidades**

Como basta con observar lo que sucede a los vectores de la base estándar de $\R²$ y tomando en cuenta que una expansión en el eje $x$ implica que los valores se transforman de $x$ a ${c_x}$ mientras que los que están en $y$ permanecen fijos, podemos determinar que:

$$
T\left(\begin{bmatrix}x\\y\end{bmatrix} \right)
=
\begin{bmatrix}{c_x}x\\y\end{bmatrix}
$$
de modo que la matriz A buscada se obtiene al hacer:
$$
A = \left[T\left({e_1}\right)|T\left({e_2}\right)\right]
$$
Como
$$ T\left({e_1}\right)=T\left( \begin{bmatrix} 1\\0 \end{bmatrix} \right) =  \begin{bmatrix} {c_x}*1\\0*1 \end{bmatrix} = \begin{bmatrix} {c_x}\\0 \end{bmatrix} $$
$$ T\left({e_2}\right)=T\left( \begin{bmatrix} 0\\1 \end{bmatrix} \right) = \begin{bmatrix} {c_x}*0\\1*1 \end{bmatrix} = \begin{bmatrix} 0\\1 \end{bmatrix} $$

la matriz de transformación es
$$A= \begin{bmatrix} {c_x} & 0 \\ 0 & 1 \end{bmatrix} $$

y representa una **expansión** en el eje $x$ si ${c_x} >1$ y una contracción si $0<{c_x}<1$



## Reflexiones
![reflexiones][reflexiones] ![reflexiones][reflexiones2]

### Ejemplo:
**Determine la matriz de transformación para una reflexión sobre el eje $x$**  
Como basta con observar lo que les sucede a los vectores de la base estándar de $\R^2$, y tomando en cuenta que una reflexión en el eje $x$ implica que los valores de $x$ se quedan iguales, pero los de $y$ se cambian a $-y$, podemos determinar que:
$$T \left( \begin{bmatrix} x\\y \end{bmatrix} \right) = \begin{bmatrix}x\\-y\end{bmatrix}$$
de mode que la matriz $A$ buscada se obtiene al hacer
$$A = \left[ T\left( {e_1} \right) | T\left({e_2}\right) \right]$$
Como
$$ T\left({e_1}\right)=T\left( \begin{bmatrix} 1\\0 \end{bmatrix} \right) = \begin{bmatrix} 1\\0 \end{bmatrix} $$
$$ T\left({e_2}\right)=T\left( \begin{bmatrix} 0\\1 \end{bmatrix} \right) = \begin{bmatrix} 0\\-1 \end{bmatrix} $$
la matriz de transformación es
$$A = \begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix}$$
y representa una reflexión en el eje $x$.

### Ejercicios:
**Verifique que las matrices $A$ indicadas corresponden a**

a. Reflexión en el eje $y$:
$$A=\begin{bmatrix}-1 & 0 \\ 0 & 1\end{bmatrix}$$

Cómo queremos invertir la matriz en el eje $y$, tenemos que dejar los valores en para el eje $y$ iguales y cambiar los valores del eje $x$ a negativo

$$T \left( \begin{bmatrix}x\\y\end{bmatrix} \right) = \begin{bmatrix} -x\\y \end{bmatrix}$$

de modo que la matriz $A$ buscada se obtiene al hacer:
$$ A = \left[ T\left({e_1}\right) | T\left({e_2}\right) \right]$$
Como:
$$T\left({e_1}\right) = \begin{bmatrix} -1 \\ 0\end{bmatrix}$$
$$T\left({e_2}\right) = \begin{bmatrix} 0 \\ 1\end{bmatrix}$$
Por lo que:

$$A= \begin{bmatrix} -1 & 0 \\ 0 & 1\end{bmatrix}$$

Verificamos con la matriz $E = \begin{bmatrix}1 & 2 \\ 3 & 4\end{bmatrix}$

$$E * A = \begin{bmatrix} \left(  \right) & \left( \right) \\ \left( \right) & \left( \right)\end{bmatrix} = \begin{bmatrix}\end{bmatrix}$$


## Rotaciones
![rotaciones][rotaciones]

### Recordando Coordenadas polares
![polares][polares]
$$ x = r\cos(\alpha)$$
$$ y = r\sin(\alpha)$$
Pero consideramos que $r$ se mantiene igual. Por lo tanto sólo queremos _rotar_ el punto $\theta$ radianes, es decir, rotarlo para que se encuentre en el ángulo $\alpha + \theta$ porque $\alpha$ es nuestro ángulo inicial.

### Ejemplo:
**Determine la matriz de transformación para una rotación en sentido _antihorario_ de $\theta$ radianes.**

Como no se modifica la norma de los vectores en la rotación, sin pérdida de generalidad, consideramos que son unitarios, lo cual es cierto para los vectors {e_1} y {e_2}.

Si se rota un punto $(x,y)$ un ángulo de $\theta$ radianes en sentido antihorario, usaremos resultados considerando las coordenadas polares en lugar de las cartesianas. Cualquier punto de la circunferencia unitaria se puede identificar como:
$$x = \cos(\alpha)$$
$$y = \sin(\alpha)$$
done $\alpha$ es el ángulo en el que se encuentra el punto.

De modo que si se rota un ángulo de $\theta$ radianes en sentido antihorario, las nuevas coordenadas quedan determinadas por:
$$x = \cos(\alpha + \theta)$$
$$y = \sin(\alpha + \theta)$$
para los vectores de la base, los ángulos son $\alpha = 0$ para ${e_1}$ y $\alpha = \frac{\pi}{2}$ para ${e_2}$

De este modo, tendremos que:
$$T\left({e_1}\right) = \begin{bmatrix} 1 \\ 0\end{bmatrix} = \begin{bmatrix}\cos\left(0+\theta\right) \\ \sin\left(0+\theta\right)\end{bmatrix} = \begin{bmatrix}\cos(\theta) \\ \sin(\theta)\end{bmatrix}$$
$$T\left({e_2}\right) = \begin{bmatrix} 0 \\ 1\end{bmatrix} = \begin{bmatrix}\cos\left(\frac{\pi}{2}+\theta\right) \\ \sin\left(\frac{\pi}{2}+\theta\right)\end{bmatrix} = \begin{bmatrix}\cos(\theta) \\ \sin(\theta)\end{bmatrix}$$

De este modo, tendremos que la matriz de transformación es:
$$A=\begin{bmatrix}\cos(\theta) & -\sin(\theta) \\ \sin(\theta) & \cos(\theta)\end{bmatrix}$$
y representa una **rotación** $\theta$ radianes en sentido contrario a las manecillas del reloj.


### Ejercicios
1. Rotación de un ángulo $\theta = \frac{\pi}{2}$:
$$A=\begin{bmatrix}0 & -1 \\ 1 & 0\end{bmatrix}$$
2. Rotación en un ángulo $\theta = \frac{\pi}{4}$:
$$A=\begin{bmatrix}\frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{2}} \\ \frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}}\end{bmatrix}$$
3. Rotación en un ángulo $\theta = \frac{3\pi}{2}$:
$$A=\begin{bmatrix}0 & 1 \\ -1 & 0\end{bmatrix}$$

## Cortes
![cortes][cortes]

Consiste en transformar las coordenadas en $x$ en un punto sobre una recta y/o las coordenadas en $x$ en $y$ en puntos sobre otra recta.

### Ejemplo:
**Determine la matriz de transformación para un corte sobre el eje $x$**

Como basta con observar lo que les sucede a los vectores de la base estándar de $\R^2$ y tomando en cuenta que un corte en el eje $x$ implica que el vectore ${e_1}$ permanece igual y que para el vector ${e_2}$ se transforma la coordenada en $x$ a $k$ mientras que la coordenada en $y$ permanece fija, podemos determinar que: 

$$ T\left({e_1}\right)=T\left( \begin{bmatrix} 1\\0 \end{bmatrix} \right) = \begin{bmatrix} 1\\0 \end{bmatrix} $$
$$ T\left({e_2}\right)=T\left( \begin{bmatrix} 0\\1 \end{bmatrix} \right) = \begin{bmatrix} k\\1 \end{bmatrix} $$

De esta forma la matriz de transformación es:
$$A= \begin{bmatrix} 1 & k \\ 0 & 1 \end{bmatrix} $$
y representa un **corte** en el eje $x$.

### Ejercicios:
1. Corte en el eje $y$:
$$A= \begin{bmatrix} 1 & 0 \\ k & 1 \end{bmatrix} $$
2. Corte en ambos ejes:
$$A= \begin{bmatrix} 1 & {k_x} \\ {k_y} & 1 \end{bmatrix} $$

## Proyecciones sobre los ejes
![proyecciones][proyecciones]

### Ejemplo:
**Determine la matriz de transformación para una proyección sobre el eje $x$.**

Como basta con observar lo que les sucede a los vectores de la base estándar de $\R^2$, y tomando en cuenta que una proyección sobre el eje $x$ es _la sombra_ que queda en el eje $x4 implica que el vector {e_1} permanece igual y que para el vector {e_2} la coordenada en $x$ permanece igual y la coordenada en $y$ se _proyecta_ y se va al cero, podemos determinar que:
$$T{e_1} = T\left(\begin{bmatrix}1 \\ 0\end{bmatrix}\right) = \begin{bmatrix}1\\0\end{bmatrix}$$
$$T{e_1} = T\left(\begin{bmatrix}0 \\ 1\end{bmatrix}\right) = \begin{bmatrix}0\\0\end{bmatrix}$$

De esta forma, la matriz de transformación es:
$$A=\begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix}$$

## Kernel e Imagen

### Ejercicios
1. sdf
2. $T\left(\begin{bmatrix}-y\\x+2y\\3x-4y\end{bmatrix}\right)$
$$A = \begin{bmatrix}0 & -1 \\ 1 & 2 \\ 3 & -4\end{bmatrix}$$
$$ 
\begin{bmatrix}0 & -1 & | & x \\ 1 & 2 & | & y\\ 3 & -4 & | & z\end{bmatrix} 
-rref->
\begin{bmatrix}1 & 0 & | & 2x+y \\ 0 & 1 & | & -x\\ 0 & 0 & | & 10x+3y-z\end{bmatrix} 
$$

#### Kernel
$$\begin{bmatrix}1 & 0 & | & 0 \\ 0 & 1 & | & 0\\ 0 & 0 & | & 0\end{bmatrix}$$
Como la solución es única para el SEL => $ker(T)=\left\{\vec{0}\right\}$

#### Imagen
Como el SEL No tiene solución si.
Como el plano que genera tiene la ecuación $10x+3y-z=0$ entonces $z=10x+3y$. Entonces:
$$\begin{bmatrix}x\\y\\z\end{bmatrix} = \begin{bmatrix}x\\y\\10x+3y\end{bmatrix}$$
$$\begin{bmatrix}x\\y\\z\end{bmatrix} = x\begin{bmatrix}1\\0\\10\end{bmatrix} + y\begin{bmatrix}0\\1\\3\end{bmatrix}$$
Por lo tanto:
$$Im(T)=Gen\left\{\begin{bmatrix}1\\0\\10\end{bmatrix},\begin{bmatrix}0\\1\\3\end{bmatrix}\right\}$$

$$N(T) = 0, \rho(T) = 2$$

3. $T\begin{bmatrix}x\\y\\z\end{bmatrix} = \begin{bmatrix}x-y+z \\2x+y-3z\end{bmatrix}$

$$A = \begin{bmatrix}1 & -1 & 1\\2 & 1 & -3\end{bmatrix}$$

#### Kernel
$$
\begin{bmatrix}1 & -1 & 1\\2 & 1 & -3\end{bmatrix}
-rref->
\begin{bmatrix}1 & -1 & 1\\2 & 1 & -3\end{bmatrix}
$$

#### Imagen




[expansiones]: ../img/tl_expansionesYContracciones.png
[reflexiones]: ../img/tl_reflexiones.png
[reflexiones2]: ../img/tl_reflexiones2.png
[rotaciones]: ../img/tl_rotaciones.png
[cortes]: ../img/tl_cortes.png
[proyecciones]: ../img/tl_proyecciones.png
[polares]: ../img/tl_polares.png
