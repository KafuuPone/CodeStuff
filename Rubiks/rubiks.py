import matplotlib.pyplot as plt
import numpy as np

from matplotlib.patches import Rectangle, PathPatch
from matplotlib.transforms import Affine2D
import mpl_toolkits.mplot3d.art3d as art3d

import sys

def display_cube(cube):
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    colors = ["green", "royalblue", "red", "darkorange", "yellow", "white"]
    
    # Draw front
    for i in range(3):
        for j in range(3):
            p = Rectangle((1+j*10, 21-i*10), 9, 9, color=colors[cube['front'][i][j]])
            ax.add_patch(p)
            art3d.pathpatch_2d_to_3d(p, z=0, zdir="y")
            j += 1
        i += 1
    # Draw back
    for i in range(3):
        for j in range(3):
            p = Rectangle((1+j*10, 21-i*10), 9, 9, color=colors[cube['back'][i][2-j]])
            ax.add_patch(p)
            art3d.pathpatch_2d_to_3d(p, z=31, zdir="y")
            j += 1
        i += 1
    # Draw left
    for i in range(3):
        for j in range(3):
            p = Rectangle((21-j*10, 21-i*10), 9, 9, color=colors[cube['left'][i][j]])
            ax.add_patch(p)
            art3d.pathpatch_2d_to_3d(p, z=0, zdir="x")
            j += 1
        i += 1
    # Draw right
    for i in range(3):
        for j in range(3):
            p = Rectangle((21-j*10, 21-i*10), 9, 9, color=colors[cube['right'][i][2-j]])
            ax.add_patch(p)
            art3d.pathpatch_2d_to_3d(p, z=31, zdir="x")
            j += 1
        i += 1
    # Draw bottom
    for i in range(3):
        for j in range(3):
            p = Rectangle((1+j*10, 1+i*10), 9, 9, color=colors[cube['bottom'][i][j]])
            ax.add_patch(p)
            art3d.pathpatch_2d_to_3d(p, z=0, zdir="z")
            j += 1
        i += 1
    # Draw top
    for i in range(3):
        for j in range(3):
            p = Rectangle((1+j*10, 1+i*10), 9, 9, color=colors[cube['top'][2-i][j]])
            ax.add_patch(p)
            art3d.pathpatch_2d_to_3d(p, z=31, zdir="z")
            j += 1
        i += 1
    # Draw borders
    for direction in ['x', 'y', 'z']:
        for z_height in [0, 31]:
            for x in range(0, 31, 10):
                p = Rectangle((x, 0), 1, 31, color='black')
                ax.add_patch(p)
                art3d.pathpatch_2d_to_3d(p, z=z_height, zdir=direction)
                p = Rectangle((0, x), 31, 1, color='black')
                ax.add_patch(p)
                art3d.pathpatch_2d_to_3d(p, z=z_height, zdir=direction)

    ax.set_xlim(0, 40)
    ax.set_ylim(0, 40)
    ax.set_zlim(0, 40)
    ax.set_box_aspect([1.0, 1.0, 1.0])

    plt.axis('off')
    plt.show()

