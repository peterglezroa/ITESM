Examen parcial 2
====
### Pedro Luis González Roa A01651517

$$ \alpha=7 \\ \beta=-1 $$

1. **Considera $W$ el subespacio de $D$ que tiene base $B=e^{8x},e^{8x}cos(x),e^{8x}sen(x)$. Sea $T:W\rightarrow W$ definida por $T[f(x)]=f^I(x)$ una transformación lineal de $W$ en $W$**
    1. **Determina la matriz de la transformación lineal $T_D$**
    $$ A = \begin{bmatrix}T({e_1}) & | & T({e_2}) & | & T({e_3})\end{bmatrix} $$
    $$T({e_1}) = {D_x}(e^{8x}) = 8e^{8x}$$
    $$T({e_2}) = {D_x}(e^{8x}cos(x)) = e^{8x}(8cos(x)-sen(x))$$
    $$T({e_2}) = {D_x}(e^{8x}cos(x)) = e^{8x}(8sen(x)+cos(x))$$
    $$A=
    \begin{bmatrix}
    8 & 0 & 0\\
    0 & 8 & -1\\
    0 & 1 & 8
    \end{bmatrix}
    $$
    
    2. **Usando el resultado anterior, integra 3 veces la función**
    $$f(x)=200e^{8x} + 25e^{8x}sen(x)-120e^{8x}cos(x)$$
    $$A^{-1}=
    \begin{bmatrix}
    \frac{65}{520} & 0 & 0\\
    0 & \frac{64}{520} & \frac{8}{520}\\
    0 & -\frac{8}{520} & \frac{64}{520}
    \end{bmatrix}
    $$
    $$
    \begin{bmatrix}
    \frac{65}{520} & 0 & 0\\
    0 & \frac{64}{520} & \frac{8}{520}\\
    0 & -\frac{8}{520} & \frac{64}{520}
    \end{bmatrix}^3
    \begin{bmatrix}200\\-120\\25\end{bmatrix} = 
    \begin{bmatrix}\frac{25}{64}\\-\frac{128873633}{66015625}\\\frac{8593144}{34328125}\end{bmatrix}
    $$
    
    3. **Los profesores de Matemáticas II, que enseñan integrales, a veces suelen evaluar incorrectamente resultados que no tienen la constante de integración. ¿Por qué crees que esta metodología _no toma en cuenta_ esto y no regresa el valor de la constante de integración?**  
    Porque 

