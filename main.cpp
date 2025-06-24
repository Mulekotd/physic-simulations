#include <GLFW/glfw3.h>
#include <iostream>

#include "core/Camera2D.hpp"
#include "core/Field.hpp"
#include "core/Vector3.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

GLFWwindow* window = nullptr;

Field field(Vector3(0, 0, 0), WINDOW_WIDTH, WINDOW_HEIGHT);
Camera2D camera(&field, WINDOW_WIDTH, WINDOW_HEIGHT);

bool initialize() {
    if (!glfwInit()) {
        return false;
    }

    window = glfwCreateWindow(field.getWidth(), field.getHeight(), "Physics Simulation", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, field.getWidth(), field.getHeight());

    return true;
}

void update(float dt) {
}

void render() {
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
}

void cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main() {
    if (!initialize()) return -1;

    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);

        lastTime = currentTime;

        update(deltaTime);
        render();

        glfwPollEvents();
    }

    cleanup();

    return 0;
}
