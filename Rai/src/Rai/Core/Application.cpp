#include "Application.h"

namespace Rai
{
  Application::Application()
  {
    m_Window = new Window(800, 600, "Rai Engine");
  }

  Application::~Application()
  {
  }

  void Application::Run()
  {
    while (!m_Window->ShouldClose())
    {
      m_Window->PollEvents();

      m_Window->SwapBuffers();
    }
  }
}
