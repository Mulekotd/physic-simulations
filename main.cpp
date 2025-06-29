#include <GLFW/glfw3.h>
#include <iostream>

#include "common/Size.hpp"
#include "common/Vector3.hpp"

#include "core/Camera2D.hpp"
#include "core/Field.hpp"

#include "simulation/Motion.hpp"

const Size WINDOW_SIZE = Size(800, 600);

GLFWwindow* window = nullptr;

Field field(Vector3(0, 0, 0), WINDOW_SIZE);
Camera2D camera(&field, WINDOW_SIZE);

// Simulations

simulation::Motion motion(100, simulation::Law::Third);

bool initialize() {
    const Size size = field.getSize();

    if (!glfwInit()) {
        return false;
    }

    window = glfwCreateWindow(size.width, size.height, "Physics Simulation", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, size.width, size.height);

    return true;
}

void update(float dt) {
    motion.update(dt);
}

void render() {
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (const auto& particle : motion.particles()) {
        particle.draw(camera);
    }

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
