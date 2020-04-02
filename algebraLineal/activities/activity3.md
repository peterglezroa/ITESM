**Pedro Luis González Roa A01651517**  
**Marcela Arcos Caballero A01703191**  
**Lisieux Serrano A01207648**  
**Adolfo**
# Actividad 3
1. Sean $\vec{v_1}=\begin{bmatrix}1\\2\end{bmatrix}$ y $\vec{v_2}=\begin{bmatrix}-3\\-6\end{bmatrix}$ en $\R²$
    1. Determine $Gen\left\{\vec{v_1},\vec{v_2}\right\}$. ¿Es $\left\{\vec{v_1},\vec{v_2}\right\}$ es un conjunto generador de $\R^2$?
      $$
      \begin{bmatrix}
      1 & -3 & | & x\\
      2 & -6 & | & y
      \end{bmatrix}
      -rref->
      \begin{bmatrix}
      1 & -3 & | & x\\
      0 & 0 & | & 2x-y
      \end{bmatrix}
      $$
      **Concluimos que: $Gen\left\{\vec{v_1},\vec{v_2}\right\} = \left\{\begin{bmatrix}x\\y\end{bmatrix} \epsilon \R^2 : 2x-y=0 \right\}$**

    2. Determine si $\left\{{v_1},{v_2}\right\}$ es un conjunto LI o LD. Si es un conjunto LD, exhiba una combinación lineal de ellos que genere 0, donde no todos los coeficientes son cero.  
    $$-3\vec{v_1}=\vec{v_2}$$
    **${v_1}$ pertenece a lo que genera ${v_2}$ por lo que es linealmente dependiente.**

<br>

