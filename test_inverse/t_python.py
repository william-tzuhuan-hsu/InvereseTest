import numpy as np
import time


m1 = np.loadtxt('test_inverse/input_matrix1.txt')

f = open("numpy_time.txt", "w")


start_time1 = time.time()
for x in range(100):
    m1 = np.linalg.inv(m1)

t1 = time.time() - start_time1

f.write(str(t1) + ' seconds')

f.close()


