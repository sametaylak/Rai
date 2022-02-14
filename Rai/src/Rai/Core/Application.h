#pragma once

#include "Rai/Core/Window.h"
#include "Rai/Core/LayerStack.h"
#include "Rai/Events/Event.h"
#include "Rai/Events/ApplicationEvent.h"

namespace Rai {

  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

    inline Window& GetWindow() { return *m_Window; }
    inline static Application& Get() { return *s_Instance; }
  private:
    bool OnWindowClose(WindowCloseEvent& e);

    Window* m_Window;
    bool m_IsRunning = true;
    LayerStack m_LayerStack;
  private:
    static Application* s_Instance;
  };

  Application* CreateApplication();
}
