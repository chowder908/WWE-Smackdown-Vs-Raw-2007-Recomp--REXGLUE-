#pragma once
#include <rex/rex_app.h>
#include <rex/filesystem/devices/host_path_device.h>
#include <filesystem>

class Svr2007App : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;
  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<Svr2007App>(new Svr2007App(ctx, "svr2007",
        PPCImageConfig));
  }

  void OnPostSetup() override {
    auto cache = std::filesystem::current_path() / "cache";
    std::filesystem::create_directories(cache);

    auto* vfs = runtime()->file_system();

    auto device = std::make_unique<rex::filesystem::HostPathDevice>(
        "\\Device\\Cache", cache, false);
    device->Initialize();
    vfs->RegisterDevice(std::move(device));

    vfs->RegisterSymbolicLink("cache:", "\\Device\\Cache");
  }
};

  // Override virtual hooks for customization:
  // void OnPostInitLogging() override {}
  // void OnPreSetup(rex::RuntimeConfig& config) override {}
  // void OnLoadXexImage(std::string& xex_image) override {}
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // void OnShutdown() override {}
  // void OnConfigurePaths(rex::PathConfig& paths) override {}
};
