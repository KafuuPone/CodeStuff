import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *

import numpy as np

def Cube():
    vertices = (
    (1, -1, -1),
    (1, 1, -1),
    (-1, 1, -1),
    (-1, -1, -1),
    (1, -1, 1),
    (1, 1, 1),
    (-1, -1, 1),
    (-1, 1, 1)
    )

    edges = (
        (0,1),
        (0,3),
        (0,4),
        (2,1),
        (2,3),
        (2,7),
        (6,3),
        (6,4),
        (6,7),
        (5,1),
        (5,4),
        (5,7)
        )

    glBegin(GL_LINES)
    glColor3f(1, 1, 1)  # Color
    for edge in edges:
        for vertex in edge:
            glVertex3fv(vertices[vertex])
    glEnd()

def Surface():
    glBegin(GL_QUADS)
    glColor3f(1, 1, 0)  # Yellow color
    glVertex3f(-1, -1, 1)
    glVertex3f(1, -1, 1)
    glVertex3f(1, 1, 1)
    glVertex3f(-1, 1, 1)
    glEnd()

def RotateVector(vector, axis, angle):
    angle *= np.pi/180
    v = np.copy(vector)
    k = np.copy(axis)
    return v * np.cos(angle) + np.cross(k, v) * np.sin(angle) + k * np.dot(k, v) * (1-np.cos(angle))


def main():
    pygame.init()
    display = (800, 600)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)

    glTranslatef(0.0, 0.0, -10)

    view_xaxis = np.array([1, 0, 0])
    view_yaxis = np.array([0, 1, 0])
    view_zaxis = np.array([0, 0, 1])
    
    while True:
        for event in pygame.event.get():
            # Quit game
            if event.type == pygame.QUIT or pygame.key.get_pressed()[K_ESCAPE]:
                pygame.quit()
                quit()
            # Rotate view
            elif event.type == pygame.MOUSEBUTTONDOWN:
                pygame.mouse.get_rel()
            # Zoom in/out
            elif event.type == pygame.MOUSEWHEEL:
                sensitivity = 0.5 # Zoom sensitivity
                amount = event.y*sensitivity
                glTranslatef(amount*view_zaxis[0], amount*view_zaxis[1], amount*view_zaxis[2])

        # View rotation
        state = pygame.mouse.get_pressed() # Get mouse state
        # Left click
        if state[0]:
            dx, dy = pygame.mouse.get_rel()
            if (dx, dy) != (0, 0):           
                sensitivity = 0.3 # Rotation sensitivity
                glRotatef(dx * sensitivity, view_yaxis[0], view_yaxis[1], view_yaxis[2])
                view_xaxis = RotateVector(view_xaxis, view_yaxis, -dx*sensitivity)
                glRotatef(dy * sensitivity, view_xaxis[0], view_xaxis[1], view_xaxis[2])
                view_yaxis = RotateVector(view_yaxis, view_xaxis, -dy*sensitivity)
                view_zaxis = np.cross(view_xaxis, view_yaxis)
        # Right click
        elif state[2]:
            # Determine amount of rotation
            curr_x, curr_y = pygame.mouse.get_pos()
            dx, dy = pygame.mouse.get_rel()
            prev_x = curr_x - dx
            prev_y = curr_y - dy
            angle_curr = np.angle((curr_x-display[0]/2)+(display[1]/2-curr_y)*1j)
            angle_prev = np.angle((prev_x-display[0]/2)+(display[1]/2-prev_y)*1j)
            del_angle = (angle_curr-angle_prev)*180/np.pi
            # Rotate view and view_xaxis, view_yaxis
            glRotatef(del_angle, view_zaxis[0], view_zaxis[1], view_zaxis[2])
            view_xaxis = RotateVector(view_xaxis, view_zaxis, -del_angle)
            view_yaxis = RotateVector(view_yaxis, view_zaxis, -del_angle)
            
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        Cube()
        Surface()
        pygame.display.flip()
        pygame.time.wait(10)

main()