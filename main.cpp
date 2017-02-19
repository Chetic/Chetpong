#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

void killApplication(int exitCode) {
    glfwTerminate();
    exit(exitCode);
}

int main() {
    if (glfwInit() != GL_TRUE) {
        cout << "Unable to initialize glfw";
        return 1;
    }

    GLFWwindow* window = glfwCreateWindow(320, 240, "Chetpong", NULL, NULL);
    if (window == NULL) {
        cerr << "Unable to create glfw window";
        killApplication(1);
    }
    glfwMakeContextCurrent(window);

    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        cerr << "Unable to init glew: " << glewGetErrorString(glewError);
        killApplication(1);
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    while (glfwGetKey(window, GLFW_KEY_Q) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == false) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    killApplication(0);
}
