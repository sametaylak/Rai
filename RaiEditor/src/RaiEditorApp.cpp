#include <Rai.h>

namespace Rai
{
  class RaiEditor : public Application
  {
  public:
    RaiEditor()
    {
    }

    ~RaiEditor()
    {
    }
  };

  Application* CreateApplication()
  {
    return new RaiEditor();
  }
}
