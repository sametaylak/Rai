#pragma once

#include <string>
#include <memory>

struct GLFWwindow;
namespace Rai
{
  class Window
  {
  public:
    Window(int width, int height, const std::string& title);
    ~Window();

    inline GLFWwindow* GetNativeWindow() { return m_Window; }

    bool ShouldClose() const noexcept;

    void PollEvents() const noexcept;
    void SwapBuffers() const noexcept;

    std::pair<int, int> GetWindowSize() const noexcept;
  
  private:
    GLFWwindow* m_Window;
  };
}