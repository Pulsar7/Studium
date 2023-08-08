#
# Python 3.10.6
#
import os,time,matplotlib.pyplot as plt,numpy as np
import math
from matplotlib.animation import FuncAnimation


class Object():
    def __init__(self,x:float,y:float,m:float,r:float,vy:float,vx:float) -> None:
        (self.x,self.y,self.mass,self.radius,self.vy,self.vx) = (x,y,m,r,vy,vx)
        self.thing = ""

class Calculator():
    def __init__(self) -> None:
        pass
    
    
class Visualizer(Calculator):
    def __init__(self,objectA:Object,objectB:Object,g:float) -> None:
        self.fig, self.ax = plt.subplots()
        (self.objectA,self.objectB,self.g) = (objectA,objectB,g)
        objectA.thing = self.ax.plot([objectA.x],[objectA.y],color="red",marker="o")[0]
        objectB.thing = self.ax.plot([objectB.x],[objectB.y],color="blue",marker="o")[0]
        self.num_frames:int = 100
        self.ax.set_ylim(-5,20)
        self.ax.set_xlim(-5,20)
        super().__init__()
    
    def update(self,frame) -> tuple((Object,Object)):
        if self.objectA.vy > 0 or self.objectA.vx > 0:
            if self.objectA.y > 0:
                self.objectA.vy = 
            self.objectA.x = self.objectA.vx * frame
        if self.objectB.vy > 0 or self.objectB.vx > 0:
            if self.objectB.y > 0:
                pass
            self.objectB.x = self.objectB.vx * frame
        self.objectA.thing.set_xdata(self.objectA.x)
        self.objectA.thing.set_ydata(self.objectA.y)
        self.objectB.thing.set_xdata(self.objectB.x)
        self.objectB.thing.set_ydata(self.objectB.y)
        return (self.objectA.thing,self.objectB.thing)
        
    def show(self) -> None:
        anim = FuncAnimation(self.fig, self.update, frames=self.num_frames, blit=True)
        
        
        plt.show()
    

if __name__ == '__main__':
    os.system("clear") # 
    objectA = Object(x=0,y=2,m=10.0,r=1.0,vy=3.0,vx=3)
    objectB = Object(x=2,y=1,m=15.0,r=2.0,vy=1.0,vx=3)
    Visualizer(objectA,objectB,9.81).show()