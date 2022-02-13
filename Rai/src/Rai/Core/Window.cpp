#include "Window.h"

#include "GLFW/glfw3.h"

namespace Rai
{
  Window::Window(int width, int height, const std::string& title)
	{
		glfwInit();
		m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	bool Window::ShouldClose() const noexcept
	{
		return glfwWindowShouldClose(m_Window) != 0;
	}

	void Window::PollEvents() const noexcept
	{
		glfwPollEvents();
	}

	void Window::SwapBuffers() const noexcept
	{
		glfwSwapBuffers(m_Window);
	}

	std::pair<int, int> Window::GetWindowSize() const noexcept
	{
		std::pair<int, int> sz{};
		glfwGetWindowSize(m_Window, &sz.first, &sz.second);
		return sz;
	}
}