//
// Created by Remi Peyras on 13/10/2021.
//

#include "assignement2.hpp"
#include <iostream>
#include "MidPoint/MidPoint.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

void displayAxis() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -1.5, 0.0, 0.0, -4.5, 0, 1, 0);
    glPushMatrix();

    glBegin(GL_LINES);
    {

        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(5.0, 0.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 5.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 5.0);
    }
    glEnd();
    glPopMatrix();
    glFlush();
}


void exerciseMidPoint(GLFWwindow *window) {
    std::cout << "exerciseMidPoint" << std::endl;
    MidPoint midPoint(glm::vec2(-2, 6), glm::vec2(2, 12));

    midPoint.draw();
}

void exerciseHomogeneousCoordinates(GLFWwindow *window) {
    std::cout << "exerciseHomogeneousCoordinates" << std::endl;
}


void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow *initGlwWindow() {
    GLFWwindow *window;
    if (!glfwInit()) {
        throw std::exception();
    }
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::exception();
    }
    glfwMakeContextCurrent(window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
    return window;
}

int main() {
    GLFWwindow *window;
    try {
        window = initGlwWindow();
    } catch (std::string &exception) {
        std::cerr << "Error when initialize something ..." << std::endl;
        return EXIT_FAILURE;
    }
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);
        displayAxis();
        exerciseMidPoint(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return EXIT_SUCCESS;
}