# INTRO
### Problemas ejemplo
#### Problema 1
*. CF = 0.3(Parcial1 + Parcial2) + 0.25ED + 0.15EO
Donde:
...*. P1 = 0.3(ER1) + 0.2(AP1) + 0.50(EP1)
...*. P2 = 0.3(ER2) + 0.2(AP2) + 0.50(EP2)

#### Problema 2
Considera que para crecer cierto cultivo se recomienda que cada metro cuadrado de tierra sea tratado con 10 unidades de fósforo, 9 unidades de potasio, y 19 unidades de nitrógeno. En el mercado existen 3 diferentes marcas de fertilizantes (A,B,C). Un kilo de la marca A contiene 2 unidades de fósforo, 3 de potasio, y 5 de nitrógeno; un kilo de la marca B contiene 1 unidad de fósforo, 3 de potasio y 4 nitrógeno; un kilo de la marca C contiene 1 unidad de fósforo y una de nitrógeno.
¿Será posible con la recomendación usando alguna combinación de fertilizantes? En caso de que sea posible, ¿esta forma es única o se pueden más de una forma? ¿Cuántas?
*. A = x
*. B = y
*. C = z
Por lo tanto:
1. 2x + y + z = 10 (Ecuación para el fósforo)
2. 3x + 3y = 9 (Ecuación para el potasio)
3. 5x + 4y + z = 19 (Ecuación para el nitrógeno)

$$\begin{bmatrix}
2 & 1 & 1 & | & 10 \\
3 & 3 & 0 & | & 9 \\
5 & 4 & 1 & | & 19
\end{bmatrix}$$

$$\begin{bmatrix}
1 & 0 & 1 & | & 7 \\
0 & 1 & -1 & | & -4 \\
0 & 0 & 0 & | & 0
\end{bmatrix}$$

**Conclusión: Tiene infinitas soluciones porque 0 = 0**
$$ x= 7 - z $$
$$ y = -4 + z $$
$$ z = z $$
$$ z \in I\!R $$
#### Problema 4
Determinar un polinomio de interpolación para una función o conjunto de datos.  
Contexto: En Estadística la función de densidad de distribución de una variable aleatoria normal, por lo que es necesario calcular probabilidades, las cuales están relacionadas con áreas bajo la curva, las cuales son integrales, por ejemplo:
$$ {F_{x}} = {e^\frac{x²}{2}}  $$
Por lo que si tenemos:
$$ 2x + 3y + 9z =  4 $$
$$ - 3x - 3y - 18z = -4 $$
$$ x + 2y + 3z = 1 $$
Que eso se convierte en la siguiente matriz
$$ \begin{bmatrix}
2 & 3 & 9 & | & 4 \\
-3 & -3 & -18 & | & -4 \\
1 & 2 & 3 & | & 1
\end{bmatrix} $$

R1 <-> R3

$$ \begin{bmatrix}
1 & 2 & 3 & | & 1 \\
-3 & -3 & -18 & | & -4 \\
2 & 3 & 9 & | & 4
\end{bmatrix} $$

R2 <-> 3R1 + R2

$$\begin{bmatrix}
1 & 2  & 3 & | & 1 \\
0 & 3 & -9 & | & -1 \\
0 & -1 & 3 & | & 2
\end{bmatrix}$$

R3 <-> 3R3
$$\begin{bmatrix}
1 & 2 & 3 & | & 1 \\
0 & 3 & -9 & | & -1 \\
0 & -3 & 9 & | & 6 \\
\end{bmatrix}$$

R3 <- R2 + R3
$$\begin{bmatrix}
1 & 2 & 3 & | & 1 \\
0 & 3 & -9 & | & -1 \\
0 & 0 & 0 & | & 5
\end{bmatrix}$$

**Conclusión: podemos ver que es un sistema inconsistente porque la última equación es imposible**

#### Problema 5
**1. 2x + y + 3z = 2**  
**2. -6x -6y -6z = -4**  
**3. 4x +11y -3z = -2**
$$\begin{bmatrix}
2 & 1 & 3 & | & 2 \\
-6 & -6 & -6 & | & -4 \\
4 & 11 & -3 & | & -2 
\end{bmatrix}$$

R2 <- 3R1 + R2
R3 <- -2R + R3
$$\begin{bmatrix}
2 & 1 & 3 & | & 2 \\
0 & -3 & 3 & | & 2 \\
0 & 9 & -9 & | & -6
\end{bmatrix}$$

R3 <- R3 + 3R1
$$\begin{bmatrix}
2 & 1 & 3 & | & 2 \\
0 & -3 & 3 & | & 2 \\
0 & 0 & 0 & | & 0
\end{bmatrix}$$
**Conclusión: Tiene infinitas soluciones ya que la última ecuación es 0 = 0**

#### Problema 6
**7x -5y = 3**  
Tiene infinitas soluciones, dadas por:
$$ \left\lbrace (x,y) | y=\frac{7x - 3}{5} \right\rbrace$$  
**3x1 - 5x2 + 4x3 = 7**  
Tiene infinitas soluciones, dadas por:
$$ \left\lbrace ({x_1},{x_2}, {x_3}) | {x_3}=\frac{7-3{x_1}+5{x_2}}{4} \right\rbrace$$
