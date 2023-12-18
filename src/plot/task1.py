import matplotlib.pyplot as plt
import pandas as pd

def plot_point():
    point = pd.read_csv("D:/5sem/numerical/Lab3/cmake-build-debug/node_task1.txt", sep=' ', names=['X', 'Y'])
    line = pd.read_csv("D:/5sem/numerical/Lab3/cmake-build-debug/interpolFoo_task1.txt", sep=' ', names=['X', 'Y'])

    plt.scatter(point['X'], point['Y'],color='dimgray' ,label='Точки')
    plt.plot(line['X'], line['Y'], color='pink',label='Прямая')
    plt.grid(True)
    plt.title('График точек и прямой')
    plt.xlabel('Ось X')
    plt.ylabel('Ось Y')
    plt.legend()

    plt.show()

plot_point()
