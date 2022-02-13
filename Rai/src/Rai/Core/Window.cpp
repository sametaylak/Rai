#include "Window.h"

#include "GLFW/glfw3.h"

namespace Rai
{
  Window::Window(int width, int height, const std::string& title)
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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