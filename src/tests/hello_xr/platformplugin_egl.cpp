#include "pch.h"
#include "common.h"
#include "platformplugin.h"

#ifdef XR_USE_PLATFORM_EGL
namespace {
struct EGLPlatformPlugin : public IPlatformPlugin {
    EGLPlatformPlugin(const std::shared_ptr<Options>& /*unused*/) {}

    std::vector<std::string> GetInstanceExtensions() const override { return { XR_MND_EGL_ENABLE_EXTENSION_NAME }; }

    XrBaseInStructure* GetInstanceCreateExtension() const override { return nullptr; }
};
}  // namespace

std::shared_ptr<IPlatformPlugin> CreatePlatformPlugin_EGL(const std::shared_ptr<Options>& options) {
    return std::make_shared<EGLPlatformPlugin>(options);
}
#endif
