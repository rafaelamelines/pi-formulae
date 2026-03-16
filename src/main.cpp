#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_plot.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "leibniz/leibniz.hpp"
#include "nilakantha/nilakantha.hpp"
#include "ramanujan/ramanujan.hpp"

int main() {
    if (!glfwInit()) {
        std::cerr << "something went wrong" << "\n";
    }

    GLFWwindow* window = glfwCreateWindow(1080, 720, "Pi Formulae", NULL, NULL);

    if (!window) {
        glfwTerminate();
        std::cerr << "something went wrong" << "\n";
    }

    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        glfwSwapBuffers(window);
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::SetNextWindowPos({ 0.0f, 0.0f });
            ImGui::SetNextWindowSize({ (float)width, 240.0f });
            ImGui::Begin("Leibniz Formula", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
            ImGui::Text("Independently discovered by Madhava of Sangamagrama ~300 years earlier than Leibniz.");
            if (ImGui::Button(leibniz::running ? "Stop" : "Start")) {
                leibniz::running = !leibniz::running;
            }

            ImGui::SameLine();

            if (ImGui::Button("Reset")) {
                leibniz::reset();
            }

            static char leibnizResult[12] = "0";

            if (leibniz::running) {
                double next = leibniz::next();
                leibniz::values.push_back((float)next);
                sprintf(leibnizResult, "%f", next);
            }

            static ImGui::PlotConfig conf;

            conf.values.ys = leibniz::values.data();
            conf.values.count = leibniz::values.size();
            conf.scale.min = 3;
            conf.scale.max = 4;
            conf.tooltip.show = false;
            conf.grid_x.show = false;
            conf.grid_y.show = true;
            conf.frame_size = ImVec2((float)width - 16.0f, 128.0f);
            conf.line_thickness = 1.0f;

            ImGui::Plot("plot", conf);

            ImGui::PushID(0);
            ImGui::Text(leibnizResult);
            ImGui::PopID();

            ImGui::End();
        }

        {
            ImGui::SetNextWindowPos({ 0.0f, 240.0f });
            ImGui::SetNextWindowSize({ (float)width, 240.0f });
            ImGui::Begin("Nilakantha Series", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
            ImGui::Text("An refinement to the Madhava-Leibniz series which converges significantly more quickly.");
            if (ImGui::Button(nilakantha::running ? "Stop" : "Start")) {
                nilakantha::running = !nilakantha::running;
            }

            ImGui::SameLine();

            if (ImGui::Button("Reset")) {
                nilakantha::reset();
            }

            static char nilakanthaResult[12] = "0";

            if (nilakantha::running) {
                double next = nilakantha::next();
                nilakantha::values.push_back((float)next);
                sprintf(nilakanthaResult, "%f", next);
            }

            static ImGui::PlotConfig conf;

            conf.values.ys = nilakantha::values.data();
            conf.values.count = nilakantha::values.size();
            conf.scale.min = 3.1f;
            conf.scale.max = 3.2f;
            conf.tooltip.show = false;
            conf.grid_x.show = false;
            conf.grid_y.show = true;
            conf.frame_size = ImVec2((float)width - 16.0f, 128.0f);
            conf.line_thickness = 1.0f;

            ImGui::Plot("plot", conf);

            ImGui::PushID(0);
            ImGui::Text(nilakanthaResult);
            ImGui::PopID();

            ImGui::End();
        }

        {
            ImGui::SetNextWindowPos({ 0.0f, 480.0f });
            ImGui::SetNextWindowSize({ (float)width, 240.0f });
            ImGui::Begin("Ramanujan Formula", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
            ImGui::Text("15 decimal places after one iteration.");

            static char ramanujanResult[12] = "0";

            if (ImGui::Button("Next")) {
                double next = ramanujan::next();
                ramanujan::values.push_back((float)next);
                sprintf(ramanujanResult, "%f", next);
            }

            ImGui::SameLine();

            if (ImGui::Button("Reset")) {
                ramanujan::reset();
            }

            static ImGui::PlotConfig conf;

            conf.values.ys = ramanujan::values.data();
            conf.values.count = ramanujan::values.size();
            conf.scale.min = 3.1f;
            conf.scale.max = 3.2f;
            conf.tooltip.show = false;
            conf.grid_x.show = false;
            conf.grid_y.show = true;
            conf.frame_size = ImVec2((float)width - 16.0f, 128.0f);
            conf.line_thickness = 1.0f;

            ImGui::Plot("plot", conf);

            ImGui::PushID(0);
            ImGui::Text(ramanujanResult);
            ImGui::PopID();

            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}