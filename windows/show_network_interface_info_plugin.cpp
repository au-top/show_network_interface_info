#include "include/show_network_interface_info/show_network_interface_info_plugin.h"
#include "function.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <map>
#include <memory>
#include <sstream>

#pragma comment(lib,"Iphlpapi.lib")

namespace {

class ShowNetworkInterfaceInfoPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  ShowNetworkInterfaceInfoPlugin();

  virtual ~ShowNetworkInterfaceInfoPlugin();

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

// static
void ShowNetworkInterfaceInfoPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "show_network_interface_info",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<ShowNetworkInterfaceInfoPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

ShowNetworkInterfaceInfoPlugin::ShowNetworkInterfaceInfoPlugin() {}

ShowNetworkInterfaceInfoPlugin::~ShowNetworkInterfaceInfoPlugin() {}

void ShowNetworkInterfaceInfoPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {

  if(method_call.method_name().compare("getNetWorkInfo")==0){
    auto resDataPoint = FlutterGetNetWorkInfo();
    result->Success(*resDataPoint);
    return;
  }else{
    result->NotImplemented();
    return;
  }

}

}  // namespace

void ShowNetworkInterfaceInfoPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  ShowNetworkInterfaceInfoPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
