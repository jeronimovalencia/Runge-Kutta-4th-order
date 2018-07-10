import matplotlib.pyplot as plt
import numpy as np

datosPendulo = np.genfromtxt("datosPendulo.dat")

plt.figure()
plt.plot(datosPendulo[:,0],datosPendulo[:,1], label = "Pendulo")
plt.savefig("graficas.pdf")
