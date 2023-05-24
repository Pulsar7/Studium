#!
import os,matplotlib.pyplot as plt,numpy as np,math

def main() -> None:
    elements:list[int] = []
    calculation_time:list[float] = []
    expected_case_calc_times:list[float] = []
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
    average_time = time_sum/len(elements)
    for element in elements:
        if (element != 0):
            expected_case_calc_times.append((average_time*(10**-6.5))*((element**2)))  # ((10**-4)*math.log((int(args[0]))**2,10))
        else:
            expected_case_calc_times.append(0)
    average_calc_time:list[float] = [average_time for e in elements]
    plt.plot(elements,average_calc_time,label="Average calculation time in seconds",color="orange")
    # plt.plot(elements,expected_case_calc_times,label="Expected calculation time in seconds",color="black")
    plt.plot(elements,calculation_time,label="Actual calculation time in seconds",color="royalblue")
    plt.fill_between(x = elements, y1 = 0, color="b",alpha=0.2)
    plt.xticks(np.arange(min(elements), max(elements)+10, step=10))
    plt.ylabel("Calculation time in seconds")
    plt.xlabel("Amount of elements")
    plt.title("Visualizing the Bubble-sorting-Algorithm")
    plt.grid(True)
    plt.legend()
    # plt.savefig("graph.png")
    plt.show()

filepath:str = 'bubble_sort_times.txt'


if __name__ == '__main__':
    os.system("clear") # 
    main()
