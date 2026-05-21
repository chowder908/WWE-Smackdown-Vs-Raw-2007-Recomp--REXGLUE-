// wwesmackdownvsraw2007 - ReXGlue Recompiled Project
//
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>
#include <rex/filesystem/devices/host_path_device.h>

class Wwesmackdownvsraw2007App : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<Wwesmackdownvsraw2007App>(new Wwesmackdownvsraw2007App(ctx, "wwesmackdownvsraw2007",
        PPCImageConfig));
  }


void OnConfigurePaths(rex::PathConfig& paths) override {
    std::filesystem::path exe_dir = std::filesystem::current_path();
    paths.game_data_root = exe_dir / "assets";
    paths.user_data_root = exe_dir / "saves";
    paths.cache_root = exe_dir / "cache";
  }

void OnPostSetup() override {
    window()->SetTitle("WWE SmackDown vs. Raw 2007: ReXGlue");
    auto exe_dir = std::filesystem::current_path();
    auto cache = exe_dir / "cache";
    auto saves = exe_dir / "saves";
    std::filesystem::create_directories(cache);
    std::filesystem::create_directories(saves);
    auto* vfs = runtime()->file_system();

    auto cache_device = std::make_unique<rex::filesystem::HostPathDevice>(
        "\\Device\\Cache", cache, false);
    cache_device->Initialize();
    vfs->RegisterDevice(std::move(cache_device));
    vfs->RegisterSymbolicLink("cache:", "\\Device\\Cache");

    auto profile_device = std::make_unique<rex::filesystem::HostPathDevice>(
        "\\Device\\Profile0", saves, false);
    profile_device->Initialize();
    vfs->RegisterDevice(std::move(profile_device));
    vfs->RegisterSymbolicLink("profile0:", "\\Device\\Profile0");
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