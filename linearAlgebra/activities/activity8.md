Actividad 8
====
### Pedro Luis González Roa A01651517

1. **Considere la sucesión de Lucas (_Lucas sequence_), definida por:**
    $${L_n} = {L_{n-1}} + {L_{n-2}}$$
    $${L_0} = 2, {L_1} = 1$$

    Determine:  
    1. **Los primeros 5 términos de la sucesión.**
    $$L_1=1$$
    $$L_2=1$$
    $$L_3=2$$
    $$L_4=3$$
    $$L_5=5$$
    2. **La matriz que representa la recursión.**
    $$
    \begin{bmatrix}
    f_n \\
    f_{n-1}
    \end{bmatrix}
    =
    \begin{bmatrix}
    1 & 1 \\
    1 & 0
    \end{bmatrix}
    \begin{bmatrix}
    f_{n-1} \\
    f_{n-2}
    \end{bmatrix}
    $$
    3. **Los eigenvalores de la matriz del inciso anterior.**
    $$\lambda_1 = \frac{\sqrt{5}+1}{2}$$
    $$\lambda_2 = \frac{-\sqrt{5}+1}{2}$$
    4. **La solución de la relación de recurrencia.**
    $$n = 0: f_0 = 2 = c_1(1) + c_2(1)$$
    $$n = 1: f_1 = 1 =c_1(\frac{\sqrt{5}+1}{2}) + c_2(\frac{-\sqrt{5}+1}{2})$$
    $$c_1=1,c_2=1$$
    $$f_n=\left(\frac{1+\sqrt{5}}{2}\right)^n - \left(\frac{1-\sqrt{5}}{2}\right)^n$$

2. **Considere la sucesión de números de Pell, definida por:**
    $$x_n=2x_{n-1} + x_{n-2}$$
    $$x_0 =0, x_1 = 1$$
    Determine
    1. **Los primeros 5 términos de la sucesión.**
    $$x_0 = 0$$
    $$x_1 = 1$$
    $$x_2 = 2$$
    $$x_3 = 5$$
    $$x_4 = 12$$
    $$x_5 = 29$$
    2. **La matriz que representa la recursión.**
    $$  
    \begin{bmatrix}
    f_{n}\\
    f_{n-1} 
    \end{bmatrix}
    =
    \begin{bmatrix}
    2 && 1\\
    1 && 0
    \end{bmatrix} 
    \begin{bmatrix}
    f_{n-1}\\
    f_{n-2} 
    \end{bmatrix}
    $$
    3. **Los eigenvalores de la matriz del inciso anterior.**
    $$\lambda_1 = -\sqrt{2}+1$$
    $$\lambda_2 = \sqrt{2}+1$$
    4. **La solución de la relación de recurrencia.**
    $$n=0: f_0=0=c1(2)+c2(1)$$
    $$n=1: f_0=1=c1(2(-\sqrt{2}+1))+c2(\sqrt{2}+1)$$
    $$c_1=-\frac{1}{2.82842},c_2=\frac{1}{2.82842}$$
    $$fn = \frac{\left(\sqrt{2}+1\right)^n}{2.82842}-\frac{\left(-\sqrt{2}+1\right)^n}{2.82842}$$
