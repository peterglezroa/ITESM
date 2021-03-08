Tercer Examen Rápido
====
#### Pedro Luis González Roa A01651517

1. **Considere que una matriz $A$ de 2x2 se puede escribir de la siguiente forma:**
    $$
    A =
    \begin{bmatrix}1 & 0\\\frac{7}{5}+1 & 1\end{bmatrix}
    \begin{bmatrix}1 & 0\\0 & -1\end{bmatrix}
    \begin{bmatrix}14 & 0\\0 & 1\end{bmatrix}
    \begin{bmatrix}1 & 0\\0 & 2\left(\frac{7}{3}+1\right)\end{bmatrix}
    $$
    1. **Determine $T\left(\begin{bmatrix}x\\y\end{bmatrix}\right)$ como una función vectorial usando los valores de $\alpha$ y $\beta$ que correspondan a sus datos.**
    $$\begin{bmatrix}1 & 0\\\frac{7}{5}+1 & 1\end{bmatrix} \begin{bmatrix}1 & 0\\0 & -1\end{bmatrix} \begin{bmatrix}14 & 0\\0 & 1\end{bmatrix} \begin{bmatrix}1 & 0\\0 & 2\left(\frac{7}{3}+1\right)\end{bmatrix} \begin{bmatrix}x\\y\end{bmatrix} = \begin{bmatrix}14x\\\frac{168x}{5}-\frac{20y}{3}\end{bmatrix}$$
    $$T\left(\begin{bmatrix}x\\y\end{bmatrix}\right) =  \begin{bmatrix}14x\\\frac{168x}{5}-\frac{20y}{3}\end{bmatrix}= \begin{bmatrix}14 & 0\\ \frac{168}{5} & \frac{-20}{3}\end{bmatrix}$$
    2. **Determine qué efecto tiene el multiplicar la matriz $A$ por un vector de $\R^2$. _Sugerencia:_ identifique cada matriz del producto como una matriz de transformación conocida y describa el efecto que se tiene y en qué orde se efectúa.**  
    $$ \begin{bmatrix}1 & 0 \\ 0 & 2\left(\frac{7}{3}+1\right)\end{bmatrix}$$
    Primero se le hace una expansión al vector en el eje $y$ de $\frac{17}{3}$

    $$ \begin{bmatrix}14 & 0 \\ 0 & 1\end{bmatrix}$$
    Después se le vuelve a hacer una expansión pero ahora en el eje $x$ de $14$
    
    $$ \begin{bmatrix}1 & 0 \\ 0 & -1\end{bmatrix}$$
    Después se le hace una reflexión en el eje $x$

    $$ \begin{bmatrix}1 & 0 \\\frac{7}{5} + 1 & 1\end{bmatrix}$$ 
    Finalmente se realiza un corte en el eje $y$ de $\frac{7}{5}+1$


    3. **Determine $T\left(\begin{bmatrix}x\\y\end{bmatrix}\right)$, donde $\gamma$ y $\delta$ son el antepenúltimo y penúltimo dígito de su matrícula.**
    $$\gamma = 5, \delta = 1$$
    $$T\left(\begin{bmatrix}x\\y\end{bmatrix}\right) = \begin{bmatrix}14x\\\frac{168x}{5}-\frac{20y}{3}\end{bmatrix} = \begin{bmatrix}70 \\161.33 \end{bmatrix}$$
    
    3. **Encuentre un vector $\begin{bmatrix}x\\y\end{bmatrix}$ tal que transformalo mediante A, se obtiene el vector $\begin{bmatrix}2\\3\end{bmatrix}$. En caso de no poder obtenerlo, mencione por qué**

    No se puede obtener porque la matriz $T\left(\begin{bmatrix}x\\y\end{bmatrix}\right) = \begin{bmatrix}14x\\\frac{168x}{5}-\frac{20y}{3}\end{bmatrix}$ NO es invertible
