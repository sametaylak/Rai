#pragma once

extern Rai::Application* Rai::CreateApplication();

int main(int argc, char** argv)
{
  Rai::Log::Init();

  auto app = Rai::CreateApplication();
  app->Run();
  delete app;
}
