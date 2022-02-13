#pragma once

#include "Window.h"

namespace Rai {

  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  
  private:
    Window* m_Window;
  };

  Application* CreateApplication();
}
