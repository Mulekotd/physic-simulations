#include "common/Application.hpp"
#include "common/InputManager.hpp"

namespace Application {

    bool initialize() {
        if (!glfwInit()) return false;

        window = glfwCreateWindow(screenSize.width, screenSize.height, Constants::Window::DEFAULT_TITLE, nullptr, nullptr);

        if (!window) {
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(window);

        glfwSetKeyCallback(window, InputManager::keyCallback);
        glfwSetCursorPosCallback(window, InputManager::cursorCallback);

        glViewport(0, 0, screenSize.width, screenSize.height);

        return true;
    }

    void update(float dt) {
        motion.update(dt);
    }

    void render() {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        motion.render();

        glfwSwapBuffers(window);
    }

    void tick(float dt) {
        update(dt);
        render();
    }

    void cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
