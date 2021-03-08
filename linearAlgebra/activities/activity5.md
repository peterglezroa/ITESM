Actividad 5
=======
1. **Determine la forma matricial de las siguientes transformaciones lineales. Determine e indique claramente $Ker(T)$ e $Im(T)$. Luego diga si la transformación es uno a uno y si esinvertible. Finalmente, enliste 2 vectores diferentes (si es posible) que estén en $Ker(T)$ y 2 vectores diferentes que estén en $Im(T)$**
    1. $T\left(\begin{bmatrix}x \\ y\end{bmatrix}\right) = \begin{bmatrix}2x-y \\ -8x+4y \\ x+y \\ x-y\end{bmatrix}$
    $$
    T\left(\begin{bmatrix}x \\ y\end{bmatrix}\right) = 
    \begin{bmatrix}
    2 & -1 \\
    -8 & 4 \\
    1 & 1 \\
    1 & -1 
    \end{bmatrix}
    $$
    $$
    \begin{bmatrix}
    2 & -1 & | & x\\
    -8 & 4 & | & y\\
    1 & 1  & | & z\\
    1 & -1 & | & a
    \end{bmatrix}
    -rref\rightarrow
    \begin{bmatrix}
    1 & 0  & | & \frac{x+z}{3}\\
    0 & 1 & | & \frac{-1+2z}{3}\\
    0 & 0 & | & 0 \\
    0 & 0 & | & 0 
    \end{bmatrix}
    $$
    Para obtener el kernel:
    $$
    Ker(T) = 
    \begin{bmatrix}
    1 & 0  & | & 0\\
    0 & 1 & | & 0\\
    0 & 0 & | & 0 \\
    0 & 0 & | & 0 
    \end{bmatrix}
    $$
    Cómo la solución es única para SEL. Entonces el $Ker(T)$ es el $\vec{0}$

    $$
    Im(T) =
    \begin{bmatrix}
    1 & 0  & | & \frac{x+z}{3}\\
    0 & 1 & | & \frac{-1+2z}{3}\\
    0 & 0 & | & 0 \\
    0 & 0 & | & 0 
    \end{bmatrix}
    $$
    Cómo tiene infinitas soluciones entonces $Im(T)=\R^2$

    2. $T\left(\begin{bmatrix}x \\ y\end{bmatrix}\right) = \begin{bmatrix}x+y+z+w \\ 3x-6y+2z-w \\ w\end{bmatrix}$
    $$
    T\left(\begin{bmatrix}x \\ y\end{bmatrix}\right) = 
    \begin{bmatrix}
    1 & 1 & 1 & 1 \\
    3 & -6 & 2 & -1\\
    0 & 0 & 0 & 1 
    \end{bmatrix}
    $$
    $$
    \begin{bmatrix}
    1 & 1 & 1 & 1 & | & x\\
    3 & -6 & 2 & -1 & | & y\\
    0 & 0 & 0 & 1 & | & z
    \end{bmatrix}
    -rref\rightarrow
    \begin{bmatrix}
    1 & 0 & \frac{8}{9} & 0 & | & \frac{6x+y-5z}{9}\\
    0 & 1 & \frac{1}{9} & 0 & | & \frac{3x-y-4z}{9}\\
    0 & 0 & 0 & 1 & | & z
    \end{bmatrix}
    $$
    $$
    Ker(T)=
    \begin{bmatrix}
    1 & 0 & \frac{8}{9} & 0 & | & 0\\
    0 & 1 & \frac{1}{9} & 0 & | & 0\\
    0 & 0 & 0 & 1 & | & 0
    \end{bmatrix}
    $$
    Como la solución es única para SEL. Entonces el $Ker(T)$ es el $\vec{0}$
    $$
    Im(T) = 
    \begin{bmatrix}
    1 & 0 & \frac{8}{9} & 0 & | & \frac{6x+y-5z}{9}\\
    0 & 1 & \frac{1}{9} & 0 & | & \frac{3x-y-4z}{9}\\
    0 & 0 & 0 & 1 & | & z
    \end{bmatrix}
    $$
    Como el SEL tiene infinitas soluciones. Entonces $Im(T)=\R^2$

2. Considere $W = gen\left\{e^{-2x}, e^{-2xsen(x)}, e^{-2xcos(x)}cos(x)\right\}$ como un subespacio de $D$, las funciones derivables. Considere que el conjunto $\left\{e^{-2x}, e^{-2x}cos(x), e^{-2x}sin(x)\right\}$ es una base para W. Determine:
    1. La matriz de transformación con respecto  a la base indicada.
    $$ A = \begin{bmatrix}T({e_1}) & | &  T({e_2}) & | & T({e_3})\end{bmatrix} $$
    $$T({e_1}) = {D_x}(e^{-2x})= -2e^{-2x}$$
    $$T({e_2}) = {D_x}(e^{-2x}cos(x))= -2e^{-2x}(sin(x)+2cos(x))$$
    $$T({e_3}) = {D_x}(e^{-2x}sin(x)) = e^{-2x}(cos(x)-2sin(x))$$

    $$A =
    \begin{bmatrix}
    -2 & 0 & 0 \\
    0 & -4 & -2 \\
    0 & 1 & -2
    \end{bmatrix}
    $$

    2. Calcule la derivada de la función $y=3e^{-2x}-e^{-2x}cos(x)+2e^{-2x}sen(x)$ usando dicha matriz. Verifique el resultado.
    $${D_x}(y)=
    \begin{bmatrix}
    -2 & 0 & 0 \\
    0 & -4 & -2 \\
    0 & 1 & -2
    \end{bmatrix}
    \begin{bmatrix}3 \\ -1 \\ 2\end{bmatrix}=
    \begin{bmatrix}-6 \\ 0 \\ -5\end{bmatrix}
    $$
    La derivada es $-6e^{-2x}-5e^{-2x}sen(x)$

    3. ¿Será que puede usar esta matriz para calcular $y^{(5)}$, la quinta derivada ¿Cómo lo haría?  
    Elevando la matriz a la quinta potencia.
