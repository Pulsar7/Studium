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

for line in Lines:
    args:list[str] = line.strip().split(";")
    # 1
    data['1']['x'].append(float(args[0]))
    data['1']['y'].append(float(args[1]))
    # 2
    data['2']['x'].append(float(args[2]))
    data['2']['y'].append(float(args[3]))

fig, ax = plt.subplots()
scatter_1 = ax.scatter([], [], c='blue', label="Ball")
scatter_2 = ax.scatter([], [], c='green', label="Bullet")
first_obj = ax.plot(data['1']['x'],data['1']['y'],c='blue',label="Trajectory BALL",linestyle="-.")
second_obj = ax.plot(data['2']['x'],data['2']['y'],c='green',label="Trajectory BULLET",linestyle="-.")

def init():
    ax.set_xlim(-50,50)
    ax.set_ylim(-10, 50)
    return scatter_1, scatter_2

def update(frame):
    scatter_1.set_offsets([data['1']['x'][frame], data['1']['y'][frame]])
    scatter_2.set_offsets([data['2']['x'][frame], data['2']['y'][frame]])
    return scatter_1,scatter_2

animation = FuncAnimation(fig, update, frames=len(data['1']['x']), init_func=init, blit=True)

# plt.scatter(data['1']['x'],data['1']['y'],label="Object 1 (BALL)",color="green")
# plt.scatter(data['2']['x'],data['2']['y'],label="Object 2 (BULLET)",color="blue")
plt.grid(True)
plt.legend()
plt.show()