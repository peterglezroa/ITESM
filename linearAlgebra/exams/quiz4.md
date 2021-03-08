Quiz 4
=====
#### Pedro Luis González Roa A01651517
**Considera $\alpha = 7$ y $\beta=-1$**

### 1. **Considera la transformación lineal definida por: $\R² \rightarrow \R³$**
$$
T\left(\begin{bmatrix}x\\y\end{bmatrix}\right) = \begin{bmatrix}x-\beta y \\ 3x-3y \\ -2\alpha + 12y\end{bmatrix}
$$
1. **Determina la matriz de la transformación lineal $A_T$. Usa el valor de $\alpha$ y $\beta$ correspondientes**.  
La matriz de la transformación lineal es:
$$
M(T)=
\begin{bmatrix}
1 & 1  \\
3 & 3  \\
-14 & 12 
\end{bmatrix}
$$

$$
\begin{bmatrix}
1 & 1 & | & a \\
3 & 3 & | &  b \\
-14 & 12 & | & c
\end{bmatrix}
-rref
\rightarrow
\begin{bmatrix}
1 & 0 & | & \frac{1}{26}(12a-c) \\
0 & 1 & | & \frac{1}{26}(14a+c) \\
0 & 0 & | & 0
\end{bmatrix}
$$
2. **Determina el Kernel de la transformación lineal y calcula la dimensión de dicho espacio vectorial.**
$$
\begin{bmatrix}
1 & 0 & | & 0 \\
0 & 1 & | & 0 \\
0 & 0 & | & 0
\end{bmatrix}
$$
$$kernel(t) = \vec{0}$$
3. **Determinal la imagen de la transformación lineal y calcula la dimensión de dicho espacio vectorial**
$$
\begin{bmatrix}
1 & 0 & | & \frac{1}{26}(12a-c) \\
0 & 1 & | & \frac{1}{26}(14a+c) \\
0 & 0 & | & 0
\end{bmatrix}
$$
$$im(T) = \R^3$$
**No hay restricciones**  
4. **Determina si la transformación lineal es invertible o no**  
La transformación lineal sí es invertible porque: $\R^3$ es una dimensión mayor que $\R^2$.


### 2.
Estoy perdido :c
