#include "Rai/Core/Application.h"
#include "Rai/Core/Log.h"

#include "Rai/Events/ApplicationEvent.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace Rai
{
  Application* Application::s_Instance = nullptr;

  Application::Application()
  {
    s_Instance = this;

    m_Window = new Window(1080, 720, "Rai Engine");
    m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
  }

  Application::~Application()
  {
  }

  void Application::Run()
  {
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while (m_IsRunning)
    {
      m_Window->PollEvents();

      glClear(GL_COLOR_BUFFER_BIT);

      for (Layer* layer : m_LayerStack)
      {
        layer->OnUpdate();
      }

      m_Window->SwapBuffers();
    }
  }

  void Application::PushLayer(Layer* layer)
  {
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
  }

  void Application::PushOverlay(Layer* overlay)
  {
    m_LayerStack.PushOverlay(overlay);
    overlay->OnAttach();
  }

  void Application::OnEvent(Event& e)
  {
    EventDispatcher dispatcher(e);

    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

    RAI_CORE_INFO("{0}", e);

    for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
    {
      (*--it)->OnEvent(e);
      if (e.Handled)
      {
        break;
      }
    }
  }

  bool Application::OnWindowClose(WindowCloseEvent& e)
  {
    m_IsRunning = false;
    return true;
  }
}
