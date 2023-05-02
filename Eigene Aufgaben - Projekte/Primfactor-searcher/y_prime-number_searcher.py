#!
# Primenumber-Searcher
# by Benedikt Fichtner
# Python-Version: 3.10.6
#
import os,sys,math
import matplotlib.pyplot as plt


def main() -> None:
    x:list[int] = []
    y:list[int] = []
    max_number:int = 100
    last_highest_num:int = max_number
    for n in range(0,10000,100):
        max_number += n
        last_highest_num = max_number-n
        not_prim_counter:int = 2 # 0 and 1
        prim_counter:int = 0
        sys.stdout.write("\r [*] Searching for prime-numbers from 2 to %s..."%(max_number))
        sys.stdout.flush()
        for number in range(last_highest_num,max_number,1):
            prim_state:int = 1
            for i in range(2,number,1):
                if number%i == 0:
                    prim_state = 0
                    not_prim_counter += 1
                    break
            if prim_state == 1:
                prim_counter += 1
                # print("%s is a prime-number"%(number))
        percentage:float = (100/max_number)*prim_counter;
        print("Prime numbers: %s => %s percent"%(prim_counter,percentage))
        y.append(percentage)
        x.append(max_number)
    plt.plot(x,y) 
    plt.grid(True)
    plt.ylabel("Percentage of PrimNumbers")
    plt.xlabel("Total number")
    plt.show()
    del x,y


if __name__ == "__main__":
    os.system("clear") # 
    main()