#pragma once

#include "Rai/Events/Event.h"

#include <string>
#include <memory>
#include <functional>

struct GLFWwindow;
namespace Rai
{
  class Window
  {
  public:
  	using EventCallbackFn = std::function<void(Event&)>;

    Window(int width, int height, const std::string& title);
    ~Window();

    inline GLFWwindow* GetNativeWindow() { return m_Window; }
    inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

    void PollEvents() const noexcept;
    void SwapBuffers() const noexcept;

    std::pair<int, int> GetWindowSize() const noexcept;
  
  private:
    GLFWwindow* m_Window;

    struct WindowData
		{
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
  };
}
