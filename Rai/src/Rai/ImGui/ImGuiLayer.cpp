#include "raipch.h"
#include "Rai/Core/Application.h"
#include "Rai/ImGui/ImGuiLayer.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"

namespace Rai
{
  ImGuiLayer::ImGuiLayer()
    : Layer("ImGuiLayer")
  {
  }

  ImGuiLayer::~ImGuiLayer()
  {
  }

  void ImGuiLayer::OnAttach()
  {
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    Application& app = Application::Get();
    io.DisplaySize = ImVec2(app.GetWindow().GetWindowSize().first, app.GetWindow().GetWindowSize().second);

    ImGui_ImplOpenGL3_Init("#version 330");
  }

  void ImGuiLayer::OnDetach()
  {

  }

  void ImGuiLayer::OnUpdate()
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    float time = (float)glfwGetTime();
    ImGuiIO& io = ImGui::GetIO();
    io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
    m_Time = time;

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

  void ImGuiLayer::OnEvent(Event& e)
  {

  }
}
