#!
import os,matplotlib.pyplot as plt,numpy as np


def main() -> None:
    elements:list[int] = []
    calculation_time:list[float] = []
    expected_calc_times:list[float] = []
    file = open(filepath,'r')
    Lines = file.readlines()
    file.close()
    average_time:float = 0.0
    time_sum:float = 0.0
    for line in Lines:
        args = line.strip().split(',')
        elements.append(int(args[0]))
        calculation_time.append(float(args[1]))
        time_sum += float(args[1])
        expected_calc_times.append((float(args[1]))**2)
    average_time = time_sum/len(elements)
    average_calc_time:list[float] = [average_time for e in elements]
    plt.plot(elements,calculation_time)
    plt.plot(elements,average_calc_time,label="Average calculation time in seconds")
    plt.plot(elements,expected_calc_times,label="Expected calculation time in seconds")
    plt.xticks(np.arange(min(elements), max(elements), step=100))
    plt.ylabel("Calculation time in seconds")
    plt.xlabel("Amount of elements")
    plt.title("Visualizing the Bubble-sorting-Algorithm")
    plt.grid(True)
    plt.legend()
    plt.savefig("graph.png")

filepath:str = 'bubble_sort_times.txt'


if __name__ == '__main__':
    os.system("clear") # 
    main()