import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


filepath:str = 'obj_data.txt'
file = open(filepath,'r')
Lines = file.readlines()
file.close()

data:dict = {
    '1': {
        'x': [],
        'y': []
    },
    '2': {
        'x': [],
        'y': []
    }
}

# fig, ax = plt.subplots()
# scatter = ax.scatter([], [], c='blue')

"""def init():
    ax.set_xlim(0, 4)
    ax.set_ylim(4, 8)
    return scatter,

def update(frame):
    scatter.set_offsets([[data['1'][frame], data['1'][frame]]])
    return scatter,
"""
# animation = FuncAnimation(fig, update, frames=len(x), init_func=init, blit=True)

for line in Lines:
    args:list[str] = line.strip().split(";")
    print(args)
    # 1
    data['1']['x'].append(float(args[0]))
    data['1']['y'].append(float(args[1]))
    # 2
    data['2']['x'].append(float(args[2]))
    data['2']['y'].append(float(args[3]))


plt.scatter(data['1']['x'],data['1']['y'],label="Object 1 (BALL)",color="green")
plt.scatter(data['2']['x'],data['2']['y'],label="Object 2 (BULLET)",color="blue")
plt.grid(True)
plt.legend()
plt.show()