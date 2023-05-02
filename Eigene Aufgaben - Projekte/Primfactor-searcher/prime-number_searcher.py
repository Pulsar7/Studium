#!
# Prime-Number search
# Python-Version: 3.10.6
#
import os,math,matplotlib.pyplot as plt,sys,argparse


def show_graph(x:list,y:list) -> None:
    plt.ylabel("Percentage of prime-numbers")
    plt.xlabel("Maxmimum number")
    plt.plot(x,y)
    plt.grid(True)
    plt.show()

def main() -> None:
    pass


#
parser = argparse.ArgumentParser()
parser.add_argument('-m','--max',help = "Maximum number (has to be positive!)",required = True,type = int)
parser.add_argument('-','--',help = "",required = True,type = int)
args = parser.parse_args()

if args.max < 0:
    parser.print_help()
    sys.exit()
    
#

if __name__ == '__main__':
    os.system("clear") #
    main()