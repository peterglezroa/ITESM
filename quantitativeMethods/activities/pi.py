import matplotlib.pyplot as plt
import numpy as np

pi_values = list()
dots = 500
tries = 100
pi_avg = 0
for i in range(tries):
    val = 0
    # Generate randoms
    x = np.random.uniform(0, 1, dots).tolist()
    y = np.random.uniform(0, 1, dots).tolist()
    for j in range(dots):
        if np.sqrt(x[j]*x[j]+y[j]*y[j]) <= 1:
            val += 1
    pi = float(val)*4/dots
    pi_values.append(pi)
    pi_avg += pi
pi_final = pi_avg/tries
print("Final estimation: ", pi_final)
plt.plot(pi_values)
plt.show()
