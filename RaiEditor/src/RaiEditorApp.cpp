#include <Rai.h>

class ExampleLayer : public Rai::Layer
{
public:
  ExampleLayer()
    : Rai::Layer("Example")
  {
  }

  void OnUpdate() override
  {
    RAI_INFO("ExampleLayer: OnUpdate");
  }

  void OnEvent(Rai::Event& e) override
  {
    RAI_INFO("{0}", e);
  }
};

class RaiEditor : public Rai::Application
{
public:
  RaiEditor()
  {
    PushLayer(new ExampleLayer());
    PushLayer(new Rai::ImGuiLayer());
  }

  ~RaiEditor()
  {
  }
};

Rai::Application* Rai::CreateApplication()
{
  return new RaiEditor();
}
