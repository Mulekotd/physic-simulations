#include "backends/imgui_impl_glfw.h" 

#include "system/InputManager.hpp"

namespace {
    inline InputManager& input = InputManager::Instance();
}

/* ---------- Singleton --------------------------------------------------- */

InputManager& InputManager::Instance() {
    static InputManager s;
    return s;
}

/* ---------- Query helpers ----------------------------------------------- */

bool InputManager::isKeyPressed(int key) const noexcept {
    return key >=0 && key < static_cast<int>(m_keys.size()) && m_keys[key];
}

bool InputManager::isMouseButton(int btn) const noexcept {
    return btn >=0 && btn < static_cast<int>(m_mouse.size()) && m_mouse[btn];
}

/* ---------- GLFW Callbacks ---------------------------------------------- */

void InputManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);

    if (key >= 0 && key < static_cast<int>(input.m_keys.size()))
        input.m_keys[key] = (action != GLFW_RELEASE);
}

void InputManager::MouseCallback(GLFWwindow* window, int button, int action, int mods) {
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

    if (button >= 0 && button < static_cast<int>(input.m_mouse.size()))
        input.m_mouse[button] = (action != GLFW_RELEASE);
}

void InputManager::CursorCallback(GLFWwindow* window, double xpos, double ypos) {
    ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);

    input.m_mouseX = xpos;
    input.m_mouseY = ypos;
}
