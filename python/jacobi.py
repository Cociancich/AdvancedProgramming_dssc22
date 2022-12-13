#run this file with `python anim.py` from command line
#open the .gif in whatever you usually open them with to check that it worked
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
fig=plt.figure()
#you can put something depending on i here

def animate(i): 
    size = 9
    times = i
    arr_center = np.full((size-2,size-2), 0.5)
    arr_upper = np.zeros((1,size-2), dtype='int')
    arr_right = np.zeros((size-1,1), dtype='int')
    arr_lower = np.linspace(100,0,size).reshape(1, size)
    arr_left= np.linspace(0,100,size)
    arr = np.concatenate([arr_upper,arr_center])
    arr = np.concatenate([arr,arr_right],axis=1)
    arr = np.concatenate([arr_left[:-1].reshape(size-1, 1),arr],axis=1)
    arr = np.concatenate([arr,arr_lower])
    #plt.imshow(arr)
    arr_new = arr.copy()

    for t in range (times):
        for i in range (size):
            for j in range (size):
                if i > 0 and j > 0 and i < size-1 and j < size-1:
                    arr_new[i][j] = 0.25*(arr[i-1][j] + arr[i][j-1] + arr[i+1][j]+ arr[i][j+1])
        arr = arr_new
        plt.imshow(arr)
 
anim = animation.FuncAnimation(fig,animate,frames=20, interval=10)

# save the animation as an gif
anim.save("jacobi.gif") 
