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
    for n in range(0,1000,10):
        max_number += n
        not_prim_counter:int = 0
        prim_counter:int = 0
        for number in range(2,max_number,1):
            prim_state:int = 1
            for i in range(2,int(math.sqrt(number)),1):
                if number%i == 0 and i != 1:
                    prim_state = 0
                    not_prim_counter += 1
                    break
            if prim_state == 1:
                prim_counter += 1
        percentage:float = (100/max_number)*prim_counter;
        print("(%s) Primnumbers: %s | Not Primnumbers: %s | Percentage of Primnumbers: %s percent"%(max_number,prim_counter,not_prim_counter,percentage))
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