def operation(cube, op):
    if op == "U":
        #top
        top_temp = np.copy(cube['top']) # Copies without altering original
        for i in range(3):
            for j in range(3):
                cube['top'][i][j] = top_temp[2-j][i]
        #side
        top_side_temp = [np.copy(cube['front'][0]), np.copy(cube['left'][0]), np.copy(cube['right'][0]), np.copy(cube['back'][0])]
        target_side = ['left', 'back', 'front', 'right']
        for i in range(4):
            cube[target_side[i]][0] = top_side_temp[i]
    elif op == "E":
        #side
        mid_temp = [np.copy(cube['front'][1]), np.copy(cube['left'][1]), np.copy(cube['right'][1]), np.copy(cube['back'][1])]
        target_side = ['right', 'front', 'back', 'left']
        for i in range(4):
            cube[target_side[i]][1] = mid_temp[i]
    elif op == "D":
        #bottom
        bottom_temp = np.copy(cube['bottom']) # Copies without altering original
        for i in range(3):
            for j in range(3):
                cube['bottom'][i][j] = bottom_temp[2-j][i]
        #side
        bottom_side_temp = [np.copy(cube['front'][2]), np.copy(cube['left'][2]), np.copy(cube['right'][2]), np.copy(cube['back'][2])]
        target_side = ['right', 'front', 'back', 'left']
        for i in range(4):
            cube[target_side[i]][2] = bottom_side_temp[i]
    elif op == "L":
        #left
        left_temp = np.copy(cube['left']) # Copies without altering original
        for i in range(3):
            for j in range(3):
                cube['left'][i][j] = left_temp[2-j][i]
        #side
        front = np.copy(cube['front'])
        top = np.copy(cube['top'])
        back = np.copy(cube['back'])
        bottom = np.copy(cube['bottom'])
        for i in range(3):
            cube['bottom'][i][0] = front[i][0]
            cube['front'][i][0] = top[i][0]
            cube['top'][i][0] = back[2-i][2]
            cube['back'][2-i][2] = bottom[i][0]
    elif op == "M":
        front = np.copy(cube['front'])
        top = np.copy(cube['top'])
        back = np.copy(cube['back'])
        bottom = np.copy(cube['bottom'])
        for i in range(3):
            cube['bottom'][i][1] = front[i][1]
            cube['front'][i][1] = top[i][1]
            cube['top'][i][1] = back[2-i][1]
            cube['back'][2-i][1] = bottom[i][1]
    elif op == "R":
        #right
        right_temp = np.copy(cube['right']) # Copies without altering original
        for i in range(3):
            for j in range(3):
                cube['right'][i][j] = right_temp[2-j][i]
        #side
        front = np.copy(cube['front'])
        top = np.copy(cube['top'])
        back = np.copy(cube['back'])
        bottom = np.copy(cube['bottom'])
        for i in range(3):
            cube['bottom'][i][2] = back[2-i][0]
            cube['front'][i][2] = bottom[i][2]
            cube['top'][i][2] = front[i][2]
            cube['back'][2-i][0] = top[i][2]
    elif op == "F":
        #front
        front_temp = np.copy(cube['front']) # Copies without altering original
        for i in range(3):
            for j in range(3):
                cube['front'][i][j] = front_temp[2-j][i]
        #side
        left = np.copy(cube['left'])
        top = np.copy(cube['top'])
        right = np.copy(cube['right'])
        bottom = np.copy(cube['bottom'])
        for i in range(3):
            cube['top'][2][i] = left[2-i][2]
            cube['left'][i][2] = bottom[0][i]
            cube['bottom'][0][i] = right[2-i][0]
            cube['right'][i][0] = top[2][i]
    elif op == "S":
        #side
        left = np.copy(cube['left'])
        top = np.copy(cube['top'])
        right = np.copy(cube['right'])
        bottom = np.copy(cube['bottom'])
        for i in range(3):
            cube['top'][1][i] = left[2-i][1]
            cube['left'][i][1] = bottom[1][i]
            cube['bottom'][1][i] = right[2-i][1]
            cube['right'][i][1] = top[1][i]
    elif op == "B":
        #back
        back_temp = np.copy(cube['back']) # Copies without altering original
        for i in range(3):
            for j in range(3):
                cube['back'][i][j] = back_temp[2-j][i]
        #side
        left = np.copy(cube['left'])
        top = np.copy(cube['top'])
        right = np.copy(cube['right'])
        bottom = np.copy(cube['bottom'])
        for i in range(3):
            cube['left'][2-i][0] = top[0][i]
            cube['bottom'][2][i] = left[i][0]
            cube['right'][2-i][2] = bottom[2][i]
            cube['top'][0][i] = right[i][2]
    elif op == "f":
        algorithm(cube, "F S")
    elif op == "b":
        algorithm(cube, "B S'")
    elif op == "u":
        algorithm(cube, "U E'")
    elif op == "d":
        algorithm(cube, "D E")
    elif op == "l":
        algorithm(cube, "L M")
    elif op == "r":
        algorithm(cube, "R M'")
    elif op == "x":
        algorithm(cube, "R M' L'")
    elif op == "y":
        algorithm(cube, "U E' E'")
    elif op == "z":
        algorithm(cube, "F S B'")

    elif op[-1] == "2":
        op = op[:-1]
        for i in range(2):
            operation(cube, op)
    elif op[-1] == "'":
        op = op[:-1]
        for i in range(3):
            operation(cube, op)
    elif op[1] == "w":
        operation(cube, op.replace("w", "").lower())
    else:
        sys.exit(f"[Error] Invalid move `{op}`")

def algorithm(cube, alg):
    for i in ["(", ")", "[", "]"]:
        alg = alg.replace(i, " ")
    for move in alg.split():
        operation(cube, move)

def edge_other_col(cube, face, index_i, index_j):
    edges = [
        ['top01', 'back01'], ['top10', 'left01'], ['top12', 'right01'], ['top21', 'front01'],
        ['left10', 'back12'], ['front10', 'left12'], ['right10', 'front12'], ['back10', 'right12'],
        ['bottom01', 'front21'], ['bottom10', 'left21'], ['bottom12', 'right21'], ['bottom21', 'back21']
    ]
    output_edge = ''
    input_edge = face + f'{index_i}' + f'{index_j}'
    for edge in edges:
        if input_edge in edge:
            edge.remove(input_edge)
            output_edge = edge[0]
    if output_edge == '':
        print(f"[ERROR] Invalid edge index `{input_edge}`")
        sys.exit()
    return cube[output_edge[:-2]][int(output_edge[-2])][int(output_edge[-1])]

def main():
    rubiks_cube = {
        "front": [[0, 0, 0], [0, 0, 0], [0, 0, 0]],
        "back": [[1, 1, 1], [1, 1, 1], [1, 1, 1]],
        "left": [[2, 2, 2], [2, 2, 2], [2, 2, 2]],
        "right": [[3, 3, 3], [3, 3, 3], [3, 3, 3]],
        "top": [[4, 4, 4], [4, 4, 4], [4, 4, 4]],
        "bottom": [[5, 5, 5], [5, 5, 5], [5, 5, 5]]
        }

    # while True:
    #     algorithm(rubiks_cube, input("Input algorithm: "))
    #     display_cube(rubiks_cube)
    #     if input("Do another? (y/n)").lower() == "n":
    #         sys.exit()

    # Test for edge_other_col()
    other_edge_color_index = edge_other_col(rubiks_cube, 'top', 0, 1)
    colors = ["green", "royalblue", "red", "darkorange", "yellow", "white"]
    print(colors[other_edge_color_index])

main()