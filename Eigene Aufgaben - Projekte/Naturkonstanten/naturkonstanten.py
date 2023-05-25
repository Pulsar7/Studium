#!
import numpy as np, matplotlib.pyplot as plt,math


def main() -> None:
    data:dict = {
        'c_0':299792458,
        'y': 6.67408*10**-11,
        'N_A': 6.0221367*10**23,
        'e': 1.602117733*10**-19,
        'm_c': 9.1093879*10**-31,
        'm_p': 1.6726231*10**-27,
        'h': 6.6260693*10**-34,
        '€_0': 8.85418781762*10**4,
        'ü_0': 4*math.pi*10**-7,
        'F': 9.6485309,
        'R': 8.314510*10**-8,
        'k': 1.380658*10**-23,
        'stefan_boltz': 5.67051*10**-8 
    }
    plt.plot(data.keys(),data.values())
    plt.grid(True)
    plt.show()


if __name__ == '__main__':
    # os.system("clear") # 
    main()