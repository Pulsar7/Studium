#!
import matplotlib.pyplot as plt
import numpy as np


def main() -> None:
    x:list[str] = [
        "Li","Be","B","C","N","O","F","Ne",
        "Na","Mg","Al","Si","P","S","Cl","Ar",
        "K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
        "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
        "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
        "Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
        "Fr","Ra","Ac","Th","Pa","U","Np","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr",
        "Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"
    ]
    y:list[float] = [
        -259+253,-269,1347-181,2470-1278,3650-2180,4830-3750,-210+196,-219+183,-220+188,-249+246,                                         # S < Schm.
        760-63,1484-839,2836-1541,3262-1668,3378-1890,2640-1890,2032-1244,2750-1535,2870-1495,2732-1453,2595-1083,907-420,2403-30,2830-937,817-615,685-217,-7-59,-157+153,
        688-39,1384-769,3338-1522,4377-1852,4928-2468,4825-2617,4877-2172,3900-2310,3730-1966,3140-1554,2163-962,765-321,2080-157,2687-232,1635-631,990-450,184-114,-112+108,
        678-28,1696-725,4602-2227,5425-2996,5657-3410,5630-3180,5027-3054,4530-2410,3827-1772
    ]
    print(len(x),len(y))
    # plt.plot(x,y)
    # plt.show()

if __name__ == '__main__':
    # os.system("clear") # 
    main()