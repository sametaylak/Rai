#pragma once

namespace Rai {

  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  Application* CreateApplication();
}
