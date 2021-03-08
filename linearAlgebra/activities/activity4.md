Actividad 4
====
#### Pedro Luis González Roa A01651517

1. **Determine la matriz de transformación de las siguientes transformaciones lineales de $\R^2$ en $\R^2$. Dibuje el cuadrado unitario, la semicircunferencia de radio $r=5$, el cardioide/corazón o el logo de Batman (sólo uno de ellos) y la forma final del mismo después de aplicarle la transformación. Puede usar el archivo de Matlab en Blackboard o hacerlo a mano y proporcionar un _screenshot_ de la figura que se genera.**
    1. **Una rotación de $\theta=\frac{\pi}{4}$ radianes en sentido horario, seguido de una reflexión sobre el eje $y$**.
    $$
    \begin{bmatrix}\cos(-\frac{\pi}{4}) & -\sin(-\frac{\pi}{4}) \\ \sin(-\frac{\pi}{4}) & \cos(-\frac{\pi}{4}) \end{bmatrix}
    \begin{bmatrix}-1 & 0 \\ 0 & 1 \end{bmatrix}
    $$
    ![figura 1][fig1]

    2. **Una rotación de $\theta = \frac{\pi}{4}$ radianes en sentido antihorario, seguido de una reflexión sobre la recta $y=x$.**
    $$
    \begin{bmatrix}\cos(\frac{\pi}{4}) & -\sin(\frac{\pi}{4}) \\ \sin(\frac{\pi}{4}) & \cos(\frac{\pi}{4}) \end{bmatrix}
    \begin{bmatrix}-1 & 0 \\ 0 & -1 \end{bmatrix}
    $$
    ![figura 2][fig2]

    3. **Una expansión en el eje $x$ en un factor de 2 unidades, seguido de un corte en el eje $y$ con $k=\frac{1}{3}$ y una reflexión sobre el origen.**

    $$
    \begin{bmatrix}2 & 0 \\ 0 & 1 \end{bmatrix}
    \begin{bmatrix}1 & 0 \\ \frac{1}{3} & 1 \end{bmatrix}
    \begin{bmatrix}-1 & 0 \\ 0 & -1 \end{bmatrix}
    $$
    ![figura 3][fig3]

    4. **Un corte sobre el eje $x$ con $k=-2$ seguido de una proyección sobre el eje $x$ y una reflexión sobre el eje $x$.**
    $$
    \begin{bmatrix}1 & -2 \\ 0 & 1 \end{bmatrix}
    \begin{bmatrix}1 & 0 \\ 0 & 0 \end{bmatrix}
    \begin{bmatrix}1 & 0 \\ 0 & -1 \end{bmatrix}
    $$
    ![figura 4][fig4]

2. **De manera análoga a lo que se hizo para un $\R^2$, defina matrices de transformación de $\R^3$ para los siguientes casos:**
    1. **Una rotación sólo en el eje $x$ de $\alpha$ radianes en sentido antihorario. (_Sugerencia_: considere que el eje $x$ está fijo y las componentes que cmabian son $y$ y $z$).**
    $$T({e_1}) = \begin{bmatrix}1 \\ 0 \\ 0\end{bmatrix}$$
    $$T({e_2}) = \begin{bmatrix}0 \\ 1 \\ 0\end{bmatrix}$$
    $$T({e_3}) = \begin{bmatrix}0 \\ 0 \\ 1\end{bmatrix}$$
    Como no cambiamos el eje x ponemos no cambiamos $T({e_1})$ ni tampoco la primera linea de cada uno. Pero sí rotamos los de acuerdo a los otros ejes como si fuera $\R^2$:
    $$\begin{bmatrix}1 & 0 & 0 \\ 0 & \cos(\alpha) & -\sin(\alpha) \\ 0 & \sin(\alpha) & \cos(\alpha)\end{bmatrix}$$

    2. **Una expansión sobre el eje $z$ de ${c_z}$ unidades.**

    Realizando algo parecido al ejercicio anterior, $x$ y $y$ no cambian. El único que se ve afectado es $z$: 
    $$\begin{bmatrix}1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & {c_z} \end{bmatrix}$$

    3. **Una proyección sobre el plano $xz$**  
    Es muy parecido al ejercicio anterior...
    $$\begin{bmatrix}0 & 0 & 0 \\ 0 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

3. **Use identidades trigonométricas para describir qué sucede geométricamente con los vectores de $\R^2$ cuando se multiplican por la matriz.**
$$\sin(2\theta)=2\sin(\theta)\cos(\theta)$$
$$\cos(2\theta)=\cos^2(\theta) - \sin^2(\theta)$$

$$A = \begin{bmatrix}\cos^2(\theta)-\sin²(\theta) & -2\sin(\theta)\cos(\theta) \\ 2\sin(\theta)\cos(\theta) & \cos^2(\theta)-\sin^2(\theta)\end{bmatrix} $$
$$A = \begin{bmatrix}\cos(2\theta) & -\sin(2\theta) \\ \sin(2\theta) & \cos(2\theta) \end{bmatrix}$$
Resulta que se hace una rotación de dos veces el ángulo $\theta$.


[fig1]: ../img/act4_1.jpg
[fig2]: ../img/act4_2.jpg
[fig3]: ../img/act4_3.jpg
[fig4]: ../img/act4_4.jpg
