Actividad 6
====
### Pedro Luis González Roa A01651517
1. **Se han acumulado datos acerca de las estaturas de niños en relación con sus padres. Suponga que las probabilidades de que un padre alto tenga un hijo alto, de mediana estatura o bajo son 0.7, 0.2 y 0.1, respectivamente; las probabilidades de que un padre de talla media tenga un hijo alto, de estatura media o bajo son 0.2, 0.6 y 0.2, respectivamente; y las probabilidades de que un padre bajo tenga un hijo alto mediano, o bajo son 0.2 0.4 y 0.4, respectivamente**
    1. **Escriba la matriz de transición para esta cadena de Markov**
    $$
    \begin{bmatrix}
    0.7 & 0.2 & 0.2 \\
    0.2 & 0.6 & 0.4 \\
    0.1 & 0.2 & 0.4
    \end{bmatrix}
    $$
    
    2. **¿Cuál es la probabilidad de que una persona baja tenga un nieto alto?**
    $$
    \begin{bmatrix}
    0.7 & 0.2 & 0.2 \\
    0.2 & 0.6 & 0.4 \\
    0.1 & 0.2 & 0.4
    \end{bmatrix}
    \begin{bmatrix}
    0.7 & 0.2 & 0.2 \\
    0.2 & 0.6 & 0.4 \\
    0.1 & 0.2 & 0.4
    \end{bmatrix}
    =
    \begin{bmatrix}
    0.55 & 0.30 & 0.30 \\
    0.30 & 0.48 & 0.44 \\
    0.15 & 0.22 & 0.26
    \end{bmatrix}
    $$
    La posibilidad de que una persona baja tenga un nieto alto es de 0.30.
    
    3. **Si 10% de la población actual es alta, 60% es de estatura media y 30% es de estatura baja ¿Cuál será la distribución en tres generaciones?**
    $$
    \begin{bmatrix}
    0.7 & 0.2 & 0.2 \\
    0.2 & 0.6 & 0.4 \\
    0.1 & 0.2 & 0.4
    \end{bmatrix} ^3
    \begin{bmatrix}
    0.1\\
    0.6\\
    0.3 
    \end{bmatrix}
    =
    \begin{bmatrix}
    0.3625\\
    0.4250\\
    0.2125 
    \end{bmatrix}
    $$
    La población tendría una distribución de 0.3625 altos, 0.4250 medianos, 0.2125 bajos.    

    4. **A largo plazo, ¿qué proporción de la población será alta, de estatura mediana y baja?**
    $$ P-I = \begin{bmatrix}-0.3 & 0.2 & 0.2 \\ 0.2 & -0.4 & 0.4 \\ 0.1 & 0.2 & -0.6\end{bmatrix} $$ 
    $$
    \begin{bmatrix}-0.3 & 0.2 & 0.2 & | & 0\\ 0.2 & -0.4 & 0.4 & | & 0\\ 0.1 & 0.2 & -0.6 & | & 0\end{bmatrix}
    -rref\rightarrow
    \begin{bmatrix}1 & 0 & -2 & | & 0\\ 0 & 1 & -2 & | & 0\\ 0 & 0 & 0 & | & 0\end{bmatrix} 
    $$
    $$x=2z$$
    $$y=2z$$
    $$ Ker(P-I) = Gen\left\{\begin{bmatrix}2\\2\\1\end{bmatrix}\right\} $$

    $$x = \begin{bmatrix}2/5 \\ 2/5 \\ 1/5 \end{bmatrix}$$
    Por lo que la distribución a largo plazo sería de 2/5 para altos, 2/5 para medianos y 1/5 para bajos.

2. **Una Universidad de Nuevo León tiene un esquema de clasificación de profesores de acuerdo a su producción en docencia, en investigación y en consultoría. Las tres clasificaciones son: _Asistente_, _Asociado_ y _Titular_. Cada cierto periodo, se evalúan sus productos y cada empleado puede cambiar de categoría de acuerdo a la evaluación. Un estudio recolectó la siguiente información: un profesor que está en la categoría _Titular_ cambia, con probabilidad 0.7, 0.2 y 0.1 a la categoría _Titular_, _Asociado_ y _Asistente_, respectivamente. Un profesor que está en la categoría _Asociado_ cambia, con probabilidad 0.2, 0.6 y 0.2 a la categoría _Titular_, _Asociado_ y _Asistente_, respectivamente; mientras que un profesor que está en categoría _Asistente_ cambia, con probabilidad 0.1, 0.4 y 0.5 a la categoría _Titular_, _Asociado_ y _Asistente_, respectivamente.**
    1. **Escriba la matriz de transición para esta cadena de Markov.**
    $$
    \begin{bmatrix}0.7 & 0.2 & 0.1 \\ 0.2 & 0.6 & 0.4 \\ 0.1 & 0.2 & 0.5\end{bmatrix}
    $$
    2. **A largo plazo, ¿Qué porcentaje de profesores estará en cada categoría?**
    $$
    P-I=
    \begin{bmatrix}-0.3 & 0.2 & 0.1 & | & 0 \\ 0.2 & -0.4 & 0.4 & | & 0 \\ 0.1 & 0.2 & -0.5 & | & 0\end{bmatrix}
    -rref\rightarrow
    \begin{bmatrix}1 & 0 & -1.5 & | & 0\\ 0 & 1 & -1.75 & | & 0\\ 0 & 0 & 0 & | & 0\end{bmatrix}
    $$
    $$x=1.5z$$
    $$y=1.75$$
    $$Ker(P-I)=Gen\left\{\begin{bmatrix}1.5\\1.75\\1\end{bmatrix}\right\}$$
    $$x=\begin{bmatrix}1.5/4.25\\1.75/4.25\\1/4.25\end{bmatrix}$$
    La distribución termina siendo $\frac{1.5}{4.25}$ para Titular, $\frac{1.75}{4.25}$ para Asociado y $\frac{1}{4.25}$ para Asistente.
