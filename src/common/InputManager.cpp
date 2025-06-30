#include "common/InputManager.hpp"

namespace {
    inline InputManager& input = InputManager::instance();
}

/* ---------- Singleton --------------------------------------------------- */

InputManager& InputManager::instance() {
    static InputManager s;
    return s;
}

/* ---------- GLFW Callbacks ---------------------------------------------- */

void InputManager::keyCallback(GLFWwindow*, int key, int, int action, int) {
    if (key >= 0 && key < static_cast<int>(input.m_keys.size()))
        input.m_keys[key] = (action != GLFW_RELEASE);
}

void InputManager::mouseCallback(GLFWwindow*, int button, int, int action, int) {
    if (button >= 0 && button < static_cast<int>(input.m_mouse.size()))
        input.m_mouse[button] = (action != GLFW_RELEASE);
}

void InputManager::cursorCallback(GLFWwindow*, double xpos, double ypos) {
    input.m_mouseX = xpos;
    input.m_mouseY = ypos;
}

/* ---------- Query helpers ----------------------------------------------- */

bool InputManager::isKeyPressed(int key) const noexcept {
    return key >=0 && key < static_cast<int>(m_keys.size()) && m_keys[key];
}

bool InputManager::isMouseButton(int btn) const noexcept {
    return btn >=0 && btn < static_cast<int>(m_mouse.size()) && m_mouse[btn];
}
