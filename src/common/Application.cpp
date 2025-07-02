#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "system/ImGuiLayer.hpp"
#include "system/InputManager.hpp"

#include "common/Application.hpp"

namespace Application {

    bool Init() {
        if (!glfwInit()) return false;

        window = glfwCreateWindow(resolution.width, resolution.height, Constants::Window::DEFAULT_TITLE, nullptr, nullptr);

        if (!window) {
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(window); 
        ImGuiLayer::Init(window);

        glfwSetKeyCallback(window, InputManager::keyCallback);
        glfwSetCursorPosCallback(window, InputManager::cursorCallback);

        glViewport(0, 0, resolution.width, resolution.height);

        return true;
    }

    void Update(float dt) {
        if (motion) motion->update(dt);
    }

    void Render() {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if (motion) motion->render();

        // ImGui rendering
        ImGuiLayer::BeginFrame();
        ImGui::Begin("Simulation Control");

        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

        ImGui::SliderInt("Particles", &context.count, 100, 500);

        if (ImGui::Button(context.isRunning ? "Restart" : "Start")) {
            context.isRunning = true;
            motion = std::make_unique<Simulation::Motion>(context.count, world);
        }

        ImGui::End();
        ImGuiLayer::EndFrame();

        glfwSwapBuffers(window);
    }

    void Tick(float dt) {
        Update(dt);
        Render();
    }

    void Cleanup() {
        ImGuiLayer::Shutdown();

        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