2. Sean $\vec{v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$,$\vec{v_2}=\begin{bmatrix}0\\1\\4\end{bmatrix}$, $\vec{v_3}=\begin{bmatrix}5\\6\\3\end{bmatrix}$ y $\vec{v_4}=\begin{bmatrix}7\\2\\-1\end{bmatrix}$ en $\R^3$.
    1. Determine $Gen\left\{\vec{v_1},\vec{v_2},\vec{v_3},\vec{v_4}\right\}$. ¿Es $\left\{\vec{v_1},\vec{v_2},\vec{v_3},\vec{v_4}\right\}$ un conjunto generador de $\R^3$?
      $$
      \begin{bmatrix}
      1 & 0 & 5 & 7 & | & x\\
      3 & 1 & 6 & 2 & | & y\\
      3 & 4 & 3 & -1 & | & w
      \end{bmatrix}
      -rref->
      \begin{bmatrix}
      1 & 0 & 0 & \frac{-17}{4} & | & \frac{-5w-21x+20y}{24}\\
      0 & 1 & 0 & \frac{5}{4} & | & \frac{3w+3x-4y}{8}\\
      0 & 0 & 1 & \frac{9}{4} & | & \frac{w+9x-4y}{2y}
      \end{bmatrix}
      $$
      **Como el SEL siempre es consistente entonces el espacio generado $Gen\left\{\vec{v_1},\vec{v_2},\vec{v_3},\vec{v_4}\right\}=\R^3$.**

    2. Determine si $\left\{\vec{v_1},\vec{v_2},\vec{v_3},\vec{v_4}\right\}$ es un conjunto LI o LD. Si es un conjunto LD, exhiba una combinación lineal de ellos que genere 0, donde no todos los coeficientes son cero.  
    **Hay más columnas que renglones. Por lo tanto es linealmente dependiente. Combinación lineal: $\frac{17}{4}\vec{v_1} + \frac{-5}{4}{v_2}+\frac{-9}{4}{v_3}+{v_4}$**

<br>

3. Sean $\vec{v_1}=\begin{bmatrix}2\\-1\\4\end{bmatrix}$, $\vec{v_2}=\begin{bmatrix}3\\6\\2\end{bmatrix}$ y $\vec{v_1}=\begin{bmatrix}2\\10\\-4\end{bmatrix}$ en $\R^3$.
    1. Determine $Gen\left\{\vec{v_1},\vec{v_2},\vec{v_3}\right\}$. ¿Es $\left\{\vec{v_1},\vec{v_2},\vec{v_3}\right\}$ un conjunto generado de $\R^3$?
    $$
    \begin{bmatrix}
    2 & 3 & 2 & | & x\\
    -1 & 6 & 10 & | & y\\
    4 & 2 & -4 & | & z
    \end{bmatrix}
    -rref->
    \begin{bmatrix}
    1 & 0 & 0 & | & \frac{22x-8y-9z}{16}\\
    0 & 1 & 0 & | & \frac{-18x+8y+11z}{16}\\
    0 & 0 & 1 & | & \frac{26x-8y-15z}{32}
    \end{bmatrix}
    $$
    **Como el SEL siempre es consistente entonces el espacio generado $Gen\left\{\vec{v_1},\vec{v_2},\vec{v_3}\right\}=\R^3$**

    2. Determine si $\left\{\vec{v_1},\vec{v_2},\vec{v_3}\right\}$ es un conjunto LI o LD. Si es un conjunto LD, exhiba una combinación lineal de ellos que genere 0, donde no todos los coeficientes son cero.  
    **Por tener una solución única (misma cantidad de variables y de pivotes) el conjunto es linealmente independiente.**

<br>

4. Sean $\vec{v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$, $\vec{v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$ y $\vec{v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$ en $\R^4$.
    1. Determine $Gen\left\{\vec{v_1},\vec{v_2},\vec{v_3}\right\}$. ¿Es $\left\{\vec{v_1},\vec{v_2},\vec{v_3}\right\}$ un conjunto generado de $\R^4$?
    $$
    \begin{bmatrix}
    1 & 0 & 4 & | & x\\
    2 & 1 & -2 & | & y\\
    -1 & 2 & 0 & | & z\\
    3 & 4 & -2 & | & w
    \end{bmatrix}
    -rref->
    \begin{bmatrix}
    1 & 0 & 4 & | & x\\
    0 & 1 & -10 & | & -2x+4\\
    0 & 0 & 1 & | & \frac{5x-2y+z}{2y}\\
    0 & 0 & 0 & | & \frac{12w-5x-22y-13z}{12}
    \end{bmatrix}
    $$

    2. Determine si $\left\{\vec{v_1},\vec{v_2},\vec{v_3}\right\}$ es un conjunto LI o LD. Si es un conjunto LD, exhiba una combinación lineal de ellos que genere 0, donde no todos los coeficientes son cero.  
    **Existe una restricción para que haya una solución en el SEL: $\frac{12w-5x-22y-13z}{12} = 0$. EL conjunto es linealmente independiente.**

5. Escriba cada uno de los vectores como combinaciones lineales de los vectores $u=\begin{bmatrix}2\\1\\4\end{bmatrix}$, $v=\begin{bmatrix}1\\-1\\3\end{bmatrix}$ y $u=\begin{bmatrix}3\\2\\5\end{bmatrix}$
    1. $\begin{bmatrix}-9\\-7\\-15\end{bmatrix}$
    2. $\begin{bmatrix}6\\11\\6\end{bmatrix}$
    3. $\begin{bmatrix}0\\0\\0\end{bmatrix}$
    4. $\begin{bmatrix}7\\8\\9\end{bmatrix}$
    $$
    \begin{bmatrix}
    2 & 1 & 3 & -9 & 6 & 0 & 7\\
    1 & -1 & 2 & -7 & 11 & 0 & 8\\
    4 & 3 & 5 & -15 & 6 & 0 & 9
    \end{bmatrix}
    -rref->
    \begin{bmatrix}
    1 & 0 & 0 & -4 & 4 & 0 & 0\\
    0 & 1 & 0 & -5 & -5 & 0 & -2\\
    0 & 0 & 1 & -2 & 1 & 0 & 3
    \end{bmatrix}
    $$
    **Se plantea matriz aumentada con los vectores a combinar $\left(\vec{u},\vec{v},\vec{w}\right)$ y los vectores que se quieren formar (incisos _i_ a _iv_). Se concluye que todos se pueden formar de manera única ya que en la forma rref hay un pivote para cada variable en el SEL que se está representando. Las combinaciones lineales son**
    $$
    a=-2u+v-2w\\
    b=4u-5v+w\\
    c=0v+0v+0w\\
    d=0u-2v+3w
    $$
