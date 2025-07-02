#pragma once

#include <GLFW/glfw3.h>

namespace ImGuiLayer {

    void Init(GLFWwindow* window);
    void BeginFrame();
    void EndFrame();
    void Shutdown();
}
