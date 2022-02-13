#pragma once

#include "raipch.h"
#include "Rai/Events/Event.h"

namespace Rai
{
  class Layer
  {
  public:
    Layer(const std::string& name = "Layer");
    virtual ~Layer();

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnEvent(Event& e) {}

    inline const std::string& GetName() const { return m_DebugName; }

  private:
    std::string m_DebugName;
  };
}
