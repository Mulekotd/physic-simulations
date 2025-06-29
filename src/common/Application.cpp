#include "common/Application.hpp"

namespace Application {
    const Size fieldSize = field.getSize();

    bool initialize() {
        if (!glfwInit()) return false;

        window = glfwCreateWindow(fieldSize.width, fieldSize.height, "Physics Simulation", nullptr, nullptr);

        if (!window) {
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(window);
        glViewport(0, 0, fieldSize.width, fieldSize.height);

        return true;
    }

    void update(float dt) {
        motion.update(dt);
    }

    void render() {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for (const auto& particle : motion.particles()) {
            particle.draw();
        }

        glfwSwapBuffers(window);
    }

    void cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
