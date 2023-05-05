#!
# Euklidischer Algorithmus
# by Benedikt Fichtner
# Python-Version: 3.10.6
#
import matplotlib.pyplot as plt
from rich import (pretty,console as cons)

def get_ggt(a:int,b:int) -> int:
    while (a != b and a != 0 and b != 0):
        if a > b:
            a = a-b
        elif b > a:
            b = b-a
    if a == 0:
        return b
    else:
        return a
        

def main(max_number:int) -> None:
    x:list[int] = []
    y:list[int] = []
    for i in range(0,max_number):
        for h in range(0,max_number):
            ggt:int = get_ggt(i,h)
            if ggt != 1:
                x.append(i)
                y.append(ggt)
    plt.plot(x,y,marker="x")
    plt.grid(True)
    plt.ylabel("ggt")
    plt.xlabel("Zahlen")
    console.print(x)
    console.print(y)
    plt.show()
    del x,y
    

#
pretty.install()
console = cons.Console()
#

if __name__ == '__main__':
    # os.system("clear") # 
    main(50)