2. **Considere la transformación lineal de $\R^2 \rightarrow \R^2$ que corresponde a efectuar, en el siguiente orden, las siguientes transformaciones:**
* **Una contracción en el eje $x$ en un factor de $\frac{1}{8}$**
* **Una reflexión sobre la recta $y=x$**
* **Un corte sobre el eje $y$ con $k=-2$**
* **Una rotación en sentido antihorario de $\theta = \frac{3}{4}\pi$ radianes**

    1. **Determine la matriz $A$ que representa esta transformación lineal**
    $$B=\begin{bmatrix}-\frac{1}{8} & 0 \\ 0 & 1\end{bmatrix}$$
    $$C=\begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}$$
    $$D=\begin{bmatrix}1 & 0 \\ -2 & 1\end{bmatrix}$$
    $$E=\begin{bmatrix}cos(\frac{3}{4}\pi) & -sen(\frac{3}{4}\pi) \\ sen(\frac{3}{4}\pi) & cos(\frac{3}{4}\pi)\end{bmatrix}$$
    $$
    \begin{bmatrix}-\frac{1}{8} & 0 \\ 0 & 1\end{bmatrix}
    \begin{bmatrix}x\\y\end{bmatrix}
    =\begin{bmatrix}-\frac{x}{8} \\ y\end{bmatrix}
    $$
    $$
    \begin{bmatrix}0 & 1 \\ 1 & 0\end{bmatrix}
    \begin{bmatrix}-\frac{x}{8} \\ y\end{bmatrix}
    =\begin{bmatrix}y \\ -\frac{x}{8}\end{bmatrix}
    $$
    $$
    \begin{bmatrix}1 & 0 \\ -2 & 1\end{bmatrix}
    \begin{bmatrix}y \\ -\frac{x}{8}\end{bmatrix}
    =\begin{bmatrix}y \\ -\frac{x}{8} - 2y\end{bmatrix}
    $$
    $$
    \begin{bmatrix}cos(\frac{3}{4}\pi) & -sen(\frac{3}{4}\pi) \\ sen(\frac{3}{4}\pi) & cos(\frac{3}{4}\pi)\end{bmatrix}
    \begin{bmatrix}y \\ -\frac{x}{8} - 2y\end{bmatrix}
    =\begin{bmatrix}\frac{\sqrt{2}x}{16} - \frac{\sqrt{2}y}{2} \\ \frac{\sqrt{2}x}{16} + \frac{\sqrt{2}y}{2}\end{bmatrix}
    $$
    $$A=\begin{bmatrix}\frac{2^{\frac{1}{2}}x}{16} - \frac{2^{\frac{1}{2}}y}{2} \\ \frac{2^{\frac{1}{2}}x}{16} + \frac{2^{\frac{1}{2}}y}{2}\end{bmatrix}$$
  
    2. **Determine la imagen del vector $\begin{bmatrix}7\\-1\end{bmatrix}$ bajo esta transformación**
    $$
    \begin{bmatrix}\frac{2^{\frac{1}{2}}7}{16} - \frac{2^{\frac{1}{2}}-1}{2} \\ \frac{2^{\frac{1}{2}}7}{16} + \frac{2^{\frac{1}{2}}-1}{2}\end{bmatrix}=
    \begin{bmatrix}\frac{15}{8\sqrt{2}}\\ -\frac{1}{8\sqrt{2}}\end{bmatrix}
    $$

3. **La empresa _Hertz_ tiene algunas sucursales en Detroit. Después de un estudio por el administrador de la empresa, se encontró el patrón de renta y devolución de los automoviles, en tres puntos que son Aeropuerto en la ciudad (AC), Centro (C) y Aeropuerto fuera de la ciudad (AF). Dichos patrones, descritos en proporciones son:**
* **Si se renta un carro en AC se tiene que 0.85 de ellos se entrega en AC, 0.10 de ellos en C, y 0.05 en AF**
* **Si se renta un carro en C se tiene que 0.07 de ellos se entrega en AC, 0.92 de ellos en C, y 0.01 en AF**
* **Si se renta un carro en AF se tiene que 0.20 de ellos se entrega en AC, 0.70 de ellos en C, y 0.10 en AF**

    1. **La matriz de transición que modela la dinámica de esta empresa en Detroit.**
    $$T=
    \begin{bmatrix}
    .85 & .07 & .20\\
    .10 & .92 & .70\\
    .05 & .01 & .10
    \end{bmatrix}
    $$
    
    2. **Si se cuenta con una flota de 2,000 automoviles. ¿Cuántos estarán rentados o listos para rentarse en la sucursal ubicada en el centro de la ciudad?**
    $$Ker(T-I) =
    \begin{bmatrix}
    -0.15 & .07 & .20\\
    .10 & -0.08 & .70\\
    .05 & .01 & -.90
    \end{bmatrix}
    -rref\rightarrow
    \begin{bmatrix}
    1 & 0 & -13\\
    0 & 1 & -25\\
    0 & 0 & 0
    \end{bmatrix}
    $$
    $$Ker(T-I)= Gen{\begin{bmatrix}13 \\ 25 \\ 1\end{bmatrix}}$$
    $$\begin{bmatrix}\frac{13}{29} \\ \frac{25}{39} \\  \frac{1}{39}\end{bmatrix}$$
    1283 automoviles en la surcusal C.

4. **En el caso de que la transformación del problema 2 sea invertible, determine la matriz de transformación inversa, y describa geométricamente qué efecto tiene (y en que órden), multiplicar esta matriz de transformación inversa por un vector de $\R^2$**
