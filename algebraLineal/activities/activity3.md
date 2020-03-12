Activity 3
===
1. Sean ${v_1}=\begin{bmatrix}1\\2\end{bmatrix}$ y ${v_2}=\begin{bmatrix}-3\\-6\end{bmatrix}$ en $\R²$
    1. Determine $Gen\left\{{v_1}{v_2}\right\}$. ¿Es $\left\{{v_1},{v_2}\right\}$ es un conjunto generador de $\R^2$?
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
**No genera $\R^2$ al menos que $2x-y=0$**

    2. Determine si $\left\{{v_1},{v_2}\right\}$ es un conjunto LI o LD. Si es un conjunto LD, exhiba una combinación lineal de ellos que genere 0, donde no todos los coeficientes son cero.
2. Sean ${v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$,${v_2}=\begin{bmatrix}0\\1\\4\end{bmatrix}$, ${v_3}=\begin{bmatrix}5\\6\\3\end{bmatrix}$ y ${v_4}=\begin{bmatrix}7\\2\\-1\end{bmatrix}$ en $\R^3$.
    1. Determine $Gen\left\{{v_1},{v_2},{v_3},{v_4}\right\}$. ¿Es $\left\{{v_1},{v_2},{v_3},{v_4}\right\}$ un conjunto generador de $\R^3$?
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
**Como el SEL siempre es consistente entonces el espacio generado $Gen\left\{{v_1},{v_2},{v_3},{v_4}\right\}=\R^3$**

    2. Determine si $\left\{{v_1},{v_2},{v_3},{v_4}\right\}$ es un conjunto LI o LD. Si es un conjunto LD, exhiba una combinación lineal de ellos que genere 0, donde no todos los coeficientes son cero.
3. Sean ${v_1}=\begin{bmatrix}2\\-1\\4\end{bmatrix}$, ${v_2}=\begin{bmatrix}3\\6\\2\end{bmatrix}$ y ${v_1}=\begin{bmatrix}2\\10\\-4\end{bmatrix}$ en $\R^3$.
    1. Determine $Gen\left\{{v_1},{v_2},{v_3}\right\}$. ¿Es $\left\{{v_1},{v_2},{v_3}\right\}$ un conjunto generado de $\R^3$?
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
**Como el SEL siempre es consistente entonces el espacio generado $Gen\left\{{v_1},{v_2},{v_3}\right\}=\R^3$**

    2. Determine
4. Sean ${v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$, ${v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$ y ${v_1}=\begin{bmatrix}1\\3\\3\end{bmatrix}$ en $\R^4$.
    1. Determine $Gen\left\{{v_1},{v_2},{v_3}\right\}$. ¿Es $\left\{{v_1},{v_2},{v_3}\right\}$ un conjunto generado de $\R^4$?
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


    2. Determine

5. Escriba cada uno de los vectores como combinaciones lineales de los vectores $u=\begin{bmatrix}2\\1\\4\end{bmatrix}$, $v=\begin{bmatrix}1\\-1\\3\end{bmatrix}$ y $u=\begin{bmatrix}3\\2\\5\end{bmatrix}$
    1. $\begin{bmatrix}-9\\-7\\-15\end{bmatrix}$
    2. $\begin{bmatrix}6\\11\\6\end{bmatrix}$
    3. $\begin{bmatrix}0\\0\\0\end{bmatrix}$
    4. $\begin{bmatrix}7\\8\\9\end{bmatrix}$
