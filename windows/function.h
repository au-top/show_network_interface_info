#ifndef FLUTTER_PLUGIN_SHOW_NETWORK_INTERFACE_INFO_PLUGIN_FILE_FUNCTION_H_
#define FLUTTER_PLUGIN_SHOW_NETWORK_INTERFACE_INFO_PLUGIN_FILE_FUNCTION_H_
    #include <windows.h>
    #include <VersionHelpers.h>
    #include <flutter/method_channel.h>
    #include <flutter/plugin_registrar_windows.h>
    #include <flutter/standard_method_codec.h>
    #include <flutter/encodable_value.h>
    #include <map>
    #include <memory>
    #include <sstream>
    #include <string>
    #include <vector>
    #include <Iphlpapi.h>
    #pragma comment(lib,"Iphlpapi.lib")
    flutter::EncodableList* FlutterGetNetWorkInfo();
#endif  
