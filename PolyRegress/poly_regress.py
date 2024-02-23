import numpy as np

def reduced_form(mat, y):
    # assuming everything is positive in mat and nothing fancy goes wrong
    n = mat.shape[0] - 1 # polynomial power
    for j in range(0, n+1):
        scale = mat[j,j]
        mat[j,:] = mat[j,:]/scale
        y[j] = y[j]/scale
        for i in range(j+1, n+1):
            scale_2 = mat[i,j]
            mat[i,:] = mat[i,:]-scale_2*mat[j,:]
            y[i] = y[i]-scale_2*y[j]
    for j in range(n-1, -1, -1):
        for i in range(j+1, n+1):
            y[j] = y[j] - mat[j,i]*y[i]
    return (mat, y)

def input_mat(samples):
    n = int(input('Polynomial power: '))
    m = samples.shape[1] # number of samples
    x, y = samples[0], samples[1]
    if m >= n+1:
        # construct matrix
        mat = np.zeros((n+1, n+1))
        y_arr = np.zeros(n+1)
        # tempsum, mat setup
        temp_sum = np.zeros(2*n+1)
        for i in range(2*n+1):
            for j in range(0, m):
                temp_sum[i] += x[j]**i
        for i in range(n+1):
            for j in range(n+1):
                mat[i, j] = temp_sum[i+j]
        # yarr setup
        for i in range(0, n+1):
            for j in range(0, m):
                y_arr[i] += y[j]*(x[j]**i)
        return (mat, y_arr)
    else:
        raise ValueError('Number of samples too low!')

def r_squared(samples, coeff):
    n = coeff.shape[0]-1
    m = samples.shape[1] # number of samples
    x, y = samples[0], samples[1]
    # finding ss_tot
    avg = np.average(y)
    ss_tot = 0
    for i in range(m):
        ss_tot += (y[i]-avg)**2
    # finding ss_res
    ss_res = 0
    for i in range(m):
        y_fit = 0
        for j in range(n+1):
            y_fit += coeff[j]*(x[i]**j) 
        ss_res += (y[i]-y_fit)**2
    return 1-ss_res/ss_tot

def main():
    print("Importing from 'samples.csv'...")
    samples = np.genfromtxt('samples.csv', delimiter=',')

    eq_sys = input_mat(samples)
    output_mat = reduced_form(eq_sys[0], eq_sys[1])
    coeff = output_mat[1]
    print('Coefficients:', coeff)
    print('Polyfit func:', (np.polyfit(samples[0], samples[1], coeff.shape[0]-1))[::-1])
    print('R^2:', r_squared(samples, coeff))

main()