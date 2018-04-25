import matplotlib.pyplot as plt
import numpy as np

datos = np.loadtxt("advection.txt")

plt.figure()
plt.title("Evolucion de la funcion y")
plt.xlabel("x")
plt.ylabel("y")
plt.plot(datos[:,0],datos[:,1], label="iteracion 1")
plt.plot(datos[:,0],datos[:,2], label="iteracion 175")
plt.plot(datos[:,0],datos[:,3], label="iteracion 350")
plt.plot(datos[:,0],datos[:,4], label="iteracion 525")
plt.plot(datos[:,0],datos[:,5], label="iteracion 700")
plt.legend()
plt.savefig("RS_graph.pdf")
