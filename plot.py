import matplotlib.pyplot as plt
import numpy as np

datosPendulo = np.genfromtxt("datosPendulo.dat")

plt.figure(figsize=(10,10))
plt.subplot(211)
plt.title("Ángulo vs. Tiempo")
plt.plot(datosPendulo[:,0],datosPendulo[:,1], label = "Pendulo")
plt.subplot(212)
plt.title("Trayectoria del péndulo")
plt.scatter(np.sin(datosPendulo[:,1]),-np.cos(datosPendulo[:,1]))
plt.savefig("graficas.pdf")
