#pragma once

#include <spdlog/spdlog.h>

namespace Rai
{
  class Log
  {
  public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };
}

#define RAI_CORE_ERROR(...) ::Rai::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RAI_CORE_WARN(...)  ::Rai::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RAI_CORE_INFO(...)  ::Rai::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RAI_CORE_TRACE(...) ::Rai::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RAI_CORE_FATAL(...) ::Rai::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define RAI_ERROR(...) ::Rai::Log::GetClientLogger()->error(__VA_ARGS__)
#define RAI_WARN(...)  ::Rai::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RAI_INFO(...)  ::Rai::Log::GetClientLogger()->info(__VA_ARGS__)
#define RAI_TRACE(...) ::Rai::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RAI_FATAL(...) ::Rai::Log::GetClientLogger()->critical(__VA_ARGS__)
