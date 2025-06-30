#include <GLFW/glfw3.h>
#include <iostream>

#include "common/Application.hpp"

int main() {
    if (!Application::initialize()) return -1;

    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(Application::window)) {
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);

        lastTime = currentTime;

        Application::tick(deltaTime);

        glfwPollEvents();
    }

    Application::cleanup();

    return 0;
}
