#run this file with `python anim.py` from command line
#open the .gif in whatever you usually open them with to check that it worked
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
fig=plt.figure()
#you can put something depending on i here
class Mesh:
    def __init__(self, size):
        self.size = size
        arr_center = np.full((size-2,size-2), 0.5)
        arr_upper = np.zeros((1,size-2), dtype='int')
        arr_right = np.zeros((size-1,1), dtype='int')
        arr_lower = np.linspace(100,0,size).reshape(1, size)
        arr_left= np.linspace(0,100,size)
        arr = np.concatenate([arr_upper,arr_center])
        arr = np.concatenate([arr,arr_right],axis=1)
        arr = np.concatenate([arr_left[:-1].reshape(size-1, 1),arr],axis=1)
        arr = np.concatenate([arr,arr_lower])
        self.arr = arr
    def __str__(self):
        return "{0} ".format(self.arr) #"converts" class to a string
    def __getitem__(self, index):
        """Supports two-dimensional indexing 
        with [row][column]."""
        return self.arr[index]
        
class Solve:
    def __init__(self, Mesh, times):
        self.arr = Mesh
        self.arr_new = Mesh
        self.printable = np.zeros((Mesh.size, Mesh.size), dtype='float')
        self.times = times
        self.size = Mesh.size
        #self.size = Mesh.size
        #arr_new = arr.copy()
    def solve(self):
        for t in range (self.times):
            for i in range (self.size):
                for j in range (self.size):
                    if i > 0 and j > 0 and i < self.size-1 and j < self.size-1:
                        self.arr_new[i][j] = 0.25*(self.arr[i-1][j] + self.arr[i][j-1] + self.arr[i+1][j]+ self.arr[i][j+1])
                    self.printable[i][j] = self.arr[i][j]
            self.arr = self.arr_new            
            plt.imshow(self.printable)
            
def animate(i): 
    j = Mesh(9)
    abc = Solve(j, i)
    fff = abc.solve()

 
anim = animation.FuncAnimation(fig,animate,frames=20, interval=10)

# save the animation as an gif
anim.save("jacobi2.gif") 
