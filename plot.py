import matplotlib.pyplot as plt
import numpy as np

datosPendulo = np.genfromtxt("datosPendulo.dat")

plt.figure()
plt.subplot(211)
plt.plot(datosPendulo[:,0],datosPendulo[:,1], label = "Pendulo")
plt.subplot(212)
plt.scatter(np.sin(datosPendulo[:,1]),-np.cos(datosPendulo[:,1]))
plt.savefig("graficas.pdf")
