Dependencia e Independencia lineal
===
### Preámbulo
$${\vec{A}_{mxn}}{x_{nx1}}={b_{mx1}}$$

**Donde:**
1. \vec{A} -> es la matriz de coeficientes
2. x -> vector de incógnitas
3. b -> vector del lado derecho

Supongamos que $\vec{x_0} y \vec{x_1}$ son soluciones del SEL:
$$\vec{A}\vec{x_0}=b\\
\vec{A}\vec{x_1}=b\\
\vec{A}\vec{x_0} - \vec{A}\vec{x_1}=b-b=0\\
\vec{A}\left(\vec{x_0},\vec{x_1}\right)=0$$

$\vec{A}\left(\vec{x_0},\vec{x_1}\right)=0$ es un SEL homogéneo, por lo tanto, es consistente.

$\vec{A}\left(\vec{x_1}-\vec{x_0}\right) = 0$ tiene solución única => la solución es $\vec{x_1}-\vec{x_0}=0$ => $\vec{x_1} = \vec{x_0}$

<center style="font-size:0.9rem;font-weight:bold">Observación: Si el SEL homogéneo asociado tiene solución única => el SEL no homogéneo, también</center>

Si tiene infinitas soluciones hay otra solución diferente a la trivial del SEL homogéneo.
$$\vec{A}\vec{y} = 0\\
\vec{X_h} != 0\\
\vec{A}\vec{X_h} = 0, \vec{X_h} != \vec{0}$$

### Dependencia lineal
$\left\{{v_1},..,{v_k}\right\}$ es _linealmente independiente (LI)_ si $0={c_1}{v_1}+...+{c_k}{v_k}$ implica que ${c_1}={c_2}=...={c_k}=0$ (si el SEL ${c_1}{v_1}+..+{c_k}{v_k}=0$ tiene solución única)

#### Ejemplo
Si tenemos los vectores $\begin{bmatrix}4\\-3\\7\end{bmatrix}$, $\begin{bmatrix}2\\-5\\8\end{bmatrix}$, $\begin{bmatrix}4\\-8\\7\end{bmatrix}$:
$$
\begin{bmatrix}
4 & 2 & 4 & | & 0\\
-3 & -5 & -8 & | & 0 \\
7 & 8 & 7 & | & 0
\end{bmatrix}
-rref->
\begin{bmatrix}
1 & 0 & 0 & | & 0\\
0 & 1 & 0 & | & 0 \\
0 & 0 & 1 & | & 0
\end{bmatrix}
$$

### Independencia lineal
Al hacer el _rref_ si hay una variable libre.
(Básicamente cuando no puedes llegar un vector con el otro(s) vectores. \vec{i} es independiente de $\vec{j}$ pero $\vec{i+j}$ no lo es

<center>Talvez los términos están al revéz</center>

#### Ejemplo
${v_1}=\begin{bmatrix}-2\\3\\7\end{bmatrix}$,${v_2}=\begin{bmatrix}4\\-1\\5\end{bmatrix}$, ${v_3}=\begin{bmatrix}3\\1\\3\end{bmatrix}$, ${v_4}=\begin{bmatrix}5\\0\\2\end{bmatrix}$
$$
\begin{bmatrix}
-2 & 4 & 3 & 5 & | & 0 \\
3 & -1 & 1 & 0 & | & 0 \\
7 & 5 & 3 & 2 & | & 0
\end{bmatrix}
-rref->
\begin{bmatrix}
1 & 0 & 0 & \frac{-13}{37} & | & 0 \\
0 & 1 & 0 & \frac{6}{37} & | & 0 \\
0 & 0 & 1 & \frac{45}{37} & | & 0
\end{bmatrix}
$$
$${c_1}=\frac{13}{37}{c_4}\\$$
$${c_2}=\frac{-6}{37}{c_4}\\$$
$${c_3}=\frac{-45}{37}{c_4}\\$$
$${c_4}={c_4}\\$$

